/*
 * led.h
 *
 * Created: 9/2/2022 9:28:27 PM
 *  Author: ADHAM ABDELAZIZ
 */ 


#ifndef LED_H_
#define LED_H_
#include <stdint.h>
#include "../../MCAL/DIO Driver/dio.h"


#define ON 1
#define OFF 0

typedef struct LED_t {	uint8_t ledPin , ledPort ;	}	LED;
typedef enum LED_ERROR_t { LED_OK , LED_FAILED } LED_ERROR_t;
	
LED_ERROR_t LED_init(uint8_t ledPort , uint8_t ledPin);
LED_ERROR_t LED_on (uint8_t ledPort , uint8_t ledPin);
LED_ERROR_t LED_off (uint8_t ledPort , uint8_t ledPin);
LED_ERROR_t LED_toggle (uint8_t ledPort , uint8_t ledPin);

/************************* same functions as above but for structs *******************************/


LED_ERROR_t LED_init_t(LED* led);
LED_ERROR_t LED_on_t (LED* led);
LED_ERROR_t LED_off_t (LED* led);
LED_ERROR_t LED_toggle_t (LED* led);

#endif /* LED_H_ */