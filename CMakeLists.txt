cmake_minimum_required(VERSION 2.8)
project(ColorOctreeViewer)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11 -O3")

find_package(OpenCV REQUIRED)

find_package(Pangolin REQUIRED)

find_package(Eigen3 3.1.0 REQUIRED)

find_package(octomap REQUIRED)

#find_package(G2O REQUIRED)


set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

add_library(${PROJECT_NAME} SHARED 
src/LocalMapping.cc
src/ParameterServer.cc
src/Viewer.cc
src/ColorOctreeServer.cc
src/ColorOctomap.cc
)

include_directories(
${PROJECT_SOURCE_DIR}/include
${EIGEN3_INCLUDE_DIR}
${Pangolin_INCLUDE_DIRS}
${OCTOMAP_INCLUDE_DIRS}
${OPENCV_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME}
${OpenCV_LIBS}
${EIGEN3_LIBS}
${Pangolin_LIBRARIES}
${OCTOMAP_LIBRARIES}
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(color_octree_viewer src/main.cc)
target_link_libraries(color_octree_viewer ${PROJECT_NAME})

add_executable(octree_direct_viewer src/direct.cc)
target_link_libraries(octree_direct_viewer ${PROJECT_NAME})
