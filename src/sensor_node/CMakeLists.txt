cmake_minimum_required(VERSION 3.16)
project(sensor_node)

# Add micro-ROS dependencies
find_package(micro_ros REQUIRED)

add_executable(sensor_node sensor_node.c)
target_link_libraries(sensor_node micro_ros::micro_ros)
