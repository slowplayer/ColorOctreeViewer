#include "ParameterServer.h"

ParameterServer* ParameterServer::_instance=NULL;

ParameterServer::ParameterServer()
{

}
ParameterServer* ParameterServer::instance()
{
  if(_instance==NULL)
    _instance=new ParameterServer();
  return _instance;
}
bool ParameterServer::setPath(const std::string filename)
{
  cv::FileStorage fs(filename,cv::FileStorage::READ);
  if(!fs.isOpened())
    return false;

  setParam("Camera.fx",fs["Camera.fx"]);
  setParam("Camera.fy",fs["Camera.fy"]);
  setParam("Camera.cx",fs["Camera.cx"]);
  setParam("Camera.cy",fs["Camera.cy"]);
  
  setParam("Camera.width",fs["Camera.width"]);
  setParam("Camera.height",fs["Camera.height"]);
  
  setParam("Camera.fps",fs["Camera.fps"]);
  
  setParam("Camera.depthScale",fs["Camera.depthScale"]);

  setParam("Viewer.ViewpointX",fs["Viewer.ViewpointX"]);
  setParam("Viewer.ViewpointY",fs["Viewer.ViewpointY"]);
  setParam("Viewer.ViewpointZ",fs["Viewer.ViewpointZ"]);
  setParam("Viewer.ViewpointF",fs["Viewer.ViewpointF"]);
  
  setParam("Octomap.resolution",fs["Octomap.resolution"]);
  setParam("Octomap.displayLevel",fs["Octomap.displayLevel"]);
  
  return true;
}