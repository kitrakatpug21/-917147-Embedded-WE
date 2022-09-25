/*
 * ADC_with_Interrupt_LCD.c
 *
 * Created: 18-09-2022 10:33:57 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <stdio.h>
#include "lcd4bit.h"
#include <avr/interrupt.h>
char array[10];


ISR(ADC_vect)
{
	lcd_command(0x80);
	print("Interrupt Called");
	
	lcd_command(0xC0);
	sprintf(array,"ADC:%d   ",ADC);
	print(array);
}

int main(void)
{
	DDRA = 0b00000000;
	ADMUX = 0b01000101;
	ADCSRA = 0b10001110;
	lcd_inititalize();
	sei();
	while (1)
	{
		ADCSRA = ADCSRA | 0b01000000; // Set the Start bit to 1
		// now we will wait for the flag to be Set to 1
		// once the ADIF Flag is set, Interrupt will be executed
		//_delay_ms(10);
	}
}