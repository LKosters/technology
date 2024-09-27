#include <Arduino.h>

void setup() {
  pinMode(4, OUTPUT);
}

void loop() {
  digitalWrite(4, HIGH);
  
  delay(1000);
  
  digitalWrite(4, LOW);
  
  delay(1000);

  digitalWrite(5, HIGH);
  
  delay(1000);
  
  digitalWrite(5, LOW);

  delay(1000);  
}