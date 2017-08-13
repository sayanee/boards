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

void loop() {
  readKey();
  delay(2000);
}

void writeKey(String writeStr) {
  EEPROM.begin(512);
  delay(10);

  for (int i = 0; i < writeStr.length(); ++i) {
    EEPROM.write(i, writeStr[i]);
    Serial.print("[INFO] Writing to EEPROM: ");
    Serial.println(writeStr[i]);
  }

  EEPROM.commit();
}

String readKey() {
  String readStr;
  char readChar;
  Serial.print("[INFO] Reading from EEPROM: ");

  EEPROM.begin(512);
  
  // TODO: Store length of key
  for (int i = 0; i < 22; ++i) {
    readChar = char(EEPROM.read(i));
    readStr += readChar;

    Serial.print("Char: ");
    Serial.println(readChar);
  }

  Serial.println("");
  Serial.println(readStr);
  return readStr;
}
