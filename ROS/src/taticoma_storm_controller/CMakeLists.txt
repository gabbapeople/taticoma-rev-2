cmake_minimum_required(VERSION 2.8.3)
project(taticoma_storm_controller)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  taticoma_msgs
  serial
)

catkin_package(
  CATKIN_DEPENDS
    serial
    std_msgs
)

include_directories( include ${catkin_INCLUDE_DIRS} )

add_executable(taticoma_storm_controller src/taticoma_storm_controller.cpp)
target_link_libraries(taticoma_storm_controller ${catkin_LIBRARIES})
