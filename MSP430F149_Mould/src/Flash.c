/*
 * Flash.c
 *
 *  Created on: 2016��3��12��
 *      Author: ICUI4CU
 */

#include "Flash.h"

#include <msp430f149.h>

#include "lcd1602.h"
#include "type.h"

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
//
///***************************************************************************
// * �ֱ��
// * Adr:Ҫ��̵ĵ�ַ��ע�⣺����ָ�����ͣ�Ӧ����ż��ַ
// * DataW��Ҫ��̵���
// ***************************************************************************/
//void Flash_WriteWord(uint16 Adr,uint16 DataW)
//{
//	FCTL1=FWKEY+WRT;
//	FCTL3=FWKEY;
//	while(FlashBusy()==1);
//	*((uint16 *)Adr)=DataW;
//	while(FlashBusy()==1);
//	FCTL1=FWKEY;
//	FCTL3=FWKEY+LOCK;
//}
//
///***************************************************************************
// * �ֽڱ��
// * Adr:ָ���̵ĵ�ַ��ע�⣺����ָ������
// * DataB��Ҫ��̵��ֽ�
// ***************************************************************************/
//void Flash_WriteByte(uint16 Adr,uint8 DataB)
//{
//	FCTL1=FWKEY+WRT;
//	FCTL3=FWKEY;
//	while(FlashBusy()==1);
//	*((uint8 *)Adr)=DataB;
//	while(FlashBusy()==1);
//	FCTL1=FWKEY;
//	FCTL3=FWKEY+LOCK;
//}
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
void FlashAB_WriteByte(uint16 Adr,uint8 DataB)
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

/******************************************************************************
 * ��Flash��дһ�ֽ�
 * Adr:��Ҫ��ȡλ�õĵ�ַ��ע�⣺����ָ��
 ******************************************************************************/
void Flash_WriteByte(uint8 *Adr,uint16 Data_cnt,uint16 Target_Adr)
{
	uint16 Adr_f=0xffff;
	uint16 Adr_r=0x0000;
	uint8 *prt_adr;
	uint8 *src_adr;
	uint16 i;
	prt_adr=(uint8 *)Target_Adr;
	src_adr=Adr;
	if((Target_Adr<0x1100)&&(Target_Adr>0x0fff)){//����Ϣ�β�������
		//��Ҫ����Adr_f��Adr_r
		Adr_f=0x10ff-((0x10ff-Target_Adr)/128)*128;
		Adr_r=(0x10ff-Target_Adr)%128;
		//����Flash_PrtUnWB��������ı�����ݲ���ʹ��Ҫ�ı�����ݿ��޸ġ�
		Flash_PrtUnWB(Adr_f,128,Adr_r,Data_cnt);
	}else if((Target_Adr<=0xffff)&&(Target_Adr>0x10ff)){//��������˲������ݣ�������Ҫ������ò�Ҫ��flash 0x1100��0xffff�����޸����ݣ�
		//��Ҫ����Adr_f��Adr_r
		Adr_f=0xffff-((0xffff-Target_Adr)/512)*512;
		Adr_r=(0xffff-Target_Adr)%512;
		//����Flash_PrtUnWB��������ı�����ݲ���ʹ��Ҫ�ı�����ݿ��޸ġ�
		Flash_PrtUnWB(Adr_f,512,Adr_r,Data_cnt);
	}else{

	}
	//��flash��д������
	FCTL1=FWKEY+WRT;
	FCTL3=FWKEY;
	while(FlashBusy()==1);
	for(i=0;i<Data_cnt;i++){
		*prt_adr--=*src_adr++;
	}
	while(FlashBusy()==1);
	FCTL1=FWKEY;
	FCTL3=FWKEY+LOCK;
	/****************************
	 * ���Դ��룬��lcd��ʾ��ַ�ͱ�ַ
	 */
//	LCD_Hex16ToAscii(LcdLine2,0,Adr_f);
//	LCD_Hex16ToAscii(LcdLine2,7,Adr_r);
	LCD_Hex8ToAscii(LcdLine2,6,*(uint8 *)(Target_Adr-1));
	LCD_Hex8ToAscii(LcdLine2,0,*(uint8 *)Target_Adr);
}

void Flash_PrtUnWB(uint16 Prt_Adrf,uint16 Prt_cnt,uint16 Prt_Adrr,uint16 DataCnt)// Protect Unwrite byte
{
	uint16 i=0;
	uint8 *Flash_ptrAdr;
	Flash_ptrAdr=(uint8 *)Prt_Adrf;
	//1.�������ֶ����ݣ���ȫ�ֶ�����copy��������
	uint8 temp_bk[512];
	for(i=0;i<Prt_cnt;i++){
//		temp_bk[i]=Flash_ReadByte(0x1002);
		temp_bk[i]=Flash_ReadByte(i+Prt_Adrf-Prt_cnt+1);
	}
	//2.�������ֶ�
	FlashErase(Prt_Adrf);
	//3.������Ҫ�޸ĵ�����д��flash
	FCTL1=FWKEY+WRT;
	FCTL3=FWKEY;
	while(FlashBusy()==1);
	for(i=0;i<Prt_cnt;i++){
		if(!((i>=Prt_Adrr)&&(i<(Prt_Adrr+DataCnt)))){//if(!((i>=Prt_Adrr)&&(i<(Prt_Adrr+DataCnt))))
			*Flash_ptrAdr=temp_bk[Prt_cnt-i-1];
		}
		Flash_ptrAdr--;
	}
	while(FlashBusy()==1);
	FCTL1=FWKEY;
	FCTL3=FWKEY+LOCK;

	for(i=0;i<Prt_cnt;i++){
//		temp_bk[i]=Flash_ReadByte(0x1002);
		temp_bk[i]=Flash_ReadByte(i+Prt_Adrf-Prt_cnt+1);
	}
}
