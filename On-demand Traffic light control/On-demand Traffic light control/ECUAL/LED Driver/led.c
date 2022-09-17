/*
 * led.c
 *
 * Created: 9/2/2022 9:25:37 PM
 *  Author: ADHAM ABDELAZIZ
 */ 

#include "led.h"
LED_ERROR_t LED_init(uint8_t ledPort , uint8_t ledPin){
	
	if(DIO_init(ledPin , ledPort , OUT) != DIO_OK ){
		return LED_FAILED;
	}
		
	return LED_OK;
}


LED_ERROR_t LED_on (uint8_t ledPort , uint8_t ledPin){
	
	if(DIO_write(ledPin , ledPort , HIGH) != DIO_OK ){
		return LED_FAILED;
	}
	
	return LED_OK ;
}


LED_ERROR_t LED_off (uint8_t ledPort , uint8_t ledPin){
	
	if(DIO_write(ledPin , ledPort , LOW) != DIO_OK){
		return LED_FAILED;
	}
	
	return LED_OK;
}


LED_ERROR_t LED_toggle (uint8_t ledPort , uint8_t ledPin){
	
	if (DIO_toggle(ledPin , ledPort) != DIO_OK){
		return LED_FAILED ;
	}
	
	return LED_OK;
}

/************************* same functions as above but for structs *******************************/

LED_ERROR_t LED_init_t(LED* led){
	if (DIO_init(led->ledPin , led->ledPort , OUT) != DIO_OK ){
		return LED_FAILED;
	}
	
	return LED_OK;
}


LED_ERROR_t LED_on_t (LED* led){
	if (DIO_write(led->ledPin , led->ledPort , HIGH) != DIO_OK ){
		return LED_FAILED;
	}
	
	return LED_OK;
}


LED_ERROR_t LED_off_t (LED* led){
	if (DIO_write(led->ledPin , led->ledPort , LOW) != DIO_OK ){
		return LED_FAILED;
	}
	
	return LED_OK;
}


LED_ERROR_t LED_toggle_t (LED* led){
	if (DIO_toggle(led->ledPin , led->ledPort) != DIO_OK ){
		return LED_FAILED;
	}
	
	return LED_OK;
}

