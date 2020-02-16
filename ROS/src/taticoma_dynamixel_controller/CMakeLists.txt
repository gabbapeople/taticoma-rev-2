cmake_minimum_required(VERSION 2.8.3)
project(taticoma_dynamixel_controller)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  taticoma_msgs
)

catkin_package(
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(dynamixel_controller src/dynamixel_controller.cpp)
target_link_libraries(dynamixel_controller ${catkin_LIBRARIES})


