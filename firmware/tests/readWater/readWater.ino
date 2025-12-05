#include <Arduino.h>

#define BUTTON_PIN 14

void onWater() {
  Serial.println("Water Detected");
}

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  int state = digitalRead(BUTTON_PIN);

  if (state == LOW) {
    onWater();
  }

  delay(200);
}