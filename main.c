#include    "stc8a8k64d4.h"
#include    "string.h"
/****************** 库函数头文件 *******************/
#include    "config.h"
#include    "STC8A_GPIO.h"
#include	"STC8A_Delay.h"
/**************** 用户函数头文件 *******************/
#include    "oled.h"
#include    "timer.h"
#include    "ADC.h"    
#include    "uart.h"
/********************* 变量定义 *******************/
u8 xdata FlagOfCOM1 = 0;
u8 xdata FinishOfADC = 1;
u8 COMCnt = 0;

u16 ADCValue[10] = {0};
u8 xdata FlagOfGroup = 0;
u16 xdata ADCValueCOM1[9] = {0};
u16 xdata ADCValueCOM2[9] = {0};
u16 xdata ADCValueCOM3[9] = {0};

extern u16 Timer0_Count;
/*
    高电平持续时间约8.7ms
    在这段时间内完成9个通道的测量
    假设9个通道的测量在4ms内完成
    则ADC频率要达到2250Hz
*/

/******************* IO配置函数 *******************/
void	GPIO_config(void)
{
    //OLED IO初始化 P5.4 P5.5设置为准双向口
    P5_MODE_IO_PU(GPIO_Pin_4);      
    P5_MODE_IO_PU(GPIO_Pin_5);
    
    //ADC IO初始化
	P0_MODE_IN_HIZ(GPIO_Pin_LOW | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6);		//P0.0~P0.6 设置为高阻输入
	P1_MODE_IN_HIZ(GPIO_Pin_All);		//P1.0~P1.7 设置为高阻输入
	P3_MODE_IO_PU(GPIO_Pin_0 | GPIO_Pin_1);	//P3.0,P3.1 设置为准双向口
}

void main()
{
//    AUXR &= !EXTRAM;        //允许访问内部XRAM
    EAXSFR();       //使用XSFR
    
    //初始化代码
    
    ADC_config();           //初始化ADC
    delay_ms(20);
    
    UART_config();          //初始化串口
    Timer_config();         //初始化定时器
    //开启总中断
    EA = 1;
    
    //初始化OLED
    OLED_Init();			
    OLED_Clear();

    ADC_CONTR = (ADC_CONTR & 0xf0) | ADC_START | 0;     //通道0            

    while(1)
    {
        u8 i;

//        printf("%d,%d,%d,%d,%d,%d,%d\n", ADCValueCOM2[0],ADCValueCOM2[1],ADCValueCOM2[2],ADCValueCOM2[3],ADCValueCOM2[4],ADCValueCOM2[5],ADCValueCOM2[6]);
 
        /*
            if 检测到COM1高
            then Timer0_Run(n)
            else 持续检测COM1
        */
//        printf("%d\n",ADCValue[0]);
//        if(ADCValue[0] > 1000)
//        {
//            PrintString1("1\n");
//            FlagOfCOM1 = 1;
//        }else
//        {
//            PrintString1("0\n");

//        }
        //转换完成后进行数据转移
//        if(FinishOfADC)
//        {
//            if(Timer0_Count > 194)
//            {
//                memcpy(ADCValueCOM3, &ADCValue[1], 9);
//            }else if(Timer0_Count > 107)
//            {
//                memcpy(ADCValueCOM2, &ADCValue[1], 9);
//            }else if(Timer0_Count > 20)
//            {
//                memcpy(ADCValueCOM1, &ADCValue[1], 9);
//            }
//        }

    }
}
