/*---------------------------------------------------------------------*/
/* --- STC MCU Limited ------------------------------------------------*/
/* --- STC 1T Series MCU Demo Programme -------------------------------*/
/* --- Mobile: (86)13922805190 ----------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ------------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966 ------------------------*/
/* --- Web: www.STCAI.com ---------------------------------------------*/
/* --- BBS: www.STCAIMCU.com  -----------------------------------------*/
/* --- QQ:  800003751 -------------------------------------------------*/
/* 如果要在程序中使用此代码,请在程序中注明使用了STC的资料及程序            */
/*---------------------------------------------------------------------*/

#include	"STC8A_Timer.h"
#include    "ADC.h"
#include    "uart.h"

extern u8 FlagOfCOM1;
extern u8 xdata FlagOfGroup;

extern u8 FinishOfADC;
u16 Timer0_Count = 0;
extern u16 xdata ADCValueCOM1[9];
extern u16 ADCValue[10];
//========================================================================
// 函数: Timer0_ISR_Handler
// 描述: Timer0中断函数.
// 参数: none.
// 返回: none.
// 版本: V1.0, 2020-09-23
//========================================================================
void Timer0_ISR_Handler (void) interrupt TIMER0_VECTOR		//进中断时已经清除标志 10KHz 0.1ms
{
    //COM1事件计时器
    if(FlagOfCOM1)
    {
        Timer0_Count++;
    }else
    {
        Timer0_Count = 0;
    }
    
//    if(!FlagOfCOM1 && FinishOfADC)         //持续检测COM1高电平
//    {
//        FinishOfADC = 0;
//        ADC_CONTR = (ADC_CONTR & 0xf0) | ADC_START | 0;     //通道0            
//    } 
    if(FlagOfCOM1 && FinishOfADC)                  //检测9个通道
    {
        FinishOfADC = 0;
        switch(Timer0_Count)
        {
            case 20:        //检测到COM1高电平后   20ms后   转化各通道
                FlagOfGroup = 0;
                ADC_CONTR = (ADC_CONTR & 0xf0) | ADC_START | 1;     //通道1
                break;
            case 107:       //再过8.7ms   转化各通道
                FlagOfGroup = 1;
                ADC_CONTR = (ADC_CONTR & 0xf0) | ADC_START | 1;     //通道1
                break;
            case 194:       //再过8.7ms   转化各通道
                FlagOfGroup = 2;
                ADC_CONTR = (ADC_CONTR & 0xf0) | ADC_START | 1;     //通道1
                break;
            case 294:       //再过10ms   开启COM1的检测
                FlagOfCOM1 = 0;
                FinishOfADC = 1;
                ADC_CONTR = (ADC_CONTR & 0xf0) | ADC_START | 0;     //通道0 
                break;
            default:
                break;
        }
    }
}

//========================================================================
// 函数: Timer1_ISR_Handler
// 描述: Timer1中断函数.
// 参数: none.
// 返回: none.
// 版本: V1.0, 2020-09-23
//========================================================================
void Timer1_ISR_Handler (void) interrupt TIMER1_VECTOR		//进中断时已经清除标志
{
	// TODO: 在此处添加用户代码
	P66 = ~P66;
}

//========================================================================
// 函数: Timer2_ISR_Handler
// 描述: Timer2中断函数.
// 参数: none.
// 返回: none.
// 版本: V1.0, 2020-09-23
//========================================================================
void Timer2_ISR_Handler (void) interrupt TIMER2_VECTOR		//进中断时已经清除标志
{
	// TODO: 在此处添加用户代码
	P65 = ~P65;
}

//========================================================================
// 函数: Timer3_ISR_Handler
// 描述: Timer3中断函数.
// 参数: none.
// 返回: none.
// 版本: V1.0, 2020-09-23
//========================================================================
void Timer3_ISR_Handler (void) interrupt TIMER3_VECTOR		//进中断时已经清除标志
{
	// TODO: 在此处添加用户代码
	P64 = ~P64;
}

//========================================================================
// 函数: Timer4_ISR_Handler
// 描述: Timer4中断函数.
// 参数: none.
// 返回: none.
// 版本: V1.0, 2020-09-23
//========================================================================
void Timer4_ISR_Handler (void) interrupt TIMER4_VECTOR		//进中断时已经清除标志
{
	// TODO: 在此处添加用户代码
	P63 = ~P63;
}
