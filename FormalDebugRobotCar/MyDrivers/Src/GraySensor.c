/**
  ******************************************************************************
  * @file    GraySensor.c
  * @author  俞立
  * @brief   灰度传感器S515驱动（基本完善） 5.3
  *
  @verbatim
	(#) S515设置
	(++)波特率115200
	(++)其余默认
	@endverbatim
	禁止触动灰度传感器上的按键，使用5V电源
	注意：7个配置函数若连续调用必须延迟，否则可能会失效
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "GraySensor.h"

/* Define\Declare ------------------------------------------------------------*/
uint8_t GraySensorReceiveBuffer[18];
uint8_t GraySensorTransferFlag, GraySensorRecieveFlag;

/**
 ******************************************************************************
 *  @defgroup 外部调用
 *  @brief
 *
**/
//灰度传感器初始化
void GraySensorInit(void)  
{
	GraySensorTransferFlag = 1;
	GraySensorRecieveFlag = 1;
	GraySensorManualConfigLight(75);
}

//配置 1~7
//******************************************************************************
//测试
void GraySensorConfigTest(void)  
{
	if(GraySensorRecieveFlag == 1)
	{
		GraySensorRecieveFlag = 0;
		if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 2) != HAL_OK)
			Error_Handler();
	}
	if(GraySensorTransferFlag == 1)
	{
		GraySensorTransferFlag = 0;
		if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorTestConfiguration, 2) != HAL_OK)
			Error_Handler();
	}
}

//自动线上亮度配置
void GraySensorConfigLineLight(void)  
{
	if(GraySensorRecieveFlag == 1)
	{
		GraySensorRecieveFlag = 0;
		if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 2) != HAL_OK)
			Error_Handler();
	}
	if(GraySensorTransferFlag == 1)
	{
		GraySensorTransferFlag = 0;
		if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorLineLightConfiguration, 2) != HAL_OK)
			Error_Handler();
	}
}

//自动地上亮度配置
void GraySensorConfigGroundLight(void)  
{
	if(GraySensorRecieveFlag == 1)
	{
		GraySensorRecieveFlag = 0;
		if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 2) != HAL_OK)
			Error_Handler();
	}
	if(GraySensorTransferFlag == 1)
	{
		GraySensorTransferFlag = 0;
		if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGroundLightConfiguration, 2) != HAL_OK)
			Error_Handler();
	}
}

//手动设置亮度  范围0-100，建议不超过75，LDO会发烫
void GraySensorManualConfigLight(uint8_t light)
{
	uint8_t GraySensorLightConfiguration[3] = {0x00, 0xc6, light};
	
	if(GraySensorRecieveFlag == 1)
	{
		GraySensorRecieveFlag = 0;
		if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 2) != HAL_OK)
			Error_Handler();
	}
	if(GraySensorTransferFlag == 1)
	{
		GraySensorTransferFlag = 0;
		if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorLightConfiguration, 3) != HAL_OK)
			Error_Handler();
	}
}

//自动设置线AD值
void GraySensorConfigLineAd(void)  
{
	if(GraySensorRecieveFlag == 1)
	{
		GraySensorRecieveFlag = 0;
		if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 2) != HAL_OK)
			Error_Handler();
	}
	if(GraySensorTransferFlag == 1)
	{
		GraySensorTransferFlag = 0;
		if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorLineAdConfiguration, 2) != HAL_OK)
			Error_Handler();
	}
}

//自动设置地AD值
void GraySensorConfigGroundAd(void)  
{
	if(GraySensorRecieveFlag == 1)
	{
		GraySensorRecieveFlag = 0;
		if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 2) != HAL_OK)
			Error_Handler();
	}
	if(GraySensorTransferFlag == 1)
	{
		GraySensorTransferFlag = 0;
		if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGroundAdConfiguration, 2) != HAL_OK)
			Error_Handler();
	}
}

//手动设置某一路AD阈值（num = 1~15）
void GraySensorManualConfigThresholdValue(uint8_t num, uint8_t threshold)  
{
	uint8_t GraySensorThresholdValueConfiguration[4] = {0x00, 0xc7, num, threshold};
	
	if(GraySensorRecieveFlag == 1)
	{
		GraySensorRecieveFlag = 0;
		if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 2) != HAL_OK)
			Error_Handler();
	}
	if(GraySensorTransferFlag == 1)
	{
		GraySensorTransferFlag = 0;
		if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorThresholdValueConfiguration, 4) != HAL_OK)
			Error_Handler();
	}
}


//数据读取 8~13
//******************************************************************************
//读取15路阈值
void GraySensorFifteenThresholdValueGet(void)  
{
	if(GraySensorRecieveFlag == 1)
	{
		GraySensorRecieveFlag = 0;
		if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 18) != HAL_OK)
			Error_Handler();
	}
	if(GraySensorTransferFlag == 1)
	{
		GraySensorTransferFlag = 0;
		if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGetFifteenThresholdValue, 2) != HAL_OK)
			Error_Handler();
	}
}

//读取15路设置线值
void GraySensorFifteenLineValueGet(void)  
{
	if(GraySensorRecieveFlag == 1)
	{
		GraySensorRecieveFlag = 0;
		if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 18) != HAL_OK)
			Error_Handler();
	}
	if(GraySensorTransferFlag == 1)
	{
		GraySensorTransferFlag = 0;
		if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGetFifteenLineValue, 2) != HAL_OK)
			Error_Handler();
	}
}

//读取15路设置地值
void GraySensorFifteenGroundValueGet(void)  
{
	if(GraySensorRecieveFlag == 1)
	{
		GraySensorRecieveFlag = 0;
		if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 18) != HAL_OK)
			Error_Handler();
	}
	if(GraySensorTransferFlag == 1)
	{
		GraySensorTransferFlag = 0;
		if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGetFifteenGroundValue, 2) != HAL_OK)
			Error_Handler();
	}
}

//读取15路数字量
void GraySensorFifteenDigitalValueGet(void)  
{
	if(GraySensorRecieveFlag == 1)
	{
		GraySensorRecieveFlag = 0;
		if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 5) != HAL_OK)
			Error_Handler();
	}
	if(GraySensorTransferFlag == 1)
	{
		GraySensorTransferFlag = 0;
		if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGetFifteenDigitalValue, 2) != HAL_OK)
			Error_Handler();
	}
}

//读取15路模拟量
void GraySensorFifteenAnalogValueGet(void)  
{
	if(GraySensorRecieveFlag == 1)
	{
		GraySensorRecieveFlag = 0;
		if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 18) != HAL_OK)
			Error_Handler();
	}
	if(GraySensorTransferFlag == 1)
	{
		GraySensorTransferFlag = 0;
		if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGetFifteenAnalogValue, 2) != HAL_OK)
			Error_Handler();
	}
}

//读取单模拟量值
void GraySensorSingleAnalogValueGet(void)  
{
	if(GraySensorRecieveFlag == 1)
	{
		GraySensorRecieveFlag = 0;
		if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 5) != HAL_OK)
			Error_Handler();
	}
	if(GraySensorTransferFlag == 1)
	{
		GraySensorTransferFlag = 0;
		if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGetFifteenSigleAnalogValue, 2) != HAL_OK)
			Error_Handler();
	}
}

uint8_t GraySensorOneOfFifteenReceiveValueGet(uint8_t num)    //读取灰度传感器15路某一位 num范围0~14
{
	if(num >= 0 && num <= 14)
		return GraySensorReceiveBuffer[num+3];
	else
		return 1;
}
