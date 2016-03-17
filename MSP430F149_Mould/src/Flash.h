#ifndef SRC_FLASH_H_
#define SRC_FLASH_H_
#include "type.h"


void FlashInit();	//flash初始化
void FlashErase(uint16 adr);
uint8 FlashBusy();

/***************************************************************************
 * 字编程
 * Adr:要编程的地址。注意：不是指针类型，应当是偶地址
 * DataW：要编程的字
 ***************************************************************************/
void Flash_WriteWord(uint16 Adr,uint16 DataW);

/***************************************************************************
 * 字节编程
 * Adr:指向编程的地址。注意：不是指针类型
 * DataB：要编程的字节
 ***************************************************************************/
void FlashAB_WriteByte(uint16 Adr,uint8 DataB);
void Flash_WriteByte(uint8 *Adr,uint16 Data_cnt,uint16 Target_Adr);
void Flash_PrtUnWB(uint16 Prt_Adrf,uint16 Prt_cnt,uint16 Prt_Adrr,uint16 DataCnt);// Protect Unwrite byte
#endif /* SRC_FLASH_H_ */
