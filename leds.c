/********************************************************************************
* led.c: Funktionsdefinitioner för styrning av lysdioderna.
********************************************************************************/
#include "header.h"

static uint16_t speed_ms = 0;
/********************************************************************************
* led_toggle: Togglar angiven lysdiod.
********************************************************************************/
void led_toggle(void)
{
	leds_enabled = !leds_enabled;
	speed_ms = 0;
	if(!leds_enabled) LEDS_OFF;
	return;
}
/********************************************************************************
*leds_blink_sequence:  Genererar sekventiell blinkning av lysdioder.
*
*                      - blink_speed_ms: Blinkhastighet i millisekunder.
********************************************************************************/
void leds_blink_sequence(const uint16_t blink_speed_ms)
{
    if(!leds_enabled) return;
	
	else
	{
		speed_ms = blink_speed_ms;
		LED1_ON;
		LED2_OFF;
		LED3_OFF;
		delay_ms(&speed_ms);

		LED1_OFF;
		LED2_ON;
		LED3_OFF;
		delay_ms(&speed_ms);

		LED1_OFF;
		LED2_OFF;
		LED3_ON;
		delay_ms(&speed_ms);
		LEDS_OFF;
	}
	return;
}


/********************************************************************************
* delay_ms: Genererar angiven fördröjning mätt i millsekunder.
*
*           - delay_time_ms: Fördröjningstid mätt i millisekunder.
********************************************************************************/
void delay_ms(const volatile uint16_t* blink_speed_ms)
{
	for (uint16_t i = 0; i < *blink_speed_ms; ++i)
	{
		_delay_ms(1);
	}

	return;
}