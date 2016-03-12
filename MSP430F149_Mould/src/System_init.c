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
	LCD_init();
	while(1);

}




