/*
 * simplecounter.c
 *
 * Created: 30/11/2019 03:41:12 م
 * Author : mohamed khaled
 */ 

#include <avr/io.h>
#include "seven_seg.h"
#include "std_macros.h"


int main(void)
{
	seven_seg_init(); 
    
    while (1) 
    {
		int c = 0 ; 
		for (c = 0 ; c < 100 ; c++){
			seven_seg_update(c); 
			_delay_ms(100);
			if (c == 99) c = 0; 
		}
		
    }
}

