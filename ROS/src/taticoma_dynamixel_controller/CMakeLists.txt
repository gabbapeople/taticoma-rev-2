cmake_minimum_required(VERSION 2.8.3)
project(taticoma_dynamixel_controller)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  dynamixel_sdk
  dynamixel_workbench_toolbox
  taticoma_msgs
)

catkin_package(
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME} src/taticoma_dynamixel_controller.cpp)

target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
)

