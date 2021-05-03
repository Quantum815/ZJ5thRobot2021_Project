/**
  ******************************************************************************
  * @file    GraySensor.c
  * @author  YL
  * @brief   灰度传感器S515驱动（基本完善） 5.3
  *
  @verbatim
	
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "GraySensor.h"

/* Define\Declare ------------------------------------------------------------*/
uint8_t GraySensorReceiveBuffer[18];

//数据读取指令
static uint8_t GraySensorGetFifteenThresholdValue[2] = {0x00, 0xd7};  //读取15路阈值
static uint8_t GraySensorGetFifteenLineValue[2] = {0x00, 0xd1};  //读取15路设置线值
static uint8_t GraySensorGetFifteenGroundValue[2] = {0x00, 0xd2};  //读取15路设置地值
static uint8_t GraySensorGetFifteenDigitalValue[2] = {0x00, 0xd8};  //读取15路数字量
static uint8_t GraySensorGetFifteenAnalogValue[2] = {0x00, 0xd9};  //读取15路模拟量
static uint8_t GraySensorGetFifteenSigleAnalogValue[2] = {0x00, 0xdb};  //读取单模拟量值

/**
 ******************************************************************************
 *  @defgroup 驱动
 *  @brief
 *
**/

//配置 1~7
//******************************************************************************
void GraySensorConfigTest(void)  //测试
{
	uint8_t GraySensorTestConfiguration[2] = {0x00, 0xaa};
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorTestConfiguration, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorConfigLineLight(void)  //自动线上亮度配置
{
	uint8_t GraySensorLineLightConfiguration[2] = {0x00, 0xc9};
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorLineLightConfiguration, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorConfigGroundLight(void)  //自动地上亮度配置
{
	uint8_t GraySensorGroundLightConfiguration[2] = {0x00, 0xca};
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGroundLightConfiguration, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorManualConfigLight(uint8_t light)  //手动设置亮度
{
	uint8_t GraySensorLightConfiguration[3] = {0x00, 0xc6, light};
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorLightConfiguration, 3) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 3) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorConfigLineAd(void)  //自动设置线AD值
{
	uint8_t GraySensorLineAdConfiguration[2] = {0x00, 0xc1};
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorLineAdConfiguration, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorConfigGroundAd(void)  //自动设置地AD值
{
	uint8_t GraySensorGroundAdConfiguration[2] = {0x00, 0xc2};
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGroundAdConfiguration, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorManualConfigThresholdValue(uint8_t num, uint8_t threshold)  //手动设置某一路AD阈值（num = 1~15）
{
	uint8_t GraySensorThresholdValueConfiguration[4] = {0x00, 0xc7, num, threshold};
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorThresholdValueConfiguration, 4) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}


//数据读取 8~11
//******************************************************************************
void GraySensorFifteenThresholdValueGet(void)  //读取15路阈值
{
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGetFifteenThresholdValue, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 18) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorFifteenLineValueGet(void)  //读取15路设置线值
{
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGetFifteenLineValue, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 18) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorFifteenGroundValueGet(void)  //读取15路设置地值
{
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGetFifteenGroundValue, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 18) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorFifteenDigitalValueGet(void)  //读取15路数字量
{
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGetFifteenDigitalValue, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 5) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorFifteenAnalogValueGet(void)  //读取15路模拟量
{
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGetFifteenAnalogValue, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 18) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorSingleAnalogValueGet(void)  //读取单模拟量值
{
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGetFifteenSigleAnalogValue, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 5) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorInit(void)  //灰度传感器初始化
{
	GraySensorConfigTest();
}


/**
 ******************************************************************************
 *  @defgroup 数据获取
 *  @brief
 *
**/
uint8_t GetGraySensorOneOfFifteenReceiveValue(uint8_t num)    //读取灰度传感器缓冲区某一位0~14
{
	return GraySensorReceiveBuffer[num+3];
}
