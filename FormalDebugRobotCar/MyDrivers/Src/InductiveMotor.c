/**
  ******************************************************************************
  * @file    InductiveMotor.c
  * @author  HZY
  * @brief   无刷有感电机驱动（单）
  *
  @verbatim
	
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "InductiveMotor.h"

uint8_t leftMotorTxBuf[5]= {0x00};
uint8_t rightMotorTxBuf[5]= {0x00};


void MotorInit(void)
{
	leftMotorTxBuf[0] = 0xee;
	leftMotorTxBuf[1] = 0xee;
	rightMotorTxBuf[0] = 0xee;
	rightMotorTxBuf[1] = 0xee;
	
	HAL_GPIO_WritePin(LEFTMOTOR_RST_GPIO_PORT, LEFTMOTOR_RST_GPIO_PIN, 0);
	HAL_Delay(10);
	HAL_GPIO_WritePin(LEFTMOTOR_RST_GPIO_PORT, LEFTMOTOR_RST_GPIO_PIN, 1);
	HAL_GPIO_WritePin(RIGHTMOTOR_RST_GPIO_PORT, RIGHTMOTOR_RST_GPIO_PIN, 0);
	HAL_Delay(10);
	HAL_GPIO_WritePin(RIGHTMOTOR_RST_GPIO_PORT, RIGHTMOTOR_RST_GPIO_PIN, 1);
}

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

void StartMotor(void)
{
	leftMotorTxBuf[4] = 0xaa;
	rightMotorTxBuf[4] = 0xaa;
	HAL_UART_Transmit(&LEFTMOTORUartHandle, leftMotorTxBuf, sizeof(leftMotorTxBuf), 0xff);
	HAL_UART_Transmit(&RIGHTMOTORUartHandle, rightMotorTxBuf, sizeof(rightMotorTxBuf), 0xff);
}

void StopMotor(void)
{
	leftMotorTxBuf[4] = 0xff;
	rightMotorTxBuf[4] = 0xff;
	HAL_UART_Transmit(&LEFTMOTORUartHandle, leftMotorTxBuf, sizeof(leftMotorTxBuf), 0xff);
	HAL_UART_Transmit(&RIGHTMOTORUartHandle, rightMotorTxBuf, sizeof(rightMotorTxBuf), 0xff);
}

void DebugMotor(void)
{
	static uint8_t flag = 0;
	static uint8_t initFlag = 0;
	static uint8_t timeFlag = 0;
	int16_t Speed = 1500;
	if(timeFlag <= 60)
	{
		if(initFlag == 0)
		{
			MotorInit();
			SetMotorSpeed(0, &Speed);
			StartMotor();
			initFlag = 1;
		}
		if(flag == 0)
		{
			Speed = 3000;
			SetMotorSpeed(0, &Speed);
			flag = 1;
		}
		else
		{
			Speed = 100;
			SetMotorSpeed(0, &Speed);
			flag = 0;
		}
		timeFlag ++;
	}
	else
	{
		StopMotor();
	}
}