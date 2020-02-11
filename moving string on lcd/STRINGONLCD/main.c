/*
 * STRINGONLCD.c
 *
 * Created: 26/07/2019 03:28:07 م
 * Author : mohamed khaled
 */ 

#include <avr/io.h>
#include "lcd.h"
#include "std_macros.h"
#include  "util/delay.h"


int main(void)
{
	char name[5] = "mooo";
    lcd_init();
    lcd_enable_cursor();
	
    while (1) 
    { 
       lcd_set_cursor(1,1);
	   lcd_puts(name);
	   _delay_ms(200);
	   lcd_clear();
	   
	    lcd_set_cursor(3,1);
	    lcd_puts(name);
		_delay_ms(200);
	    lcd_clear();
		
		 lcd_set_cursor(2,1);
		 lcd_puts(name);
		 _delay_ms(200);
		 lcd_clear();
		 
    }
}

