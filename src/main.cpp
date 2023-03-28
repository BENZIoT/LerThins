
#include <LerThings.h>
#include "esp32-hal-log.h"
#include <PubSubClient.h>
#include <ArduinoJson.h>

WiFiClient mqttclient;
PubSubClient mqtt(mqttclient);

#define SSID "Teddy_Bear_2.4G1"
#define PASS "ultraman"

void callback(char *topic, byte *payload, unsigned int length)
{
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++)
  {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void reconnectMQTT();

LerThing ler(SSID, PASS);

void setup()
{
  Serial.begin(115200);
  // Serial.setDebugOutput(true);

  // esp_log_level_set("*", ESP_LOG_VERBOSE);
  // ESP_LOGD("EXAMPLE", "This doesn't show");

  // log_v("Verbose");
  // log_d("Debug");
  // log_i("Info");
  // log_w("Warning");
  // log_e("Error");

  ler.begin();
  mqtt.setServer("iothub.fogwing.net", 1883);
  mqtt.setCallback(callback);
}

void loop()
{
  if (!mqtt.connected())
  {
    reconnectMQTT();
  }
  else
  {
    
    DynamicJsonDocument doc(1024);

    doc["sensor"] = "gps";
    doc["time"] = 1351824120;
    doc["data"][0] = 48.756080;
    doc["data"][1] = 2.302038;

    serializeJsonPretty(doc, Serial);
    String json;
    serializeJson(doc, json);

    mqtt.publish("fwent/edge/bf34a52395263833/inbound", json.c_str());
    delay(30000);
  }
  mqtt.loop();
}

void reconnectMQTT()
{

  if (mqtt.connect("1151-3181-2295-2666", "bf34a52395263833", "Ysdtqczw1!"))
  // if (mqtt.connect(mqttclienid.c_str(), mqttuser.c_str(), mqttpass.c_str(), WILL_TOPIC, WILL_QOS, WILL_RETAIN, willMessage("disconnect").c_str()))
  {
    // mqtt.publish(WILL_TOPIC, willMessage("connected").c_str());
    // mqtt.subscribe("device/control");
    // mqtt.subscribe("/update/url/");
    // mqtt.subscribe("device/ota");
    Serial.println("connected");
    // mqtt.loop();
  }
  else
  {
    Serial.print("failed, rc=");
    Serial.print(mqtt.state());
    Serial.println(" try again in 5 seconds");
    delay(2000);
  }
}