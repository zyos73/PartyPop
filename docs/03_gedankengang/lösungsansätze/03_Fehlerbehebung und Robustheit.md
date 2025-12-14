# Fehlerbehebung und Robustheit

## Ziel
Erhöhung der Stabilität und Zuverlässigkeit der ESP32-Anwendung im Betrieb.

## Ausgangslage
Während des Betriebs können WLAN- oder MQTT-Verbindungen abbrechen.  
Ohne zusätzliche Logik würde dies zu fehlgeschlagenen Datenübertragungen führen.

## Umgesetzter Lösungsansatz
Das Skript wurde so angepasst, dass Verbindungen vor jeder Datenübertragung geprüft werden.

### WLAN-Handling
- Prüfung, ob eine aktive WLAN-Verbindung besteht  
- Automatischer **Reconnect**, falls keine Verbindung vorhanden ist  

### MQTT-Handling
- Prüfung, ob eine aktive MQTT-Verbindung besteht  
- Automatischer **Reconnect** vor dem Senden von Daten  

### Sende-Logik
- Publish erfolgt **nur**, wenn WLAN **und** MQTT verbunden sind  
- Kein Sendeversuch bei Verbindungsfehlern

## Vorteile
- Stabiler Dauerbetrieb  
- Keine verlorenen Sendeversuche durch Verbindungsabbrüche  
- Automatische Wiederherstellung ohne manuelles Eingreifen  

## Typische Fehlerfälle
- WLAN kurzzeitig nicht verfügbar  
- MQTT-Broker neu gestartet  
- Netzwerkunterbrechungen  

## Ergebnis
Das System arbeitet robuster.  
Verbindungsabbrüche werden automatisch erkannt und behoben.
