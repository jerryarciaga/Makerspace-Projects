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
  attachInterrupt(digitalPinToInterrupt(ON_BUTTON), TurnOnTablet, RISING);
  attachInterrupt(digitalPinToInterrupt(OFF_BUTTON), TurnOffTablet, RISING);
  set_sleep_mode(2); // Power Down Mode
  sei(); // Enable interrupts before starting the rest of the program

  return;
}

void TurnOnTablet() {
  _delay_ms(5);
  cli(); // Disable Interrupts
  // Pressing the ON Button automatically wakes the MCU from sleep
  sei();
  return;
}

void TurnOffTablet() {
  _delay_ms(5);
  cli();
  // Insert your power down functions
  
  // Here.
  sleep_enable();
  sei();
  sleep_cpu();
  sleep_disable();
  return;
}
