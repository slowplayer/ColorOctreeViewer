#include "LocalMapping.h"

LocalMapping::LocalMapping(std::string data_path)
:data_str(data_path)
{
  ParameterServer* ps=ParameterServer::instance();
  
  fxinv=1.0/ps->getParam("Camera.fx");
  fyinv=1.0/ps->getParam("Camera.fy");
  cx=ps->getParam("Camera.cx");
  cy=ps->getParam("Camera.cy");
  depthScale=ps->getParam("Camera.depthScale");
  
  resolution=ps->getParam("Octomap.resolution");
  tree_=new octomap::ColorOcTree(resolution);
  mViewer=new Viewer(tree_);
}
void LocalMapping::Run()
{
  std::string rgb_path=data_str+"/rgb.txt";
  std::string depth_path=data_str+"/depth.txt";
  std::string gt_path=data_str+"/groundtruth.txt";
  
  std::ifstream rgb_txt,depth_txt;
  std::string rgb_str,depth_str;
  Eigen::Isometry3d pose;;
  Eigen::Quaterniond q;
  
  
  
}
