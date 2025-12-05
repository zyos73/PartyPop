#include <WiFi.h>

const char* ssid = "name";
const char* password = "password";

void connectWifi() {
  WiFi.mode(WIFI_STA);

  WiFi.disconnect(true);
  delay(100);

  WiFi.begin(ssid, password);

  unsigned long start = millis();

  const unsigned long timeout = 20000;
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
    if (millis() - start > timeout) {
      Serial.println();
      Serial.println("Timeout, Status=");
      Serial.println(WiFi.status());
      return;
    }
  }

  Serial.println("Connected!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(115200);
  delay(100);
  connectWifi();
}

void loop(){}