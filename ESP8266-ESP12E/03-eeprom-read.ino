// Reference: https://github.com/esp8266/Arduino/blob/master/libraries/EEPROM/examples/eeprom_read/eeprom_read.ino

#include <EEPROM.h>

int address = 0;
byte value;

void setup() {
  Serial.begin(9600);
  EEPROM.begin(512);
}

void loop() {
  blink();

  value = EEPROM.read(address);

  Serial.print(address);
  Serial.print("\t");
  Serial.print(value, DEC);
  Serial.println();

  address = address + 1;

  if (address == 512)
    address = 0;

  delay(20);
}

void blink() {
  digitalWrite(2, HIGH);
  delay(10);

  digitalWrite(2, LOW);
  delay(10);
}
