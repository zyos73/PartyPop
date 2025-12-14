# Schaltkreisbeschreibung

## Übersicht
Der Schaltkreis besteht aus einem ESP32 und einem Taster.  
Der Taster ist direkt an einen GPIO-Pin angeschlossen und nutzt den internen Pull-up-Widerstand des ESP32.

## Aufbau des Schaltkreises
- Ein Kontakt des Tasters ist mit einem **GPIO-Pin** des ESP32 verbunden  
- Der andere Kontakt des Tasters ist mit **GND** verbunden  
- Es werden **keine externen Widerstände** verwendet  

## Pinbelegung
| Bauteil | Pin | Verbindung |
|-------|-----|------------|
| ESP32 | GPIO14 | Taster |
| ESP32 | GND | Taster |

## Elektrisches Prinzip
- Der GPIO-Pin ist als **INPUT_PULLUP** konfiguriert  
- Der interne Pull-up-Widerstand zieht den Pin im Ruhezustand auf **HIGH**  
- Beim Drücken des Tasters wird der Pin direkt mit **GND** verbunden  
- Der Pegel wechselt von **HIGH** auf **LOW**

## Logikzustände
| Tasterzustand | GPIO-Pegel |
|--------------|-----------|
| Nicht gedrückt | HIGH |
| Gedrückt | LOW |

## Signalverarbeitung
- Der ESP32 liest den digitalen Zustand des GPIO-Pins zyklisch aus  
- Ein erkannter LOW-Pegel wird als Ereignis interpretiert  
- Dieses Ereignis kann anschließend per MQTT gesendet werden  

## Vorteile des Schaltkreises
- Sehr einfacher Aufbau  
- Geringe Fehleranfälligkeit  
- Kein zusätzlicher Bauteilaufwand  
- Gut geeignet für Tests und Prototypen  

## Hinweise
- Mechanische Taster können prellen  
- Entprellung kann softwareseitig erfolgen  
- Andere GPIO-Pins sind ebenfalls nutzbar  

## Ergebnis
Der Schaltkreis liefert ein stabiles digitales Eingangssignal.  
Er ist optimal für die Anbindung an MQTT-basierte Anwendungen geeignet.
