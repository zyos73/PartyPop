# Lösungsansatz – MQTT-Verbindung mit ESP32

## Ziel
Der ESP32 soll eine stabile Verbindung zu einem MQTT-Broker herstellen und Nachrichten senden können.

## Voraussetzungen
- ESP32 mit funktionierender WLAN-Verbindung  
- MQTT-Broker im lokalen Netzwerk  
- Arduino IDE mit installiertem ESP32 Board-Paket  
- MQTT-Client-Bibliothek (z. B. PubSubClient)

## Grundkonzept
Die MQTT-Verbindung baut auf der bestehenden WLAN-Verbindung auf.  
Erst wenn WLAN aktiv ist, wird eine Verbindung zum Broker hergestellt.

## Verbindungsparameter
- **Broker-Adresse**: IP des Laptops im lokalen Netzwerk  
- **Port**: 1883  
- **Client-ID**: eindeutige Kennung des ESP32  
- **Topic**: `sensor/water`  

## Ablauf der MQTT-Verbindung
1. WLAN-Verbindung herstellen  
2. MQTT-Client initialisieren  
3. Verbindung zum Broker aufbauen  
4. Verbindungsstatus überwachen  
5. Nachricht senden

## Programmstruktur

### Initialisierung
- WLAN starten  
- MQTT-Server und Port setzen  
- Callback-Funktion definieren

### Verbindungsaufbau
- Prüfen, ob MQTT verbunden ist  
- Falls nicht, Verbindungsversuch starten  
- Bei Erfolg: Statusmeldung im Serial Monitor

### Senden von Daten
- Vor dem Senden prüfen:
  - WLAN verbunden  
  - MQTT verbunden  
- Publish auf definiertes Topic

## Beispielhafte Logik (vereinfacht)
```cpp
if (WiFi.status() != WL_CONNECTED) {
  connectWiFi();
}

if (!mqttClient.connected()) {
  connectMQTT();
}

mqttClient.publish("sensor/water");
