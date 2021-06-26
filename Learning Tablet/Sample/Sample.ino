#include "PowerButton.h"

void setup() {
  SetUpPowerButton();

  DDRB |= 1 << DDB7;
}

void loop() {
  PORTB ^= (1 << PORTB7);
  _delay_ms(250);
}
