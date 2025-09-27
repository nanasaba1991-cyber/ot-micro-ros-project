#!/bin/bash
echo "Setting up OT micro-ROS project environment"

# Check dependencies
echo "Checking dependencies..."
command -v renode >/dev/null 2>&1 || echo "Renode not found"
command -v ros2 >/dev/null 2>&1 || echo "ROS 2 not found"

echo "Setup complete"
