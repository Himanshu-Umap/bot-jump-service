#include "urosElement.hpp"
#include "std_srvs/srv/set_bool.h"


class jumping_service : public urosElement{

    public:
        const char* service_name = "jumping_service"; 
        void init();
        static void service_callback(const void* req, void *res);

    private:
        rcl_service_t service;
        std_srvs__srv__SetBool_Response res;
        std_srvs__srv__SetBool_Request req;
        // static jumping_service *ser;
};

