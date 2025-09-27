echo " Verifying Project Structure..."

check_file() {
    if [ -f "$1" ]; then
        echo " $1"
    else
        echo " $1 - MISSING"
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

echo "=== Folder Structure ==="
find . -type d -not -path "./.git*" | sort

echo "=== Total Files ==="
find . -type f -not -path "./.git*" | wc -l
