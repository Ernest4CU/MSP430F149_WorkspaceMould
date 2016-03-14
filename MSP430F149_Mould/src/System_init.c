#include "System_init.h"
#include <in430.h>
#include <msp430f149.h>
#include "Flash.h"
#include "lcd1602.h"
#include "system.h"
#include "Sys_Config.h"
#include "Watchdog.h"

void Sys_init()
{
	Watchdog_init();
	Clock_Init();
	LCD_init();
	FlashInit();
	P6DIR=0xff;
	P6OUT=0xf0;
	LCD_write_str(LcdLine1,0,"System Starting");
	LCD_write_str(LcdLine2,8,"...");
	delay_ms(1000);

	_EINT();
}




