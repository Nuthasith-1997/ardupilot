#include <AP_HAL/AP_HAL.h>
#include <GCS_MAVLink/GCS.h>

class AP_ZLTECH_RS485{
    public:
        AP_ZLTECH_RS485();
        
        void send_msg();

    protected:
        AP_HAL::UARTDriver *_uart;

};