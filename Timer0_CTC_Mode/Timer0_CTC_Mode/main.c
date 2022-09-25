/*
 * Timer0_CTC_Mode.c
 *
 * Created: 25-09-2022 10:41:41 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL


int main(void)
{
	DDRB = 0b00001000; // PB3 as Output for OC0 pin
    TCCR0 = 0b00011001;
	// Force: No, WGM: CTC, Output: Toggle, Prescale: by 1
	TCNT0 = 0;
	
	while (1) 
    {
		if (PINA & 0b00000001)
			OCR0 = 40; // for 5us
		else
			OCR0 = 80;// for 10us
    }
}
/*
Create a Program to generate a waveform for 100us, 500us and 1ms waveform using
switch. The default state of the output should be at 1us.
*/
