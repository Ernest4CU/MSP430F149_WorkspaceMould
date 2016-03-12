2016年3月12日18:14:26
本工程用于集成MSP430F149 CCS6.1工程模板
工程结构包括：
	main	程序入口，也是程序逻辑结构的最上层
		内部包含Sys_init()函数和Sys_loop()函数，分别用来做系统的初始化和正常运行。
	interrupt	中断处理函数均在此处
	system.c	包括时钟初始化和IO初始化
		system.h对system.c中的函数进行声明
	Const.c	常数数组在此定义
		Const.h对Const.c中定义的常数数组进行extern声明
	Sys_Config.h	系统配置（CPU_F），宏定义和一些基本函数（包括循环左移，右移和延时）
	System_init.c	系统初始化函数的定义
		System_init.h系统初始化函数的声明
	System_running.c	系统正常运行时的逻辑层（在此编写正常工作逻辑）
		System_running.h Sys_loop()函数的声明，用于main.c中调用Sys_loop()函数
	type.h	定义了一系列的数据类型
	Watchdog.c	看门狗相关的函数定义
		Watchdog.h Watchdog.c中的函数进行声明
		
现有扩展模块：
	Lcd1602.c	LCD1602相关函数的定义
		LCD1602.h Lcd1602.c中的函数进行声明