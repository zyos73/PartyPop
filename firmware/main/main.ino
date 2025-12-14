#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

#define BUTTON_PIN 14 // Water Sensor
#define DEBOUNCE_MS 250

const char* ssid = "ssid"; // configure this
const char* password = "password"; // configure this

const char* mqtt_server = "0.0.0.0"; // configure this
const int   mqtt_port   = 1883; // configure this
const char* mqtt_topic  = "sensor/water"; // configure this

WiFiClient espClient;
PubSubClient client(espClient);

unsigned long lastPressTime = 0;
int lastState = HIGH;

// Hilfsfunktionen
void wifiStatusName(int st) {
  Serial.print("WiFi.status() = ");
  Serial.print(st);
  Serial.print("  (");
  switch(st) {
    case WL_IDLE_STATUS: Serial.print("WL_IDLE_STATUS"); break;
    case WL_NO_SSID_AVAIL: Serial.print("WL_NO_SSID_AVAIL"); break;
    case WL_SCAN_COMPLETED: Serial.print("WL_SCAN_COMPLETED"); break;
    case WL_CONNECTED: Serial.print("WL_CONNECTED"); break;
    case WL_CONNECT_FAILED: Serial.print("WL_CONNECT_FAILED"); break;
    case WL_CONNECTION_LOST: Serial.print("WL_CONNECTION_LOST"); break;
    case WL_DISCONNECTED: Serial.print("WL_DISCONNECTED"); break;
    default: Serial.print("unknown");
  }
  Serial.println(")");
}

// WLAN connect (einmalig)
void connectWifi() {
  Serial.print("Verbinde mit WLAN '");
  Serial.print(ssid);
  Serial.println("' ...");

  WiFi.mode(WIFI_STA);
  WiFi.disconnect(true);
  delay(100);

  WiFi.begin(ssid, password);

  unsigned long start = millis();
  const unsigned long timeout = 20000; // 20s
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
    if (millis() - start > timeout) {
      Serial.println();
      Serial.println("WLAN Timeout - konnte nicht verbinden.");
      wifiStatusName(WiFi.status());
      return;
    }
  }

  Serial.println();
  Serial.println("WLAN verbunden!");
  Serial.print("ESP IP: ");
  Serial.println(WiFi.localIP());
}

// MQTT connect + reconnect
String makeClientId() {
  uint8_t mac[6];
  WiFi.macAddress(mac);
  char id[24];
  snprintf(id, sizeof(id), "ESP32_%02X%02X%02X", mac[3], mac[4], mac[5]);
  return String(id);
}

void connectMQTT() {
  if (WiFi.status() != WL_CONNECTED) {
    connectWifi();
    return;
  }

  client.setServer(mqtt_server, mqtt_port);
  String cid = makeClientId();

  unsigned long start = millis();
  const unsigned long timeout = 10000; // 10s
  while (!client.connected()) {
    Serial.print("Verbinde MQTT mit ClientID=");
    Serial.print(cid);
    Serial.print(" ... ");

    if (client.connect(cid.c_str())) {
      Serial.println("OK");
      break;
    } else {
      Serial.print("failed rc=");
      Serial.println(client.state());
    }

    if (millis() - start > timeout) {
      Serial.println("MQTT connect timeout.");
      return;
    }

    delay(1000);
  }
}

// sendet die MQTT-Nachricht
void sendWaterMessage() {
  if (WiFi.status() != WL_CONNECTED) {
    connectWifi();

    sendWaterMessage();
  }
  if (!client.connected()) {
    connectMQTT();

    sendWaterMessage();
  }

  const char* payload = "WATER_DETECTED";
  bool ok = client.publish(mqtt_topic, payload);
  if (ok) Serial.println("MQTT: WATER_DETECTED gesendet.");
  else     Serial.println("MQTT: publish fehlgeschlagen.");
}

void setup() {
  Serial.begin(115200);
  delay(100);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  connectWifi();
  connectMQTT();
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    connectWifi();
  }

  if (WiFi.status() == WL_CONNECTED && !client.connected()) {
    connectMQTT();
  }

  client.loop();

  int state = digitalRead(BUTTON_PIN); // HIGH = kein Wasser, LOW = Wasser
  if (state != lastState) {
    unsigned long now = millis();
    if (now - lastPressTime > DEBOUNCE_MS) {
      // Flanke: HIGH->LOW oder LOW->HIGH
      if (state == LOW) {
        Serial.println("Sensor: Wasser erkannt (LOW) -> sende MQTT");
        sendWaterMessage();
      }
      
      lastPressTime = now;
    }
    lastState = state;
  }

  delay(20);
}
