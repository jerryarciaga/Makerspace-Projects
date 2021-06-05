/*
    Project: Learning Tablet Two-Button Switch
    Microcontroller: Arduino Mega 2560
    
    Notes:
    On Button:  Pin A8 -> PK0 -> PCINT16
    Off Button: Pin A9 -> PK1 -> PCINT17
*/

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR(PCINT2_vect) {
    _delay_ms(5);
    if (PINK & (1 << PINK0)) // On Button is pressed
        PORTB |= (1 << PORTB7);
    if (PINK & (1 << PINK1)) // Off Button is pressed
        PORTB &= ~(1 << PORTB7);
}


int main() {
    // Set both ON and OFF buttons as inputs; set PCMSK
    DDRK &= ~((1 << DDK0) & (1 << DDK1));

    // Enable PCINT2, then enable interrupts PCINT16 and PCINT17
    PCICR |= (1 << PCIE2);
    PCMSK2 |= (1 << PCINT16) | (1 << PCINT17);

    // Test function using built in LED (PB7); set as output
    DDRB |= (1 << DDB7);
    
    // Set enable interrupt to use ISR code above
    sei();

    while(1);

    return 0;
}
