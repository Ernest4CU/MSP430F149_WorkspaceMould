#ifndef SRC_FLASH_H_
#define SRC_FLASH_H_
#include "type.h"


void FlashInit();	//flash初始化
void FlashErase(uint16 adr);
uint8 FlashBusy();
uint8 Flash_ReadByte(uint16 Adr); // 读字节
/***************************************************************************
 * 向Flash中写一字节
 * Adr:指向数据源首地址
 * Adr:指向编程的地址。注意：不是指针类型
 * DataB：要编程的字节
 ***************************************************************************/
void Flash_WriteByte(uint8 *Adr,uint16 Data_cnt,uint16 Target_Adr);
void Flash_PrtUnWB(uint16 Prt_Adrf,uint16 Prt_cnt,uint16 Prt_Adrr,uint16 DataCnt);// Protect Unwrite byte
#endif /* SRC_FLASH_H_ */
