/*
 * Flash.c
 *
 *  Created on: 2016年3月12日
 *      Author: ICUI4CU
 */
#include "Flash.h"
#include "msp430f149.h"

void FlashInit()
{
	FCTL2=FWKEY+FSSEL_1+FN3+FN4;	//分频为320kHz
}

/***************************************************************************
 * 段擦除
 * adr:要擦除的段内的任一地址
 ***************************************************************************/
void FlashErase(uint16 Adr)
{
	uint8 *p0;
	FCTL1=FWKEY+ERASE;
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
	FCTL3=FWKEY;
	while(FlashBusy()==1);
	*((uint8 *)Adr)=DataB;
	while(FlashBusy()==1);
	FCTL1=FWKEY;
	FCTL3=FWKEY+LOCK;
}
/******************************************************************************
 * 读字节
 * Adr:需要读取位置的地址，注意：不是指针
 ******************************************************************************/
uint8 Flash_ReadByte(uint16 Adr)
{
	return *(uint8 *)Adr;
}

/******************************************************************************
 * 向信息存储段中写一字节
 * Adr:需要读取位置的地址，注意：不是指针
 ******************************************************************************/
void FlashA_WriteByte(uint16 Adr,uint8 DataB)
{
	uint8 tempArray[128];
	uint8 *Flash_ptrA;
	uint8 i;
	Flash_ptrA=(uint8 *)0x1080;
	for(i=0;i<128;i++){                   //读取segmentA中的数据到tempArray数组中
		tempArray[i]=Flash_ReadByte(i+0x1080);
	}
	FlashErase(Adr);
	tempArray[Adr-0x1080]=DataB;
	FCTL1=FWKEY+WRT;
	FCTL3=FWKEY;
	while(FlashBusy()==1);
	for(i=0;i<128;i++){
		*Flash_ptrA++=tempArray[i];
	}
	while(FlashBusy()==1);
	FCTL1=FWKEY;
	FCTL3=FWKEY+LOCK;
}

