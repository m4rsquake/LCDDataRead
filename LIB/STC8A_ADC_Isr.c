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

#include	"STC8A_ADC.h"
#include    "string.h"

extern u16 ADCValue[10];
extern xdata u16 ADCValueCOM1[9];
extern xdata u16 ADCValueCOM2[9];
extern xdata u16 ADCValueCOM3[9];


extern u8 xdata FlagOfCOM1;
extern u8 xdata FinishOfADC;
extern u8 xdata FlagOfGroup;

extern u16 Timer0_Count;
//========================================================================
// 函数: ADC_ISR_Handler
// 描述: ADC中断函数.
// 参数: none.
// 返回: none.
// 版本: V1.0, 2020-09-23
//========================================================================
void ADC_ISR_Handler (void) interrupt ADC_VECTOR        //16457.15KHz
{
    u16	adc;
	ADC_CONTR &= ~ADC_FLAG;			//清除中断标志
	
    if(ADCCFG &  (1<<5))		//转换结果右对齐。 
    {
        adc = ((u16)ADC_RES << 8) | ADC_RESL;
    }
    else		//转换结果左对齐。 
    {
        adc = (u16)ADC_RES;
        adc = (adc << 4) | ((ADC_RESL >> 4)&0x0f);
    }
    
    

    ADCValue[ADC_CONTR & 0x0f] = adc;
//    printf("%d\n",adc);
    printf("%d\n",ADCValue[0]);

    switch(ADC_CONTR & 0x0f)
    {
        case 0:                 //case0和9代表ADC的转换完成，其余需要进行连续转换
            if(adc > 1700)
            {
                FlagOfCOM1 = 1;
            }else
            {
                ADC_CONTR = (ADC_CONTR & 0xf0) | ADC_START | 0;     //通道0            
            }
            break;
        case 9:
            printf("666\n");

            switch(FlagOfGroup)
            {
                case 0:
                    memcpy(ADCValueCOM1, &ADCValue[1], 9);
                    break;
                case 1:
                    memcpy(ADCValueCOM2, &ADCValue[1], 9);
                    break;
                case 2:
                    memcpy(ADCValueCOM3, &ADCValue[1], 9);
                    break;
                default: break;
            }
            FinishOfADC = 1;
            break;
        default: 
            ADC_CONTR = (ADC_CONTR & 0xf0) | ADC_START | ((ADC_CONTR & 0x0f)+1);    //开始下一通道的ADC转换
            break;
    }
    //转换完成，一个高电平的转换任务完成，也许不可靠
   
}


