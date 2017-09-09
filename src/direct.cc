#include "ColorOctreeServer.h"


int main()
{
  std::string data_path="/home/huo/coke/";
  std::string param_path="/home/huo/ColorOctreeViewer/data/TUM1.yaml";
  
  ColorOctreeServer* octree=new ColorOctreeServer(data_path,param_path);
  
  octree->run();
  
  delete octree;
  
  return 0;
}