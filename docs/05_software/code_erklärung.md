# Codebeschreibung – ESP32 Taster mit MQTT

## Überblick
Der Code verbindet einen ESP32 mit einem WLAN und einem MQTT-Broker.  
Ein Taster simuliert einen Wassersensor.  
Bei erkanntem Wasserkontakt wird eine MQTT-Nachricht gesendet.

## Verwendete Bibliotheken
`Arduino.h` – Grundfunktionen der Arduino-Umgebung  
`WiFi.h` – WLAN-Funktionalität des ESP32  
`PubSubClient.h` – MQTT-Client für Publish/Subscribe  

## Konstanten und Definitionen
```cpp
#define BUTTON_PIN 14
#define DEBOUNCE_MS 250
BUTTON_PIN ist der GPIO-Pin für den Taster
DEBOUNCE_MS ist die Entprellzeit in Millisekunden
```

## Netzwerk- und MQTT-Konfiguration
```cpp
Code kopieren
const char* ssid = "ssid";
const char* password = "password";
const char* mqtt_server = "0.0.0.0";
const int   mqtt_port   = 1883;
const char* mqtt_topic = "sensor/water";
```
SSID und Passwort sind die WLAN-Zugangsdaten
MQTT-Server und Port definieren den Broker
Das Topic wird für Wassermeldungen verwendet

## Globale Objekte
```cpp
WiFiClient espClient;
PubSubClient client(espClient);
```
WiFiClient stellt die TCP-Verbindung bereit
PubSubClient übernimmt die MQTT-Kommunikation

## Statusvariablen
```cpp
unsigned long lastPressTime = 0;
int lastState = HIGH;
```
lastPressTime speichert den Zeitpunkt der letzten Zustandsänderung
lastState speichert den letzten Tasterzustand

## WLAN-Statusanzeige
```cpp
void wifiStatusName(int st)
```
Gibt den aktuellen WLAN-Status lesbar im Serial Monitor aus
Dient zur Fehlersuche bei Verbindungsproblemen

## WLAN-Verbindung
```cpp
void connectWifi()
```
Versetzt den ESP32 in den Station-Modus
Baut die WLAN-Verbindung auf
Verwendet ein Timeout von 20 Sekunden
Gibt IP-Adresse und Status aus

## MQTT-Client-ID
```cpp
String makeClientId()
```
Erzeugt eine eindeutige Client-ID aus der MAC-Adresse
Verhindert Konflikte im MQTT-Broker

## MQTT-Verbindung
```cpp
void connectMQTT()
```
Prüft zuerst die WLAN-Verbindung
Stellt danach die MQTT-Verbindung her
Verwendet ein Timeout von 10 Sekunden

## MQTT-Nachricht senden
```cpp
void sendWaterMessage()
```
Prüft WLAN- und MQTT-Verbindung
Führt automatische Reconnects durch
Sendet die Payload WATER_DETECTED

## setup()
```cpp
void setup()
```
Initialisiert die serielle Schnittstelle
Setzt den Taster auf INPUT_PULLUP
Stellt WLAN- und MQTT-Verbindung her

## loop()
```cpp
void loop()
```
Überwacht WLAN- und MQTT-Verbindung
Ruft client.loop() auf
Liest den Tasterzustand zyklisch
Erkennt Zustandsänderungen
Sendet bei LOW-Pegel eine MQTT-Nachricht

## Tasterlogik
HIGH bedeutet kein Wasserkontakt
LOW bedeutet Wasserkontakt erkannt

## Robustheit
Automatischer WLAN-Reconnect
Automatischer MQTT-Reconnect
Kein Senden ohne aktive Verbindung

## Ergebnis
Der ESP32 erkennt Wasserkontakt zuverlässig
Die Meldung wird stabil per MQTT gesendet