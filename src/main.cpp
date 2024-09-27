#include <Arduino.h>

const int ledPin = 4;
const int buttonPin = 8;

void setup() {
  pinMode(ledPin, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}