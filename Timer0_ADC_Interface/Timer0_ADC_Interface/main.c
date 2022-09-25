/*
 * Timer0_ADC_Interface.c
 *
 * Created: 25-09-2022 11:25:21 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

ISR(ADC_vect)
{
	OCR0 = (int)(ADC * 0.25);
}

void ADC_Init(int channel)
{
	ADMUX = 0b01000000 | channel;
	ADCSRA = 0b10001110;
}

int main(void)
{
	DDRB = 0b00001000; // PB3 as Output for OC0 pin
    TCCR0 = 0b01101010;
	// Force: No, WGM: (Fast)PWM, Output: Set on Match, Prescale: by 64
	TCNT0 = 0;
	sei();
	ADC_Init(0);
	while (1) 
    {
		ADCSRA = ADCSRA | 0b01000000; // Set the Start bit to 1
	}
}