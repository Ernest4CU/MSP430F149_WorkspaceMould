#ifndef SRC_FLASH_H_
#define SRC_FLASH_H_
#include "type.h"


void FlashInit();	//flash��ʼ��
void FlashErase(uint16 adr);
uint8 FlashBusy();

/***************************************************************************
 * �ֱ��
 * Adr:Ҫ��̵ĵ�ַ��ע�⣺����ָ�����ͣ�Ӧ����ż��ַ
 * DataW��Ҫ��̵���
 ***************************************************************************/
void Flash_WriteWord(uint16 Adr,uint16 DataW);

/***************************************************************************
 * �ֽڱ��
 * Adr:ָ���̵ĵ�ַ��ע�⣺����ָ������
 * DataB��Ҫ��̵��ֽ�
 ***************************************************************************/
void FlashAB_WriteByte(uint16 Adr,uint8 DataB);
void Flash_WriteByte(uint8 *Adr,uint16 Data_cnt,uint16 Target_Adr);
void Flash_PrtUnWB(uint16 Prt_Adrf,uint16 Prt_cnt,uint16 Prt_Adrr,uint16 DataCnt);// Protect Unwrite byte
#endif /* SRC_FLASH_H_ */
