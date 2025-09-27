#include <stdio.h>
#include <unistd.h>
#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <std_msgs/msg/int32.h>

#include "rmw_microros/rmw_microros.h"

#define THRESHOLD 25  

rcl_subscription_t subscriber;
std_msgs__msg__Int32 msg;

void subscription_callback(const void *msgin) {
    const std_msgs__msg__Int32 *msg = (const std_msgs__msg__Int32 *)msgin;
    
    printf("Actuator received temperature: %d°C\n", msg->data);
    
    if (msg->data > THRESHOLD) {
        printf(" TEMPERATURE TOO HIGH! Activating cooler...\n");
        
        printf(" Cooler activated for 3 seconds\n");
    } else {
        printf(" Temperature normal. No action needed.\n");
    }
}

int main() {
    rcl_allocator_t allocator = rcl_get_default_allocator();
    rclc_support_t support;
    rcl_node_t node;

    rmw_uros_set_custom_transport(
        false, NULL,
        rmw_uros_serial_transport_open,
        rmw_uros_serial_transport_close,
        rmw_uros_serial_transport_write,
        rmw_uros_serial_transport_read
    );

    rclc_support_init(&support, 0, NULL, &allocator);
    rclc_node_init_default(&node, "actuator_node", "", &support);

    rclc_subscription_init_default(
        &subscriber,
        &node,
        ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32),
        "temperature"
    );

    rclc_executor_t executor;
    rclc_executor_init(&executor, &support.context, 1, &allocator);
    rclc_executor_add_subscription(&executor, &subscriber, &msg, &subscription_callback, ON_NEW_DATA);

    printf("Actuator node started. Waiting for temperature data...\n");
    printf("Threshold set to: %d°C\n", THRESHOLD);

    while(1) {
        rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100));
        usleep(100000);
    }

    return 0;
}
