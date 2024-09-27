#include <Arduino.h>

unsigned long count = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  count++;

  Serial.print("Number of people: ");
  Serial.println(count);

  delay(1000);
}