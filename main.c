/********************************************************************************
* main.c: Tre lysdioder anslutna till pin 8 � 10 samt en tryckknapp ansluten till
*         pin 13. Vid uppsl�ppning av tryckknappen togglas lysdioderna mellan att
          blinka i en slinga var 100:e millisekund samt vara sl�ckta. 
********************************************************************************/
#include "header.h"


int main(void)
{
    setup();
    while (1) 
    {
		leds_blink_sequence(100);
    }
	return 0;
}

