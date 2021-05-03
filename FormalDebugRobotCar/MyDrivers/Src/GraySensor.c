/**
  ******************************************************************************
  * @file    GraySensor.c
  * @author  YL
  * @brief   �Ҷȴ�����S515�������������ƣ� 5.3
  *
  @verbatim
	
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "GraySensor.h"

/* Define\Declare ------------------------------------------------------------*/
uint8_t GraySensorReceiveBuffer[18];

//���ݶ�ȡָ��
static uint8_t GraySensorGetFifteenThresholdValue[2] = {0x00, 0xd7};  //��ȡ15·��ֵ
static uint8_t GraySensorGetFifteenLineValue[2] = {0x00, 0xd1};  //��ȡ15·������ֵ
static uint8_t GraySensorGetFifteenGroundValue[2] = {0x00, 0xd2};  //��ȡ15·���õ�ֵ
static uint8_t GraySensorGetFifteenDigitalValue[2] = {0x00, 0xd8};  //��ȡ15·������
static uint8_t GraySensorGetFifteenAnalogValue[2] = {0x00, 0xd9};  //��ȡ15·ģ����
static uint8_t GraySensorGetFifteenSigleAnalogValue[2] = {0x00, 0xdb};  //��ȡ��ģ����ֵ

/**
 ******************************************************************************
 *  @defgroup ����
 *  @brief
 *
**/

//���� 1~7
//******************************************************************************
void GraySensorConfigTest(void)  //����
{
	uint8_t GraySensorTestConfiguration[2] = {0x00, 0xaa};
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorTestConfiguration, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorConfigLineLight(void)  //�Զ�������������
{
	uint8_t GraySensorLineLightConfiguration[2] = {0x00, 0xc9};
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorLineLightConfiguration, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorConfigGroundLight(void)  //�Զ�������������
{
	uint8_t GraySensorGroundLightConfiguration[2] = {0x00, 0xca};
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGroundLightConfiguration, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorManualConfigLight(uint8_t light)  //�ֶ���������
{
	uint8_t GraySensorLightConfiguration[3] = {0x00, 0xc6, light};
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorLightConfiguration, 3) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 3) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorConfigLineAd(void)  //�Զ�������ADֵ
{
	uint8_t GraySensorLineAdConfiguration[2] = {0x00, 0xc1};
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorLineAdConfiguration, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorConfigGroundAd(void)  //�Զ����õ�ADֵ
{
	uint8_t GraySensorGroundAdConfiguration[2] = {0x00, 0xc2};
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGroundAdConfiguration, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorManualConfigThresholdValue(uint8_t num, uint8_t threshold)  //�ֶ�����ĳһ·AD��ֵ��num = 1~15��
{
	uint8_t GraySensorThresholdValueConfiguration[4] = {0x00, 0xc7, num, threshold};
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorThresholdValueConfiguration, 4) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}


//���ݶ�ȡ 8~11
//******************************************************************************
void GraySensorFifteenThresholdValueGet(void)  //��ȡ15·��ֵ
{
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGetFifteenThresholdValue, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 18) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorFifteenLineValueGet(void)  //��ȡ15·������ֵ
{
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGetFifteenLineValue, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 18) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorFifteenGroundValueGet(void)  //��ȡ15·���õ�ֵ
{
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGetFifteenGroundValue, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 18) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorFifteenDigitalValueGet(void)  //��ȡ15·������
{
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGetFifteenDigitalValue, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 5) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorFifteenAnalogValueGet(void)  //��ȡ15·ģ����
{
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGetFifteenAnalogValue, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 18) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorSingleAnalogValueGet(void)  //��ȡ��ģ����ֵ
{
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGetFifteenSigleAnalogValue, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 5) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorInit(void)  //�Ҷȴ�������ʼ��
{
	GraySensorConfigTest();
}


/**
 ******************************************************************************
 *  @defgroup ���ݻ�ȡ
 *  @brief
 *
**/
uint8_t GetGraySensorOneOfFifteenReceiveValue(uint8_t num)    //��ȡ�Ҷȴ�����������ĳһλ0~14
{
	return GraySensorReceiveBuffer[num+3];
}
