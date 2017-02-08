// in board nodeMCU wire up pin D0 to pin RST
// GPIO16 on ESP8266 is Deep-Sleep Wakeup
void setup() { // on wakeup Arduino will run setup()
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.println('Wake up!');

  for (int i=0; i <= 5; i++){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  }
}

void loop() {
  Serial.println("Sleep.... 2");
  delay(100);
  Serial.println("Sleep.... 1");
  delay(100);
  ESP.deepSleep(0, WAKE_RF_DEFAULT); // sleep indefinitely until wakeup
}
