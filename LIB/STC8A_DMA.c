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

#include "STC8A_DMA.h"
#include "STC8A_UART.h"

//========================================================================
// 函数: void DMA_ADC_Inilize(DMA_ADC_InitTypeDef *DMA)
// 描述: DMA ADC 初始化程序.
// 参数: DMA: 结构参数,请参考DMA.h里的定义.
// 返回: none.
// 版本: V1.0, 2021-05-17
//========================================================================
void DMA_ADC_Inilize(DMA_ADC_InitTypeDef *DMA)
{
	DMA_ADC_STA = 0x00;
	DMA_ADC_CHSW = DMA->DMA_Channel;
	DMA_ADC_RXA = DMA->DMA_Buffer;
	DMA_ADC_CFG2 = DMA->DMA_Times;

	if(DMA->DMA_Enable == ENABLE)		DMA_ADC_CR |= 0x80;	//使能ADC DMA
	else DMA_ADC_CR &= ~0x80;	//禁止ADC DMA
}

//========================================================================
// 函数: void DMA_M2M_Inilize(DMA_M2M_InitTypeDef *DMA)
// 描述: DMA M2M 初始化程序.
// 参数: DMA: 结构参数,请参考DMA.h里的定义.
// 返回: none.
// 版本: V1.0, 2021-05-17
//========================================================================
void DMA_M2M_Inilize(DMA_M2M_InitTypeDef *DMA)
{
	DMA_M2M_STA = 0x00;
	DMA_M2M_RXA = DMA->DMA_Rx_Buffer;
	DMA_M2M_TXA = DMA->DMA_Tx_Buffer;
	DMA_M2M_AMT = DMA->DMA_Length;
	
	if(DMA->DMA_SRC_Dir == M2M_ADDR_DEC)		DMA_M2M_CFG |= 0x20;	//数据读完后地址自减
	else DMA_M2M_CFG &= ~0x20;	//数据读完后地址自减
	if(DMA->DMA_DEST_Dir == M2M_ADDR_DEC)		DMA_M2M_CFG |= 0x10;	//数据写入后地址自减
	else DMA_M2M_CFG &= ~0x10;	//数据写入后地址自减
	
	if(DMA->DMA_Enable == ENABLE)		DMA_M2M_CR |= 0x80;	//使能M2M DMA
	else DMA_M2M_CR &= ~0x80;	//禁止M2M DMA
}

//========================================================================
// 函数: void DMA_SPI_Inilize(DMA_SPI_InitTypeDef *DMA)
// 描述: DMA SPI 初始化程序.
// 参数: DMA: 结构参数,请参考DMA.h里的定义.
// 返回: none.
// 版本: V1.0, 2021-05-17
//========================================================================
void DMA_SPI_Inilize(DMA_SPI_InitTypeDef *DMA)
{
	DMA_SPI_STA = 0x00;
	DMA_SPI_RXA = DMA->DMA_Rx_Buffer;
	DMA_SPI_TXA = DMA->DMA_Tx_Buffer;
	DMA_SPI_AMT = DMA->DMA_Length;
	
	if(DMA->DMA_SS_Sel <= SPI_SS_P35) DMA_SPI_CFG2 = (DMA_SPI_CFG2 & 0xfc) | DMA->DMA_SS_Sel;	//自动控制SS脚选择

	if(DMA->DMA_Tx_Enable == ENABLE)		DMA_SPI_CFG |= 0x40;	//使能SPI发送数据
	else DMA_SPI_CFG &= ~0x40;	//禁止SPI发送数据
	
	if(DMA->DMA_Rx_Enable == ENABLE)		DMA_SPI_CFG |= 0x20;	//使能SPI接收数据
	else DMA_SPI_CFG &= ~0x20;	//禁止SPI接收数据
	
	if(DMA->DMA_AUTO_SS == ENABLE)		DMA_SPI_CFG2 |= 0x04;	//使能SS自动控制
	else DMA_SPI_CFG2 &= ~0x04;	//禁止SS自动控制
	
	if(DMA->DMA_Enable == ENABLE)		DMA_SPI_CR |= 0x80;	//使能SPI DMA
	else DMA_SPI_CR &= ~0x80;	//禁止SPI DMA
}

