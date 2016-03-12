#include <msp430f149.h>
#include "system.h"
#include "type.h"

void Clock_Init()
{
  uint8 i;
  BCSCTL1&=~XT2OFF;                 //打开XT2振荡器
  BCSCTL2|=SELM1+SELS;              //MCLK为8MHZ，SMCLK为8MHZ
  do{
    IFG1&=~OFIFG;                   //清楚振荡器错误标志
    for(i=0;i<100;i++)
       _NOP();
  }
  while((IFG1&OFIFG)!=0);           //如果标志位1，则继续循环等待
  IFG1&=~OFIFG;
}

//IO初始化//
/*********************************************************************
 * 例如将P6口全部设置为输出模式并输出为高，如下
 * P6DIR=0xff;
 * P6OUT=0xff;
*********************************************************************/
void IO_init()
{

}
