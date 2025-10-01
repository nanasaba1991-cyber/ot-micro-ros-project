#!/bin/bash
echo "Building micro-ROS firmware..."

# Source micro-ROS setup
source ~/micro_ros_ws/install/setup.bash

# Use micro_ros_setup tools CORRECTLY
ros2 run micro_ros_setup create_firmware_ws.sh freertos nucleo_f446re
ros2 run micro_ros_setup build_firmware.sh

echo "Build complete! Firmware located at:"
find ~/micro_ros_ws -name "micro-ROS.elf" -type f 2>/dev/null
