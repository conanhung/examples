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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hung/dev/examples/cvsnakeimage

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hung/dev/examples/cvsnakeimage/build

# Include any dependencies generated for this target.
include CMakeFiles/cvsnakeimage.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cvsnakeimage.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cvsnakeimage.dir/flags.make

CMakeFiles/cvsnakeimage.dir/cvsnakeimage.cpp.o: CMakeFiles/cvsnakeimage.dir/flags.make
CMakeFiles/cvsnakeimage.dir/cvsnakeimage.cpp.o: ../cvsnakeimage.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/hung/dev/examples/cvsnakeimage/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/cvsnakeimage.dir/cvsnakeimage.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/cvsnakeimage.dir/cvsnakeimage.cpp.o -c /home/hung/dev/examples/cvsnakeimage/cvsnakeimage.cpp

CMakeFiles/cvsnakeimage.dir/cvsnakeimage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cvsnakeimage.dir/cvsnakeimage.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/hung/dev/examples/cvsnakeimage/cvsnakeimage.cpp > CMakeFiles/cvsnakeimage.dir/cvsnakeimage.cpp.i

CMakeFiles/cvsnakeimage.dir/cvsnakeimage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cvsnakeimage.dir/cvsnakeimage.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/hung/dev/examples/cvsnakeimage/cvsnakeimage.cpp -o CMakeFiles/cvsnakeimage.dir/cvsnakeimage.cpp.s

CMakeFiles/cvsnakeimage.dir/cvsnakeimage.cpp.o.requires:
.PHONY : CMakeFiles/cvsnakeimage.dir/cvsnakeimage.cpp.o.requires

CMakeFiles/cvsnakeimage.dir/cvsnakeimage.cpp.o.provides: CMakeFiles/cvsnakeimage.dir/cvsnakeimage.cpp.o.requires
	$(MAKE) -f CMakeFiles/cvsnakeimage.dir/build.make CMakeFiles/cvsnakeimage.dir/cvsnakeimage.cpp.o.provides.build
.PHONY : CMakeFiles/cvsnakeimage.dir/cvsnakeimage.cpp.o.provides

CMakeFiles/cvsnakeimage.dir/cvsnakeimage.cpp.o.provides.build: CMakeFiles/cvsnakeimage.dir/cvsnakeimage.cpp.o

CMakeFiles/cvsnakeimage.dir/cvsnakes.cpp.o: CMakeFiles/cvsnakeimage.dir/flags.make
CMakeFiles/cvsnakeimage.dir/cvsnakes.cpp.o: ../cvsnakes.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/hung/dev/examples/cvsnakeimage/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/cvsnakeimage.dir/cvsnakes.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/cvsnakeimage.dir/cvsnakes.cpp.o -c /home/hung/dev/examples/cvsnakeimage/cvsnakes.cpp

CMakeFiles/cvsnakeimage.dir/cvsnakes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cvsnakeimage.dir/cvsnakes.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/hung/dev/examples/cvsnakeimage/cvsnakes.cpp > CMakeFiles/cvsnakeimage.dir/cvsnakes.cpp.i

CMakeFiles/cvsnakeimage.dir/cvsnakes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cvsnakeimage.dir/cvsnakes.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/hung/dev/examples/cvsnakeimage/cvsnakes.cpp -o CMakeFiles/cvsnakeimage.dir/cvsnakes.cpp.s

CMakeFiles/cvsnakeimage.dir/cvsnakes.cpp.o.requires:
.PHONY : CMakeFiles/cvsnakeimage.dir/cvsnakes.cpp.o.requires

CMakeFiles/cvsnakeimage.dir/cvsnakes.cpp.o.provides: CMakeFiles/cvsnakeimage.dir/cvsnakes.cpp.o.requires
	$(MAKE) -f CMakeFiles/cvsnakeimage.dir/build.make CMakeFiles/cvsnakeimage.dir/cvsnakes.cpp.o.provides.build
.PHONY : CMakeFiles/cvsnakeimage.dir/cvsnakes.cpp.o.provides

CMakeFiles/cvsnakeimage.dir/cvsnakes.cpp.o.provides.build: CMakeFiles/cvsnakeimage.dir/cvsnakes.cpp.o

# Object files for target cvsnakeimage
cvsnakeimage_OBJECTS = \
"CMakeFiles/cvsnakeimage.dir/cvsnakeimage.cpp.o" \
"CMakeFiles/cvsnakeimage.dir/cvsnakes.cpp.o"

