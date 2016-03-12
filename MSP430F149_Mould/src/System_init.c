#include "System_init.h"
#include "Sys_Config.h"
#include "lcd1602.h"
#include "system.h"
#include "Watchdog.h"

void Sys_init()
{
	Watchdog_init();
	Clock_Init();
	LCD_init();
	LCD_write_str(LcdLine1,0,"System Starting");
	LCD_write_str(LcdLine2,8,"...");
	delay_ms(1000);
}




