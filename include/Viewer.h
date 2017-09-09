#ifndef VIEWER_H
#define VIEWER_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <octomap/ColorOcTree.h>
#include <octomap/octomap.h>

#include "ParameterServer.h"
#include "ColorOctomap.h"

class ColorOctomap;
class Viewer
{
public:
  Viewer(ColorOctomap* map);
  
  void Run();
  void setFinish();
private:
  bool checkFinish();
  void octreeRender();
  
  ColorOctomap* mOcTree;
  
  float mT;
  float mImageWidth,mImageHeight;
  float mViewpointX,mViewpointY,mViewpointZ,mViewpointF; 

  bool mFinished;
  std::mutex mMutexFinish;
  octomap::ColorOcTree* tree_;
};
#endif