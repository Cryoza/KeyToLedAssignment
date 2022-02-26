/*
 * key_driver.c
 *
 * Created: 25/02/2022 11:09:55
 *  Author: Matey
 */ 
#include <avr/io.h>
#include "key_driver.h"

void init_keys() {
	DDRD &= ~(_BV(DDD3)| _BV(DDD2)); //DDD3 -> DDRD 4th and 3rd bit cleaned.
	DDRC &= ~(_BV(DDC5) | _BV(DDC4) | _BV(DDC3) | _BV(DDC2) | _BV(DDC1) | _BV(DDC0)); //DDD3 -> DDRD first to sixth bit cleaned. 0
	//pullup enabled.
	PORTD |= (_BV(PORTD3) | _BV(PORTD2)); //3th and 4th bits set.
	PORTC |= (_BV(PORTD5) | _BV(PORTD4) | _BV(PORTD3) | _BV(PORTD2) | _BV(PORTD1) | _BV(PORTD0)); //first to sixth bit set.
}

uint8_t get_key(uint8_t key_no) {
	if (key_no < 1 | key_no > 8) { 
		return -1;
	}
	else if (key_no <= 6) {
		return 0 == (PORTC & _BV(key_no - 1)); //Case for switches 0-5
		//Key pressed -> Result of AND will be 0;
	}
	else { //will be bigger than 6, less than 8
		return 0 == (PORTD & _BV(key_no - 1));
		
	}
}