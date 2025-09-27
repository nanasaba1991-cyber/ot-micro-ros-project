cmake_minimum_required(VERSION 3.16)
project(actuator_node)

find_package(ament_cmake REQUIRED)
find_package(rcl REQUIRED)
find_package(rclc REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(actuator_node actuator_node.c)
ament_target_dependencies(actuator_node rcl rclc std_msgs)

install(TARGETS actuator_node DESTINATION lib/${PROJECT_NAME})