# External object files for target cvsnakeimage
cvsnakeimage_EXTERNAL_OBJECTS =

cvsnakeimage: CMakeFiles/cvsnakeimage.dir/cvsnakeimage.cpp.o
cvsnakeimage: CMakeFiles/cvsnakeimage.dir/cvsnakes.cpp.o
cvsnakeimage: CMakeFiles/cvsnakeimage.dir/build.make
cvsnakeimage: /usr/local/lib/libopencv_videostab.so.2.4.8
cvsnakeimage: /usr/local/lib/libopencv_video.so.2.4.8
cvsnakeimage: /usr/local/lib/libopencv_ts.a
cvsnakeimage: /usr/local/lib/libopencv_superres.so.2.4.8
cvsnakeimage: /usr/local/lib/libopencv_stitching.so.2.4.8
cvsnakeimage: /usr/local/lib/libopencv_photo.so.2.4.8
cvsnakeimage: /usr/local/lib/libopencv_ocl.so.2.4.8
cvsnakeimage: /usr/local/lib/libopencv_objdetect.so.2.4.8
cvsnakeimage: /usr/local/lib/libopencv_nonfree.so.2.4.8
cvsnakeimage: /usr/local/lib/libopencv_ml.so.2.4.8
cvsnakeimage: /usr/local/lib/libopencv_legacy.so.2.4.8
cvsnakeimage: /usr/local/lib/libopencv_imgproc.so.2.4.8
cvsnakeimage: /usr/local/lib/libopencv_highgui.so.2.4.8
cvsnakeimage: /usr/local/lib/libopencv_gpu.so.2.4.8
cvsnakeimage: /usr/local/lib/libopencv_flann.so.2.4.8
cvsnakeimage: /usr/local/lib/libopencv_features2d.so.2.4.8
cvsnakeimage: /usr/local/lib/libopencv_core.so.2.4.8
cvsnakeimage: /usr/local/lib/libopencv_contrib.so.2.4.8
cvsnakeimage: /usr/local/lib/libopencv_calib3d.so.2.4.8
cvsnakeimage: /usr/local/lib/libopencv_nonfree.so.2.4.8
cvsnakeimage: /usr/local/lib/libopencv_ocl.so.2.4.8
cvsnakeimage: /usr/local/lib/libopencv_gpu.so.2.4.8
cvsnakeimage: /usr/local/lib/libopencv_photo.so.2.4.8
cvsnakeimage: /usr/local/lib/libopencv_objdetect.so.2.4.8
cvsnakeimage: /usr/local/lib/libopencv_legacy.so.2.4.8
cvsnakeimage: /usr/local/lib/libopencv_video.so.2.4.8
cvsnakeimage: /usr/local/lib/libopencv_ml.so.2.4.8
cvsnakeimage: /usr/local/lib/libopencv_calib3d.so.2.4.8
cvsnakeimage: /usr/local/lib/libopencv_features2d.so.2.4.8
cvsnakeimage: /usr/local/lib/libopencv_highgui.so.2.4.8
cvsnakeimage: /usr/local/lib/libopencv_imgproc.so.2.4.8
cvsnakeimage: /usr/local/lib/libopencv_flann.so.2.4.8
cvsnakeimage: /usr/local/lib/libopencv_core.so.2.4.8
cvsnakeimage: CMakeFiles/cvsnakeimage.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable cvsnakeimage"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cvsnakeimage.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cvsnakeimage.dir/build: cvsnakeimage
.PHONY : CMakeFiles/cvsnakeimage.dir/build

CMakeFiles/cvsnakeimage.dir/requires: CMakeFiles/cvsnakeimage.dir/cvsnakeimage.cpp.o.requires
CMakeFiles/cvsnakeimage.dir/requires: CMakeFiles/cvsnakeimage.dir/cvsnakes.cpp.o.requires
.PHONY : CMakeFiles/cvsnakeimage.dir/requires

CMakeFiles/cvsnakeimage.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cvsnakeimage.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cvsnakeimage.dir/clean

CMakeFiles/cvsnakeimage.dir/depend:
	cd /home/hung/dev/examples/cvsnakeimage/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hung/dev/examples/cvsnakeimage /home/hung/dev/examples/cvsnakeimage /home/hung/dev/examples/cvsnakeimage/build /home/hung/dev/examples/cvsnakeimage/build /home/hung/dev/examples/cvsnakeimage/build/CMakeFiles/cvsnakeimage.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cvsnakeimage.dir/depend

