#include <Arduino.h>

void setup() {
  Serial.begin(9600);
  
  // int
  int intValue = 42; 
  Serial.print("Int value: ");
  Serial.println(intValue, BIN);
  
  // unsigned int
  unsigned int uintValue = 42; 
  Serial.print("Unsigned int value: ");
  Serial.println(uintValue, BIN);
  
  // long
  long longValue = 100000L; 
  Serial.print("Long value: ");
  Serial.println(longValue, BIN);
  
  // unsigned long
  unsigned long ulongValue = 100000UL;
  Serial.print("Unsigned long value: ");
  Serial.println(ulongValue, BIN);
  
  // char
  char charValue = 'A';
  Serial.print("Char value: ");
  Serial.println(charValue, BIN);
  
  // boolean
  boolean boolValue = true; 
  Serial.print("Boolean value: ");
  Serial.println(boolValue, BIN);
}

void loop() {

}