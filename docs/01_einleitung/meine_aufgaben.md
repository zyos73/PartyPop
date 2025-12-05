# Inhalt
- [0. Übersicht](##0.%20Übersicht)
- [1. Entwicklungsumgebung einrichten](##1.%20Entwicklungsumgebung%20einrichten)
- [2. Hardware Grundlagen aufbauen und Testen mit dem Taster](##2.%20Hardware%20Grundlagen%20aufbauen%20und%20Testen%20mit%20dem%20Taster)
- [3. Fehlerbehebung und Robustheit](##3.%20Fehlerbehebung%20und%20Robustheit)
- [4. MQTT Schnittstellenbeschreibung](##4.%20MQTT%20Schnittstellenbeschreibung)
- [5. MQTT Verbindung programmieren zum ESP32](##5.%20MQTT%20Verbindung%20programmieren%20zum%20ESP32)
- [6. Taster mit MQTT Verbindung finalisieren](##6.%20Taster%20mit%20MQTT%20Verbindung%20finalisieren)
## 0. Übersicht
Dieses Dokument beschreibt alle Aufgaben, die ich im Projekt übernommen habe. Mein Schwerpunkt liegt auf dem ESP32, dem Taster (als Wasserkontakt-Simulation) und der MQTT-Anbindung.

---

## 1. Entwicklungsumgebung einrichten
**Beschreibung:**  
Ich habe die vollständige Entwicklungsumgebung für den ESP32 eingerichtet. Dazu gehörten:
- Installation und Konfiguration der Arduino IDE  
- Hinzufügen des ESP32-Boardpakets  
- Installation benötigter Bibliotheken (z. B. WiFi, PubSubClient)  
- Initialer Funktionstest mit einem Taster, um sicherzustellen, dass Eingaben zuverlässig erkannt werden  

**Ziel:**  
Eine stabile Grundlage schaffen, auf der die spätere MQTT-Funktion und Sensorlogik aufbauen können.

---

## 2. Hardware Grundlagen aufbauen und Testen mit dem Taster
**Beschreibung:**  
Ich habe den Hardware-Aufbau übernommen, der den Wasserkontakt über einen Taster simuliert. Dazu gehörten:
- Auswahl eines geeigneten Tasters  
- Verkabelung des Tasters mit dem ESP32  
- Festlegen der Pinbelegung  
- Test der Signalstabilität (z. B. Pull-Up/Pull-Down Konfiguration)

**Ziel:**  
Ein funktionierender Hardwareaufbau, der definierte digitale Signale liefert.

---

## 3. Fehlerbehebung und Robustheit
**Beschreibung:**  
Während der Entwicklung habe ich verschiedene Hardware- und Softwareprobleme analysiert und behoben. Dazu gehörten:
- Beheben von Wackelkontakten am Taster  
- Debuggen von Verbindungsproblemen im Code  
- Stabilisierung der Schleifenlogik, damit der ESP32 zuverlässig Nachrichten sendet  

**Ziel:**  
Ein robust funktionierendes System, das fehlerfrei arbeitet.

---

## 4. MQTT Schnittstellenbeschreibung
**Beschreibung:**  
Ich habe dokumentiert, wie der ESP32 mit dem MQTT-Broker kommuniziert. Diese Beschreibung umfasst:
- MQTT-Topic-Struktur  
- Art der gesendeten Nachrichten (Payload)  
- Ereignisdefinition: wann genau der ESP32 eine Nachricht senden soll  

**Ziel:**  
Eine klare Schnittstellenbeschreibung, die auch andere Teammitglieder verstehen und weiterverwenden können.

---

## 5. MQTT Verbindung programmieren zum ESP32
**Beschreibung:**  
Ich habe die eigentliche Verbindung zwischen ESP32 und MQTT-Broker implementiert. Dazu gehörten:
- WLAN-Verbindung herstellen  
- MQTT-Client konfigurieren  
- Reconnect-Logik implementieren  
- Senden von Nachrichten basierend auf dem Tasterstatus  

**Ziel:**  
Der ESP32 soll zuverlässig MQTT-Nachrichten an den Broker übertragen.

---

## 6. Taster mit MQTT Verbindung finalisieren
**Beschreibung:**  
Im letzten Schritt habe ich die Integration abgeschlossen:
- Prüfen, ob der Taster zuverlässig Events auslöst  
- Optimieren der Nachrichtenübertragung (z. B. Entprellung)  
- Finaler Test: Taster drücken → MQTT-Nachricht am Laptop sichtbar  

**Ziel:**  
Ein vollständiges, funktionierendes Teilsystem, das korrekt in das Gesamtprojekt eingebunden werden kann.