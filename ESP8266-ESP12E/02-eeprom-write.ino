// https://github.com/esp8266/Arduino/tree/master/libraries/EEPROM/examples/eeprom_write
#include <EEPROM.h>

int addr = 0;

void setup() {
  // GPIO02 on ESP-12 module is linked to on-board LED
  pinMode(2, OUTPUT);
  Serial.begin(9600);

  EEPROM.begin(512);
  EEPROM.write(addr, 2);
  EEPROM.commit();
}

void loop() {
  blink();

  Serial.print(addr);
  Serial.print("\t");

  if (addr % 4 == 0) {
    EEPROM.write(addr, 4);
    Serial.print(4, DEC);
  } else {
    EEPROM.write(addr, 2);
    Serial.print(2, DEC);
  }

  EEPROM.commit();
  Serial.println();

  addr = addr + 1;
  if (addr == 512) {
    addr = 0;
  }
}

void blink() {
  digitalWrite(2, HIGH);
  delay(10);

  digitalWrite(2, LOW);
  delay(10);
}
