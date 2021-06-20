/**
  ******************************************************************************
  * @file    InductiveMotor.c
  * @author  YL
  * @brief   ��ˢ�ие������������
  *
  @verbatim
	
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "InductiveMotor.h"

uint8_t leftMotorTxBuf[5]= {0x00};
uint8_t rightMotorTxBuf[5]= {0x00};

//˫������ʼ��
void MotorInit(void)
{
	leftMotorTxBuf[0] = 0xee;
	leftMotorTxBuf[1] = 0xee;
	rightMotorTxBuf[0] = 0xee;
	rightMotorTxBuf[1] = 0xee;
	
	HAL_GPIO_WritePin(LEFTMOTOR_RST_GPIO_PORT, LEFTMOTOR_RST_GPIO_PIN, 0);
	HAL_Delay(2);
	HAL_GPIO_WritePin(LEFTMOTOR_RST_GPIO_PORT, LEFTMOTOR_RST_GPIO_PIN, 1);
	HAL_GPIO_WritePin(RIGHTMOTOR_RST_GPIO_PORT, RIGHTMOTOR_RST_GPIO_PIN, 0);
	HAL_Delay(2);
	HAL_GPIO_WritePin(RIGHTMOTOR_RST_GPIO_PORT, RIGHTMOTOR_RST_GPIO_PIN, 1);
}

//����ĳ�����ٶȣ���λ ת/���ӣ�������Ч
void SetMotorSpeed(uint8_t targetMotor, int16_t* Speed)
{
	switch(targetMotor)
	{
		case LMOTOR:
      
			leftMotorTxBuf[2] = *(uint8_t*) Speed;
			leftMotorTxBuf[3] = *((uint8_t*) Speed + 1);
			leftMotorTxBuf[4] = 0xbb;
			HAL_UART_Transmit(&LEFTMOTORUartHandle, leftMotorTxBuf, sizeof(leftMotorTxBuf), 0xff);
			break;
		case RMOTOR:
      
			rightMotorTxBuf[2] = *(uint8_t*) Speed;
			rightMotorTxBuf[3] = *((uint8_t*) Speed + 1);
			rightMotorTxBuf[4] = 0xbb;
			HAL_UART_Transmit(&RIGHTMOTORUartHandle, rightMotorTxBuf, sizeof(rightMotorTxBuf), 0xff);
			break;
		
		default:	
		case ALLMOTOR:
			leftMotorTxBuf[2] = *(uint8_t*) Speed;
			leftMotorTxBuf[3] = *((uint8_t*) Speed + 1);
			rightMotorTxBuf[2] = *(uint8_t*) Speed;
			rightMotorTxBuf[3] = *((uint8_t*) Speed + 1);
			leftMotorTxBuf[4] = 0xbb;
			rightMotorTxBuf[4] = 0xbb;
			HAL_UART_Transmit(&LEFTMOTORUartHandle, leftMotorTxBuf, sizeof(leftMotorTxBuf), 0xff);
			HAL_UART_Transmit(&RIGHTMOTORUartHandle, rightMotorTxBuf, sizeof(rightMotorTxBuf), 0xff);
			break;
	}
}

//����˫����
void StartMotor(void)
{
	leftMotorTxBuf[4] = 0xaa;
	rightMotorTxBuf[4] = 0xaa;
	HAL_UART_Transmit(&LEFTMOTORUartHandle, leftMotorTxBuf, sizeof(leftMotorTxBuf), 0xff);
	HAL_UART_Transmit(&RIGHTMOTORUartHandle, rightMotorTxBuf, sizeof(rightMotorTxBuf), 0xff);
}

//ֹͣ˫����
void StopMotor(void)
{
	leftMotorTxBuf[4] = 0xff;
	rightMotorTxBuf[4] = 0xff;
	HAL_UART_Transmit(&LEFTMOTORUartHandle, leftMotorTxBuf, sizeof(leftMotorTxBuf), 0xff);
	HAL_UART_Transmit(&RIGHTMOTORUartHandle, rightMotorTxBuf, sizeof(rightMotorTxBuf), 0xff);
}


//�����ô���
void DebugMotor(void)
{
	static uint8_t flag = 0;
	static uint8_t initFlag = 0;
	static uint8_t timeFlag = 0;
	int16_t LSpeed = 1500;
  int16_t RSpeed = -1500;
	if(timeFlag <= 15)
	{
		if(initFlag == 0)
		{
			MotorInit();
			SetMotorSpeed(LMOTOR, &LSpeed);
      SetMotorSpeed(RMOTOR, &RSpeed);
			StartMotor();
			initFlag = 1;
		}
    else
    {
      if(flag == 0)
      {
        LSpeed = 1000;
        RSpeed = 1000;
        SetMotorSpeed(LMOTOR, &LSpeed);
        SetMotorSpeed(RMOTOR, &RSpeed);
        flag = 1;
      }
      else
      {
        LSpeed = 1000;
        RSpeed = 1000;
        SetMotorSpeed(LMOTOR, &LSpeed);
        SetMotorSpeed(RMOTOR, &RSpeed);
        flag = 0;
      }
      timeFlag ++;
    }
	}
	else
	{
		StopMotor();
	}
}
