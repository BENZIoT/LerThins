#ifndef LERTHING_H
#define LERTHING_H

#include <Arduino.h>
#include <WiFi.h>
// #include <pubsubClient.h>

// WiFiClient _mqttclient;
// PubSubClient _mqtt(_mqttclient);

class LerThing
{
private:
    const char *_ssid;
    const char *_password;
    static void WiFiEventHandler(WiFiEvent_t event);
    
public:
    // const char *_mqttUser;
    // const char *_mqttPassword;
    // const char *_mqttClientId;
    // bool _mqttStart = false;

    LerThing(const char *ssid, const char *password);
    void begin();
    bool isConnected();
    // void setupMqtt(const char *mqttServer, int mqttPort, const char *mqttUser, const char *mqttPassword, const char *mqttClientId);
    // void connectMqtt();
    // void publishMqtt(const char *topic, const char *message);
    // void subscribeMqtt(const char *topic, void (*callback)(char *, byte *, unsigned int));
    ~LerThing();
};
#endif
