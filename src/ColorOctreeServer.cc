#include "ColorOctreeServer.h"
#include <boost/concept_check.hpp>

ColorOctreeServer::ColorOctreeServer(const std::string data,const std::string param)
:data_path(data)
{
  rgb_path=data_path+"rgb.txt";
  depth_path=data_path+"depth.txt";
  gt_path=data_path+"groundtruth.txt";
  
  ParameterServer::instance()->setPath(param);
  
  std::cout<<"ready to init"<<std::endl;
  ParameterServer* ps=ParameterServer::instance();
  
  mImageWidth=ps->getParam("Camera.width");
  mImageHeight=ps->getParam("Camera.height");
  
  if(mImageWidth<1||mImageHeight<1)
  {
    mImageWidth=640;
    mImageHeight=480;
  }
  
  mViewpointX=ps->getParam("Viewer.ViewpointX");
  mViewpointY=ps->getParam("Viewer.ViewpointY");
  mViewpointZ=ps->getParam("Viewer.ViewpointZ");
  mViewpointF=ps->getParam("Viewer.ViewpointF");
  
  float fps=ps->getParam("Camera.fps");
  if(fps<1)
    fps=30;
  mT=1e3/fps;
   
  displayLevel=static_cast<int>(ps->getParam("Octomap.displayLevel"));
  
  fxinv=1.0/ps->getParam("Camera.fx");
  fyinv=1.0/ps->getParam("Camera.fy");
  cx=ps->getParam("Camera.cx");
  cy=ps->getParam("Camera.cy");
  depthScale=ps->getParam("Camera.depthScale");
  
  resolution=ps->getParam("Octomap.resolution");
  //init Octree
  tree_=new octomap::ColorOcTree(resolution);
  
}
void ColorOctreeServer::init()
{
  
}
bool ColorOctreeServer::run()
{
  pangolin::CreateWindowAndBind("Color Octree Viewer",1024,768);
  
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  
  pangolin::OpenGlRenderState s_cam(
    pangolin::ProjectionMatrix(1024,768,mViewpointF,mViewpointF,512,389,0.1,1000),
    pangolin::ModelViewLookAt(mViewpointX,mViewpointY,mViewpointZ,0,0,0,0.0,-1.0,0.0)
  );
  pangolin::View& d_cam=pangolin::CreateDisplay()
  //.SetBounds(0.0,1.0,0.0,1.0,-1024.0f/768.0f)
  .SetHandler(new pangolin::Handler3D(s_cam));  
  
   //d_cam.Activate(s_cam);
  
  std::ifstream rgb_txt,depth_txt,gt_txt;
  std::string rgb_str,depth_str;
  Eigen::Isometry3d pose;
  Eigen::Quaterniond q;
  double data[8];
  int cnt;
  
  rgb_txt.open(rgb_path.c_str());
  if(!rgb_txt.is_open())
  {
    std::cout<<"rgb error"<<std::endl;
    return false;
  }
  depth_txt.open(depth_path.c_str());
  if(!depth_txt.is_open())
  {
    std::cout<<"depth error"<<std::endl;
    return false;
  }
//  depth_txt>>depth_str;depth_txt>>depth_str;depth_txt>>depth_str;
  gt_txt.open(gt_path.c_str());
  if(!gt_txt.is_open())
  {
    std::cout<<"gt error"<<std::endl;
    return false;
  }
 // gt_txt>>rgb_str;gt_txt>>rgb_str;gt_txt>>rgb_str;
  
  cnt=0;
  while(1)
  {
    if(rgb_txt.eof()||depth_txt.eof()||gt_txt.eof())
    {
      break;
    }
    std::cout<<"Image "<<++cnt<<std::endl;
    rgb_txt>>rgb_str;rgb_txt>>rgb_str;
    depth_txt>>depth_str;depth_txt>>depth_str;
    for(int i=0;i<8;i++)
      gt_txt>>data[i];
    q=Eigen::Quaterniond(data[7],data[4],data[5],data[6]);
    pose=Eigen::Isometry3d(q);
    pose.pretranslate(Eigen::Vector3d(data[1],data[2],data[3]));
    cv::Mat color=cv::imread(data_path+rgb_str);
    cv::Mat depth=cv::imread(data_path+depth_str,-1);
    
 //   std::cout<<data_path+rgb_str<<std::endl;
 //   std::cout<<depth_path+depth_str<<std::endl;
 
 //   std::cout<<"ready to update"<<std::endl;
    treeUpdate(color,depth,pose);
 //   std::cout<<"ready to render"<<std::endl;
    treeRender(s_cam,d_cam);
  }
  return true;
}
void ColorOctreeServer::treeUpdate(const cv::Mat& imRGB, const cv::Mat& imDepth, const Eigen::Isometry3d& pose)
{
   for(int v=0;v<imRGB.rows;v++)
     for(int u=0;u<imRGB.cols;u++)
     {
       unsigned int d=imDepth.ptr<unsigned short>(v)[u];
       if(d==0)continue;
       if(d>=7000)continue;
       
	Eigen::Vector3d point;
	point[2]=double(d)/depthScale;
	point[0]=(u-cx)*point[2]*fxinv;
	point[1]=(v-cy)*point[2]*fyinv;
	Eigen::Vector3d pointWorld=pose*point;
	
	uint8_t b,g,r;
	b=imRGB.data[v*imRGB.step+u*imRGB.channels()];
	g=imRGB.data[v*imRGB.step+u*imRGB.channels()+1];
	r=imRGB.data[v*imRGB.step+u*imRGB.channels()+2];
	
	tree_->updateNode(octomap::point3d(pointWorld[0],pointWorld[1],pointWorld[2]),true);
	tree_->averageNodeColor(pointWorld[0],pointWorld[1],pointWorld[2],r,g,b);
     }
  tree_->updateInnerOccupancy();
}
void ColorOctreeServer::treeRender(pangolin::OpenGlRenderState s_cam,pangolin::View& d_cam)
{
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  
  d_cam.Activate(s_cam);
  glClearColor(1.0f,1.0f,1.0f,1.0f);
  
  //render coloroctree
  octomap::ColorOcTree::tree_iterator it=tree_->begin_tree();
  octomap::ColorOcTree::tree_iterator end=tree_->end_tree();
  glBegin(GL_TRIANGLES);
  for(;it!=end;++it)
  {
      if(displayLevel!=it.getDepth())
        continue;
    
      glColor4ub(it->getColor().r, it->getColor().g, it->getColor().b,128);
      float halfsize = it.getSize()/2.0;
      float x = it.getX(); 
      float y = it.getY(); 
      float z = it.getZ(); 
     // std::cout<<"x:"<<x<<" y:"<<y<<" z:"<<z<<std::endl;
      //Front
      glVertex3f(x-halfsize,y-halfsize,z-halfsize);
      glVertex3f(x-halfsize,y+halfsize,z-halfsize);
      glVertex3f(x+halfsize,y+halfsize,z-halfsize);

      glVertex3f(x-halfsize,y-halfsize,z-halfsize);
      glVertex3f(x+halfsize,y+halfsize,z-halfsize);
      glVertex3f(x+halfsize,y-halfsize,z-halfsize);

      //Back
      glVertex3f(x-halfsize,y-halfsize,z+halfsize);
      glVertex3f(x+halfsize,y-halfsize,z+halfsize);
      glVertex3f(x+halfsize,y+halfsize,z+halfsize);

      glVertex3f(x-halfsize,y-halfsize,z+halfsize);
      glVertex3f(x+halfsize,y+halfsize,z+halfsize);
      glVertex3f(x-halfsize,y+halfsize,z+halfsize);

      //Left
      glVertex3f(x-halfsize,y-halfsize,z-halfsize);
      glVertex3f(x-halfsize,y-halfsize,z+halfsize);
      glVertex3f(x-halfsize,y+halfsize,z+halfsize);

      glVertex3f(x-halfsize,y-halfsize,z-halfsize);
      glVertex3f(x-halfsize,y+halfsize,z+halfsize);
      glVertex3f(x-halfsize,y+halfsize,z-halfsize);

      //Right
      glVertex3f(x+halfsize,y-halfsize,z-halfsize);
      glVertex3f(x+halfsize,y+halfsize,z-halfsize);
      glVertex3f(x+halfsize,y+halfsize,z+halfsize);

      glVertex3f(x+halfsize,y-halfsize,z-halfsize);
      glVertex3f(x+halfsize,y+halfsize,z+halfsize);
      glVertex3f(x+halfsize,y-halfsize,z+halfsize);

      //?
      glVertex3f(x-halfsize,y-halfsize,z-halfsize);
      glVertex3f(x+halfsize,y-halfsize,z-halfsize);
      glVertex3f(x+halfsize,y-halfsize,z+halfsize);

      glVertex3f(x-halfsize,y-halfsize,z-halfsize);
      glVertex3f(x+halfsize,y-halfsize,z+halfsize);
      glVertex3f(x-halfsize,y-halfsize,z+halfsize);

      //?
      glVertex3f(x-halfsize,y+halfsize,z-halfsize);
      glVertex3f(x-halfsize,y+halfsize,z+halfsize);
      glVertex3f(x+halfsize,y+halfsize,z+halfsize);

      glVertex3f(x-halfsize,y+halfsize,z-halfsize);
      glVertex3f(x+halfsize,y+halfsize,z+halfsize);
      glVertex3f(x+halfsize,y+halfsize,z-halfsize);
  }
  glEnd();
  pangolin::FinishFrame();
  cv::waitKey(mT);
}














