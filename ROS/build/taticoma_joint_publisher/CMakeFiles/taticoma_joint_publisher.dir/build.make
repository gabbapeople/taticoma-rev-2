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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/TATICOMA/ROS/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/TATICOMA/ROS/build

# Include any dependencies generated for this target.
include taticoma_joint_publisher/CMakeFiles/taticoma_joint_publisher.dir/depend.make

# Include the progress variables for this target.
include taticoma_joint_publisher/CMakeFiles/taticoma_joint_publisher.dir/progress.make

# Include the compile flags for this target's objects.
include taticoma_joint_publisher/CMakeFiles/taticoma_joint_publisher.dir/flags.make

taticoma_joint_publisher/CMakeFiles/taticoma_joint_publisher.dir/src/taticoma_joint_publisher.cpp.o: taticoma_joint_publisher/CMakeFiles/taticoma_joint_publisher.dir/flags.make
taticoma_joint_publisher/CMakeFiles/taticoma_joint_publisher.dir/src/taticoma_joint_publisher.cpp.o: /home/ubuntu/TATICOMA/ROS/src/taticoma_joint_publisher/src/taticoma_joint_publisher.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/TATICOMA/ROS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object taticoma_joint_publisher/CMakeFiles/taticoma_joint_publisher.dir/src/taticoma_joint_publisher.cpp.o"
	cd /home/ubuntu/TATICOMA/ROS/build/taticoma_joint_publisher && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/taticoma_joint_publisher.dir/src/taticoma_joint_publisher.cpp.o -c /home/ubuntu/TATICOMA/ROS/src/taticoma_joint_publisher/src/taticoma_joint_publisher.cpp

taticoma_joint_publisher/CMakeFiles/taticoma_joint_publisher.dir/src/taticoma_joint_publisher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/taticoma_joint_publisher.dir/src/taticoma_joint_publisher.cpp.i"
	cd /home/ubuntu/TATICOMA/ROS/build/taticoma_joint_publisher && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/TATICOMA/ROS/src/taticoma_joint_publisher/src/taticoma_joint_publisher.cpp > CMakeFiles/taticoma_joint_publisher.dir/src/taticoma_joint_publisher.cpp.i

taticoma_joint_publisher/CMakeFiles/taticoma_joint_publisher.dir/src/taticoma_joint_publisher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/taticoma_joint_publisher.dir/src/taticoma_joint_publisher.cpp.s"
	cd /home/ubuntu/TATICOMA/ROS/build/taticoma_joint_publisher && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/TATICOMA/ROS/src/taticoma_joint_publisher/src/taticoma_joint_publisher.cpp -o CMakeFiles/taticoma_joint_publisher.dir/src/taticoma_joint_publisher.cpp.s

taticoma_joint_publisher/CMakeFiles/taticoma_joint_publisher.dir/src/taticoma_joint_publisher.cpp.o.requires:

.PHONY : taticoma_joint_publisher/CMakeFiles/taticoma_joint_publisher.dir/src/taticoma_joint_publisher.cpp.o.requires

taticoma_joint_publisher/CMakeFiles/taticoma_joint_publisher.dir/src/taticoma_joint_publisher.cpp.o.provides: taticoma_joint_publisher/CMakeFiles/taticoma_joint_publisher.dir/src/taticoma_joint_publisher.cpp.o.requires
	$(MAKE) -f taticoma_joint_publisher/CMakeFiles/taticoma_joint_publisher.dir/build.make taticoma_joint_publisher/CMakeFiles/taticoma_joint_publisher.dir/src/taticoma_joint_publisher.cpp.o.provides.build
.PHONY : taticoma_joint_publisher/CMakeFiles/taticoma_joint_publisher.dir/src/taticoma_joint_publisher.cpp.o.provides

taticoma_joint_publisher/CMakeFiles/taticoma_joint_publisher.dir/src/taticoma_joint_publisher.cpp.o.provides.build: taticoma_joint_publisher/CMakeFiles/taticoma_joint_publisher.dir/src/taticoma_joint_publisher.cpp.o


# Object files for target taticoma_joint_publisher
taticoma_joint_publisher_OBJECTS = \
"CMakeFiles/taticoma_joint_publisher.dir/src/taticoma_joint_publisher.cpp.o"

# External object files for target taticoma_joint_publisher
taticoma_joint_publisher_EXTERNAL_OBJECTS =

