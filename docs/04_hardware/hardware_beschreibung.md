# Hardwarebeschreibung

## Zentrale Hardware
- **ESP32 Dev Module**  
- **Taster (Push Button)**  
- **Breadboard**  
- **Jumper-Kabel**  
- **USB-Kabel (datenfähig)**  

## ESP32
Der ESP32 ist die zentrale Steuereinheit des Systems.

**Aufgaben:**
- Auslesen des Tasters  
- Aufbau der WLAN-Verbindung  
- Aufbau der MQTT-Verbindung  
- Senden von MQTT-Nachrichten  

**Eigenschaften:**
- Integriertes WLAN  
- Mehrere digitale GPIO-Pins  
- Unterstützung durch die Arduino IDE  

## Taster
Der Taster dient als einfaches Eingabegerät.

**Funktion:**
- Erzeugt ein digitales Signal bei Betätigung  
- Wird als Ersatz für einen Wasserkontaktsensor verwendet  

**Betriebsart:**
- Nutzung des internen Pull-up-Widerstands des ESP32  
- Ruhezustand: HIGH  
- Gedrückt: LOW  

## Elektrischer Anschluss

### Pinbelegung
| ESP32 Pin | Verbindung |
|----------|-----------|
| GPIO14   | Taster |
| GND      | Taster |

## Funktionsprinzip
- Der GPIO-Pin ist als `INPUT_PULLUP` konfiguriert  
- Ohne Tastendruck liegt ein HIGH-Pegel an  
- Beim Drücken wird der Pin mit GND verbunden und auf LOW gezogen  

## Hinweise
- Kein externer Widerstand notwendig  
- Andere GPIO-Pins können ebenfalls verwendet werden  
- Anschluss ist für Test- und Lernzwecke ausgelegt  

## Ergebnis
Die Hardware ist einfach aufgebaut und zuverlässig.  
Sie eignet sich als Grundlage für MQTT-basierte Eingabesysteme.
