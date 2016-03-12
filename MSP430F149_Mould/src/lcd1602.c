#include <msp430x14x.h>
#include "lcd1602.h"
//*************************************************************************
//			初始化IO口子程序
//*************************************************************************
void delay_ms(unsigned int x)
{
	volatile unsigned int i;
	while(x--)
		for(i=800;i>0;i--);
}
void Lcd_Portinit()
{
	LCDDATSEL = 0x00;
	LCDDATDIR = 0xFF;                   //数据口输出模式
	LCDCOMSEL = 0x00;
	LCDCOMDIR|= BIT5 + BIT6 + BIT7;     //控制口设置为输出模式
}

//***********************************************************************
//	显示屏命令写入函数
//***********************************************************************
void LCD_write_com(unsigned char com) 
{	
	RS_CLR;
	RW_CLR;
	EN_SET;
	LCDDAT = com;                 //命令写入端口
	delay_ms(5);
	EN_CLR;
}

//***********************************************************************
//	显示屏数据写入函数
//***********************************************************************
void LCD_write_data(unsigned char data) 
{
	RS_SET;
	RW_CLR;
	EN_SET;
	LCDDAT = data;                //数据写入端口
	delay_ms(5);
	EN_CLR;
}

//***********************************************************************
//	显示屏清空显示
//***********************************************************************
void LCD_clear(void) 
{
	LCD_write_com(0x01);            //清屏幕显示
	delay_ms(5);
}

//***********************************************************************
//	显示屏字符串写入函数
//***********************************************************************
void LCD_write_str(unsigned char row,unsigned char column,unsigned char *s)
{
	
    if (row == 0)
    {
    	LCD_write_com(0x80 + column);        //第一行显示
    }
    else 
    {
    	LCD_write_com(0xC0 + column);        //第二行显示
    }
    
    while (*s) 
    {
    	LCD_write_data( *s);
    	s ++;
    }
}

//***********************************************************************
//	显示屏单字符写入函数
//***********************************************************************
void LCD_write_char(unsigned char row,unsigned char column,unsigned char data)
{
	
    if (row == 0)
    {
    	LCD_write_com(0x80 + column);        //第一行显示
    }
    else 
    {
    	LCD_write_com(0xC0 + column);        //第二行显示
    }
    
    LCD_write_data(data);
}

//***********************************************************************
//	显示屏初始化函数
//***********************************************************************
void LCD_init(void) 
{
	Lcd_Portinit();
    LCD_write_com(0x38);		//显示模式设置  
    delay_ms(5);
    LCD_write_com(0x08);		//显示关闭
    delay_ms(5);
    LCD_write_com(0x01);		//显示清屏
    delay_ms(5);
    LCD_write_com(0x06);		//显示光标移动设置
    delay_ms(5);
    LCD_write_com(0x0C);		//显示开及光标设置
    delay_ms(5);
    LCD_clear();
}

//***********************************************************************
//      液晶显示界面初始化
//***********************************************************************
void LCD_Desk(void)
{    
  LCD_clear();
  LCD_write_str(0,0,"The Key Number:");
  delay_ms(250);
}

