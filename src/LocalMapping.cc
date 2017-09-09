#include "LocalMapping.h"

LocalMapping::LocalMapping(std::string data,std::string param)
:data_path(data)
{
  ParameterServer* ps=ParameterServer::instance();
  
  ps->setPath(param);
  
  fxinv=1.0/ps->getParam("Camera.fx");
  fyinv=1.0/ps->getParam("Camera.fy");
  cx=ps->getParam("Camera.cx");
  cy=ps->getParam("Camera.cy");
  depthScale=ps->getParam("Camera.depthScale");
  
  rgb_path=data_path+"rgb.txt";
  depth_path=data_path+"depth.txt";
  gt_path=data_path+"groundtruth.txt";
  
  
  float resolution=ps->getParam("Octomap.resolution");
  int displayLevel=static_cast<int>(ps->getParam("Octomap.displayLevel"));
  
 
  mMap=new ColorOctomap(resolution,displayLevel);
  
  mViewer=new Viewer(mMap);
  
  mptViewer=new std::thread(&Viewer::Run,mViewer);
}
LocalMapping::~LocalMapping()
{
  delete mMap;
  delete mViewer;
}
void LocalMapping::Run()
{
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
    return;
  }
  depth_txt.open(depth_path.c_str());
  if(!depth_txt.is_open())
  {
    std::cout<<"depth error"<<std::endl;
    return;
  }
//  depth_txt>>depth_str;depth_txt>>depth_str;depth_txt>>depth_str;
  gt_txt.open(gt_path.c_str());
  if(!gt_txt.is_open())
  {
    std::cout<<"gt error"<<std::endl;
    return;
  }
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
 //   std::cout<<data_path+depth_str<<std::endl;
    
    mapUpdate(color,depth,pose);
  }
  Stop();
}
void LocalMapping::mapUpdate(const cv::Mat& imRGB, const cv::Mat& imDepth, Eigen::Isometry3d pose)
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
	
	mMap->treeUpdateNode(pointWorld[0],pointWorld[1],pointWorld[2],r,g,b);
	
	///cv::waitKey(1);
     }
  mMap->treeUpdateOccupancy();
}

void LocalMapping::Stop()
{
  mViewer->setFinish();
}