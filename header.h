/********************************************************************************
* header.h: Innehåller diverse definitioner och funktionsdeklarationer för
*           implementering av programmet.
********************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_
#define F_CPU 16000000UL   /* Klockfrekvens. */
#include <avr/io.h>        /* Information om I/O-register såsom PORTB. */
#include <avr/interrupt.h> /* Information om avbrottsvektorer, avbrottsrutiner med mera. */
#include <util/delay.h>

/* Makrodefinitioner: */
#define LED1 0 /* Lysdiod 1 på pin 8 / PORTB0. */
#define LED2 1 /* Lysdiod 2 på pin 9 / PORTB1. */
#define LED3 2 /* Lysdiod 3 på pin 10 / PORTB2. */

#define BUTTON1 5 /* Tryckknapp 1 på pin 11 / PORTB3. */

#define LED1_ON PORTB |= (1 << LED1) /* Tänder lysdiod 1. */
#define LED2_ON PORTB |= (1 << LED2) /* Tänder lysdiod 2. */
#define LED3_ON PORTB |= (1 << LED3) /* Tänder lysdiod 3. */

#define LED1_OFF PORTB &= ~(1 << LED1) /* Släcker lysdiod 1. */
#define LED2_OFF PORTB &= ~(1 << LED2) /* Släcker lysdiod 2. */
#define LED3_OFF PORTB &= ~(1 << LED3) /* Släcker lysdiod 3. */

#define LEDS_ON PORTB |= ((1 << LED1) | (1 << LED2) | (1 << LED3))   /* Tänder lysdioderna. */
#define LEDS_OFF PORTB &= ~((1 << LED1) | (1 << LED2) | (1 << LED3)) /* Släcker lysdioderna. */



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