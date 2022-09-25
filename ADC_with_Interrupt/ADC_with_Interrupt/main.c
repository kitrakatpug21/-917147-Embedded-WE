/*
 * ADC_with_Interrupt.c
 *
 * Created: 17-09-2022 11:41:22 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

ISR(ADC_vect)
{
	PORTC = ADCL;
	PORTD = ADCH;
}

int main(void)
{
	DDRA = 0b00000000;
	ADMUX = 0b01000101;
	ADCSRA = 0b10001110;
	DDRC = 0b11111111;
	DDRD = 0b00000011;
	sei();
	while (1)
	{
		ADCSRA = ADCSRA | 0b01000000; // Set the Start bit to 1
		// now we will wait for the flag to be Set to 1
		// once the ADIF Flag is set, Interrupt will be executed
		//_delay_ms(10);
	}
}