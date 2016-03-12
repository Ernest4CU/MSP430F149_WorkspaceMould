/*
 * Flash.c
 *
 *  Created on: 2016年3月12日
 *      Author: ICUI4CU
 */
#include "Flash.h"
#include "msp430f149.h"

/***************************************************************************
 * 段擦除
 * adr:要擦除的段内的任一地址
 ***************************************************************************/
void FlashErase(uint16 Adr)
{
	uint8 *p0;
	FCTL1=FWKEY+ERASE;
	FCTL2=FWKEY+FSSEL_1+FN4;
	FCTL3=FWKEY;
	while(FlashBusy()==1);
	p0=(uint8 *)Adr;
	*p0=0;
	while(FlashBusy()==1);
	FCTL3=FWKEY+LOCK;
}

/***************************************************************************
 * 测试FLASH是否忙
 * 返回值：1：忙；2：不忙
 ***************************************************************************/
uint8 FlashBusy()
{
	if((FCTL3&BUSY)==BUSY)
		return 1;
	else
		return 0;
}

/***************************************************************************
 * 字编程
 * Adr:要编程的地址。注意：不是指针类型，应当是偶地址
 * DataW：要编程的字
 ***************************************************************************/
void Flash_WriteWord(uint16 Adr,uint16 DataW)
{
	FCTL1=FWKEY+WRT;
	FCTL2=FWKEY+FSSEL_1+FN3+FN4;	//分频为320kHz
	FCTL3=FWKEY;
	while(FlashBusy()==1);
	*((uint16 *)Adr)=DataW;
	while(FlashBusy()==1);
	FCTL1=FWKEY;
	FCTL3=FWKEY+LOCK;
}

/***************************************************************************
 * 字节编程
 * Adr:指向编程的地址。注意：不是指针类型
 * DataB：要编程的字节
 ***************************************************************************/
void Flash_WriteByte(uint16 Adr,uint8 DataB)
{
	FCTL1=FWKEY+WRT;
	FCTL2=FWKEY+FSSEL_1+FN3+FN4;	//分频为320kHz
	FCTL3=FWKEY;
	while(FlashBusy()==1);
	*((uint8 *)Adr)=DataB;
	while(FlashBusy()==1);
	FCTL1=FWKEY;
	FCTL3=FWKEY+LOCK;
}

