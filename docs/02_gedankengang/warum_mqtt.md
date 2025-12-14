# Warum MQTT

## Anforderungen
Die Kommunikation sollte:
- Netzwerkbasiert sein  
- Zuverlässig funktionieren  
- Einfach erweiterbar sein  
- Für IoT-Geräte geeignet sein  

## Entscheidungskriterien

### Leichtgewichtiges Protokoll
MQTT ist für Embedded- und IoT-Geräte entwickelt.  
Geringer Overhead.  
Geeignet für ESP32 mit begrenzten Ressourcen.

### Publish/Subscribe-Prinzip
- Entkopplung von Sender und Empfänger  
- ESP32 sendet Daten, ohne den Empfänger zu kennen  
- Mehrere Clients können Daten gleichzeitig empfangen

### Zentrale Datenverteilung
- MQTT-Broker als zentrale Instanz  
- Einfache Weiterverarbeitung der Daten  
- Gute Übersicht durch Topic-Struktur

### Zuverlässigkeit
- QoS-Stufen verfügbar  
- Verbindungsüberwachung möglich  
- Reconnect-Mechanismen leicht umsetzbar

### Einfache Erweiterbarkeit
- Weitere Sensoren können Topics nutzen  
- Neue Clients ohne Codeänderung integrierbar  
- Skalierbar für größere Systeme

## Vergleich zu Alternativen
- **HTTP**: Hoher Overhead, ungeeignet für dauerhafte Verbindungen  
- **TCP/UDP direkt**: Mehr Eigenaufwand, keine Struktur  
- **WebSockets**: Komplexer für einfache Sensorik

## Ergebnis
MQTT erfüllt alle Projektanforderungen.  
Es ist effizient, stabil und gut skalierbar.

## Fazit
MQTT ist die passende Wahl für zuverlässige Kommunikation zwischen ESP32 und lokalen Systemen.