/home/ubuntu/TATICOMA/ROS/devel/lib/taticoma_joint_publisher/taticoma_joint_publisher: taticoma_joint_publisher/CMakeFiles/taticoma_joint_publisher.dir/src/taticoma_joint_publisher.cpp.o
/home/ubuntu/TATICOMA/ROS/devel/lib/taticoma_joint_publisher/taticoma_joint_publisher: taticoma_joint_publisher/CMakeFiles/taticoma_joint_publisher.dir/build.make
/home/ubuntu/TATICOMA/ROS/devel/lib/taticoma_joint_publisher/taticoma_joint_publisher: /opt/ros/melodic/lib/libroscpp.so
/home/ubuntu/TATICOMA/ROS/devel/lib/taticoma_joint_publisher/taticoma_joint_publisher: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/ubuntu/TATICOMA/ROS/devel/lib/taticoma_joint_publisher/taticoma_joint_publisher: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/ubuntu/TATICOMA/ROS/devel/lib/taticoma_joint_publisher/taticoma_joint_publisher: /opt/ros/melodic/lib/librosconsole.so
/home/ubuntu/TATICOMA/ROS/devel/lib/taticoma_joint_publisher/taticoma_joint_publisher: /opt/ros/melodic/lib/librosconsole_log4cxx.so
/home/ubuntu/TATICOMA/ROS/devel/lib/taticoma_joint_publisher/taticoma_joint_publisher: /opt/ros/melodic/lib/librosconsole_backend_interface.so
/home/ubuntu/TATICOMA/ROS/devel/lib/taticoma_joint_publisher/taticoma_joint_publisher: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/ubuntu/TATICOMA/ROS/devel/lib/taticoma_joint_publisher/taticoma_joint_publisher: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/ubuntu/TATICOMA/ROS/devel/lib/taticoma_joint_publisher/taticoma_joint_publisher: /opt/ros/melodic/lib/libxmlrpcpp.so
/home/ubuntu/TATICOMA/ROS/devel/lib/taticoma_joint_publisher/taticoma_joint_publisher: /opt/ros/melodic/lib/libroscpp_serialization.so
/home/ubuntu/TATICOMA/ROS/devel/lib/taticoma_joint_publisher/taticoma_joint_publisher: /opt/ros/melodic/lib/librostime.so
/home/ubuntu/TATICOMA/ROS/devel/lib/taticoma_joint_publisher/taticoma_joint_publisher: /opt/ros/melodic/lib/libcpp_common.so
/home/ubuntu/TATICOMA/ROS/devel/lib/taticoma_joint_publisher/taticoma_joint_publisher: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/ubuntu/TATICOMA/ROS/devel/lib/taticoma_joint_publisher/taticoma_joint_publisher: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/ubuntu/TATICOMA/ROS/devel/lib/taticoma_joint_publisher/taticoma_joint_publisher: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/ubuntu/TATICOMA/ROS/devel/lib/taticoma_joint_publisher/taticoma_joint_publisher: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/ubuntu/TATICOMA/ROS/devel/lib/taticoma_joint_publisher/taticoma_joint_publisher: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/ubuntu/TATICOMA/ROS/devel/lib/taticoma_joint_publisher/taticoma_joint_publisher: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/ubuntu/TATICOMA/ROS/devel/lib/taticoma_joint_publisher/taticoma_joint_publisher: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/ubuntu/TATICOMA/ROS/devel/lib/taticoma_joint_publisher/taticoma_joint_publisher: taticoma_joint_publisher/CMakeFiles/taticoma_joint_publisher.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/TATICOMA/ROS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/ubuntu/TATICOMA/ROS/devel/lib/taticoma_joint_publisher/taticoma_joint_publisher"
	cd /home/ubuntu/TATICOMA/ROS/build/taticoma_joint_publisher && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/taticoma_joint_publisher.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
taticoma_joint_publisher/CMakeFiles/taticoma_joint_publisher.dir/build: /home/ubuntu/TATICOMA/ROS/devel/lib/taticoma_joint_publisher/taticoma_joint_publisher

.PHONY : taticoma_joint_publisher/CMakeFiles/taticoma_joint_publisher.dir/build

taticoma_joint_publisher/CMakeFiles/taticoma_joint_publisher.dir/requires: taticoma_joint_publisher/CMakeFiles/taticoma_joint_publisher.dir/src/taticoma_joint_publisher.cpp.o.requires

.PHONY : taticoma_joint_publisher/CMakeFiles/taticoma_joint_publisher.dir/requires

taticoma_joint_publisher/CMakeFiles/taticoma_joint_publisher.dir/clean:
	cd /home/ubuntu/TATICOMA/ROS/build/taticoma_joint_publisher && $(CMAKE_COMMAND) -P CMakeFiles/taticoma_joint_publisher.dir/cmake_clean.cmake
.PHONY : taticoma_joint_publisher/CMakeFiles/taticoma_joint_publisher.dir/clean

taticoma_joint_publisher/CMakeFiles/taticoma_joint_publisher.dir/depend:
	cd /home/ubuntu/TATICOMA/ROS/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/TATICOMA/ROS/src /home/ubuntu/TATICOMA/ROS/src/taticoma_joint_publisher /home/ubuntu/TATICOMA/ROS/build /home/ubuntu/TATICOMA/ROS/build/taticoma_joint_publisher /home/ubuntu/TATICOMA/ROS/build/taticoma_joint_publisher/CMakeFiles/taticoma_joint_publisher.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : taticoma_joint_publisher/CMakeFiles/taticoma_joint_publisher.dir/depend

