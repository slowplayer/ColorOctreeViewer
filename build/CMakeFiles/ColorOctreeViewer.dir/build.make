# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/huo/ColorOctreeViewer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/huo/ColorOctreeViewer/build

# Include any dependencies generated for this target.
include CMakeFiles/ColorOctreeViewer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ColorOctreeViewer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ColorOctreeViewer.dir/flags.make

CMakeFiles/ColorOctreeViewer.dir/src/LocalMapping.cc.o: CMakeFiles/ColorOctreeViewer.dir/flags.make
CMakeFiles/ColorOctreeViewer.dir/src/LocalMapping.cc.o: ../src/LocalMapping.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/huo/ColorOctreeViewer/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ColorOctreeViewer.dir/src/LocalMapping.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ColorOctreeViewer.dir/src/LocalMapping.cc.o -c /home/huo/ColorOctreeViewer/src/LocalMapping.cc

CMakeFiles/ColorOctreeViewer.dir/src/LocalMapping.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ColorOctreeViewer.dir/src/LocalMapping.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/huo/ColorOctreeViewer/src/LocalMapping.cc > CMakeFiles/ColorOctreeViewer.dir/src/LocalMapping.cc.i

CMakeFiles/ColorOctreeViewer.dir/src/LocalMapping.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ColorOctreeViewer.dir/src/LocalMapping.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/huo/ColorOctreeViewer/src/LocalMapping.cc -o CMakeFiles/ColorOctreeViewer.dir/src/LocalMapping.cc.s

CMakeFiles/ColorOctreeViewer.dir/src/LocalMapping.cc.o.requires:
.PHONY : CMakeFiles/ColorOctreeViewer.dir/src/LocalMapping.cc.o.requires

CMakeFiles/ColorOctreeViewer.dir/src/LocalMapping.cc.o.provides: CMakeFiles/ColorOctreeViewer.dir/src/LocalMapping.cc.o.requires
	$(MAKE) -f CMakeFiles/ColorOctreeViewer.dir/build.make CMakeFiles/ColorOctreeViewer.dir/src/LocalMapping.cc.o.provides.build
.PHONY : CMakeFiles/ColorOctreeViewer.dir/src/LocalMapping.cc.o.provides

CMakeFiles/ColorOctreeViewer.dir/src/LocalMapping.cc.o.provides.build: CMakeFiles/ColorOctreeViewer.dir/src/LocalMapping.cc.o

CMakeFiles/ColorOctreeViewer.dir/src/ParameterServer.cc.o: CMakeFiles/ColorOctreeViewer.dir/flags.make
CMakeFiles/ColorOctreeViewer.dir/src/ParameterServer.cc.o: ../src/ParameterServer.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/huo/ColorOctreeViewer/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ColorOctreeViewer.dir/src/ParameterServer.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ColorOctreeViewer.dir/src/ParameterServer.cc.o -c /home/huo/ColorOctreeViewer/src/ParameterServer.cc

CMakeFiles/ColorOctreeViewer.dir/src/ParameterServer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ColorOctreeViewer.dir/src/ParameterServer.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/huo/ColorOctreeViewer/src/ParameterServer.cc > CMakeFiles/ColorOctreeViewer.dir/src/ParameterServer.cc.i

CMakeFiles/ColorOctreeViewer.dir/src/ParameterServer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ColorOctreeViewer.dir/src/ParameterServer.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/huo/ColorOctreeViewer/src/ParameterServer.cc -o CMakeFiles/ColorOctreeViewer.dir/src/ParameterServer.cc.s

CMakeFiles/ColorOctreeViewer.dir/src/ParameterServer.cc.o.requires:
.PHONY : CMakeFiles/ColorOctreeViewer.dir/src/ParameterServer.cc.o.requires

CMakeFiles/ColorOctreeViewer.dir/src/ParameterServer.cc.o.provides: CMakeFiles/ColorOctreeViewer.dir/src/ParameterServer.cc.o.requires
	$(MAKE) -f CMakeFiles/ColorOctreeViewer.dir/build.make CMakeFiles/ColorOctreeViewer.dir/src/ParameterServer.cc.o.provides.build
.PHONY : CMakeFiles/ColorOctreeViewer.dir/src/ParameterServer.cc.o.provides

CMakeFiles/ColorOctreeViewer.dir/src/ParameterServer.cc.o.provides.build: CMakeFiles/ColorOctreeViewer.dir/src/ParameterServer.cc.o

CMakeFiles/ColorOctreeViewer.dir/src/Viewer.cc.o: CMakeFiles/ColorOctreeViewer.dir/flags.make
CMakeFiles/ColorOctreeViewer.dir/src/Viewer.cc.o: ../src/Viewer.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/huo/ColorOctreeViewer/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ColorOctreeViewer.dir/src/Viewer.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ColorOctreeViewer.dir/src/Viewer.cc.o -c /home/huo/ColorOctreeViewer/src/Viewer.cc

