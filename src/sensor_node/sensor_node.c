#include <stdio.h>
#include <unistd.h>
#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <std_msgs/msg/int32.h>

#include "rmw_microros/rmw_microros.h"

rcl_publisher_t publisher;
std_msgs__msg__Int32 msg;

void timer_callback(rcl_timer_t *timer, int64_t last_call_time) {
    (void) last_call_time;
    if (timer != NULL) {
        static int temperature = 20;
        temperature = 20 + (rand() % 11); 
        
        msg.data = temperature;
        printf("Sensor publishing temperature: %d°C\n", temperature);
        rcl_publish(&publisher, &msg, NULL);
    }
}

int main() {
    rcl_allocator_t allocator = rcl_get_default_allocator();
    rclc_support_t support;
    rcl_node_t node;
    rcl_timer_t timer;

    rmw_uros_set_custom_transport(
        false, NULL,
        rmw_uros_serial_transport_open,
        rmw_uros_serial_transport_close,
        rmw_uros_serial_transport_write,
        rmw_uros_serial_transport_read
    );

    rclc_support_init(&support, 0, NULL, &allocator);
    rclc_node_init_default(&node, "sensor_node", "", &support);

    rclc_publisher_init_default(
        &publisher,
        &node,
        ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32),
        "temperature"
    );

    rclc_timer_init_default(
        &timer,
        &support,
        RCL_MS_TO_NS(2000),
        timer_callback
    );

    rclc_executor_t executor;
    rclc_executor_init(&executor, &support.context, 1, &allocator);
    rclc_executor_add_timer(&executor, &timer);

    msg.data = 0;

    while(1) {
        rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100));
        usleep(100000);
    }

    return 0;
}
