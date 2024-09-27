#include <Arduino.h>

const int buttonPin = 8;
int peopleCount = 0;

int lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);

  Serial.println("People counter system started");
}

void loop() {
  int currentButtonState = digitalRead(buttonPin);

  if (currentButtonState != lastButtonState) {
    if (currentButtonState == LOW && (millis() - lastDebounceTime > debounceDelay)) {
      peopleCount++;

      Serial.print("Person entered at time: ");
      Serial.print(millis() / 1000);
      Serial.print(" seconds. Total people: ");
      Serial.println(peopleCount);

      lastDebounceTime = millis();
    }
  }

  lastButtonState = currentButtonState;
}