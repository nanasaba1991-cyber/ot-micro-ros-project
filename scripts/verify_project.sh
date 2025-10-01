echo "Verifying Project Structure..."

check_file() {
    if [ -f "$1" ]; then
        echo " $1"
    else
        echo " $� $1 - MISSING"
    fi
}

check_dir() {
    if [ -d "$1" ]; then
        echo " $1/"
    else
        echo " $1/ - MISSING"
    fi
}

echo "=== Required Files ==="
check_file "README.md"
check_file "LICENSE" 
check_file ".gitignore"
check_file "docs/architecture.md"
check_file "docs/setup_guide.md"
check_file "src/sensor_node/sensor_node.c"
check_file "src/sensor_node/CMakeLists.txt"
check_file "src/actuator_node/actuator_node.c"
check_file "src/actuator_node/CMakeLists.txt"
check_file "renode_scripts/sensor_node_fixed.resc"
check_file "renode_scripts/actuator_node_final.resc"
check_file "config/microros.config"
check_file "config/freertos.config"
check_file "scripts/setup.sh"
check_file "scripts/build_firmware.sh"

echo "=== micro-ROS Firmware Files ==="
check_file "firmware/freertos_apps/microros_nucleo_f446re_extensions/build/micro-ROS.elf"
check_file "firmware/freertos_apps/microros_nucleo_f446re_extensions/microros_nucleo_f446re_extensions.c"
check_file "firmware/freertos_apps/microros_nucleo_f446re_extensions/CMakeLists.txt"

echo "=== Critical Directories ==="
check_dir "firmware"
check_dir "firmware/freertos_apps"
check_dir "firmware/freertos_apps/microros_nucleo_f446re_extensions"
check_dir "renode_scripts"
check_dir "src/sensor_node"
check_dir "src/actuator_node"

echo "=== Folder Structure ==="
find . -type d -not -path "./.git*" | sort

echo "=== Total Files ==="
find . -type f -not -path "./.git*" | wc -l

echo "=== Images ==="
if [ -d "images" ]; then
    echo " Images folder exists"
    png_count=$(ls -la images/*.png 2>/dev/null | wc -l)
    echo "Number of PNG images: $png_count"
    if [ $png_count -gt 0 ]; then
        ls -la images/*.png 2>/dev/null
    else
        echo "No PNG images found"
    fi
else
    echo " No images folder"
fi

echo "=== Firmware Build Status ==="
if [ -f "firmware/freertos_apps/microros_nucleo_f446re_extensions/build/micro-ROS.elf" ]; then
    elf_size=$(ls -lh "firmware/freertos_apps/microros_nucleo_f446re_extensions/build/micro-ROS.elf" | awk '{print $5}')
    echo " micro-ROS.elf exists ($elf_size)"
else
    echo " micro-ROS.elf NOT BUILT - Run build script first"
fi