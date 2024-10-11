#include <Arduino.h>

const int led1 = 4;
const int led2 = 5;
const int led3 = 6;

const int buttonPinIncrease = 8;
const int buttonPinDecrease = 9;

int currentLed = 1;

int lastButtonStateIncrease = HIGH;
int lastButtonStateDecrease = HIGH;

unsigned long lastDebounceTimeIncrease = 0;
unsigned long lastDebounceTimeDecrease = 0;

unsigned long debounceDelay = 50;

int maxPeople = 10;
int currentPeople = 0;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  pinMode(buttonPinIncrease, INPUT_PULLUP);
  pinMode(buttonPinDecrease, INPUT_PULLUP);

  digitalWrite(led1, HIGH);
}

void blinkRedLed(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(led1, HIGH);
    delay(500);
    digitalWrite(led1, LOW);
    delay(500);
  }
}

void loop() {
  int currentButtonStateIncrease = digitalRead(buttonPinIncrease);
  int currentButtonStateDecrease = digitalRead(buttonPinDecrease);

  if (currentButtonStateIncrease != lastButtonStateIncrease) {
    if (currentButtonStateIncrease == LOW && (millis() - lastDebounceTimeIncrease > debounceDelay)) {
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

      lastDebounceTimeIncrease = millis();
      currentPeople++;  // Verhoog het aantal mensen als er op de knop wordt gedrukt
    }
  }

  if (currentButtonStateDecrease != lastButtonStateDecrease) {
    if (currentButtonStateDecrease == LOW && (millis() - lastDebounceTimeDecrease > debounceDelay)) {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);

      if (currentLed == 1) {
        currentLed = 3;
      } else if (currentLed == 3) {
        currentLed = 2;
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

      lastDebounceTimeDecrease = millis();
      currentPeople--;  // Verlaag het aantal mensen als er op de knop wordt gedrukt
    }
  }

  if (currentPeople >= maxPeople) {
    blinkRedLed(3);  // Laat de rode LED drie keer knipperen
    currentPeople = 0;  // Reset het aantal mensen (of pas aan zoals gewenst)
  }

  lastButtonStateIncrease = currentButtonStateIncrease;
  lastButtonStateDecrease = currentButtonStateDecrease;
}
