/*
 * elvator.c
 *
 * Created: 28/01/2020 06:06:22 م
 * Author : mohamed khaled
 */ 

#include <avr/io.h>
#include "lcd.h"
#include "keypad.h"
#include "std_macros.h"

uint8_t currentState = '0';
int main (){
	keypad_init();
	DDRD |= (1<<7);
	lcd_init();
	_delay_ms(20);
	lcd_write(currentState);

	
	while (1){
		
		volatile enteredNum = 0  ;
		 
		do 
		{
			enteredNum = keypad_getKey();
		} while (enteredNum == 0);
		
		if (enteredNum == currentState){
			lcd_write (currentState); 
			_delay_ms(10);
			lcd_clear();
		}
		 if (enteredNum > currentState )
		{
			uint8_t i = 0;
			for (i=currentState;i<=enteredNum;i++){
				currentState = i ;
				lcd_write (currentState);
				_delay_ms(50);
				lcd_clear();
				
			}
			
			PORTD |= (1<<7); 
			_delay_ms(10);
			PORTD &= ~(1<<7);
			
		}

		if(enteredNum < currentState )
		{ 
			uint8_t i=0;

			for ( i=currentState;i>=enteredNum;i--){
				currentState = i ;
				lcd_write (currentState);
				_delay_ms(50);
				lcd_clear(); 
				

			}
			PORTD |= (1<<7);
			_delay_ms(10);
			PORTD &= ~(1<<7);

		}

	}

}