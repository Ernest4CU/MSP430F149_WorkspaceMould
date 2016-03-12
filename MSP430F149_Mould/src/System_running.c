#include "System_running.h"
#include "Sys_Config.h"
#include <msp430f149.h>


void Sys_loop()
{
	while(1){
		P6OUT=~P6OUT;
		delay_ms(1000);
	}
}



