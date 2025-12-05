# Übersicht
- [Ziel der Aufgabe](#1%20ziel%20der%20aufgabe)  
- [Arduino IDE installieren](#2%20arduino%20ide%20installieren)  
- [CH340 Treiber installieren](#3%20ch340%20treiber%20installieren)  
- [ESP32 Board-Paket installieren (GUI)](#4%20esp32%20board-paket%20installieren%20(gui))  
- [ESP32 anschließen + COM-Port im Geräte-Manager prüfen](#5%20esp32%20anschließen%20+%20com-port%20im%20geräte-manager%20prüfen)  
- [Board auswählen](#6%20board%20auswählen)  
- [Testskript ausführen](#7%20testskript%20ausführen)  
- [Ergebnis](#8%20ergebnis)


---

# Lösungsansatz – Entwicklungsumgebung einrichten

## 1. Ziel der Aufgabe
Die Entwicklungsumgebung für den ESP32 muss vollständig eingerichtet werden.  
Dies umfasst:
- Installation der Arduino IDE  
- Installation des CH340-Treibers  
- Installation des ESP32 Board-Pakets  
- Anschließen und Erkennen des ESP32  
- Ausführen eines Testskripts, um die Verbindung zu prüfen  

---

## 2. Arduino IDE installieren
Die Arduino IDE ist die Software, mit der der ESP32 programmiert wird.

**Downloadlink (offizielle Arduino-Seite):**  
https://www.arduino.cc/en/software

**Vorgehen:**
1. Installer herunterladen  
2. Setup ausführen  
3. Standardoptionen bestätigen  
4. Arduino IDE starten  

---

## 3. CH340 Treiber installieren
Viele ESP32 Boards benutzen den **CH340 USB-Seriell-Chip**.  
Ohne diesen Treiber wird kein COM-Port angezeigt.

**Downloadlink (Hersteller WCH):**  
https://www.wch.cn/download/CH341SER_EXE.html

**Installation:**
1. Datei herunterladen  
2. Installer starten → „Install“  
3. Nach Erfolgsmeldung: ESP32 anschließen  
4. COM-Port sollte jetzt erscheinen  

---

## 4. ESP32 Board-Paket installieren (GUI)

### Schritt 1 – Board-URL eintragen  
Arduino IDE → **Datei → Voreinstellungen**  
Bei *Zusätzliche Boardverwalter-URLs* einfügen:
`https://espressif.github.io/arduino-esp32/package_esp32_index.json`


---

### Schritt 2 – Board-Paket installieren  
Arduino IDE → **Werkzeuge → Board → Boardverwalter**  
Im Suchfeld eingeben:
`esp32`

Dann esp32 installieren:
**„esp32 by Espressif Systems“**

---

## 5. ESP32 anschließen + COM-Port im Geräte-Manager prüfen

### ESP32 anschließen
1. ESP32 per **Micro-USB-Kabel** mit dem PC verbinden  
2. Kabel muss Daten übertragen können (keine reinen Ladekabel)

### COM-Port im Geräte-Manager prüfen  
Windows: **Win + R → devmgmt.msc**

Dann nachschauen unter:
**„Anschlüsse (COM & LPT)“**

Dort sollte z. B. erscheinen:
**USB-SERIAL CH340 (COM_)**

Falls **kein Port angezeigt wird** → CH340 Treiber prüfen.

---

## 6. Board auswählen
Nach erfolgreicher Installation des Board-Pakets:

Arduino IDE → **Werkzeuge → Board → ESP32 Arduino**

Dann auswählen:
**ESP32 Dev Module**

Damit ist die IDE korrekt auf das verwendete Entwicklungsboard eingestellt.

---

## 7. Testskript ausführen und Serial Monitor ansehen
Zur Überprüfung, ob alles funktioniert, soll das Testskript benutzt werden.

Dies befindet sich unter:
```
docs/05_tests/code/consoleTest
```

Serial Plotter öffnen:
**Rechts oben auf die Lupe drücken**