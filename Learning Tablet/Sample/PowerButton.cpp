#include "PowerButton.h"

// Usage:
//  #include "PowerButton.h"
//
//  void setup() {
//    SetUpPowerButton();
//    /* Rest of set up functions go here */
//   }
void SetUpPowerButton() {
  // Set Pins 18(PD3/INT3) and 19(PD2/INT2) to input
  DDRD &= ~(1 << ON_BUTTON) & ~(1 << OFF_BUTTON);
  
  // Enable interrupts for the ON and OFF buttons
  EICRA = INTERRUPT_ON_RISING_EDGE;
  EIMSK |= (1 << ON_INTERRUPT) | (1 << OFF_INTERRUPT);
  attachInterrupt(digitalPinToInterrupt(ON_BUTTON), TurnOnTablet, RISING);
  attachInterrupt(digitalPinToInterrupt(OFF_BUTTON), TurnOffTablet, RISING);
  set_sleep_mode(2); // Power Down Mode
  sei(); // Enable interrupts before starting the rest of the program

  return;
}

void TurnOnTablet() {
  _delay_ms(5);
  PORTB |= (1 << PB7);
  _delay_ms(5000);
  sleep_disable();
  // Pressing the ON Button automatically wakes the MCU from sleep
  return;
}

void TurnOffTablet() {
  _delay_ms(5);
  /* Replace line below with function/s needed to power down the Arduino (Power down message or like) */
  PORTB &= ~(1 << PB7);
  /* End Power Down Functions*/
  
  sleep_enable();
  sleep_cpu();
  sleep_disable();
  return;
}
