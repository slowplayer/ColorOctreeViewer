#ifndef COLOR_OCTOMAP_H
#define COLOR_OCTOMAP_H

#include <mutex>
#include <thread>

#include <octomap/octomap.h>
#include <octomap/ColorOcTree.h>

#include <pangolin/pangolin.h>

class ColorOctomap
{
public:
  ColorOctomap(float resolution,int displayLevel);
  ~ColorOctomap();
  
  void treeUpdateNode(double x,double y,double z,uint8_t r,uint8_t g,uint8_t b);
  void treeUpdateOccupancy();
  void treeRender();
  octomap::ColorOcTree* getColorTree();
private:
  octomap::ColorOcTree* tree_;
  std::mutex mMutexTree;
  int mLevel;
};
#endif