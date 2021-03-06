#include "Const_str.h"
#include "lcd1602.h"
#include "type.h"
#include <msp430f149.h>
#pragma vector=PORT1_VECTOR
__interrupt void External_interrupt(void)
{
	Frequency_cnt++;
	P1IFG=0;
}

// Timer A0 interrupt service routine
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=TIMERA0_VECTOR
__interrupt void Timer_A (void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(TIMERA0_VECTOR))) Timer_A (void)
#else
#error Compiler not supported!
#endif
{
	Frequency[0]=Frequency_cnt/10000|0x30;
	Frequency[1]=Frequency_cnt%10000/1000|0x30;
	Frequency[2]=Frequency_cnt%1000/100|0x30;
	Frequency[3]=Frequency_cnt%100/10|0x30;
	Frequency[4]=Frequency_cnt%10|0x30;
	LCD_write_str(0,0,(uint8 *)Frequency);
	Frequency_cnt=0;
//	LCD_write_char(0,0,'a');
}
