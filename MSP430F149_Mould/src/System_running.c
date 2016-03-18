#include "System_running.h"

#include <msp430f149.h>

#include "Flash.h"
#include "lcd1602.h"
#include "Sys_Config.h"
#include "type.h"


void Sys_loop()
{
	LCD_clear();
	LCD_write_str(LcdLine1,0,"Show Num:");
//	uint8 tem[3]={0x8a,0x9b,0x7c};
	uint8 tt=0x88;
	Flash_WriteByte(&tt,1,0x107d);
	/****************************
	 * 测试代码，用lcd1602显示写入后的数据
	 */
	LCD_Hex8ToAscii(LcdLine2,0,*(uint8 *)0x107e);
	LCD_Hex8ToAscii(LcdLine2,6,*(uint8 *)0x107d);
	LCD_Hex8ToAscii(LcdLine2,12,*(uint8 *)0x107c);
	while(1);
}



