#ifndef LERTHING_H
#define LERTHING_H

#include <Arduino.h>
#include <WiFi.h>

class LerThing
{
private:
    const char *_ssid;
    const char *_password;
    static void WiFiEventHandler(WiFiEvent_t event);
public:
    LerThing(const char* ssid, const char* password);
    void start();
    bool isConnected();
    ~LerThing();
};
#endif
