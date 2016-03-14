/*
 * Flash.c
 *
 *  Created on: 2016��3��12��
 *      Author: ICUI4CU
 */
#include "Flash.h"
#include "msp430f149.h"

void FlashInit()
{
	FCTL2=FWKEY+FSSEL_1+FN3+FN4;	//��ƵΪ320kHz
}

/***************************************************************************
 * �β���
 * adr:Ҫ�����Ķ��ڵ���һ��ַ
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
 * ����FLASH�Ƿ�æ
 * ����ֵ��1��æ��2����æ
 ***************************************************************************/
uint8 FlashBusy()
{
	if((FCTL3&BUSY)==BUSY)
		return 1;
	else
		return 0;
}

/***************************************************************************
 * �ֱ��
 * Adr:Ҫ��̵ĵ�ַ��ע�⣺����ָ�����ͣ�Ӧ����ż��ַ
 * DataW��Ҫ��̵���
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
 * �ֽڱ��
 * Adr:ָ���̵ĵ�ַ��ע�⣺����ָ������
 * DataB��Ҫ��̵��ֽ�
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
 * ���ֽ�
 * Adr:��Ҫ��ȡλ�õĵ�ַ��ע�⣺����ָ��
 ******************************************************************************/
uint8 Flash_ReadByte(uint16 Adr)
{
	return *(uint8 *)Adr;
}

/******************************************************************************
 * ����Ϣ�洢����дһ�ֽ�
 * Adr:��Ҫ��ȡλ�õĵ�ַ��ע�⣺����ָ��
 ******************************************************************************/
void FlashA_WriteByte(uint16 Adr,uint8 DataB)
{
	uint8 tempArray[128];
	uint8 *Flash_ptrA;
	uint8 i;
	Flash_ptrA=(uint8 *)0x1080;
	for(i=0;i<128;i++){                   //��ȡsegmentA�е����ݵ�tempArray������
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

