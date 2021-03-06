#include "Viewer.h"


Viewer::Viewer(ColorOctomap* map)
:mOcTree(map),mFinished(false),tree_(NULL)
{
  ParameterServer* ps=ParameterServer::instance();
  float fps=ps->getParam("Camera.fps");
  if(fps<1)
    fps=30;
  mT=1e3/fps;
  
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
  
}
void Viewer::Run()
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
 // .SetBounds(0.0,1.0,0.0,1.0,-1024.0f/768.0f)
  .SetHandler(new pangolin::Handler3D(s_cam));
  
 // pangolin::OpenGlMatrix Twc;
 // Twc.SetIdentity();
  
 // std::cout<<"Viewer ready"<<std::endl;
  
  while(!checkFinish())
  {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    
    d_cam.Activate(s_cam);
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    
  //  std::cout<<"ready to render"<<std::endl;
    //render the octomap;
   // mOcTree->treeRender();
    tree_=mOcTree->getColorTree();
    octreeRender();
    delete tree_;
    tree_=NULL;
    
    pangolin::FinishFrame(); 
    cv::waitKey(mT);
  }
}
bool Viewer::checkFinish()
{
  std::unique_lock<std::mutex> lock(mMutexFinish);
  return mFinished;
}
void Viewer::setFinish()
{
  std::unique_lock<std::mutex> lock(mMutexFinish);
  mFinished=true;
}
void Viewer::octreeRender()
{
  if(tree_==NULL)
    return;
  octomap::ColorOcTree::tree_iterator it=tree_->begin_tree();
  octomap::ColorOcTree::tree_iterator end=tree_->end_tree();
  glBegin(GL_TRIANGLES);
  for(;it!=end;++it)
  {
      if(it.getDepth()!=16)
        continue;
    
      glColor4ub(it->getColor().r, it->getColor().g, it->getColor().b,128);
      float halfsize = it.getSize()/2.0;
      float x = it.getX(); 
      float y = it.getY(); 
      float z = it.getZ(); 
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
  
}