CMakeFiles/ColorOctreeViewer.dir/src/Viewer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ColorOctreeViewer.dir/src/Viewer.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/huo/ColorOctreeViewer/src/Viewer.cc > CMakeFiles/ColorOctreeViewer.dir/src/Viewer.cc.i

CMakeFiles/ColorOctreeViewer.dir/src/Viewer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ColorOctreeViewer.dir/src/Viewer.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/huo/ColorOctreeViewer/src/Viewer.cc -o CMakeFiles/ColorOctreeViewer.dir/src/Viewer.cc.s

CMakeFiles/ColorOctreeViewer.dir/src/Viewer.cc.o.requires:
.PHONY : CMakeFiles/ColorOctreeViewer.dir/src/Viewer.cc.o.requires

CMakeFiles/ColorOctreeViewer.dir/src/Viewer.cc.o.provides: CMakeFiles/ColorOctreeViewer.dir/src/Viewer.cc.o.requires
	$(MAKE) -f CMakeFiles/ColorOctreeViewer.dir/build.make CMakeFiles/ColorOctreeViewer.dir/src/Viewer.cc.o.provides.build
.PHONY : CMakeFiles/ColorOctreeViewer.dir/src/Viewer.cc.o.provides

CMakeFiles/ColorOctreeViewer.dir/src/Viewer.cc.o.provides.build: CMakeFiles/ColorOctreeViewer.dir/src/Viewer.cc.o

# Object files for target ColorOctreeViewer
ColorOctreeViewer_OBJECTS = \
"CMakeFiles/ColorOctreeViewer.dir/src/LocalMapping.cc.o" \
"CMakeFiles/ColorOctreeViewer.dir/src/ParameterServer.cc.o" \
"CMakeFiles/ColorOctreeViewer.dir/src/Viewer.cc.o"

# External object files for target ColorOctreeViewer
ColorOctreeViewer_EXTERNAL_OBJECTS =

../lib/libColorOctreeViewer.so: CMakeFiles/ColorOctreeViewer.dir/src/LocalMapping.cc.o
../lib/libColorOctreeViewer.so: CMakeFiles/ColorOctreeViewer.dir/src/ParameterServer.cc.o
../lib/libColorOctreeViewer.so: CMakeFiles/ColorOctreeViewer.dir/src/Viewer.cc.o
../lib/libColorOctreeViewer.so: CMakeFiles/ColorOctreeViewer.dir/build.make
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.2.4.8
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.8
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libopencv_ts.so.2.4.8
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.2.4.8
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.2.4.8
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.8
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libopencv_ocl.so.2.4.8
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.8
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.8
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.8
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.8
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.8
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libopencv_gpu.so.2.4.8
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.8
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.8
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.8
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libopencv_contrib.so.2.4.8
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.8
../lib/libColorOctreeViewer.so: /home/huo/Downloads/Pangolin-master/build/src/libpangolin.so
../lib/libColorOctreeViewer.so: /usr/local/lib/liboctomap.so
../lib/libColorOctreeViewer.so: /usr/local/lib/liboctomath.so
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.8
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.8
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.8
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.8
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.8
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.8
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.8
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.8
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.8
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.8
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.8
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libGLU.so
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libGL.so
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libSM.so
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libICE.so
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libX11.so
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libXext.so
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libGLEW.so
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libSM.so
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libICE.so
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libX11.so
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libXext.so
../lib/libColorOctreeViewer.so: /usr/lib/x86_64-linux-gnu/libGLEW.so
../lib/libColorOctreeViewer.so: CMakeFiles/ColorOctreeViewer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library ../lib/libColorOctreeViewer.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ColorOctreeViewer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ColorOctreeViewer.dir/build: ../lib/libColorOctreeViewer.so
.PHONY : CMakeFiles/ColorOctreeViewer.dir/build

CMakeFiles/ColorOctreeViewer.dir/requires: CMakeFiles/ColorOctreeViewer.dir/src/LocalMapping.cc.o.requires
CMakeFiles/ColorOctreeViewer.dir/requires: CMakeFiles/ColorOctreeViewer.dir/src/ParameterServer.cc.o.requires
CMakeFiles/ColorOctreeViewer.dir/requires: CMakeFiles/ColorOctreeViewer.dir/src/Viewer.cc.o.requires
.PHONY : CMakeFiles/ColorOctreeViewer.dir/requires

CMakeFiles/ColorOctreeViewer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ColorOctreeViewer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ColorOctreeViewer.dir/clean

CMakeFiles/ColorOctreeViewer.dir/depend:
	cd /home/huo/ColorOctreeViewer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/huo/ColorOctreeViewer /home/huo/ColorOctreeViewer /home/huo/ColorOctreeViewer/build /home/huo/ColorOctreeViewer/build /home/huo/ColorOctreeViewer/build/CMakeFiles/ColorOctreeViewer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ColorOctreeViewer.dir/depend
