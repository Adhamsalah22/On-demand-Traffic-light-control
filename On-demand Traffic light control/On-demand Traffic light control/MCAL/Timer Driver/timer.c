/*
 * timer.c
 *
 * Created: 9/2/2022 9:21:19 PM
 *  Author: ADHAM ABDELAZIZ
 */ 
#include "timer.h"
#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include "../../ECUAL/LED Driver/led.h"

uint8_t i = 0;

void static (*TIMER0_callback)(void);

void TIMER0_init(void){
	
	TCNT0 = 0;
	TIMSK = 0x01;
	sei();
	
	TCCR0 = 0x05;
	
}
void TIMER_FUNC_CALL(void (*callback)(void)){

	TIMER0_callback = callback;
}

ISR(TIMER0_OVF_vect)
{
	if (i == 16)
	{
		TIMER0_callback();
	}

	i %= 16;
	
	i++;
}



