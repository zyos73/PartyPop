#include <WiFi.h>
void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("Starting Wifi Scan...");
  int n = WiFi.scanNetworks();
  Serial.println("Found Networks: ");

  for (int i = 0; i < n; ++i) {
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.print(WiFi.SSID(i));
    Serial.print(" (rssi=");
    Serial.print(WiFi.RSSI(i));
    Serial.print(") ");
    Serial.print((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? "OPEN" : "SECURE");
    Serial.println();
  }
}
void loop(){}