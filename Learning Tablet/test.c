/*
    Project: Learning Tablet Two-Button Switch
    Microcontroller: Arduino Mega 2560
    Datasheet: https://ww1.microchip.com/downloads/en/devicedoc/atmel-2549-8-bit-avr-microcontroller-atmega640-1280-1281-2560-2561_datasheet.pdf
    
    Notes:
    On Button:  Pin A8 -> PK0 -> PCINT16
    Off Button: Pin A9 -> PK1 -> PCINT17
*/

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

ISR(PCINT2_vect) {
    _delay_ms(5);

    return;
}


int main() {

    // Set both ON and OFF buttons as inputs; set PCMSK
    DDRK &= ~((1 << DDK0) & (1 << DDK1));

    // Enable PCINT2, then enable interrupts PCINT16 and PCINT17
    PCICR |= (1 << PCIE2);
    PCMSK2 |= (1 << PCINT16);

    // Test function using built in LED (PB7); set as output
    DDRB |= (1 << DDB7);

    sei();
    // Set sleep mode
    set_sleep_mode(2); // Refer to Table 11-2
        
    // Simulate a microcontroller running a program (Blinking LED)
    while(1) {
        PORTB |= (1 << PB7);
        _delay_ms(250);
        PORTB &= ~(1 << PB7);
        _delay_ms(250);

        cli();
        if(PINK & (1<<PINK1)) { // If off button is pressed
            _delay_ms(10);
            sleep_enable();
            sei();
            sleep_cpu();
            sleep_disable();
        }
        sei();
    }

    return 0;
}
