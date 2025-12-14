# Entwicklungsumgebung einrichten

## 1. Arduino IDE herunterladen
Die Arduino IDE wird benötigt, um den ESP32 zu programmieren.

Offizielle Download-Seite:  
https://www.arduino.cc/en/software/

Auf der Seite nach unten scrollen und das passende Betriebssystem auswählen.  
![](../media/arduino-ide-download-site.png)

Die heruntergeladene `.exe` Datei öffnen und dem Installationsassistenten folgen.  
![](../media/arduino-ide-installation-guide.png)

---

## 2. ESP32 Board-Paket installieren
Nach der Installation die Arduino IDE starten.

Links in der Seitenleiste auf **Boards** klicken, um den Boardmanager zu öffnen.  
Im Suchfeld **esp32** eingeben und das Paket  
**esp32 by Espressif Systems** installieren.  
![](../media/arduino-ide-board-manager.png)

---

## 3. Board auswählen
Nach der Installation das richtige Board auswählen.

Pfad in der Arduino IDE:  
**Tools → Board → esp32 → ESP32 Dev Module**  
![](../media/arduino-ide-select-board.png)

---

## 4. CH340 Treiber installieren
Viele ESP32 Boards verwenden den CH340 USB-Seriell-Chip.

Download-Seite:  
https://sparks.gogo.co.nz/ch340.html

Passenden Treiber herunterladen.  
![](../media/download-ch340-drivers.png)

ZIP-Datei entpacken und die `.exe` Datei ausführen.  
![](../media/unpack-ch340-and-install.png)

Im Installer auf **INSTALL** klicken.  
![](../media/install-ch340.png)

---

## 5. COM-Port finden und einstellen
Den **Geräte-Manager** öffnen und zu  
**Anschlüsse (COM & LPT)** wechseln.

Bei korrekter Installation erscheint ein Eintrag wie z. B.:  
**USB-SERIAL CH340 (COMx)**  
![](../media/esp32-port.png)

Anschließend zurück zur Arduino IDE wechseln und den Port auswählen:

**Tools → Port → COMx**  
![](../media/arduino-ide-select-port.png)

---

## 6. Testskript ausführen
Das Testskript dient zur Überprüfung, ob der ESP32 korrekt erkannt wird.

Das Skript aus folgendem Pfad kopieren:  
`/firmware/tests/testSerialMonitor`

Das Skript in eine `.ino` Datei einfügen.  
Wichtig: Der Ordner muss **denselben Namen wie die `.ino` Datei** haben.  
![](../media/ordner-structure-testscript.png)  
![](../media/copy-paste-testscript.png)

Den Upload starten, indem auf den Pfeil links oben geklickt wird.  
![](../media/upload-button.png)

Nach dem Upload den **Serial Monitor** rechts oben öffnen.  
![](../media/serial-monitor-button.png)
