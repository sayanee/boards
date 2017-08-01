// https://github.com/esp8266/Arduino/tree/master/libraries/EEPROM/examples/eeprom_write
// INFO: Write integer to EEPROM

#include <EEPROM.h>

int addr = 20;
char *key = "supercalifragilisticexpialidocious";

void setup() {
  Serial.begin(9600);

  // GPIO02 on ESP-12 module is linked to on-board LED
  pinMode(2, OUTPUT);

  digitalWrite(2, HIGH);

  EEPROM.begin(addr);

  int keysize = strlen(key);

  for(int count = 0; count < keysize; count++) {
    EEPROM.write(addr, (int)key[count]);
    EEPROM.end(); // FIXME: Commit only after write after everything

    addr = addr + 1;
    delay(20);

    Serial.print(addr);
    Serial.print("\t");
    Serial.print((int)key[count]);
    Serial.print("\t");
    Serial.println(EEPROM.read(addr)); // FIXME: Why is the number not the same
    delay(500);
  }
}

void loop() {
  blink();
}

void blink() {
  digitalWrite(2, HIGH);
  delay(500);

  digitalWrite(2, LOW);
  delay(500);
}
