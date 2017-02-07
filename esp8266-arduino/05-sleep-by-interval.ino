// in board nodeMCU wire up pin D0 to pin RST
// GPIO16 on ESP8266 is Deep-Sleep Wakeup
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.println('Wake up!')
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  // on wakeup Arduino will run setup()
}

void loop() {
  Serial.println("Sleep.... 2");
  delay(100);
  Serial.println("Sleep.... 1");
  delay(100);
  ESP.deepSleep(5e6, WAKE_RF_DEFAULT); // sleep for 5 seconds
}
