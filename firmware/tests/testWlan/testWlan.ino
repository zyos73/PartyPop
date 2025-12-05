#include <WiFi.h>

const char* broker = "0.0.0.0"; // <-- deine PC-IP (ersetzt)
const int brokerPort = 1883;

void setup() {
  Serial.begin(115200);
  WiFi.begin("ssid","name#");
  while (WiFi.status() != WL_CONNECTED) { delay(200); Serial.print("."); }
  Serial.println("\nWLAN OK, IP:"); Serial.println(WiFi.localIP());

  WiFiClient test;
  Serial.print("Versuche TCP zu ");
  Serial.print(broker); Serial.print(":"); Serial.println(brokerPort);
  if (test.connect(broker, brokerPort)) {
    Serial.println("TCP connect OK -> Port erreichbar");
    test.stop();
  } else {
    Serial.println("TCP connect fehlgeschlagen -> Port/Firewall/No listener");
  }
}

void loop(){}
