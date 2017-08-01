#include <EEPROM.h>

int addr = 0;
int val = 4;

void setup() {
  // GPIO02 on ESP-12 module is linked to on-board LED
  pinMode(2, OUTPUT);
  Serial.begin(9600);

  EEPROM.begin(512);
  EEPROM.write(addr, val);
  EEPROM.commit();
}

void loop() {
  digitalWrite(2, HIGH);
  Serial.println("HIGH");
  delay(500);

  digitalWrite(2, LOW);
  Serial.println("LOW");
  delay(500);
}
