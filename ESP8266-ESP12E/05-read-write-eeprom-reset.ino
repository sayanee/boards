// INFO: Read from EEPROM successfully after reset
// HARDWARE: ESP-12F module with FTDI chip for flashing

#define LED_BUILTIN 2

#include <ESP8266WiFi.h>
#include <EEPROM.h>

// Edit "secret" ssid and password below
const char* ssid = "secret";
const char* password = "secret";
String writeStr = "ohai";

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // GPIO02 on ESP-12 module is linked to on-board LED

  Serial.begin(115200);
  delay(10);

  Serial.println("");
  Serial.println("[INFO] In setup...");
  readKey();
  connectWiFi();
}

void loop() {
  Serial.println("[INFO] In loop...");
  writeKey(writeStr);
  readKey();

  Serial.print("[INFO] WiFi IP address: ");
  Serial.println(WiFi.localIP());

  blink(500);
  blink(500);
  blink(500);

  Serial.println("[INFO] Sleeping...");

  ESP.deepSleep(0, WAKE_RF_DEFAULT); // sleep indefinitely until wakeup
}

void blink(int interval) {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(interval);

  digitalWrite(LED_BUILTIN, LOW);
  delay(interval);
}

void connectWiFi() {
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
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
  EEPROM.begin(512);
  
  String readStr;
  char readChar;
  Serial.print("[INFO] Reading from EEPROM: ");

  // TODO: Store length of key
  for (int i = 0; i < 22; ++i) {
    readChar = char(EEPROM.read(i));
    readStr += readChar;
  }

  Serial.println("");
  Serial.println(readStr);
  return readStr;
}
