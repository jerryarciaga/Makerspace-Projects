#include <avr/io.h>
#include "powerbutton.h"

int main() {
    SetUpPowerButton(); 

    // Test function using built in LED (PB7); set as output
    DDRB |= (1 << DDB7);

    // Simulate a microcontroller running a program (Blinking LED)
    while(1) {
        PORTB |= (1 << PB7);
        _delay_ms(250);
        PORTB &= ~(1 << PB7);
        _delay_ms(250);
    }

    return 0;
}
