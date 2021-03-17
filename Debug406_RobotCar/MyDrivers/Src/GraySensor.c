/**
  ******************************************************************************
  * @file    GraySensor.c
  * @author  YL
  * @brief   �Ҷȴ�����S515����
  *
  @verbatim
	
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "GraySensor.h"

/* Define\Declare ------------------------------------------------------------*/
uint8_t GraySensorConfigConfirm[2];
uint8_t GraySensorReceiveBuffer[18];
uint8_t GraySensorInstructionNum;

//����ָ��
static uint8_t GraySensorTestConfiguration[2] = {0x00, 0xaa};  //����
static uint8_t GraySensorLineAdConfiguration[2] = {0x00, 0xc1};  //�Զ�������ADֵ
static uint8_t GraySensorGroundAdConfiguration[2] = {0x00, 0xc2};  //�Զ����õ�ADֵ
static uint8_t GraySensorLineLightConfiguration[2] = {0x00, 0xc9};  //�Զ�������������
static uint8_t GraySensorGroundLightConfiguration[2] = {0x00, 0xca};  //�Զ�������������

//���ݶ�ȡָ��
static uint8_t GraySensorGetFifteenThresholdValue[2] = {0x00, 0xd7};  //��ȡ15·��ֵ
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
	GraySensorInstructionNum = 1;
	if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorTestConfiguration, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
	if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorConfigConfirm, 2) != HAL_OK)
		Error_Handler();
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY);
}

void GraySensorConfigLineLight(void)  //�Զ�������������
{
	GraySensorInstructionNum = 2;
	HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorLineLightConfiguration, 2);
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY)
	{
	}
	HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorConfigConfirm, 2);
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY)
	{
	}
}

void GraySensorConfigGroundLight(void)  //�Զ�������������
{
	GraySensorInstructionNum = 3;
	HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGroundLightConfiguration, 2);
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY)
	{
	}
	HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorConfigConfirm, 2);
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY)
	{
	}
}

void GraySensorManualConfigLight(uint8_t light)  //�ֶ���������
{
	GraySensorInstructionNum = 4;
	uint8_t GraySensorLightConfiguration[3] = {0x00, 0xc6, light};
	HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorLightConfiguration, 3);
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY)
	{
	}
	HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorConfigConfirm, 2);
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY)
	{
	}
}

void GraySensorConfigLineAd(void)  //�Զ�������ADֵ
{
	GraySensorInstructionNum = 5;
	HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorLineAdConfiguration, 2);
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY)
	{
	}
	HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorConfigConfirm, 2);
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY)
	{
	}
}

void GraySensorConfigGroundAd(void)  //�Զ����õ�ADֵ
{
	GraySensorInstructionNum = 6;
	HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGroundAdConfiguration, 2);
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY)
	{
	}
	HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorConfigConfirm, 2);
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY)
	{
	}
}

void GraySensorManualConfigThresholdValue(uint8_t num, uint8_t threshold)  //�ֶ�����ĳһ·AD��ֵ��num = 1~15��
{
	GraySensorInstructionNum = 7;
	uint8_t GraySensorThresholdValueConfiguration[4] = {0x00, 0xc7, num, threshold};
	HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorThresholdValueConfiguration, 4);
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY)
	{
	}
	HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorConfigConfirm, 2);
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY)
	{
	}
}


//���ݶ�ȡ 8~11
//******************************************************************************
void GraySensorFifteenThresholdValueGet(void)  //��ȡ15·��ֵ
{
	GraySensorInstructionNum = 8;
	HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGetFifteenThresholdValue, 2);
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY)
	{
	}
	HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 18);
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY)
	{
	}
}

void GraySensorFifteenDigitalValueGet(void)  //��ȡ15·������
{
	GraySensorInstructionNum = 9;
	HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGetFifteenDigitalValue, 2);
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY)
	{
	}
	HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 5);
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY)
	{
	}
}

void GraySensorFifteenAnalogValueGet(void)  //��ȡ15·ģ����
{
	GraySensorInstructionNum = 10;
	HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGetFifteenAnalogValue, 2);
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY)
	{
	}
	HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 18);
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY)
	{
	}
}

void GraySensorConfigFifteenSigleAnalogValueGet(void)  //��ȡ��ģ����ֵ
{
	GraySensorInstructionNum = 11;
	HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGetFifteenSigleAnalogValue, 2);
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY)
	{
	}
	HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 5);
	while(HAL_UART_GetState(&GraySensorUartHandle) != HAL_UART_STATE_READY)
	{
	}
}

void GraySensorInit(void)
{
	GraySensorConfigTest();
}


/**
 ******************************************************************************
 *  @defgroup ���ݻ�ȡ
 *  @brief
 *
**/
uint8_t* GetGraySensorConfirmResult(void)
{
	return GraySensorConfigConfirm;
}

uint8_t* GetGraySensorFifteenValue(void)
{
	return GraySensorReceiveBuffer+3;
}
