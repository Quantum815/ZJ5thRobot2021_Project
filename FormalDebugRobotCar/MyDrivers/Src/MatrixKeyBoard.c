/**
  ******************************************************************************
  * @file    MatrixKeyBoard.c
  * @author  YL
  * @brief   4*4矩阵键盘
  *
  @verbatim
	
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "MatrixKeyBoard.h"

/* Define\Declare ------------------------------------------------------------*/
uint8_t KeyNum;
Matrix_KeyState keyState[4][4] = {{Key_Up}, {Key_Up}, {Key_Up}, {Key_Up}};  //先行后列

//键盘扫描
void MatrixScanning(void)
{
	static uint32_t time = 0;  //时间轮询数
	static uint8_t KeyOldNum;
	
	KeyOldNum = KeyNum;
	
	//确定按键
	KeyNum = 0;
	while(1)
	{
		HAL_GPIO_WritePin(COLUMN1_GPIO_PORT, COLUMN1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(COLUMN2_GPIO_PORT, COLUMN2_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(COLUMN3_GPIO_PORT, COLUMN3_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(COLUMN4_GPIO_PORT, COLUMN4_PIN, GPIO_PIN_SET);
		
		if(!HAL_GPIO_ReadPin(ROW1_GPIO_PORT, ROW1_PIN))
		{
			KeyNum = 1;
			break;
		}
		else if(!HAL_GPIO_ReadPin(ROW2_GPIO_PORT, ROW2_PIN))
		{
			KeyNum = 2;
			break;
		}
		else if(!HAL_GPIO_ReadPin(ROW3_GPIO_PORT, ROW3_PIN))
		{
			KeyNum = 3;
			break;
		}
		else if(!HAL_GPIO_ReadPin(ROW4_GPIO_PORT, ROW4_PIN))
		{
			KeyNum = 4;
			break;
		}
		
		HAL_GPIO_WritePin(COLUMN1_GPIO_PORT, COLUMN1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(COLUMN2_GPIO_PORT, COLUMN2_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(COLUMN3_GPIO_PORT, COLUMN3_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(COLUMN4_GPIO_PORT, COLUMN4_PIN, GPIO_PIN_SET);
		if(!HAL_GPIO_ReadPin(ROW1_GPIO_PORT, ROW1_PIN))
		{
			KeyNum = 5;
			break;
		}
		else if(!HAL_GPIO_ReadPin(ROW2_GPIO_PORT, ROW2_PIN))
		{
			KeyNum = 6;
			break;
		}
		else if(!HAL_GPIO_ReadPin(ROW3_GPIO_PORT, ROW3_PIN))
		{
			KeyNum = 7;
			break;
		}
		else if(!HAL_GPIO_ReadPin(ROW4_GPIO_PORT, ROW4_PIN))
		{
			KeyNum = 8;
			break;
		}

		HAL_GPIO_WritePin(COLUMN1_GPIO_PORT, COLUMN1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(COLUMN2_GPIO_PORT, COLUMN2_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(COLUMN3_GPIO_PORT, COLUMN3_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(COLUMN4_GPIO_PORT, COLUMN4_PIN, GPIO_PIN_SET);	
		if(!HAL_GPIO_ReadPin(ROW1_GPIO_PORT, ROW1_PIN))
		{
			KeyNum = 9;
			break;
		}
		else if(!HAL_GPIO_ReadPin(ROW2_GPIO_PORT, ROW2_PIN))
		{
			KeyNum = 10;
			break;
		}
		else if(!HAL_GPIO_ReadPin(ROW3_GPIO_PORT, ROW3_PIN))
		{
			KeyNum = 11;
			break;
		}
		else if(!HAL_GPIO_ReadPin(ROW4_GPIO_PORT, ROW4_PIN))
		{
			KeyNum = 12;
			break;
		}

		HAL_GPIO_WritePin(COLUMN1_GPIO_PORT, COLUMN1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(COLUMN2_GPIO_PORT, COLUMN2_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(COLUMN3_GPIO_PORT, COLUMN3_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(COLUMN4_GPIO_PORT, COLUMN4_PIN, GPIO_PIN_RESET);
		if(!HAL_GPIO_ReadPin(ROW1_GPIO_PORT, ROW1_PIN))
		{
			KeyNum = 13;
			break;
		}
		else if(!HAL_GPIO_ReadPin(ROW2_GPIO_PORT, ROW2_PIN))
		{
			KeyNum = 14;
			break;
		}
		else if(!HAL_GPIO_ReadPin(ROW3_GPIO_PORT, ROW3_PIN))
		{
			KeyNum = 15;
			break;
		}
		else if(!HAL_GPIO_ReadPin(ROW4_GPIO_PORT, ROW4_PIN))
		{
			KeyNum = 16;
			break;
		}
		else
		{
			break;
		}
	}
	
	if(KeyNum > 0)
	{
		if(KeyOldNum == KeyNum)
		{
			time++;
			if(time == 1)
			{
				switch(KeyNum)
				{
					case 1: keyState[0][0] = Key_Shake; break;
					case 2: keyState[0][1] = Key_Shake; break;
					case 3: keyState[0][2] = Key_Shake; break;
					case 4: keyState[0][3] = Key_Shake; break;
					case 5: keyState[1][0] = Key_Shake; break;
					case 6: keyState[1][1] = Key_Shake; break;
					case 7: keyState[1][2] = Key_Shake; break;
					case 8: keyState[1][3] = Key_Shake; break;
					case 9: keyState[2][0] = Key_Shake; break;
					case 10: keyState[2][1] = Key_Shake; break;
					case 11: keyState[2][2] = Key_Shake; break;
					case 12: keyState[2][3] = Key_Shake; break;
					case 13: keyState[3][0] = Key_Shake; break;
					case 14: keyState[3][1] = Key_Shake; break;
					case 15: keyState[3][2] = Key_Shake; break;
					case 16: keyState[3][3] = Key_Shake; break;
				}
			}
			else if(time <= 1000)
			{
				
			}
			else
			{
				
			}
		}	
	}
	else
		time = 0;
}

void R1C1ShortClipFunction(void)
{

}

void R1C2ShortClipFunction(void)
{

}
void R1C3ShortClipFunction(void)
{

}
void R1C4ShortClipFunction(void)
{

}
void R2C1ShortClipFunction(void)
{

}

void R2C2ShortClipFunction(void)
{

}

void R2C3ShortClipFunction(void)
{

}

void R2C4ShortClipFunction(void)
{

}

void R3C1ShortClipFunction(void)
{

}

void R3C2ShortClipFunction(void)
{

}

void R3C3ShortClipFunction(void)
{

}

void R3C4ShortClipFunction(void)
{

}

void R41ShortClipFunction(void)
{

}

void R4C2ShortClipFunction(void)
{

}

void R4C3ShortClipFunction(void)
{

}

void R4C4ShortClipFunction(void)
{

}

void R1C1LongClipFunction(void)
{
	
}

void R1C2LongClipFunction(void)
{
	
}

void R1C3LongClipFunction(void)
{
	
}

void R1C4LongClipFunction(void)
{
	
}

void R2C1LongClipFunction(void)
{
	
}

void R2C2LongClipFunction(void)
{
	
}

void R2C3LongClipFunction(void)
{
	
}

void R2C4LongClipFunction(void)
{
	
}

void R3C1LongClipFunction(void)
{
	
}

void R3C2LongClipFunction(void)
{
	
}

void R3C3LongClipFunction(void)
{
	
}

void R3C4LongClipFunction(void)
{
	
}

void R4C1LongClipFunction(void)
{
	
}

void R4C2LongClipFunction(void)
{
	
}

void R4C3LongClipFunction(void)
{
	
}

void R4C4LongClipFunction(void)
{
	
}

void ElseFunction(void)
{

}

