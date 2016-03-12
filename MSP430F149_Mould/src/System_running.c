#include "System_running.h"

#include <msp430f149.h>

#include "lcd1602.h"
#include "Sys_Config.h"


void Sys_loop()
{
	LCD_clear();
	while(1){
		P6OUT=~P6OUT;
		delay_ms(1000);
	}
}



