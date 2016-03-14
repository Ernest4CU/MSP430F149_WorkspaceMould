#include "System_running.h"

#include <msp430f149.h>

#include "Flash.h"
#include "lcd1602.h"
#include "Sys_Config.h"
#include "type.h"


void Sys_loop()
{
//	uint8 temp=*(uint8 *)(FlashB_ADR+1);
//	uint8 *p1;
//	p1=(uint8 *)FlashA_ADR;
	LCD_clear();
	LCD_write_str(LcdLine1,0,"Show Num:");
//	FlashErase(FlashB_ADR);
//	Flash_WriteByte(FlashB_ADR,'N');
//	Flash_WriteByte(FlashB_ADR+1,'N');
//	P6OUT=*(uint8 *)FlashB_ADR;
//	P6OUT=*p1;
//	LCD_write_char(LcdLine2,6,temp);
//	LCD_write_char(LcdLine2,8,*(uint8 *)FlashB_ADR);
//	delay_ms(1000);
//
//	Flash_WriteByte(FlashB_ADR,'J');
//	P6OUT=*(uint8 *)FlashB_ADR;
////	P6OUT=*p1;
//	LCD_write_char(LcdLine2,6,*(uint8 *)(FlashB_ADR+1));
//	LCD_write_char(LcdLine2,8,*(uint8 *)FlashB_ADR);
//	delay_ms(1000);
//	FlashErase(FlashB_ADR);
//	Flash_WriteByte(FlashB_ADR,'K');
//	P6OUT=*(uint8 *)FlashB_ADR;
////	P6OUT=*p1;
//	LCD_write_char(LcdLine2,6,*(uint8 *)(FlashB_ADR+1));
//	LCD_write_char(LcdLine2,8,*(uint8 *)FlashB_ADR);
//	FlashA_WriteByte(FlashA_ADR,'A');
//	LCD_write_char(LcdLine2,5,*(uint8 *)FlashA_ADR);
//	delay_ms(1000);
//	FlashA_WriteByte(FlashA_ADR,'B');
//	LCD_write_char(LcdLine2,5,*(uint8 *)FlashA_ADR);
//	delay_ms(1000);
//	FlashA_WriteByte(FlashA_ADR,'C');
//	LCD_write_char(LcdLine2,5,*(uint8 *)FlashA_ADR);
//	delay_ms(1000);
	LCD_write_char(LcdLine2,6,*(uint8 *)FlashA_ADR);
	while(1);
}



