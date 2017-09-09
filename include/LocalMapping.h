#ifndef  LOCAL_MAPPING_H
#define  LOCAL_MAPPING_H

#include <iostream>
#include <fstream>

#include <thread>
#include <mutex>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/video.hpp>

#include <octomap/ColorOcTree.h>
#include <octomap/octomap.h>

#include <Eigen/Geometry>

#include "ParameterServer.h"
#include "Viewer.h"

class ColorOctomap;
class Viewer;
class LocalMapping
{
public:
  LocalMapping(std::string data,std::string param);
  ~LocalMapping();
  
  void Run(); 
private:
  void mapUpdate(const cv::Mat& imRGB,const cv::Mat& imDepth,Eigen::Isometry3d pose);
  void Stop();
  
  float fxinv,fyinv,cx,cy;
  float depthScale;
  
  std::string data_path;
  std::string rgb_path,depth_path,gt_path;
  
  ColorOctomap* mMap;
  Viewer* mViewer;
  std::thread* mptViewer;
};
#endif