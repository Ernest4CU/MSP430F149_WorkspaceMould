#ifndef _LCD1602_H_
#define _LCD1602_H_

//��ʱ������IAR�Դ�������ʹ�õ�
#define CPU_F ((double)8000000)   //�ⲿ��Ƶ����8MHZ
//#define CPU_F ((double)32768)   //�ⲿ��Ƶ����32.768KHZ
#define delay_us(x) __delay_cycles((long)(CPU_F*(double)x/1000000.0)) 
//#define delay_ms(x) __delay_cycles((long)(CPU_F*(double)x/1000.0)) 

#define LcdLine1 0
#define LcdLine2 1

//�Զ������ݽṹ������ʹ��
#define uchar unsigned char
#define uint  unsigned int
#define ulong unsigned long

#define LCDDATSEL P4SEL
#define LCDDAT P4OUT
#define LCDDATDIR P4DIR

#define LCDCOMSEL P5SEL
#define LCDCOM P5OUT
#define LCDCOMDIR P5DIR

//12864/1602Һ�����ƹܽ�
#define RS_CLR	        LCDCOM &= ~BIT5           //RS�õ�
#define RS_SET	        LCDCOM |=  BIT5           //RS�ø�

#define RW_CLR	        LCDCOM &= ~BIT6           //RW�õ�
#define RW_SET	        LCDCOM |=  BIT6           //RW�ø�

#define EN_CLR	        LCDCOM &= ~BIT7           //E�õ�
#define EN_SET	        LCDCOM |=  BIT7           //E�ø�

#define PSB_CLR	        LCDCOM &= ~BIT0            //PSB�õͣ����ڷ�ʽ
#define PSB_SET	        LCDCOM |=  BIT0            //PSB�øߣ����ڷ�ʽ

#define RST_CLR	        LCDCOM &= ~BIT1            //RST�õ�
#define RST_SET	        LCDCOM |= BIT1             //RST�ø�

//*************************************************************************
//			��ʼ��IO���ӳ���
//*************************************************************************
void Lcd_Portinit();

//***********************************************************************
//	��ʾ������д�뺯��
//***********************************************************************
void LCD_write_com(unsigned char com) ;

//***********************************************************************
//	��ʾ������д�뺯��
//***********************************************************************
void LCD_write_data(unsigned char data) ;

//***********************************************************************
//	��ʾ�������ʾ
//***********************************************************************
void LCD_clear(void) ;
//***********************************************************************
//	��ʾ���ַ���д�뺯��
//***********************************************************************
void LCD_write_str(unsigned char row,unsigned char column,unsigned char *s) ;

//***********************************************************************
//	��ʾ�����ַ�д�뺯��
//***********************************************************************
void LCD_write_char(unsigned char row,unsigned char column,unsigned char data);


//***********************************************************************
//	��ʾ����ʼ������
//***********************************************************************
void LCD_init(void);

//***********************************************************************
//      Һ����ʾ�����ʼ��
//***********************************************************************
void LCD_Desk(void);




#endif
