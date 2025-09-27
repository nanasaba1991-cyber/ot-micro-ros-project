cmake_minimum_required(VERSION 3.16)
project(sensor_node)

# micro-ROS dependencies
find_package(ament_cmake REQUIRED)
find_package(rcl REQUIRED)
find_package(rclc REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(sensor_node sensor_node.c)
ament_target_dependencies(sensor_node rcl rclc std_msgs)

install(TARGETS sensor_node DESTINATION lib/${PROJECT_NAME})
