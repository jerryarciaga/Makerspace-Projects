#include "powerbutton.h"

ISR(PCINT2_vect) {
    cli();
    _delay_ms(5);
    if(PINK & (1<<PINK1)) { // If off button is pressed
        PORTB &= 0;
        PCMSK2 &= ~(1 << PCINT17); // Disable Off Button Interrupt
        sleep_enable();
        sei();
        sleep_cpu();
        sleep_disable();
    }
    if(PINK & (1<<PINK0)) { // If on button is pressed
        PCMSK2 |= (1 << PCINT17); // Enable Off Button Interrupt
    }
    sei();

    return;
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
    DDRK &= ~((1 << DDK0) & (1 << DDK1));

    // Enable PCINT2, then enable interrupts PCINT16 and PCINT17
    PCICR |= (1 << PCIE2);
    PCMSK2 |= (1 << PCINT16) | (1 << PCINT17);

    sei();
    // Set sleep mode
    set_sleep_mode(2); // Refer to Table 11-2

    return;
}
