/*
    Project: Learning Tablet Two-Button Switch
    Microcontroller: Arduino Mega 2560
    Datasheet: https://ww1.microchip.com/downloads/en/devicedoc/atmel-2549-8-bit-avr-microcontroller-atmega640-1280-1281-2560-2561_datasheet.pdf
    
    Notes:
    On Button:  Pin D10 -> PB4 -> PCINT4
    Off Button: Pin D11 -> PB5 -> PCINT5
*/
#ifndef POWERBUTTON_H
#define POWERBUTTON_H

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

void SetUpPowerButton();

#endif
