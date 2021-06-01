/**
  ******************************************************************************
  * @file    MatrixKeyBoard.c
  * @author  YL
  * @brief   4*4������̣����ƣ� 6.1
  *
  @verbatim
	��
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "MatrixKeyBoard.h"

/* Define\Declare ------------------------------------------------------------*/
uint8_t KeyState;  //0Ϊ�ް���������1-4Ϊĳ�а������£�5-8Ϊĳ�а�������


/**
 ******************************************************************************
 *  @defgroup �ⲿ����
 *  @brief
 *
**/
//������̳�ʼ��
void MatrixKeyBoardInit(void)
{
	HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_RESET);
}

//����16��������RΪ�У�CΪ�ж�Ӧ��������
void R1C1ClipFunction(void)
{

}

void R1C2ClipFunction(void)
{

}
void R1C3ClipFunction(void)
{

}
void R1C4ClipFunction(void)
{

}
void R2C1ClipFunction(void)
{

}

void R2C2ClipFunction(void)
{

}

void R2C3ClipFunction(void)
{

}

void R2C4ClipFunction(void)
{

}

void R3C1ClipFunction(void)
{

}

void R3C2ClipFunction(void)
{

}

void R3C3ClipFunction(void)
{

}

void R3C4ClipFunction(void)
{

}

void R4C1ClipFunction(void)
{

}

void R4C2ClipFunction(void)
{

}

void R4C3ClipFunction(void)
{

}

void R4C4ClipFunction(void)
{

}

//�ް������º���
void ElseFunction(void)
{

}

//�����������������޸ĺ�ʹ�ã�����������
//*****************************************************************
//*****************************************************************
/**
 ******************************************************************************
 *  @defgroup �ڲ�����
 *  @brief
 *
**/

//��������
void MatrixKeyBoardConfirm(void)
{
	if(KeyState >= 5 && KeyState <= 8)
	{
		switch(KeyState)
		{
			case 5: MatrixKeyBoardCOLUMN1Confirm(); break;
			case 6: MatrixKeyBoardCOLUMN2Confirm(); break;
			case 7: MatrixKeyBoardCOLUMN3Confirm(); break;
			case 8: MatrixKeyBoardCOLUMN4Confirm(); break;
			default: Error_Handler(); break;
		}
	}
	else if(KeyState >= 1 && KeyState <= 4)
		KeyState += 4;
}

//���̵�һ��ɨ��
void MatrixKeyBoardCOLUMN1Confirm(void)
{
	HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_SET);
	
	while(1)
	{
		HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_SET);
		if(KeyState == 1)
		{
			R1C1ClipFunction();
			KeyState = 0;
			HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_RESET);
			break;
		}
		
		HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_SET);
		if(KeyState == 1)
		{
			R2C1ClipFunction();
			HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_RESET);
			KeyState = 0;
			break;
		}
		
		HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_SET);
		if(KeyState == 1)
		{
			R3C1ClipFunction();
			HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_RESET);
			KeyState = 0;
			break;
		}
		
		HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_RESET);
		if(KeyState == 1)
		{
			R4C1ClipFunction();
			HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_RESET);
			KeyState = 0;
			break;
		}
		
		ElseFunction();
		HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_RESET);
		KeyState = 0;
		break;
	}
}

//���̵ڶ���ɨ��
void MatrixKeyBoardCOLUMN2Confirm(void)
{
	HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_SET);
	
	while(1)
	{
		HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_SET);
		if(KeyState == 2)
		{
			R1C2ClipFunction();
			HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_RESET);
			KeyState = 0;
			break;
		}
		
		HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_SET);
		if(KeyState == 2)
		{
			R2C2ClipFunction();
			HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_RESET);
			KeyState = 0;
			break;
		}
		
		HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_SET);
		if(KeyState == 2)
		{
			R3C2ClipFunction();
			HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_RESET);
			KeyState = 0;
			break;
		}
		
		HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_RESET);
		if(KeyState == 2)
		{
			R4C2ClipFunction();
			HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_RESET);
			KeyState = 0;
			break;
		}
		
		ElseFunction();
		HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_RESET);
		KeyState = 0;
		break;
	}
}

//���̵�����ɨ��
void MatrixKeyBoardCOLUMN3Confirm(void)
{
	HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_SET);
	
	while(1)
	{
		HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_SET);
		if(KeyState == 3)
		{
			R1C3ClipFunction();
			HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_RESET);
			KeyState = 0;
			break;
		}
		
		HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_SET);
		if(KeyState == 3)
		{
			R2C3ClipFunction();
			HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_RESET);
			KeyState = 0;
			break;
		}
		
		HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_SET);
		if(KeyState == 3)
		{
			R3C3ClipFunction();
			HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_RESET);
			KeyState = 0;
			break;
		}
		
		HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_RESET);
		if(KeyState == 3)
		{
			R4C3ClipFunction();
			HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_RESET);
			KeyState = 0;
			break;
		}
		
		ElseFunction();
		HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_RESET);
		KeyState = 0;
		break;
	}
}

//���̵�����ɨ��
void MatrixKeyBoardCOLUMN4Confirm(void)
{
	HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_SET);
	
	while(1)
	{
		HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_SET);
		if(KeyState == 4)
		{
			R1C4ClipFunction();
			HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_RESET);
			KeyState = 0;
			break;
		}
		
		HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_SET);
		if(KeyState == 4)
		{
			R2C4ClipFunction();
			HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_RESET);
			KeyState = 0;
			break;
		}
		
		HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_SET);
		if(KeyState == 4)
		{
			R3C4ClipFunction();
			HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_RESET);
			KeyState = 0;
			break;
		}
		
		HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_RESET);
		if(KeyState == 4)
		{
			R4C4ClipFunction();
			HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_RESET);
			KeyState = 0;
			break;
		}
		
		ElseFunction();
		HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_RESET);
		KeyState = 0;
		break;
	}
}