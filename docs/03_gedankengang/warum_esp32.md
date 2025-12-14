# Warum ESP32

## Anforderungen
Für das Projekt wurden folgende Eigenschaften benötigt:
- WLAN-Unterstützung  
- MQTT-Kommunikation  
- Digitale Ein- und Ausgänge  
- Geringe Kosten  
- Einfache Programmierung  

## Entscheidungskriterien

### Integriertes WLAN
Der ESP32 besitzt WLAN bereits on-board.  
Kein zusätzliches Modul notwendig.  
Direkte Anbindung an MQTT-Broker möglich.

### Rechenleistung und Speicher
- Ausreichend Leistung für:
  - WLAN  
  - MQTT  
  - Tasterabfrage  
- Mehr Speicher als klassische Arduino-Boards.

### Gute Software-Unterstützung
- Vollständig in der Arduino IDE nutzbar  
- Große Community  
- Viele stabile Bibliotheken  
  - WiFi  
  - PubSubClient (MQTT)

### Kosten und Verfügbarkeit
- Günstig  
- Weit verbreitet  
- Ersatz leicht beschaffbar

### Erweiterbarkeit
- Viele GPIO-Pins  
- Unterstützung für weitere Sensoren  
- Skalierbar für spätere Funktionen

## Vergleich zu Alternativen
- **Arduino UNO**: Kein WLAN, zusätzliches Modul nötig  
- **Raspberry Pi**: Overkill für einfache Sensorik  
- **ESP8266**: Weniger Leistung und Pins als ESP32

## Ergebnis
Der ESP32 erfüllt alle technischen Anforderungen.  
Er bietet die beste Balance aus Funktionalität, Kosten und Einfachheit.

## Fazit
Der ESP32 ist die optimale Wahl für MQTT-basierte Sensor- und Tasteranwendungen im lokalen Netzwerk.
