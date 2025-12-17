/*********************************************************************************
 * client_config.h
 * 
 * Added ESP32-Serial-WiFi-Client   -- Yuri - Apr 2023
 * 
*********************************************************************************/
#ifndef CLIENT_CONFIG_H
#define CLIENT_CONFIG_H

#include <WiFi.h>

#define DEBUG              // comment to suppress system serial messages

#define OTA_HANDLER        // uncomment to enable OTA programming

#define SSID   "ssid"      // SSID to join
#define PASSWD "password"  // wiFi password

#define BUFFERSIZE 1024

#define VERSION "2.0-ESP32"

#define PROTOCOL_TCP                       // PROTOCOL_TCP or PROTOCOL_UDP
//#define PROTOCOL_UDP                       // PROTOCOL_TCP or PROTOCOL_UDP
#define HOST_IP IPAddress(192, 168, 4, 1)  // only used for PROTOCOL_TCP
//#define HOST_PORT 14550                    // UDP port
#define HOST_PORT 8880                    // TCP port
#define CLIENT_BAUD 115200
#define CLIENT_PARAM SERIAL_8N1
#define CLIENT_TXPIN 1
#define CLIENT_RXPIN 3

/**************************  DO NOT EDIT BELOW HERE **************************/
// perhaps a clever way to include/exclude serial debug messages...
#ifdef DEBUG
    #define debug Serial
#else
    class Debug: public Print {
        virtual size_t write(byte b) { return 0; }
    };
    Debug debug;
#endif

#endif  // CLIENT_CONFIG_H
