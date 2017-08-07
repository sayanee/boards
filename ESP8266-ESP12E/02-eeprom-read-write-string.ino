#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <EEPROM.h>

String writeStr = "ohai";

void setup() {
  Serial.begin(115200);
  EEPROM.begin(512);
  delay(10);
  Serial.println();
  Serial.println();
  Serial.println("Startup");

  Serial.println("Writing to EEPROM...");

  for (int i = 0; i < writeStr.length(); ++i) {
    EEPROM.write(i, writeStr[i]);
    Serial.print("Wrote: ");
    Serial.println(writeStr[i]);
  }
}

void loop() {
  String readStr;
  Serial.println("Reading EEPROM...");

  for (int i = 0; i < 32; ++i) {
    readStr += char(EEPROM.read(i));
  }

  Serial.print("Read: ");
  Serial.println(readStr);

  delay(2000);
}
