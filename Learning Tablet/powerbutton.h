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

void SetUpPowerButton();
