#ifndef SRC_FLASH_H_
#define SRC_FLASH_H_
#include "type.h"


void FlashInit();	//flash��ʼ��
void FlashErase(uint16 adr);
uint8 FlashBusy();
uint8 Flash_ReadByte(uint16 Adr); // ���ֽ�
/***************************************************************************
 * ��Flash��дһ�ֽ�
 * Adr:ָ������Դ�׵�ַ
 * Adr:ָ���̵ĵ�ַ��ע�⣺����ָ������
 * DataB��Ҫ��̵��ֽ�
 ***************************************************************************/
void Flash_WriteByte(uint8 *Adr,uint16 Data_cnt,uint16 Target_Adr);
void Flash_PrtUnWB(uint16 Prt_Adrf,uint16 Prt_cnt,uint16 Prt_Adrr,uint16 DataCnt);// Protect Unwrite byte
#endif /* SRC_FLASH_H_ */
