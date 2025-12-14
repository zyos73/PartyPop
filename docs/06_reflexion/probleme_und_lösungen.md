# Probleme und Lösungen

## Treiberproblem (CH340)
Beim ersten Einrichten wurde der ESP32 nicht als COM-Port erkannt.  
Ursache war ein falsch heruntergeladener bzw. inkompatibler CH340-Treiber.

### Ursache
Es wurde ein Treiber installiert, der nicht zum Betriebssystem passte.  
Dadurch erschien kein COM-Port im Geräte-Manager.

### Lösung
Der korrekte CH340-Treiber von der offiziellen WCH-Seite wurde installiert.  
Nach einem Neustart wurde der ESP32 korrekt als  
`USB-SERIAL CH340 (COMx)` erkannt.

---

## MQTT-Verbindungsproblem (Broker-IP)
Der ESP32 konnte keine Verbindung zum MQTT-Broker herstellen, wenn als Adresse `0.0.0.0` verwendet wurde.

### Ursache
`0.0.0.0` ist nur eine Listen-Adresse für Server.  
Clients können sich nicht aktiv zu dieser Adresse verbinden.

### Lösung
Die tatsächliche IP-Adresse des Laptops im lokalen Netzwerk wurde verwendet  
(z. B. `192.168.x.x`).

Zusätzlich musste die Mosquitto-Konfigurationsdatei angepasst werden, damit der Broker Verbindungen aus dem Netzwerk akzeptiert.

---

## Anpassung der Mosquitto-Konfiguration
Die Datei `mosquitto.conf` wurde manuell bearbeitet.

### Änderungen
Der Broker wurde so konfiguriert, dass er:
- auf der richtigen Netzwerk-Schnittstelle lauscht  
- Verbindungen aus dem lokalen Netzwerk akzeptiert  

Nach dem Neustart des Mosquitto-Dienstes war eine erfolgreiche MQTT-Verbindung möglich.

---

## Ergebnis
Nach Korrektur des Treibers und Anpassung der MQTT-Konfiguration:
- ESP32 wird zuverlässig erkannt  
- MQTT-Verbindung funktioniert stabil  
- Nachrichten werden korrekt übertragen
