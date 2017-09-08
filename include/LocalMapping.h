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

class Viewer;
class LocalMapping
{
public:
  LocalMapping(std::string data_path);
  
  void Run(); 
private:
  float fxinv,fyinv,cx,cy;
  float depthScale;
  
  std::string data_str;
  
  float resolution;
  octomap::ColorOcTree* tree_;
  std::mutex mMutexTree;
  Viewer* mViewer;
};
#endif