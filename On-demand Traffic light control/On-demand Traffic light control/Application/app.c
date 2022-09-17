/*
 * app.c
 *
 * Created: 9/2/2022 9:15:00 PM
 *  Author: ADHAM ABDELAZIZ
 */ 

#include "app.h"

#define F_CPU 4000000

#include <avr/io.h>
#include <avr/interrupt.h>

#include "../MCAL/TIMER Driver/timer.h"
#include "../ECUAL/LED Driver/led.h"
#include "../MCAL/DIO Driver/dio.h"


LED cars_traffic_lights [] = {{0 ,PORT_A} , {1,PORT_A} , {2,PORT_A} , {1,PORT_A}};
LED pedestrian_traffic_lights [] = {{0,PORT_B} , {1,PORT_B} , {2,PORT_B} , {1,PORT_B}};

uint8_t current_light = 0 , last_light = 0;

uint8_t volatile counter =0;



void app_Start (void){
	
	if ( initialize_leds() != APP_OK ) { return; }

	TIMER_FUNC_CALL(traffic_orgnization);
	INT0_FUNC_CALL(pedestrian_mode);
	
	enable_external_INT0();
	TIMER0_init();
	
	traffic_orgnization();
	
	while(1){
		change_turn();
	}
	
}



void traffic_orgnization (void) {
	

	
	if (current_light ==1 || current_light ==3 )
	{
		
		LED_toggle_t(&cars_traffic_lights [ current_light ]);
		LED_on_t(&cars_traffic_lights[last_light]);
		
		LED_toggle_t(&pedestrian_traffic_lights [ current_light ]);
		LED_on_t(&pedestrian_traffic_lights[last_light]);
	}
	else {
		turn_all_leds_off();
		LED_on_t(&cars_traffic_lights [ current_light ]);
		LED_on_t(&pedestrian_traffic_lights [ current_light ]);
	}
	
	
	counter ++;
	
}

void change_turn (void){
	
	if (counter == 5)
	{
		last_light = current_light;
		current_light ++;
		current_light %= 4;

		counter = 0;
	}
	
}



APP_ERROR_t initialize_leds (void){
	
	for (int i=0 ; i < 4 ; i++)
	{
		if (( LED_init_t(&cars_traffic_lights [i]) != LED_OK ) || ( LED_init_t(&pedestrian_traffic_lights[i]) != LED_OK )) {
			return APP_FAILED ;
		}
	}
	
	return APP_OK;
}

APP_ERROR_t turn_all_leds_off(void){
	
	for (int i=0 ; i < 4 ; i++){
		
		if (( LED_off_t(&cars_traffic_lights [i]) != LED_OK ) || ( LED_off_t(&pedestrian_traffic_lights[i]) != LED_OK )){
			return APP_FAILED;
		}
	}
	
	return APP_OK;
}


void pedestrian_mode(void){
	
	if (current_light == 0)
	{
		current_light = 1;
		last_light = 0;
		counter = 0;
		
	}
	
}
