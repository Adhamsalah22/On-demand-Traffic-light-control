/*
 * dio.h
 *
 * Created: 9/2/2022 9:17:18 PM
 *  Author: ADHAM ABDELAZIZ
 */ 


#ifndef DIO_H_
#define DIO_H_

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

//macros

//direction definitions
#define IN 0
#define OUT 1

//values definitions
#define LOW 0
#define HIGH 1

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

// typedefs

typedef enum DIO_ERROR {DIO_OK , DIO_WRONG_PIN, DIO_WRONG_PORT, DIO_WRONG_VALUE}DIO_ERROR;


// functions

DIO_ERROR DIO_init(uint8_t pinNumber , uint8_t portNumber , uint8_t direction);

DIO_ERROR DIO_write(uint8_t pinNumber , uint8_t portNumber , uint8_t value);

DIO_ERROR DIO_toggle(uint8_t pinNumber , uint8_t portNumber );

DIO_ERROR DIO_read(uint8_t pinNumber , uint8_t portNumber , uint8_t* value );

/* enable_external_INT0
** enables the external interrupt in the Port d pin 2.
** set the pin to be output.
** enable the external interrupt INT0 from the register GICR.
** set the interrupt on the raising edge so that long press doesn't do anything.
*/
void enable_external_INT0(void);

/* INT0_FUNC_CALL
** setting the function that gets executed when the interrupt happens.
*/
void INT0_FUNC_CALL(void (*callback)(void));



#endif /* DIO_H_ */