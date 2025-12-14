# MQTT Schnittstellenbeschreibung
## Zweck
Der ESP32 meldet einen erkannten Wasserkontakt über MQTT.

## Systemübersicht
- **Gerät**: ESP32  
- **Rolle**: Publisher  
- **Broker**: Laptop im lokalen Netzwerk  
- **Broker-Adresse**: IP des Laptops im Router-Netzwerk (variabel)  
- **Port**: 1883  

## Topic
- **Name**: `sensor/water`  
- **Richtung**: ESP32 → Broker  
- **Bedeutung**: Meldung bei Wasserkontakt

## Publish-Bedingung
- Der ESP32 sendet eine Nachricht, **wenn Wasserkontakt erkannt wird**.

## QoS
- **QoS**: 0  
- **Begründung**: Einfache Statusmeldung, geringe Latenz ausreichend.

## Retain
- **Retain**: false  
- **Erklärung**:  
  Der Broker speichert die letzte Nachricht nicht dauerhaft.  
  Neue Subscriber erhalten nur zukünftige Meldungen.
