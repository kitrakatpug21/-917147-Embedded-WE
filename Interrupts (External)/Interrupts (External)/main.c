/*
 * Interrupts (External).c
 *
 * Created: 17-09-2022 10:39:19 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

ISR(INT2_vect) // Interrupt Service Routine
{
	PORTA = 0b00000011;
	_delay_ms(1000);
	PORTA = 0b00001100;
	_delay_ms(1000);
	PORTA = 0b00110000;
	_delay_ms(1000);
	PORTA = 0b11000000;
	_delay_ms(1000);
}

ISR(INT0_vect) // Interrupt Service Routine
{
	PORTA = 0b11000011;
	_delay_ms(1000);
	PORTA = 0b00111100;
	_delay_ms(1000);
	PORTA = 0b00000000;
	_delay_ms(1000);
	PORTA = 0b00011000;
	_delay_ms(1000);
	PORTA = 0b00100100;
	_delay_ms(1000);
	PORTA = 0b01000010;
	_delay_ms(1000);
	PORTA = 0b10000001;
	_delay_ms(1000);
	PORTA = 0b00000000;
	_delay_ms(1000);
}

int main(void)
{
	DDRA = 0b11111111;
    //GICR = 0b00100000; // Enabled INT2
	GICR = 0b01100000;// INT0 and 2 are enabled
	//GICR |= (1<<6); // Enabled INT0
	MCUCR = 0b00000010; // INT0 : Falling Edge Trigger
	//MCUCR |= (1<<1)|(1<<0);
	MCUCSR = 0b01000000; // INT2 : Rising Edge Trigger
	//MCUCSR |= (1<<6);
	sei(); // start interrupt request
	PORTA = 0b00000000;
    while (1) 
    {
		for (int i = 0; i <= 7; i = i + 1)
		{
			PORTA |= (1<<i);// generate pattern
			_delay_ms(100);
		}
		for (int i = 7; i >=0 ; i = i - 1)
		{
			PORTA &= ~(1<<i);// generate pattern
			_delay_ms(100);
		}
		for (int i = 7; i >= 0; i = i - 1)
		{
			PORTA |= (1<<i);// generate pattern
			_delay_ms(100);
		}
		for (int i = 0; i <= 7 ; i = i + 1)
		{
			PORTA &= ~(1<<i);// generate pattern
			_delay_ms(100);
		}
    }
}

