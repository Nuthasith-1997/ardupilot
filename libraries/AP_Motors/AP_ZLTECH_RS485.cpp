#include "AP_ZLTECH_RS485.h"

#include <AP_SerialManager/AP_SerialManager.h>

#define TEST    0xAA

AP_ZLTECH_RS485::AP_ZLTECH_RS485(){
    const AP_SerialManager &serial_manager = AP::serialmanager();
    _uart = serial_manager.find_serial(AP_SerialManager::SerialProtocol_ZLTECH, 0);
    if (_uart != nullptr) {
        // start uart with larger receive buffer
        _uart->begin(115200);
    }
}

void AP_ZLTECH_RS485::send_msg(){
    if (_uart == nullptr){
        gcs().send_text(MAV_SEVERITY_INFO, "uart = null");
        return;
    }

    _uart->write((uint8_t)TEST);
    gcs().send_text(MAV_SEVERITY_INFO, "uart write");
}