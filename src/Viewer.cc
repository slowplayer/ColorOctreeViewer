#include "Viewer.h"

#include <pangolin/pangolin.h>


Viewer::Viewer(octomap::ColorOcTree* tree)
:tree_(tree)
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
  
  displayLevel=ps->getParam("Octomap.displayLevel");
}
void Viewer::Run()
{
  mbFinished=false;
  pangolin::CreateWindowAndBind("Color Octree Viewer",1024,768);
  
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  
  pangolin::OpenGlRenderState s_cam(
    pangolin::ProjectionMatrix(1024,768,mViewpointF,mViewpointF,512,389,0.1,1000),
    pangolin::ModelViewLookAt(mViewpointX,mViewpointY,mViewpointZ,0,0,0,0.0,-1.0,0.0)
  );
  pangolin::View& d_cam=pangolin::CreateDisplay()
  .SetBounds(0.0,1.0,0.0,1.0,-1024.0f/768.0f)
  .SetHandler(new pangolin::Handler3D(s_cam));
  
  pangolin::OpenGlMatrix Twc;
  Twc.SetIdentity();
  
  
  while(1)
  {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    
    d_cam.Activate(s_cam);
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    
    //TODO:render the octomap;
    
    
    pangolin::FinishFrame();
    
    
    cv::waitKey(mT);
  }
}
bool Viewer::Stop()
{

}
bool Viewer::CheckFinish()
{

}
bool Viewer::SetFinish()
{

}
