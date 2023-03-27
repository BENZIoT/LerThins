
#include <LerThings.h>

#define SSID "Teddy_Bear_2.4G1"
#define PASS "ultraman"

LerThing wifi(SSID, PASS);

void setup() {
  Serial.begin(115200);
  wifi.start();
}

void loop() {
  //
}
