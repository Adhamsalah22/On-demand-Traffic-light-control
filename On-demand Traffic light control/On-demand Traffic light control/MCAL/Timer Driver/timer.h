/*
 * timer.h
 *
 * Created: 9/2/2022 9:20:58 PM
 *  Author: ADHAM ABDELAZIZ
 */ 


#ifndef TIMER_H_
#define TIMER_H_


//functions
/* TIMER0_init

** Needed 1 sec for every interrupt.
** Made the calculations to calculate the initial value in the timer register TCNT0 and how many overflows that I need to get the timing I want.
** Setting the interrupt bit of timer0 and the global interrupt.
** set the prescaler to be 1024 and start the timer.

*/

void TIMER0_init(void);

//functions
/* TIMER0_init

** Needed 1 sec for every interrupt.
** Made the calculations to calculate the initial value in the timer register TCNT0 and how many overflows that I need to get the timing I want.
** Setting the interrupt bit of timer0 and the global interrupt.
** set the prescaler to be 1024 and start the timer.

*/



/* TIMER_FUNC_CALL

** set the function that will be executed when the timer flag bit is set.
*/

void TIMER_FUNC_CALL(void (*callback)(void));



#endif /* TIMER_H_ */