/**
  ******************************************************************************
  * @file    MatrixKeyBoard.c
  * @author  YL
  * @brief   4*4�������
  *
  @verbatim
	
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "MatrixKeyBoard.h"

/* Define\Declare ------------------------------------------------------------*/
uint8_t KeyStateOrNum;  //0Ϊ�ް���������1-4Ϊĳ�а������£�5-8Ϊĳ�а���������9-24Ϊ��Ӧ���а���

void MatrixKeyBoardInit(void)
{
	HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_RESET);
}
	

//����ɨ��
void MatrixKeyBoardConfirm(void)
{
	
}

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

void R41ClipFunction(void)
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

void ElseFunction(void)
{

}

