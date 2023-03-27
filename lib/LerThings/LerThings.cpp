#include <LerThings.h>

LerThing::LerThing(const char *ssid, const char *password)
{
    _ssid = ssid;
    _password = password;
}

void LerThing::start()
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

LerThing::~LerThing()
{
}
