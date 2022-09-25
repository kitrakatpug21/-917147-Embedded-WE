/*
 * ADC-Differential.c
 *
 * Created: 04-09-2022 10:33:39 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	DDRA = 0b00000000;// INPUT bcoz, PORTA is used as ADC (input)
	
	DDRC = 0b11111111; // PORTC + PORTD we fir 10x LEDs to generate 
	DDRD = 0b00000011; // the binary result of ADC conversion
	
	// CONFIGURATION FOR THE ADC
	//ADMUX = 0b01000000;// AVCC w/ AREF at external Voltage, LAR=0 (LSB->MSB)
					   // Sensor MUX Line is at ADC0
	ADMUX = 0b01010000;// AVCC w/ AREF at external Voltage, LAR=0 (LSB->MSB)
						// Sensor MUX Line is at Pos-Diff ADC0 Neg-Diff ADC1
	
	ADCSRA = 0b10000110; // ADEN is 1, START is at 0 for now, ADATE, ADIE is OFF
						 // ADIF Flag is not set, Prescale is by 64	
	while (1)
	{
		ADCSRA = ADCSRA | 0b01000000; // Set the Start bit to 1 0b11000110
		// now we will wait for the flag to be Set to 1			   ? (ADC START)
		while ((ADCSRA & 0b00010000) == 0)
		{//					  ? (ADIF Flag)
			// wait here till conversion is complete
		}
		PORTC = ADCL;
		PORTD = ADCH;
		_delay_ms(10);
	}
}