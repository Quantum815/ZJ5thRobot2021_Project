/**
  ******************************************************************************
  * @file    MatrixKeyBoard.c
  * @author  YL
  * @brief   4*4矩阵键盘（完善） 6.1
  *
  @verbatim
	无
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "MatrixKeyBoard.h"

/* Define\Declare ------------------------------------------------------------*/
uint8_t KeyState;  //0为无按键消抖，1-4为某行按键按下，5-8为某行按键消抖


/**
 ******************************************************************************
 *  @defgroup 外部调用
 *  @brief
 *
**/
//矩阵键盘初始化
void MatrixKeyBoardInit(void)
{
	HAL_GPIO_WritePin(ROW1_GPIO_PORT, ROW1_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(ROW2_GPIO_PORT, ROW2_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(ROW3_GPIO_PORT, ROW3_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(ROW4_GPIO_PORT, ROW4_PIN, GPIO_PIN_RESET);
}

//如下16个函数，R为行，C为列对应按键函数
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

//无按键按下函数
void ElseFunction(void)
{

}

//此行以下请勿随意修改和使用！！！！！！
//*****************************************************************
//*****************************************************************
/**
 ******************************************************************************
 *  @defgroup 内部调用
 *  @brief
 *
**/

//键盘消抖
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

//键盘第一列扫描
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

//键盘第二列扫描
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

//键盘第三列扫描
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

//键盘第四列扫描
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