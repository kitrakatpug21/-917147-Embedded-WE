/*
 * LCD_Print_ADCs.c
 *
 * Created: 10-09-2022 10:36:50 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "lcd4bit.h"
#include <stdio.h>

void ADC_Init(uint8_t channel)
{
	DDRA = 0b00000000;
	ADMUX = 0b01000000 | channel;
	ADCSRA = 0b10000110;
}

int ADC_GetResult()
{
	ADCSRA = ADCSRA | 0b01000000; // Set the Start bit to 1
	// now we will wait for the flag to be Set to 1
	while ((ADCSRA & 0b00010000) == 0)
	{/* wait here till conversion is complete */}
	return ADC;
}

int main(void)
{
	DDRD = 0b11111111;
	unsigned int result = 0;
	unsigned int tempr = 0;
	unsigned int voltg_d = 0;
	unsigned int voltg_f = 0;
	char buffer[16];
	char temp[16];
	char volt[16];
	lcd_inititalize();
	while (1)
	{
		ADC_Init(0);
		result = ADC_GetResult();
		// sprintf (<name_of_array>,<"string to be printed">,<variable declaration>)
		sprintf(buffer,"ADC VALUE: %d  ",result);
		tempr = result / 2;
		sprintf(temp,"TEMP: %d DEG C  ",tempr);
		print(0x80,temp);
		sprintf(volt,"Res*5: %d   ",result * 5);
		print(0xC0,volt);
		(((result*5)/1000)<=0)?sprintf(volt,"Volt: 0.%d V ",result * 5):(sprintf(volt,"Volt: %d.%d V ",(result * 5)/1000),(result * 5)-(((result * 5)/1000)*1000));//a-(a/b)*b
		print(0x90,volt);
		//print(0x80,buffer);
		//print(0x90,"                   ");
		//print(0xC0,temp);
		//print(0xD0,volt);
		_delay_ms(500);
	}
}