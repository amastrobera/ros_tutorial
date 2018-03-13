cmake_minimum_required(VERSION 3.5)

project(ros_client_server)

set (CMAKE_CXX_STANDARD 11)

# ROS requirements
find_package(catkin REQUIRED COMPONENTS
   roscpp
   rospy
   std_msgs
   message_generation
)

# prepare the service files
add_service_files(
  FILES
  communication.srv
)


# app: client 
#include_directories(${ROS_ROOT})
#add_executable(client client.cpp)
#target_link_libraries(client ${catkin_LIBRARIES})
#add_dependencies(client beginner_tutorials_gencpp)

# app: server 
message("included: $ENV{ROS_ROOT}/../../include")
include_directories($ENV{ROS_ROOT}/../../include)
add_executable(server server.cpp)
target_link_libraries(server ${catkin_LIBRARIES})
#add_dependencies(server beginner_tutorials_gencpp)

