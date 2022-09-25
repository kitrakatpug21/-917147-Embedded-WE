/*
 * LCD Interface with Motor.c
 *
 * Created: 28-08-2022 10:34:17 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

void lcd_command(uint8_t cmd)
{
	//1. Set RS Pin to 0 for config mode
	PORTC = 0b00000000;
	//2. Load the Data on PORT-D
	PORTD = cmd;
	//3. Generate the Clock Signal 0-1-0
	PORTC = 0b00000010;
	_delay_ms(10);
	PORTC = 0b00000000;
	_delay_ms(10);
}

void lcd_character(char ch)
{
	//1. Set RS Pin to 1 for character mode
	PORTC = 0b00000001;
	//2. Load the character on PORT-D
	PORTD = ch;
	//3. Generate the Clock Signal 0-1-0
	PORTC = 0b00000011;
	_delay_ms(10);
	PORTC = 0b00000001;
	_delay_ms(10);
}
void lcd_inititalize()
{
	// 1. LCD Power Up Require 300ms
	_delay_ms(300);
	//2. to setup LCD (8-bit) 16 char 2 row mode, command = 0x38
	//2. to setup LCD (8-bit) 16 char 1 row mode, command = 0x30
	//2. to setup LCD (4-bit) 16 char 2 row mode, command = 0x28
	//2. to setup LCD (4-bit) 16 char 1 row mode, command = 0x20
	lcd_command(0x38);
	//3. to setup the lcd cursors as BLINK, command = 0x0F
	//3. to setup the lcd cursors as SOLID, command = 0x0E
	//3. to setup the lcd cursors disabled, command = 0x0C
	lcd_command(0x0C);
	//4. to clear the lcd display, command = 0x01
	lcd_command(0x01);
	_delay_ms(10);
	//5. to setup lcd print in Left-Right Direction, command = 0x06
	//5. to setup lcd print in Right-Left Direction, command = 0x04
	lcd_command(0x06);
}

void print(char *xyz)
{
	while (*xyz != '\0')
	{
		lcd_character(*xyz);
		xyz++;
	}
}

int main(void)
{
    DDRC = 0b00000011; // RS and EN 
	DDRD = 0b11111111; // lcd Data Pins
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

