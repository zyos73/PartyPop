# Entwicklungsumgebung – ESP32 einrichten und testen

## Ziel
Die Entwicklungsumgebung für den ESP32 wird eingerichtet und mit einem Testskript überprüft.

## Verwendete Software
- Arduino IDE  
- CH340 USB-Seriell-Treiber  
- ESP32 Board-Paket (Espressif)

## Installation der Arduino IDE
Die Arduino IDE wird zum Programmieren des ESP32 verwendet.

**Download:**  
https://www.arduino.cc/en/software

**Vorgehen:**
1. Installer herunterladen  
2. Setup ausführen  
3. Standardoptionen übernehmen  
4. Arduino IDE starten  

## Installation des CH340 Treibers
Der CH340-Treiber wird benötigt, damit der ESP32 als COM-Port erkannt wird.

**Download:**  
https://www.wch.cn/download/CH341SER_EXE.html

**Vorgehen:**
1. Datei herunterladen  
2. Installer starten  
3. „Install“ auswählen  
4. ESP32 nach Abschluss anschließen  

## Installation des ESP32 Board-Pakets

### Board-URL hinzufügen
Arduino IDE → **Datei → Voreinstellungen**

Eintragen bei **Zusätzliche Boardverwalter-URLs**:
https://espressif.github.io/arduino-esp32/package_esp32_index.json

### Board-Paket installieren
Arduino IDE → **Werkzeuge → Board → Boardverwalter**

Suchbegriff:
esp32


Installieren:
**esp32 by Espressif Systems**

## ESP32 anschließen und prüfen
- ESP32 per **Micro-USB-Datenkabel** mit dem PC verbinden  

### COM-Port prüfen (Windows)
- **Win + R → devmgmt.msc**  
- **Anschlüsse (COM & LPT)**  

Erwarteter Eintrag:
USB-SERIAL CH340 (COMx)


## Board und Port auswählen
Arduino IDE:

- **Werkzeuge → Board → ESP32 Arduino → ESP32 Dev Module**  
- **Werkzeuge → Port → COMx**

## Testskript ausführen
Das Testskript dient zur Überprüfung der Verbindung.

**Pfad:**
docs/05_tests/code/consoleTest

**Hinweis:**
- Der Ordnername muss dem Namen der `.ino`-Datei entsprechen.

### Testdurchführung
1. Testskript öffnen  
2. Code auf den ESP32 hochladen  
3. **Serial Monitor / Serial Plotter** öffnen  
   - Lupe rechts oben anklicken  

## Erwartetes Ergebnis
- ESP32 wird erkannt  
- Upload ohne Fehler  
- Serielle Ausgabe sichtbar  

## Typische Fehlerquellen
- Falsches USB-Kabel  
- CH340-Treiber nicht installiert  
- Falsches Board oder Port ausgewählt  

## Fazit
Die Entwicklungsumgebung ist korrekt eingerichtet.  
Der ESP32 ist bereit für weitere Hardware- und Softwaretests.
