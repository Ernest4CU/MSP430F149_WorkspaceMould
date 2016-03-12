#include "System_init.h"
#include <in430.h>
#include <msp430f149.h>
#include "lcd1602.h"
#include "system.h"
#include "Watchdog.h"
void Sys_init()
{
	Watchdog_init();
	Clock_Init();
	Port_init();
	LCD_init();

	P6DIR=0xff;
	P6OUT=0xff;

}




