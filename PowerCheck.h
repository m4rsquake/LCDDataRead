#ifndef __POWERCHECK_H__
#define __POWERCHECK_H__

#include "stc8a8k64d4.h"
#include "oled.h"
#include <intrins.h>

#define  uchar unsigned char
#define  uint unsigned int
	

/**********用于电源电压检测***********/




/*--------------------------------------------------------------------*/
/*ADC_CONTR,ADC控制寄存器,地址0XBCH,复位值000x0000B                   */
/*  bit7    |  bit6    |bit5        | bit4   | bit3  bit2  bit1  bit0 */
/*ADC_POWER |ADC_START | ADC_FLAG   |   x    |       ADC_CHS[3:0]     */
/*--------------------------------------------------------------------*/
#define ADC_POWER 0x80   /*ADC power control bit*/
#define ADC_START 0x40   /*ADC start control bit,软件置1，硬件清0*/
#define ADC_FLAG  0x20   /*ADC complete flag，硬件置1，软件清0*/
/*ADC_CHS[3:0],ADC模拟通道选择位        */
/*ADC_CHS[3:0]:0-7,P1.0/ADC0-P1.7/ADC7  */
/*ADC_CHS[3:0]:8-14,P0.0/ADC8-P0.6/ADC14*/
/*ADC_CHS[3:0]:15,测试内部1.344V基准电压*/


/*-------------------------------------------------------------*/
/*ADC_CFG,ADC配置寄存器,地址0XDEH,复位值xx0x0000B              */
/*  bit7   |  bit6  |  bit5   | bit4  | bit3  bit2  bit1  bit0 */
/*    x    |   x    | RESFMT  |   x   |       SPEED[3:0]       */
/*-------------------------------------------------------------*/
#define RESFMT  0x20   /*ADC 转换结果格式控制位*/
/*RESFMT = 0：转换结果左对齐；RESFMT = 1：转换结果右对齐。     */
/*SPEED[3:0]:ADC时钟控制,Fadc=SYSclk/2/16/(SPEED[3:0]+1)       */

#define ADCspeed32SYSclk 0x00
#define ADCspeed64SYSclk 0x01
#define ADCspeed96SYSclk 0x02
#define ADCspeed128SYSclk 0x03
#define ADCspeed160SYSclk 0x04
#define ADCspeed192SYSclk 0x05
#define ADCspeed224SYSclk 0x06
#define ADCspeed256SYSclk 0x07
#define ADCspeed288SYSclk 0x08
#define ADCspeed320SYSclk 0x09
#define ADCspeed352SYSclk 0x0a
#define ADCspeed384SYSclk 0x0b
#define ADCspeed416SYSclk 0x0c
#define ADCspeed448SYSclk 0x0d
#define ADCspeed480SYSclk 0x0e
#define ADCspeed512SYSclk 0x0f

#define ADC_CHS_7 0x07;



void PowerCheckInit(void);
void PowerShow(void);


#endif