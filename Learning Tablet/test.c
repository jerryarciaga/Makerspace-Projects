/*
    Project: Learning Tablet Two-Button Switch
    Microcontroller: Arduino Mega 2560
    Datasheet: https://ww1.microchip.com/downloads/en/devicedoc/atmel-2549-8-bit-avr-microcontroller-atmega640-1280-1281-2560-2561_datasheet.pdf
    
    Notes:
    On Button:  Pin A8 -> PK0 -> PCINT16
    Off Button: Pin A9 -> PK1 -> PCINT17
*/

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
