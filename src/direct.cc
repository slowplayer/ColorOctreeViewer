#include "ColorOctreeServer.h"

#include <chrono>

int main()
{
  std::string data_path="/home/huo/coke/";
  std::string param_path="/home/huo/ColorOctreeViewer/data/TUM1.yaml";
  
  ColorOctreeServer* octree=new ColorOctreeServer(data_path,param_path);
  
  std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
  
  octree->run();
  
  std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
  
  double ttrack= std::chrono::duration_cast<std::chrono::duration<double> >(t2 - t1).count();
  
  std::cout<<"total time: "<<ttrack<<std::endl;
  
  delete octree;
  
  return 0;
}