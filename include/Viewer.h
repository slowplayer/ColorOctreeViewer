#ifndef VIEWER_H
#define VIEWER_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <octomap/ColorOcTree.h>
#include <octomap/octomap.h>

#include <mutex>

#include "ParameterServer.h"


class Viewer
{
public:
  Viewer(octomap::ColorOcTree* tree);
  
  void Run();
private:
  bool Stop();
  
  int displayLevel;
  octomap::ColorOcTree tree_;
  
  double mT;
  float mImageWidth,mImageHeight;
  
  float mViewpointX,mViewpointY,mViewpointZ,mViewpointF;
  
  bool CheckFinish();
  bool SetFinish();
  
  bool mbFinishRequested;
  bool mbFinished;
  std::mutex mMutexFinish;
  
  bool mbStopped;
  bool mbStopRequested;
  std::mutex mMutexStop;
};
#endif