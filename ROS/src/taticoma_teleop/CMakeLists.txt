cmake_minimum_required(VERSION 2.8.3)
project(taticoma_teleop)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  serial
  std_msgs
  taticoma_msgs
)

catkin_package(
  CATKIN_DEPENDS
    serial
    std_msgs
)

include_directories( include ${catkin_INCLUDE_DIRS} )

add_executable(taticoma_teleop_serial src/taticoma_teleop_serial.cpp)
target_link_libraries(taticoma_teleop_serial ${catkin_LIBRARIES})

# add_executable(taticoma_teleop_joy src/taticoma_teleop_joy.cpp)
# target_link_libraries(taticoma_teleop_joy ${catkin_LIBRARIES})

add_executable(taticoma_teleop src/taticoma_teleop.cpp)
target_link_libraries(taticoma_teleop ${catkin_LIBRARIES})
