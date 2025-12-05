#include <Arduino.h>

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println("This is a output on the Serial Monitor.");
  delay(1000);
}