#include "powerbutton.h"
#include <avr/interrupt.h>

void setup() {
  SetUpPowerButton();
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  Serial.print("PCIFR: ");
  Serial.println(PCIFR, BIN);
  digitalWrite(13, HIGH);
  delay(250);
  digitalWrite(13, LOW);
  delay(250);
}
