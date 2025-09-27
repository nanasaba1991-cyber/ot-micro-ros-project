cmake_minimum_required(VERSION 3.16)
project(actuator_node)

find_package(micro_ros REQUIRED)

add_executable(actuator_node actuator_node.c)
target_link_libraries(actuator_node micro_ros::micro_ros)
