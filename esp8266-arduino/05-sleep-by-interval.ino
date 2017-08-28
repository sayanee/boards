// in board nodeMCU wire up pin D0 (GPIO16) to pin RST
#include <ESP8266WiFi.h>

// Time to sleep (in seconds):
const int sleepTimeS = 10;

void setup() {
  Serial.begin(115200);
  Serial.println("Wakeup!");
}

void loop() {
  Serial.println("Going into deep sleep for 10 seconds");
  ESP.deepSleep(sleepTimeS * 1000000);
}
