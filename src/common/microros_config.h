#ifndef MICROROS_CONFIG_H
#define MICROROS_CONFIG_H

#include <rcl/rcl.h>
#include <rclc/rclc.h>

#define ROS_NODE_NAME "stm32f4_node"
#define ROS_NAMESPACE ""
#define ROS_DOMAIN_ID 0

#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){printf("Failed status on line %d: %d\n",__LINE__,(int)temp_rc);}}
#define RCSOFTCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){printf("Failed status on line %d: %d\n",__LINE__,(int)temp_rc);}}

void init_microros_transport(void);

#endif
