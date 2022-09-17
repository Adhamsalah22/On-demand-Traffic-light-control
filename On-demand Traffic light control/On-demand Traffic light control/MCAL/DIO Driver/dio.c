/*
 * dio.c
 *
 * Created: 9/2/2022 9:17:05 PM
 *  Author: ADHAM ABDELAZIZ
 */ 
#include "dio.h"
#include "../../ECUAL/LED Driver/led.h"

void static (*INT0_callback)(void);

// function definition

DIO_ERROR DIO_init(uint8_t pinNumber , uint8_t portNumber , uint8_t direction){
	
	if(pinNumber > 7 || pinNumber < 0){
		return DIO_WRONG_PIN;
	}
	
	switch(portNumber){
		
		case PORT_A :
			
			if (direction == OUT)
			 {
				DDRA |= (1<<pinNumber) ;
			}
			else if (direction == IN)
			{
				DDRA &= ~(1<<pinNumber);
			}
			else{
				//error handling
				return DIO_WRONG_VALUE;
			}
			break;
			
		
		case PORT_B :
		
			if (direction == OUT)
			{
				DDRB |= (1<<pinNumber) ;
			}
			else if (direction == IN)
			{
				DDRB &= ~(1<<pinNumber);
			}
			else{
				//error handling
				return DIO_WRONG_VALUE;
			}
			break;
		
		
		case PORT_C :
		
		if (direction == OUT)
		{
			DDRC |= (1<<pinNumber) ;
		}
		else if (direction == IN)
		{
			DDRC &= ~(1<<pinNumber);
		}
		else{
			//error handling
			return DIO_WRONG_VALUE;
		}
		break;
		
		
		case PORT_D :
		
		if (direction == OUT)
		{
			DDRD |= (1<<pinNumber) ;
		}
		else if (direction == IN)
		{
			DDRD &= ~(1<<pinNumber);
		}
		else{
			//error handling
			return DIO_WRONG_VALUE;
		}
		break;
		
		default:
		return DIO_WRONG_PORT;
	}
	
	return DIO_OK;
}
DIO_ERROR DIO_write(uint8_t pinNumber , uint8_t portNumber , uint8_t value){
	
	if(pinNumber > 7 || pinNumber < 0){
		return DIO_WRONG_PIN;
	}
	
	switch(portNumber){
	
		case PORT_A :
	
		if (value == HIGH)
		{
			PORTA |= (1<<pinNumber) ;
		}
		else if (value == LOW)
		{
			PORTA &= ~(1<<pinNumber);
		}
		else{
			//error handling
			return DIO_WRONG_VALUE;
		}
		break;
	
	
		case PORT_B :
	
		if (value == HIGH)
		{
			PORTB |= (1<<pinNumber) ;
		}
		else if (value == LOW)
		{
			PORTB &= ~(1<<pinNumber);
		}
		else{
			//error handling
			return DIO_WRONG_VALUE;
		}
		break;
	
	
		case PORT_C :
	
		if (value == HIGH)
		{
			PORTC |= (1<<pinNumber) ;
		}
		else if (value == LOW)
		{
			PORTC &= ~(1<<pinNumber);
		}
		else{
			//error handling
			return DIO_WRONG_VALUE;
		}
		break;
	
	
		case PORT_D :
	
		if (value == HIGH)
		{
			PORTD |= (1<<pinNumber) ;
		}
		else if (value == LOW)
		{
			PORTD &= ~(1<<pinNumber);
		}
		else{
			//error handling
			return DIO_WRONG_VALUE;
		}
		break;
		
		default:
		return DIO_WRONG_PORT;
	}
	return DIO_OK;
}

DIO_ERROR DIO_toggle(uint8_t pinNumber , uint8_t portNumber ){
	
	if(pinNumber > 7 || pinNumber < 0){
		return DIO_WRONG_PIN;
	}
	
	switch(portNumber){
		
		case PORT_A :
		
		PORTA ^= (1<<pinNumber);
		break;
		
		
		case PORT_B :
		
		PORTB ^= (1<<pinNumber);
		break;
		
		
		case PORT_C :
		
		PORTC ^= (1<<pinNumber);
		break;
		
		
		case PORT_D :
		
		PORTD ^= (1<<pinNumber);
		break;
		
		default:
		return DIO_WRONG_PORT;
	}
	return DIO_OK;
}

DIO_ERROR DIO_read(uint8_t pinNumber , uint8_t portNumber , uint8_t* value){
	
	if(pinNumber > 7 || pinNumber < 0){
		return DIO_WRONG_PIN;
	}
	
	switch(portNumber){
		
		case PORT_A :
			*value = (PINA & (1<<pinNumber))>>pinNumber; 
			break;
			
		
		case PORT_B :
			*value = (PINB & (1<<pinNumber))>>pinNumber; 
			break;
		
		case PORT_C :
			*value = (PINC & (1<<pinNumber))>>pinNumber; 
			break;
		
		
		case PORT_D :
			*value = (PIND & (1<<pinNumber))>>pinNumber;
			break;
			
		default:
		return DIO_WRONG_PORT;
	}
	
	return DIO_OK;
}

void enable_external_INT0(void){
	
	PORTD |=(1<<2) ;
	
	GICR = 1<<INT0;
	
	MCUCR |= (1<<ISC01);
	MCUCR |= (1<<ISC00);
	sei();
}
void INT0_FUNC_CALL(void (*callback)(void)){
	
	INT0_callback = callback;
}

ISR (INT0_vect){
	
	INT0_callback();
}

