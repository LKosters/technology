#include <Arduino.h>

unsigned long previousMillis = 0;
const long interval = 200;
bool ledState = LOW;

void setup() {
  pinMode(4, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    ledState = !ledState;

    digitalWrite(4, ledState);

    Serial.print("LED state changed at: ");
    Serial.println(currentMillis);
  }
}