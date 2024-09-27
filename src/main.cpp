#include <Arduino.h>

void setup() {
  Serial.begin(9600);

  // char
  Serial.print("char: ");
  char charMin = -128;
  char charMax = 127;
  Serial.print(charMin);
  Serial.print(" to ");
  Serial.println(charMax);

  // int
  Serial.println("Testing overflow...");
  int intOverflow = 32767;
  Serial.print("int before overflow: ");
  Serial.println(intOverflow);
  intOverflow++;
  Serial.print("int after overflow: ");
  Serial.println(intOverflow);

  // unsigned int
  unsigned int uintOverflow = 65535;
  Serial.print("unsigned int before overflow: ");
  Serial.println(uintOverflow);
  uintOverflow++;
  Serial.print("unsigned int after overflow: ");
  Serial.println(uintOverflow);

  // long
  long longOverflow = 2147483647;
  Serial.print("long before overflow: ");
  Serial.println(longOverflow);
  longOverflow++;
  Serial.print("long after overflow: ");
  Serial.println(longOverflow);

  // unsigned long
  unsigned long ulongOverflow = 4294967295;
  Serial.print("unsigned long before overflow: ");
  Serial.println(ulongOverflow);
  ulongOverflow++;
  Serial.print("unsigned long after overflow: ");
  Serial.println(ulongOverflow);
}

void loop() {

}