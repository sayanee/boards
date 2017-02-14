#include <ESP8266WiFi.h>

const char* ssid     = "secret";
const char* password = "secret";

const char* host = "secret";

void setup() {
  Serial.begin(9600);
  delay(10);

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

void loop() {
  WiFiClient client;
  const int httpPort = 8000; // change accordingly
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }

  Serial.println("connecting...");
  String PostData="sample";

  Serial.println("connected");
  client.println("POST /hello HTTP/1.1");
  client.println("Host:  10.0.1.22");
  client.println("User-Agent: Arduino/1.0");
  client.println("Connection: close");
  client.println("Content-Type: application/x-www-form-urlencoded;");
  client.print("Content-Length: ");
  client.println(PostData.length());
  client.println();
  client.println(PostData);

  Serial.println(PostData);
  Serial.println("connection success");

  delay(5000);
}
