#ifndef COLOR_OCTREE_SERVER_H
#define COLOR_OCTREE_SERVER_H

#include <Eigen/Geometry>

#include <octomap/ColorOcTree.h>
#include <octomap/octomap.h>

#include <pangolin/pangolin.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "ParameterServer.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class ColorOctreeServer
{
public:
  ColorOctreeServer(const std::string data_path,const std::string param_path);
 
  bool run();
private:
  void init();
  
  void treeUpdate(const cv::Mat& imRGB,const cv::Mat& imDepth,const Eigen::Isometry3d& pose);
  void treeRender(pangolin::OpenGlRenderState s_cam,pangolin::View& d_cam);
  
  std::string data_path;
  std::string rgb_path,depth_path,gt_path;
  
  //view var.
  float mImageWidth,mImageHeight;
  float mViewpointX,mViewpointY,mViewpointZ,mViewpointF;
  float mT; 
  //update var. 
  float fxinv,fyinv,cx,cy;
  float depthScale;
 
  int displayLevel;
  
  float resolution;
  
  octomap::ColorOcTree* tree_;
  
//  pangolin::OpenGlRenderState s_cam;
//  pangolin::View& d_cam;
};
#endif