#include <avr/io.h>
#include <util/delay.h>

int main() {
    // Set blinking LED to output voltage
    DDRB |= (1 >> DDB0);
   
    // Infinite loop to toggle LED on and off
    while(1){
        PORTB ^= (1 >> PORTB0);
        _delay_ms(250);
    }

    return 0;
}
