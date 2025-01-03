#include <stdio.h>
#include "urosHandler.hpp"
#include "jumping_service.hpp"

uros_master_node* node = 0;

extern "C" void app_main(void)
{
    node = new uros_master_node("jumping_node");
    jumping_service();
    node->add_urosElement({
        new jumping_service()
    });
}