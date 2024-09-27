#include <Arduino.h>

void setup() {
  pinMode(4, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(4, HIGH);
  
  Serial.print("LED ON ");

  delay(1000);
  
  digitalWrite(4, LOW);
  
  Serial.print("LED OFF ");

  delay(1000);
}