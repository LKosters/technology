#include <Arduino.h>

void setup() {
  Serial.begin(9600);

  // int
  int temperature = -20; 
  Serial.print("int temperature: ");
  Serial.println(temperature);

  // unsigned int
  unsigned int distance = 3000; 
  Serial.print("unsigned int distance: ");
  Serial.println(distance);

  // long
  long largeNumber = 100000L;
  Serial.print("long largeNumber: ");
  Serial.println(largeNumber);

  // unsigned long
  unsigned long timeElapsed = millis(); 
  Serial.print("unsigned long timeElapsed (ms): ");
  Serial.println(timeElapsed);

  // float
  float voltage = 3.14; 
  Serial.print("float voltage: ");
  Serial.println(voltage, 2);

  // double 
  double preciseValue = 3.14159; 
  Serial.print("double preciseValue: ");
  Serial.println(preciseValue, 5);

  // char
  char letter = 'A'; 
  Serial.print("char letter: ");
  Serial.println(letter);

  // boolean
  boolean isPressed = true; 
  Serial.print("boolean isPressed: ");
  Serial.println(isPressed);

  // int
  const int ledPin = 13; 
  Serial.print("const ledPin: ");
  Serial.println(ledPin);
}

void loop() {
  
}