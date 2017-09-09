#include "ColorOctomap.h"


ColorOctomap::ColorOctomap(float resolution, int displayLevel)
:mLevel(displayLevel)
{
  tree_=new octomap::ColorOcTree(resolution);
}
ColorOctomap::~ColorOctomap()
{
  delete tree_;
}

void ColorOctomap::treeUpdateNode(double x, double y, double z, uint8_t r, uint8_t g, uint8_t b)
{
 // std::cout<<"update node"<<std::endl;
  {
    std::unique_lock<std::mutex> lock(mMutexTree);
    tree_->updateNode(octomap::point3d(x,y,z),true);
    tree_->averageNodeColor(x,y,z,r,g,b);
  }
}
void ColorOctomap::treeUpdateOccupancy()
{
//  std::cout<<"update occupancy"<<std::endl;
  std::unique_lock<std::mutex> lock(mMutexTree);
  tree_->updateInnerOccupancy();
}
octomap::ColorOcTree* ColorOctomap::getColorTree()
{
  {
    std::unique_lock<std::mutex> lock(mMutexTree);
    return new octomap::ColorOcTree(*tree_);
  }
}

void ColorOctomap::treeRender()
{
  {
  std::unique_lock<std::mutex> lock(mMutexTree);
  octomap::ColorOcTree::tree_iterator it=tree_->begin_tree();
  octomap::ColorOcTree::tree_iterator end=tree_->end_tree();
  glBegin(GL_TRIANGLES);
  for(;it!=end;++it)
  {
      if(mLevel!=it.getDepth())
        continue;
    
      glColor4ub(it->getColor().r, it->getColor().g, it->getColor().b,128);
      float halfsize = it.getSize()/2.0;
      float x = it.getX(); 
      float y = it.getY(); 
      float z = it.getZ(); 
      //Front
      glVertex3f(x-halfsize,y-halfsize,z-halfsize);
      glVertex3f(x-halfsize,y+halfsize,z-halfsize);
      glVertex3f(x+halfsize,y+halfsize,z-halfsize);

      glVertex3f(x-halfsize,y-halfsize,z-halfsize);
      glVertex3f(x+halfsize,y+halfsize,z-halfsize);
      glVertex3f(x+halfsize,y-halfsize,z-halfsize);

      //Back
      glVertex3f(x-halfsize,y-halfsize,z+halfsize);
      glVertex3f(x+halfsize,y-halfsize,z+halfsize);
      glVertex3f(x+halfsize,y+halfsize,z+halfsize);

      glVertex3f(x-halfsize,y-halfsize,z+halfsize);
      glVertex3f(x+halfsize,y+halfsize,z+halfsize);
      glVertex3f(x-halfsize,y+halfsize,z+halfsize);

      //Left
      glVertex3f(x-halfsize,y-halfsize,z-halfsize);
      glVertex3f(x-halfsize,y-halfsize,z+halfsize);
      glVertex3f(x-halfsize,y+halfsize,z+halfsize);

      glVertex3f(x-halfsize,y-halfsize,z-halfsize);
      glVertex3f(x-halfsize,y+halfsize,z+halfsize);
      glVertex3f(x-halfsize,y+halfsize,z-halfsize);

      //Right
      glVertex3f(x+halfsize,y-halfsize,z-halfsize);
      glVertex3f(x+halfsize,y+halfsize,z-halfsize);
      glVertex3f(x+halfsize,y+halfsize,z+halfsize);

      glVertex3f(x+halfsize,y-halfsize,z-halfsize);
      glVertex3f(x+halfsize,y+halfsize,z+halfsize);
      glVertex3f(x+halfsize,y-halfsize,z+halfsize);

      //?
      glVertex3f(x-halfsize,y-halfsize,z-halfsize);
      glVertex3f(x+halfsize,y-halfsize,z-halfsize);
      glVertex3f(x+halfsize,y-halfsize,z+halfsize);

      glVertex3f(x-halfsize,y-halfsize,z-halfsize);
      glVertex3f(x+halfsize,y-halfsize,z+halfsize);
      glVertex3f(x-halfsize,y-halfsize,z+halfsize);

      //?
      glVertex3f(x-halfsize,y+halfsize,z-halfsize);
      glVertex3f(x-halfsize,y+halfsize,z+halfsize);
      glVertex3f(x+halfsize,y+halfsize,z+halfsize);

      glVertex3f(x-halfsize,y+halfsize,z-halfsize);
      glVertex3f(x+halfsize,y+halfsize,z+halfsize);
      glVertex3f(x+halfsize,y+halfsize,z-halfsize);
  }
  glEnd();
  }
}

