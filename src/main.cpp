#include <Arduino.h>

const int led1 = 4;
const int led2 = 5;
const int led3 = 6;

const int buttonPin = 8;

int currentLed = 1;

int lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);

  digitalWrite(led1, HIGH);
}

void loop() {
  int currentButtonState = digitalRead(buttonPin);

  if (currentButtonState != lastButtonState) {
    if (currentButtonState == LOW && (millis() - lastDebounceTime > debounceDelay)) {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);

      if (currentLed == 1) {
        currentLed = 2;
      } else if (currentLed == 2) {
        currentLed = 3;
      } else {
        currentLed = 1;
      }

      if (currentLed == 1) {
        digitalWrite(led1, HIGH);
      } else if (currentLed == 2) {
        digitalWrite(led2, HIGH);
      } else if (currentLed == 3) {
        digitalWrite(led3, HIGH);
      }

      lastDebounceTime = millis();
    }
  }

  lastButtonState = currentButtonState;
}