//========================================================================
// 函数: void DMA_UART_Inilize(u8 UARTx, DMA_UART_InitTypeDef *DMA)
// 描述: DMA UART 初始化程序.
// 参数: UARTx: UART组号, DMA: 结构参数,请参考DMA.h里的定义.
// 返回: none.
// 版本: V1.0, 2021-05-17
//========================================================================
void DMA_UART_Inilize(u8 UARTx, DMA_UART_InitTypeDef *DMA)
{
#ifdef UART1
	if(UARTx == UART1)
	{
		DMA_UR1T_STA = 0x00;
		DMA_UR1R_STA = 0x00;
		DMA_UR1T_AMT = DMA->DMA_TX_Length;
		DMA_UR1T_TXA = DMA->DMA_TX_Buffer;
		DMA_UR1R_AMT = DMA->DMA_RX_Length;
		DMA_UR1R_RXA = DMA->DMA_RX_Buffer;

		if(DMA->DMA_TX_Enable == ENABLE)		DMA_UR1T_CR |= 0x80;	//使能ADC DMA
		else DMA_UR1T_CR &= ~0x80;	//禁止ADC DMA
		if(DMA->DMA_RX_Enable == ENABLE)		DMA_UR1R_CR |= 0x80;	//使能ADC DMA
		else DMA_UR1R_CR &= ~0x80;	//禁止ADC DMA
	}
#endif
#ifdef UART2
	if(UARTx == UART2)
	{
		DMA_UR2T_STA = 0x00;
		DMA_UR2R_STA = 0x00;
		DMA_UR2T_AMT = DMA->DMA_TX_Length;
		DMA_UR2T_TXA = DMA->DMA_TX_Buffer;
		DMA_UR2R_AMT = DMA->DMA_RX_Length;
		DMA_UR2R_RXA = DMA->DMA_RX_Buffer;

		if(DMA->DMA_TX_Enable == ENABLE)		DMA_UR2T_CR |= 0x80;	//使能ADC DMA
		else DMA_UR2T_CR &= ~0x80;	//禁止ADC DMA
		if(DMA->DMA_RX_Enable == ENABLE)		DMA_UR2R_CR |= 0x80;	//使能ADC DMA
		else DMA_UR2R_CR &= ~0x80;	//禁止ADC DMA
	}
#endif
#ifdef UART3
	if(UARTx == UART3)
	{
		DMA_UR3T_STA = 0x00;
		DMA_UR3R_STA = 0x00;
		DMA_UR3T_AMT = DMA->DMA_TX_Length;
		DMA_UR3T_TXA = DMA->DMA_TX_Buffer;
		DMA_UR3R_AMT = DMA->DMA_RX_Length;
		DMA_UR3R_RXA = DMA->DMA_RX_Buffer;

		if(DMA->DMA_TX_Enable == ENABLE)		DMA_UR3T_CR |= 0x80;	//使能ADC DMA
		else DMA_UR3T_CR &= ~0x80;	//禁止ADC DMA
		if(DMA->DMA_RX_Enable == ENABLE)		DMA_UR3R_CR |= 0x80;	//使能ADC DMA
		else DMA_UR3R_CR &= ~0x80;	//禁止ADC DMA
	}
#endif
#ifdef UART4
	if(UARTx == UART4)
	{
		DMA_UR4T_STA = 0x00;
		DMA_UR4R_STA = 0x00;
		DMA_UR4T_AMT = DMA->DMA_TX_Length;
		DMA_UR4T_TXA = DMA->DMA_TX_Buffer;
		DMA_UR4R_AMT = DMA->DMA_RX_Length;
		DMA_UR4R_RXA = DMA->DMA_RX_Buffer;

		if(DMA->DMA_TX_Enable == ENABLE)		DMA_UR4T_CR |= 0x80;	//使能ADC DMA
		else DMA_UR4T_CR &= ~0x80;	//禁止ADC DMA
		if(DMA->DMA_RX_Enable == ENABLE)		DMA_UR4R_CR |= 0x80;	//使能ADC DMA
		else DMA_UR4R_CR &= ~0x80;	//禁止ADC DMA
	}
#endif
}

//========================================================================
// 函数: void DMA_LCM_Inilize(DMA_LCM_InitTypeDef *DMA)
// 描述: DMA LCM 初始化程序.
// 参数: DMA: 结构参数,请参考DMA.h里的定义.
// 返回: none.
// 版本: V1.0, 2021-05-17
//========================================================================
void DMA_LCM_Inilize(DMA_LCM_InitTypeDef *DMA)
{
	DMA_LCM_STA = 0x00;
	DMA_LCM_RXA = DMA->DMA_Rx_Buffer;
	DMA_LCM_TXA = DMA->DMA_Tx_Buffer;
	DMA_LCM_AMT = DMA->DMA_Length;
	
	if(DMA->DMA_Enable == ENABLE)		DMA_LCM_CR |= 0x80;	//使能LCM DMA
	else DMA_LCM_CR &= ~0x80;	//禁止LCM DMA
}
