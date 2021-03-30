/**
  ******************************************************************************
  * @file    GraySensor.c
  * @author  YL
  * @brief   灰度传感器S515驱动
  *
  @verbatim
	
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "GraySensor.h"

/* Define\Declare ------------------------------------------------------------*/
uint8_t GraySensorConfirmOrReceiveBuffer[18];
uint8_t GraySensorInstructionNum;

//配置指令
static uint8_t GraySensorTestConfiguration[2] = {0x00, 0xaa};  //测试
static uint8_t GraySensorLineAdConfiguration[2] = {0x00, 0xc1};  //自动设置线AD值
static uint8_t GraySensorGroundAdConfiguration[2] = {0x00, 0xc2};  //自动设置地AD值
static uint8_t GraySensorLineLightConfiguration[2] = {0x00, 0xc9};  //自动线上亮度配置
static uint8_t GraySensorGroundLightConfiguration[2] = {0x00, 0xca};  //自动地上亮度配置

//数据读取指令
static uint8_t GraySensorGetFifteenThresholdValue[2] = {0x00, 0xd7};  //读取15路阈值
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
	GraySensorInstructionNum = 1;
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorTestConfiguration, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorConfirmOrReceiveBuffer, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorConfigLineLight(void)  //自动线上亮度配置
{
	GraySensorInstructionNum = 2;
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorLineLightConfiguration, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorConfirmOrReceiveBuffer, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorConfigGroundLight(void)  //自动地上亮度配置
{
	GraySensorInstructionNum = 3;
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGroundLightConfiguration, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorConfirmOrReceiveBuffer, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorManualConfigLight(uint8_t light)  //手动设置亮度
{
	GraySensorInstructionNum = 4;
	uint8_t GraySensorLightConfiguration[3] = {0x00, 0xc6, light};
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorLightConfiguration, 3) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorConfirmOrReceiveBuffer, 3) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorConfigLineAd(void)  //自动设置线AD值
{
	GraySensorInstructionNum = 5;
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorLineAdConfiguration, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorConfirmOrReceiveBuffer, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorConfigGroundAd(void)  //自动设置地AD值
{
	GraySensorInstructionNum = 6;
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGroundAdConfiguration, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorConfirmOrReceiveBuffer, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorManualConfigThresholdValue(uint8_t num, uint8_t threshold)  //手动设置某一路AD阈值（num = 1~15）
{
	GraySensorInstructionNum = 7;
	uint8_t GraySensorThresholdValueConfiguration[4] = {0x00, 0xc7, num, threshold};
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorThresholdValueConfiguration, 4) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorConfirmOrReceiveBuffer, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}


//数据读取 8~11
//******************************************************************************
void GraySensorFifteenThresholdValueGet(void)  //读取15路阈值
{
	GraySensorInstructionNum = 8;
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGetFifteenThresholdValue, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorConfirmOrReceiveBuffer, 18) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorFifteenDigitalValueGet(void)  //读取15路数字量
{
	GraySensorInstructionNum = 9;
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGetFifteenDigitalValue, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorConfirmOrReceiveBuffer, 5) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorFifteenAnalogValueGet(void)  //读取15路模拟量
{
	GraySensorInstructionNum = 10;
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGetFifteenAnalogValue, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorConfirmOrReceiveBuffer, 18) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorSigleAnalogValueGet(void)  //读取单模拟量值
{
	GraySensorInstructionNum = 11;
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGetFifteenSigleAnalogValue, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorConfirmOrReceiveBuffer, 5) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorInit(void)
{
	GraySensorConfigTest();
}


/**
 ******************************************************************************
 *  @defgroup 数据获取
 *  @brief
 *
**/
uint8_t GetGraySensorOneOfFifteenReceiveValue(uint8_t num)
{
	return GraySensorConfirmOrReceiveBuffer[num+3];
}
