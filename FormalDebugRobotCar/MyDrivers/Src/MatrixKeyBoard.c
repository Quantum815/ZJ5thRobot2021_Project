/**
  ******************************************************************************
  * @file    "MatrixKeyBoard.c
  * @author  YL
  * @brief   4*4æÿ’Ûº¸≈Ã
  *
  @verbatim
	
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "MatrixKeyBoard.h"

int KeyFlag;
Matrix_KeyState keyState = Key_Up;
Matrix_KeyMode keyMode = Key_NoPress;

void MatrixKeyboardScanning(void)
{
	HAL_GPIO_WritePin(Row1_GPIO_PORT, Row1_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Row2_GPIO_PORT, Row2_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Row3_GPIO_PORT, Row3_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Row4_GPIO_PORT, Row4_PIN, GPIO_PIN_SET);
	if(!HAL_GPIO_ReadPin(Column1_GPIO_PORT, Column1_PIN))
	{
		HAL_Delay(5);
		if(!HAL_GPIO_ReadPin(Column1_GPIO_PORT, Column1_PIN))
			KeyFlag = 1;
	}
	else if(!HAL_GPIO_ReadPin(Column2_GPIO_PORT, Column2_PIN))
	{
		HAL_Delay(5);
		if(!HAL_GPIO_ReadPin(Column2_GPIO_PORT, Column2_PIN))
			KeyFlag = 2;
	}
	else if(!HAL_GPIO_ReadPin(Column3_GPIO_PORT, Column3_PIN))
	{
		HAL_Delay(5);
		if(!HAL_GPIO_ReadPin(Column3_GPIO_PORT, Column3_PIN))
			KeyFlag = 3;
	}
	else if(!HAL_GPIO_ReadPin(Column4_GPIO_PORT, Column4_PIN))
	{
		HAL_Delay(5);
		if(!HAL_GPIO_ReadPin(Column4_GPIO_PORT, Column4_PIN))
			KeyFlag = 4;
	}
	else
		KeyFlag = 0;
	
	HAL_GPIO_WritePin(Row1_GPIO_PORT, Row1_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Row2_GPIO_PORT, Row2_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Row3_GPIO_PORT, Row3_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Row4_GPIO_PORT, Row4_PIN, GPIO_PIN_SET);
	if(!HAL_GPIO_ReadPin(Column1_GPIO_PORT, Column1_PIN))
	{
		HAL_Delay(5);
		if(!HAL_GPIO_ReadPin(Column1_GPIO_PORT, Column1_PIN))
			KeyFlag = 5;
	}
	else if(!HAL_GPIO_ReadPin(Column2_GPIO_PORT, Column2_PIN))
	{
		HAL_Delay(5);
		if(!HAL_GPIO_ReadPin(Column2_GPIO_PORT, Column2_PIN))
			KeyFlag = 6;
	}
	else if(!HAL_GPIO_ReadPin(Column3_GPIO_PORT, Column3_PIN))
	{
		HAL_Delay(5);
		if(!HAL_GPIO_ReadPin(Column3_GPIO_PORT, Column3_PIN))
			KeyFlag = 7;
	}
	else if(!HAL_GPIO_ReadPin(Column4_GPIO_PORT, Column4_PIN))
	{
		HAL_Delay(5);
		if(!HAL_GPIO_ReadPin(Column4_GPIO_PORT, Column4_PIN))
			KeyFlag = 8;
	}

	HAL_GPIO_WritePin(Row1_GPIO_PORT, Row1_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Row2_GPIO_PORT, Row2_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Row3_GPIO_PORT, Row3_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Row4_GPIO_PORT, Row4_PIN, GPIO_PIN_SET);	
	if(!HAL_GPIO_ReadPin(Column1_GPIO_PORT, Column1_PIN))
	{
		HAL_Delay(5);
		if(!HAL_GPIO_ReadPin(Column1_GPIO_PORT, Column1_PIN))
			KeyFlag = 9;
	}
	else if(!HAL_GPIO_ReadPin(Column2_GPIO_PORT, Column2_PIN))
	{
		HAL_Delay(5);
		if(!HAL_GPIO_ReadPin(Column2_GPIO_PORT, Column2_PIN))
			KeyFlag = 10;
	}
	else if(!HAL_GPIO_ReadPin(Column3_GPIO_PORT, Column3_PIN))
	{
		HAL_Delay(5);
		if(!HAL_GPIO_ReadPin(Column3_GPIO_PORT, Column3_PIN))
			KeyFlag = 11;
	}
	else if(!HAL_GPIO_ReadPin(Column4_GPIO_PORT, Column4_PIN))
	{
		HAL_Delay(5);
		if(!HAL_GPIO_ReadPin(Column4_GPIO_PORT, Column4_PIN))
			KeyFlag = 12;
	}

	HAL_GPIO_WritePin(Row1_GPIO_PORT, Row1_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Row2_GPIO_PORT, Row2_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Row3_GPIO_PORT, Row3_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Row4_GPIO_PORT, Row4_PIN, GPIO_PIN_RESET);
	if(!HAL_GPIO_ReadPin(Column1_GPIO_PORT, Column1_PIN))
	{
		HAL_Delay(5);
		if(!HAL_GPIO_ReadPin(Column1_GPIO_PORT, Column1_PIN))
			KeyFlag = 13;
	}
	else if(!HAL_GPIO_ReadPin(Column2_GPIO_PORT, Column2_PIN))
	{
		HAL_Delay(5);
		if(!HAL_GPIO_ReadPin(Column2_GPIO_PORT, Column2_PIN))
			KeyFlag = 14;
	}
	else if(!HAL_GPIO_ReadPin(Column3_GPIO_PORT, Column3_PIN))
	{
		HAL_Delay(5);
		if(!HAL_GPIO_ReadPin(Column3_GPIO_PORT, Column3_PIN))
			KeyFlag = 15;
	}
	else if(!HAL_GPIO_ReadPin(Column4_GPIO_PORT, Column4_PIN))
	{
		HAL_Delay(5);
		if(!HAL_GPIO_ReadPin(Column4_GPIO_PORT, Column4_PIN))
			KeyFlag = 16;
	}
	
	switch(KeyFlag)
	{
		case 1: R1C1Function(); break;
		case 2: R1C2Function(); break;
		case 3: R1C3Function(); break;
		case 4: R1C4Function(); break;
		case 5: R2C1Function(); break;
		case 6: R2C2Function(); break;
		case 7: R2C3Function(); break;
		case 8: R2C4Function(); break;
		case 9: R3C1Function(); break;
		case 10: R3C2Function(); break;
		case 11: R3C3Function(); break;
		case 12: R3C4Function(); break;
		case 13: R4C1Function(); break;
		case 14: R4C2Function(); break;
		case 15: R4C3Function(); break;
		case 16: R4C4Function(); break;
		default: ElseFunction(); break;
	}
}

void R1C1Function(void)
{

}

void R1C2Function(void)
{

}
void R1C3Function(void)
{

}
void R1C4Function(void)
{

}
void R2C1Function(void)
{

}

void R2C2Function(void)
{

}

void R2C3Function(void)
{

}

void R2C4Function(void)
{

}

void R3C1Function(void)
{

}

void R3C2Function(void)
{

}

void R3C3Function(void)
{

}

void R3C4Function(void)
{

}

void R4C1Function(void)
{

}

void R4C2Function(void)
{

}

void R4C3Function(void)
{

}

void R4C4Function(void)
{

}

void ElseFunction(void)
{

}

