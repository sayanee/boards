// Derived from: https://learn.sparkfun.com/tutorials/esp8266-thing-hookup-guide/example-sketch-ap-web-server

// Hardware: NodeMCU
// Edit: L15, L16 and L17 to set AP name prefix and AP password

// Usage:
// 1. Select AP name "Belle XXX"
// 2. Put in AP password
// 3. Go to browser http://belle.local
// 4. View Hello World!

#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>

String AP_NamePrefix = "Belle "; // set AP name prefix
const char WiFiAPPSK[] = "secret"; // set AP password
const char* DomainName = "belle"; // set domain name domain.local

WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  setupWiFi();

  if (!MDNS.begin(DomainName)) {
    Serial.println("Error setting up MDNS responder!");
    while(1) {
      delay(1000);
    }
  }

  server.begin();
  MDNS.addService("http", "tcp", 80);
}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  String req = client.readStringUntil('\r');
  client.flush();

  String s = "HTTP/1.1 200 OK\r\n";
  s += "Content-Type: text/html\r\n\r\n";
  s += "<!DOCTYPE HTML>";
  s += "<html>";
  s += "<form action='/' method=get>";
  s += "<input type=\"text\" placeholder=\"WiFi\" name=\"ssid\" required><br>";
  s += "<input type=\"text\" placeholder=\"Password\" name=\"password\" required><br>";
  s += "<input type=\"submit\" name=\"submit\" value=\"Set WiFi details\">";
  s += "</form>";
  s += "</html>\n";

  client.print(s);
  delay(1);

  if (req.indexOf("?ssid") > 0) {
    Serial.println(req);

    String ssid = getValue(getValue(req, '&', 0), '=', 1);
    String password = getValue(getValue(req, '&', 1), '=', 1);

    Serial.println("SSID: " + ssid);
    Serial.println("Password: " + password);

    Serial.println("SSID received!");
  }
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

String getValue(String data, char separator, int index) {
  int found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
