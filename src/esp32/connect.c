#include <stdlib.h>

#include "connect.h"

#include <Wifi.h>

Conn Connect(int retries, Input *input)
{
    if (input == NULL) {
#ifdef DEBUG
        Serial.println("Invalid input!");
#endif
        return not_connected;
    }

    int count = 0;

#ifdef DEBUG
    Serial.begin(115200);
    delay(1000);
#endif

    WiFi.mode(WIFI_STA);
    WiFi.begin(input->ssid, input->password);
#ifdef DEBUG
    Serial.println("\nConnecting");
#endif

    while(WiFi.status() != WL_CONNECTED || count < retries){
        count++;
        delay(100);
#ifdef DEBUG
        Serial.print(".");
#endif
    }

    if WiFi.status() != WL_CONNECTED {
        return not_connected;
    }

#ifdef DEBUG
    Serial.println("\nConnected to the WiFi network");
    Serial.print("Local ESP32 IP: ");
    Serial.println(WiFi.localIP());
#endif
    return connected;
}
