#include <EEPROM.h>

String writeStr = "ohai";

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  Serial.println("Startup");
  delay(10000);

  writeKey(writeStr);
}

void writeKey(String writeStr) {
  EEPROM.begin(512);
  delay(10);

  for (int i = 0; i < writeStr.length(); ++i) {
    EEPROM.write(i, writeStr[i]);
    Serial.print("[INFO] Writing to EEPROM: ");
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
