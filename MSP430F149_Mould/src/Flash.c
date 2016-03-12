/*
 * Flash.c
 *
 *  Created on: 2016��3��12��
 *      Author: ICUI4CU
 */
#include "Flash.h"
#include "msp430f149.h"

/***************************************************************************
 * �β���
 * adr:Ҫ�����Ķ��ڵ���һ��ַ
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
	FCTL2=FWKEY+FSSEL_1+FN3+FN4;	//��ƵΪ320kHz
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
	FCTL2=FWKEY+FSSEL_1+FN3+FN4;	//��ƵΪ320kHz
	FCTL3=FWKEY;
	while(FlashBusy()==1);
	*((uint8 *)Adr)=DataB;
	while(FlashBusy()==1);
	FCTL1=FWKEY;
	FCTL3=FWKEY+LOCK;
}

