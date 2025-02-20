/********************************************************************************
* header.h: Inneh�ller diverse definitioner och funktionsdeklarationer f�r
*           implementering av programmet.
********************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_
#define F_CPU 16000000UL   /* Klockfrekvens. */
#include <avr/io.h>        /* Information om I/O-register s�som PORTB. */
#include <avr/interrupt.h> /* Information om avbrottsvektorer, avbrottsrutiner med mera. */
#include <util/delay.h>

/* Makrodefinitioner: */
#define LED1 0 /* Lysdiod 1 p� pin 8 / PORTB0. */
#define LED2 1 /* Lysdiod 2 p� pin 9 / PORTB1. */
#define LED3 2 /* Lysdiod 3 p� pin 10 / PORTB2. */

#define BUTTON1 5 /* Tryckknapp 1 p� pin 11 / PORTB3. */

#define LED1_ON PORTB |= (1 << LED1) /* T�nder lysdiod 1. */
#define LED2_ON PORTB |= (1 << LED2) /* T�nder lysdiod 2. */
#define LED3_ON PORTB |= (1 << LED3) /* T�nder lysdiod 3. */

#define LED1_OFF PORTB &= ~(1 << LED1) /* Sl�cker lysdiod 1. */
#define LED2_OFF PORTB &= ~(1 << LED2) /* Sl�cker lysdiod 2. */
#define LED3_OFF PORTB &= ~(1 << LED3) /* Sl�cker lysdiod 3. */

#define LEDS_ON PORTB |= ((1 << LED1) | (1 << LED2) | (1 << LED3))   /* T�nder lysdioderna. */
#define LEDS_OFF PORTB &= ~((1 << LED1) | (1 << LED2) | (1 << LED3)) /* Sl�cker lysdioderna. */



#define BUTTON1_IS_PRESSED (PINB & (1 << BUTTON1)) /* Indikerar nedtryckning av tryckknapp 1. */

/* Enumerationer: */
typedef enum { false, true } bool; /* Realiserar datatypen bool. */
extern volatile bool leds_enabled;

/* Funktionsdeklarationer: */
void setup(void);
void led_toggle(void);
void delay_ms(const volatile uint16_t* blink_speed_ms);
void leds_blink_sequence(const uint16_t blink_speed_ms);




#endif /* HEADER_H_ */