//#include "PowerCheck.h"


//void PowercheckInit(void)
//{
///*--------端口模式设置-------*/
///*  PxM1  PxM0       模式    */
///*    0     0     准双向口   */
///*    0     1     强推挽输出 */
///*    1     0     高阻输入   */
///*    1     1     开漏输出   */
///*---------------------------*/
//	//将P1.7设置为高阻输入
//	P1M1 |= 0x80;
//	P1M0 &= 0x7f;
//	
//	ADCCFG = RESFMT | ADCspeed512SYSclk; //转换结果右对齐:4bit+8bit ADC数据格式, 转换时间512SYSclk
//	ADC_CONTR = ADC_POWER | ADC_START | ADC_CHS_7;  /*START ADC7*/ 
//	EADC = 1;   /*ADC转换中断 允许*/
//	EA = 1;
//}

//void PowerShow(void)
//{
//	uchar V_f = PowerValue;
//	uchar V_b = (int)(PowerValue * 100) % 1000;
//	OLED_ShowString(0,2,"V:",16);
//	OLED_ShowNum(16,2,V_f,1,16);
//	OLED_ShowChar(32,2,'.',16);
//	OLED_ShowNum(48,2,V_b,2,16);
//}