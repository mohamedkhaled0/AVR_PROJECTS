
#ifndef KEYPAD_H_
#define KEYPAD_H_
#include <avr/io.h>

#define Not_Pressed	0

void keypad_init(void);
uint8_t keypad_getKey(void);

#endif	/*KEYPAD_H_*/
