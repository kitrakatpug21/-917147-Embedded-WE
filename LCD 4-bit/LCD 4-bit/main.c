/*
 * LCD 4-bit.c
 *
 * Created: 28-08-2022 10:48:45 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "lcd4bit.h"

int main(void)
{
    DDRD = 0b11110011; // LCD Data and Command Pins
	DDRB = 0b11000011; // motor pins
	lcd_inititalize();
	
	while (1) 
    {
		lcd_command(0x80);
		print("Moving forward");
		PORTB = 0b01000001; // both motor clockwise
		_delay_ms(3000);
		lcd_command(0x01);_delay_ms(1);
		lcd_command(0x80);
		print("Moving backward");
		PORTB = 0b10000010; // both motor anti-clockwise
		_delay_ms(3000);
		lcd_command(0x01);_delay_ms(1);
		lcd_command(0x80);
		print("Moving Left");
		PORTB = 0b10000001; // 
		_delay_ms(3000);
		lcd_command(0x01);_delay_ms(1);
		lcd_command(0x80);
		print("Moving right");
		PORTB = 0b01000010; // 
		_delay_ms(3000);
		lcd_command(0x01);_delay_ms(1);
    }
}

