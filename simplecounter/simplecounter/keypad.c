
#include "keypad.h"

uint8_t ret_arr[3][3]= {{'1','2','3'},
						{'4','5','6'},
						{'7','8','9'}};

void keypad_init(void)
{
	//set bit direction
	DDRD|=(7<<PD2);
	DDRD&=~(3<<PD5);
	DDRA&=~(1<<PA3);
	
	//enable pull-up resistor for input pins
	//initialize output pins with 1
	PORTD |= (31<<PD2);
	PORTA |= (1<<PA3);
}

uint8_t keypad_getKey(void)
{
	// All Rows is HIGH
	PORTD |= (7<<PD2);
	PORTD &=~(1<<PD2);	//Except Row1
	
	if (!(PIND & (1<<PD5)))
	{
		while(!(PIND & (1<<PD5)));
		return ret_arr[0][0];	//'1'
	}
	else if (!(PIND & (1<<PD6)))
	{
		while(!(PIND & (1<<PD6)));
		return ret_arr[0][1];	//'2'
	}
	else if (!(PINA & (1<<PA3)))
	{
		while(!(PINA & (1<<PA3)));
		return ret_arr[0][2];	//'3'
	}
	
	// All Rows is HIGH
	PORTD |= (7<<PD2);
	PORTD &=~(1<<PD3);	//Except Row2
	
	if (!(PIND & (1<<PD5)))
	{
		while(!(PIND & (1<<PD5)));
		return ret_arr[1][0];	//'4'
	}
	else if (!(PIND & (1<<PD6)))
	{
		while(!(PIND & (1<<PD6)));
		return ret_arr[1][1];	//'5'
	}
	else if (!(PINA & (1<<PA3)))
	{
		while(!(PINA & (1<<PA3)));
		return ret_arr[1][2];	//'6'
	}
	
	// All Rows is HIGH
	PORTD |= (7<<PD2);
	PORTD &=~(1<<PD4);	//Except Row3
	
	if (!(PIND & (1<<PD5)))
	{
		while(!(PIND & (1<<PD5)));
		return ret_arr[2][0];	//'7'
	}
	else if (!(PIND & (1<<PD6)))
	{
		while(!(PIND & (1<<PD6)));
		return ret_arr[2][1];	//'8'
	}
	else if (!(PINA & (1<<PA3)))
	{
		while(!(PINA & (1<<PA3)));
		return ret_arr[2][2];	//'9'
	}
	return Not_Pressed;	//no key is pressed
}