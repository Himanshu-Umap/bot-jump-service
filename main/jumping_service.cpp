#include "jumping_service.hpp"
#include "std_srvs/srv/set_bool.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#define action GPIO_NUM_2 
const rosidl_service_type_support_t * type_support = ROSIDL_GET_SRV_TYPE_SUPPORT(std_srvs, srv, SetBool);

gpio_config_t action_cfg{
    .pin_bit_mask = (1ULL<<action),
    .mode = GPIO_MODE_OUTPUT,
    .pull_up_en = GPIO_PULLUP_DISABLE,
    .pull_down_en = GPIO_PULLDOWN_ENABLE,
    .intr_type = GPIO_INTR_DISABLE
};


void jumping_service::init(){
    rclc_service_init_default(&service, node, type_support, service_name);
    //rcl_get_default_allocator();
    rclc_executor_add_service(exec, &service, &req, &res, &service_callback);
};


void jumping_service::service_callback(const void* req, void *res){
    const std_srvs__srv__SetBool_Request *reqIn = (std_srvs__srv__SetBool_Request*)req;
    const std_srvs__srv__SetBool_Request *resIn = (std_srvs__srv__SetBool_Request*)res;
    //res = (std_srvs__srv__SetBool_Response*)res;
    if(reqIn->data == 1){
    gpio_config(&action_cfg);
    gpio_set_level(action, 1);
    vTaskDelay(pdMS_TO_TICKS(1000));
    gpio_set_level(action, 0);
    }

}

//rclc_executor_spin(&executor);
  