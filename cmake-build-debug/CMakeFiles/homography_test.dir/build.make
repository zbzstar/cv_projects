# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /home/zbz/Downloads/clion-2018.1.6/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/zbz/Downloads/clion-2018.1.6/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zbz/opencv_test/cv_projects

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zbz/opencv_test/cv_projects/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/homography_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/homography_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/homography_test.dir/flags.make

CMakeFiles/homography_test.dir/src/main.cpp.o: CMakeFiles/homography_test.dir/flags.make
CMakeFiles/homography_test.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zbz/opencv_test/cv_projects/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/homography_test.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/homography_test.dir/src/main.cpp.o -c /home/zbz/opencv_test/cv_projects/src/main.cpp

CMakeFiles/homography_test.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/homography_test.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zbz/opencv_test/cv_projects/src/main.cpp > CMakeFiles/homography_test.dir/src/main.cpp.i

CMakeFiles/homography_test.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/homography_test.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zbz/opencv_test/cv_projects/src/main.cpp -o CMakeFiles/homography_test.dir/src/main.cpp.s

CMakeFiles/homography_test.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/homography_test.dir/src/main.cpp.o.requires

CMakeFiles/homography_test.dir/src/main.cpp.o.provides: CMakeFiles/homography_test.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/homography_test.dir/build.make CMakeFiles/homography_test.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/homography_test.dir/src/main.cpp.o.provides

CMakeFiles/homography_test.dir/src/main.cpp.o.provides.build: CMakeFiles/homography_test.dir/src/main.cpp.o


# Object files for target homography_test
homography_test_OBJECTS = \
"CMakeFiles/homography_test.dir/src/main.cpp.o"

# External object files for target homography_test
homography_test_EXTERNAL_OBJECTS =

homography_test: CMakeFiles/homography_test.dir/src/main.cpp.o
homography_test: CMakeFiles/homography_test.dir/build.make
homography_test: /usr/local/lib/libopencv_dnn.so.3.3.0
homography_test: /usr/local/lib/libopencv_ml.so.3.3.0
homography_test: /usr/local/lib/libopencv_objdetect.so.3.3.0
homography_test: /usr/local/lib/libopencv_shape.so.3.3.0
homography_test: /usr/local/lib/libopencv_stitching.so.3.3.0
homography_test: /usr/local/lib/libopencv_superres.so.3.3.0
homography_test: /usr/local/lib/libopencv_videostab.so.3.3.0
homography_test: /usr/local/lib/libopencv_calib3d.so.3.3.0
homography_test: /usr/local/lib/libopencv_features2d.so.3.3.0
homography_test: /usr/local/lib/libopencv_flann.so.3.3.0
homography_test: /usr/local/lib/libopencv_highgui.so.3.3.0
homography_test: /usr/local/lib/libopencv_photo.so.3.3.0
homography_test: /usr/local/lib/libopencv_video.so.3.3.0
homography_test: /usr/local/lib/libopencv_videoio.so.3.3.0
homography_test: /usr/local/lib/libopencv_imgcodecs.so.3.3.0
homography_test: /usr/local/lib/libopencv_imgproc.so.3.3.0
homography_test: /usr/local/lib/libopencv_core.so.3.3.0
homography_test: CMakeFiles/homography_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zbz/opencv_test/cv_projects/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable homography_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/homography_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/homography_test.dir/build: homography_test

.PHONY : CMakeFiles/homography_test.dir/build

CMakeFiles/homography_test.dir/requires: CMakeFiles/homography_test.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/homography_test.dir/requires

CMakeFiles/homography_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/homography_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/homography_test.dir/clean

CMakeFiles/homography_test.dir/depend:
	cd /home/zbz/opencv_test/cv_projects/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zbz/opencv_test/cv_projects /home/zbz/opencv_test/cv_projects /home/zbz/opencv_test/cv_projects/cmake-build-debug /home/zbz/opencv_test/cv_projects/cmake-build-debug /home/zbz/opencv_test/cv_projects/cmake-build-debug/CMakeFiles/homography_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/homography_test.dir/depend

