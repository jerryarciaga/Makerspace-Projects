/*
    Project: Learning Tablet Two-Button Switch
    Microcontroller: Arduino Mega 2560
    Datasheet: https://ww1.microchip.com/downloads/en/devicedoc/atmel-2549-8-bit-avr-microcontroller-atmega640-1280-1281-2560-2561_datasheet.pdf
    
    Notes:
    On Button:  Pin D10 -> PB4 -> PCINT4
    Off Button: Pin D11 -> PB5 -> PCINT5
*/

#include "powerbutton.h"

ISR(PCINT0_vect) {
    cli(); // Avoid race condition
    _delay_ms(5);
    if(PINB & (1<<PINB5)) { // If off button is pressed
        PORTB &= ~(1 << PB7); // Replace with some shutdown function
        PCMSK0 &= ~(1 << PCINT5); // Disable Off Button Interrupt
        sleep_enable();
        sei();
        sleep_cpu();
        sleep_disable();
    }
    if(PINB & (1<<PINB4)) { // If on button is pressed
        PCMSK0 |= (1 << PCINT5); // Enable Off Button Interrupt
    }
    sei();
}

/*
 * Add this line like shown:
 *
 * void setup() {
 *      SetUpPowerButton();
 *
 *      // Add your setup code
 * }
 *
 */
void SetUpPowerButton() {
    // Set both ON and OFF buttons as inputs; set PCMSK
    DDRB &= ~((1 << DDK4) & (1 << DDK5));

    // Enable PCINT0, then enable interrupts PCINT4 and PCINT5
    PCICR |= (1 << PCIE0);
    PCMSK0 |= (1 << PCINT4) | (1 << PCINT5);

    // Set sleep mode
    set_sleep_mode(2); // Refer to Table 11-2
    sei();
}
