echo "Building micro-ROS firmware..."

cd ~/micro_ros_ws
colcon build --packages-select microros_nucleo_f446re_extensions

echo "Build complete! Firmware located at:"
echo "firmware/freertos_apps/microros_nucleo_f446re_extensions/build/micro-ROS.elf"
