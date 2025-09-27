
- 2x STM32F407VG MCUs emulated in Renode
- USART2 for sensor node communication  
- USART3 for actuator node communication
- FreeRTOS real-time operating system

- micro-ROS client library (rcl, rclc)
- XRCE-DDS protocol for microcontrollers
- FastDDS as DDS implementation
- ROS 2 Humble as the host environment

Sensor Node → UART → micro-ROS Agent → DDS → micro-ROS Agent → UART → Actuator Node
