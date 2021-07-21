/**
  ******************************************************************************
  * @file    GraySensor.c
  * @author  ����
  * @brief   �Ҷȴ�����S515�������������ƣ� 5.3
  *
  @verbatim
	(#) S515����
	(++)������115200
	(++)����Ĭ��
	@endverbatim
	��ֹ�����Ҷȴ������ϵİ�����ʹ��5V��Դ
	ע�⣺7�����ú������������ñ����ӳ٣�������ܻ�ʧЧ
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "GraySensor.h"

/* Define\Declare ------------------------------------------------------------*/
uint8_t GraySensorReceiveBuffer[18];
uint8_t GraySensorTransferFlag, GraySensorRecieveFlag;

/**
 ******************************************************************************
 *  @defgroup �ⲿ����
 *  @brief
 *
**/
//�Ҷȴ�������ʼ��
void GraySensorInit(void)  
{
	GraySensorTransferFlag = 1;
	GraySensorRecieveFlag = 1;
	GraySensorManualConfigLight(75);
}

//���� 1~7
//******************************************************************************
//����
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

//�Զ�������������
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

//�Զ�������������
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

//�ֶ���������  ��Χ0-100�����鲻����75��LDO�ᷢ��
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

//�Զ�������ADֵ
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

//�Զ����õ�ADֵ
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

//�ֶ�����ĳһ·AD��ֵ��num = 1~15��
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


//���ݶ�ȡ 8~13
//******************************************************************************
//��ȡ15·��ֵ
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

//��ȡ15·������ֵ
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

//��ȡ15·���õ�ֵ
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

//��ȡ15·������
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

//��ȡ15·ģ����
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

//��ȡ��ģ����ֵ
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

uint8_t GraySensorOneOfFifteenReceiveValueGet(uint8_t num)    //��ȡ�Ҷȴ�����15·ĳһλ num��Χ0~14
{
	if(num >= 0 && num <= 14)
		return GraySensorReceiveBuffer[num+3];
	else
		return 1;
}
