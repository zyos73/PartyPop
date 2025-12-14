# Hardware Grundlagen aufbauen und Testen mit dem Taster

## Ziel
Ein Taster wird an einen Arduino angeschlossen und dessen Zustand über einen digitalen Eingang ausgelesen.

## Verwendete Komponenten
- Arduino UNO  
- Taster  
- Breadboard  
- Jumperkabel  

## Schaltungsbeschreibung
- **Digital Pin 14 (A0 als Digital-Pin)** wird als Eingang verwendet  
- **GND** dient als Masse  
- Der Taster verbindet den Eingang bei Betätigung mit GND  
- Interner Pull-up-Widerstand wird genutzt

### Pinbelegung
| Arduino Pin | Verbindung |
|------------|-----------|
| D14 (A0)   | Tasterkontakt |
| GND        | Tasterkontakt |

## Funktionsprinzip
- Der Eingang ist im Ruhezustand **HIGH** durch den internen Pull-up-Widerstand  
- Beim Drücken des Tasters wird der Pin auf **LOW** gezogen  
- Kein externer Widerstand notwendig

## Arduino-Testcode
```cpp
const int buttonPin = 14; // A0 als Digital Pin

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {
    Serial.println("Taster gedrückt");
  } else {
    Serial.println("Taster nicht gedrückt");
  }

  delay(500);
}
