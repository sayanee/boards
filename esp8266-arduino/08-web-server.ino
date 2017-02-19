// Derived from: https://learn.sparkfun.com/tutorials/esp8266-thing-hookup-guide/example-sketch-ap-web-server

// Hardware: NodeMCU
// Edit: L12 and L13 to set AP name prefix and AP password

// Usage:
// 1. Select AP name "Belle XXX"
// 2. Put in AP password
// 3. Go to browser http://192.168.4.1/
// 4. View Hello World!

#include <ESP8266WiFi.h>

String AP_NamePrefix = "Belle "; // set AP name prefix
const char WiFiAPPSK[] = "secret"; // set AP password

WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  setupWiFi();
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();

  String s = "HTTP/1.1 200 OK\r\n";
  s += "Content-Type: text/html\r\n\r\n";
  s += "<!DOCTYPE HTML>\r\n<html>\r\n";
  s += "Hello World! ";
  s += "</html>\n";

  client.print(s);
  delay(1);
  Serial.println("Client disonnected");
}

void setupWiFi() {
  WiFi.mode(WIFI_AP);

  uint8_t mac[WL_MAC_ADDR_LENGTH];
  WiFi.softAPmacAddress(mac);
  String macID = String(mac[WL_MAC_ADDR_LENGTH - 2], HEX) +
                 String(mac[WL_MAC_ADDR_LENGTH - 1], HEX);
  macID.toUpperCase();
  String AP_NameString = AP_NamePrefix + macID;

  char AP_NameChar[AP_NameString.length() + 1];
  memset(AP_NameChar, 0, AP_NameString.length() + 1);

  for (int i=0; i<AP_NameString.length(); i++)
    AP_NameChar[i] = AP_NameString.charAt(i);

  WiFi.softAP(AP_NameChar, WiFiAPPSK);
}
