#include "Arduino.h"
#define LED_BUILTIN 13
#ifndef UNIT_TEST

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("HIGH");
  delay(1000);

  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("LOW");
  delay(1000);
}

#endif
