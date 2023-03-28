#include <LerThings.h>

LerThing::LerThing(const char *ssid, const char *password)
{
    _ssid = ssid;
    _password = password;
}

void LerThing::begin()
{
    WiFi.onEvent(WiFiEventHandler);
    WiFi.begin(_ssid, _password);
}

bool LerThing::isConnected()
{
    return WiFi.status() == WL_CONNECTED;
}

void LerThing::WiFiEventHandler(WiFiEvent_t event)
{
    switch (event)
    {
    case SYSTEM_EVENT_STA_CONNECTED:
        Serial.println("Wi-Fi connected");
        // if (_mqtt.connected() == 0)
        // {
        //     // connectMqtt();
        //     Serial.println("Wi-Fi connected");
        // }
        break;
    case SYSTEM_EVENT_STA_DISCONNECTED:
        Serial.println("Wi-Fi disconnected");
        WiFi.reconnect();
        Serial.println("Wi-Fi reconnecting...");
        break;
    default:
        break;
    }
}

// void LerThing::setupMqtt(const char *mqttServer, int mqttPort, const char *mqttUser, const char *mqttPassword, const char *mqttClientId)
// {
//     _mqttUser = mqttUser;
//     _mqttPassword = mqttPassword;
//     _mqttClientId = mqttClientId;
//     _mqttStart = true;
//     _mqtt.setServer(mqttServer, mqttPort);
// }

// void LerThing::connectMqtt()
// {
//   // Connect to the MQTT broker with the provided credentials
//   if(_mqttStart)
//   _mqtt.connect(_mqttClientId, _mqttUser, _mqttPassword);
// }

LerThing::~LerThing()
{
}
