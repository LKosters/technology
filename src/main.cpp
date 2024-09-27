#include <Arduino.h>

const int buttonPinIncrease = 8; // Button to increase count
const int buttonPinDecrease = 9; // Button to decrease count
int peopleCount = 0;

int lastButtonStateIncrease = HIGH;
int lastButtonStateDecrease = HIGH;
unsigned long lastDebounceTimeIncrease = 0;
unsigned long lastDebounceTimeDecrease = 0;
unsigned long debounceDelay = 50;

void setup() {
  pinMode(buttonPinIncrease, INPUT_PULLUP);
  pinMode(buttonPinDecrease, INPUT_PULLUP);

  Serial.begin(9600);

  Serial.println("People counter system started");
}

void loop() {
  int currentButtonStateIncrease = digitalRead(buttonPinIncrease);
  int currentButtonStateDecrease = digitalRead(buttonPinDecrease);

  // increase
  if (currentButtonStateIncrease != lastButtonStateIncrease) {
    if (currentButtonStateIncrease == LOW && (millis() - lastDebounceTimeIncrease > debounceDelay)) {
      peopleCount++;

      Serial.print("Person entered at time: ");
      Serial.print(millis() / 1000);
      Serial.print(" seconds. Total people: ");
      Serial.println(peopleCount);

      lastDebounceTimeIncrease = millis();
    }
  }

  // decrease
  if (currentButtonStateDecrease != lastButtonStateDecrease) {
    if (currentButtonStateDecrease == LOW && (millis() - lastDebounceTimeDecrease > debounceDelay)) {
      if (peopleCount > 0) {
        peopleCount--;
      }

      Serial.print("Person left at time: ");
      Serial.print(millis() / 1000);
      Serial.print(" seconds. Total people: ");
      Serial.println(peopleCount);

      lastDebounceTimeDecrease = millis();
    }
  }

  lastButtonStateIncrease = currentButtonStateIncrease;
  lastButtonStateDecrease = currentButtonStateDecrease;
}