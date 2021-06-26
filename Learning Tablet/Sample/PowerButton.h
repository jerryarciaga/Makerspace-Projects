/*
    Project: Learning Tablet Two-Button Switch
    Microcontroller: Arduino Mega 2560
    Datasheet: https://ww1.microchip.com/downloads/en/devicedoc/atmel-2549-8-bit-avr-microcontroller-atmega640-1280-1281-2560-2561_datasheet.pdf
    
    Notes:
    On Button:  Pin D18 -> PD3 -> INT3
    Off Button: Pin D19 -> PD2 -> INT2
*/
#ifndef POWERBUTTON_H
#define POWERBUTTON_H

#include <Arduino.h>

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

// On Button
#define POWER_ON_BUTTON  PD3
#define ON_BUTTON 18
#define ON_INTERRUPT INT3

// Off Button
#define POWER_OFF_BUTTON PD2
#define OFF_BUTTON 19
#define OFF_INTERRUPT INT2

#define INTERRUPT_ON_RISING_EDGE 0b11110000

void SetUpPowerButton();
void TurnOnTablet();
void TurnOffTablet();

#endif
