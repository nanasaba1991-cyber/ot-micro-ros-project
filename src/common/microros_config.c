#include "microros_config.h"
#include "rmw_microros/rmw_microros.h"

void init_microros_transport(void) {
    rmw_uros_set_custom_transport(
        false, NULL,
        rmw_uros_serial_transport_open,
        rmw_uros_serial_transport_close,
        rmw_uros_serial_transport_write,
        rmw_uros_serial_transport_read
    );
}
