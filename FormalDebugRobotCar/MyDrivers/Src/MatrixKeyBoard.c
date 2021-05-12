/**
  ******************************************************************************
  * @file    MatrixKeyBoard.c
  * @author  YL
  * @brief   4*4æÿ’Ûº¸≈Ã
  *
  @verbatim
	
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "MatrixKeyBoard.h"

/* Define\Declare ------------------------------------------------------------*/
int KeyFlag;
Matrix_KeyState keyState[4][4] = {{Key_Up}, {Key_Up}, {Key_Up}, {Key_Up}};  //œ»––∫Û¡–
Matrix_KeyMode keyMode[4][4] = {{Key_NoPress}, {Key_NoPress}, {Key_NoPress}, {Key_NoPress}};

//æÿ’Û¡–…®√Ë
void MatrixKeyboardScanning(void)
{
	HAL_GPIO_WritePin(Row1_GPIO_PORT, Row1_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Row2_GPIO_PORT, Row2_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Row3_GPIO_PORT, Row3_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Row4_GPIO_PORT, Row4_PIN, GPIO_PIN_SET);
	if(!HAL_GPIO_ReadPin(Column1_GPIO_PORT, Column1_PIN))
	{
		keyState[1][0] = Key_Shake;
	}
	else if(!HAL_GPIO_ReadPin(Column2_GPIO_PORT, Column2_PIN))
	{
		keyState[1][0] = Key_Shake;
	}
	else if(!HAL_GPIO_ReadPin(Column3_GPIO_PORT, Column3_PIN))
	{
		keyState[2][0] = Key_Shake;
	}
	else if(!HAL_GPIO_ReadPin(Column4_GPIO_PORT, Column4_PIN))
	{
		keyState[3][0] = Key_Shake;
	}
	else
		KeyFlag = 0;
	
	HAL_GPIO_WritePin(Row1_GPIO_PORT, Row1_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Row2_GPIO_PORT, Row2_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Row3_GPIO_PORT, Row3_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Row4_GPIO_PORT, Row4_PIN, GPIO_PIN_SET);
	if(!HAL_GPIO_ReadPin(Column1_GPIO_PORT, Column1_PIN))
	{
		keyState[0][1] = Key_Shake;
	}
	else if(!HAL_GPIO_ReadPin(Column2_GPIO_PORT, Column2_PIN))
	{
		keyState[1][1] = Key_Shake;
	}
	else if(!HAL_GPIO_ReadPin(Column3_GPIO_PORT, Column3_PIN))
	{
		keyState[2][1] = Key_Shake;
	}
	else if(!HAL_GPIO_ReadPin(Column4_GPIO_PORT, Column4_PIN))
	{
		keyState[3][1] = Key_Shake;
	}

	HAL_GPIO_WritePin(Row1_GPIO_PORT, Row1_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Row2_GPIO_PORT, Row2_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Row3_GPIO_PORT, Row3_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Row4_GPIO_PORT, Row4_PIN, GPIO_PIN_SET);	
	if(!HAL_GPIO_ReadPin(Column1_GPIO_PORT, Column1_PIN))
	{
		keyState[0][2] = Key_Shake;
	}
	else if(!HAL_GPIO_ReadPin(Column2_GPIO_PORT, Column2_PIN))
	{
		keyState[1][2] = Key_Shake;
	}
	else if(!HAL_GPIO_ReadPin(Column3_GPIO_PORT, Column3_PIN))
	{
		keyState[2][2] = Key_Shake;
	}
	else if(!HAL_GPIO_ReadPin(Column4_GPIO_PORT, Column4_PIN))
	{
		keyState[3][2] = Key_Shake;
	}

	HAL_GPIO_WritePin(Row1_GPIO_PORT, Row1_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Row2_GPIO_PORT, Row2_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Row3_GPIO_PORT, Row3_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Row4_GPIO_PORT, Row4_PIN, GPIO_PIN_RESET);
	if(!HAL_GPIO_ReadPin(Column1_GPIO_PORT, Column1_PIN))
	{
		keyState[0][3] = Key_Shake;
	}
	else if(!HAL_GPIO_ReadPin(Column2_GPIO_PORT, Column2_PIN))
	{
		keyState[1][3] = Key_Shake;
	}
	else if(!HAL_GPIO_ReadPin(Column3_GPIO_PORT, Column3_PIN))
	{
		keyState[2][3] = Key_Shake;
	}
	else if(!HAL_GPIO_ReadPin(Column4_GPIO_PORT, Column4_PIN))
	{
		keyState[3][3] = Key_Shake;
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

void R1C1ShortFunction(void)
{

}

void R1C2ShortFunction(void)
{

}
void R1C3ShortFunction(void)
{

}
void R1C4ShortFunction(void)
{

}
void R2C1ShortFunction(void)
{

}

void R2C2ShortFunction(void)
{

}

void R2C3ShortFunction(void)
{

}

void R2C4ShortFunction(void)
{

}

void R3C1ShortFunction(void)
{

}

void R3C2ShortFunction(void)
{

}

void R3C3ShortFunction(void)
{

}

void R3C4ShortFunction(void)
{

}

void R41ShortFunction(void)
{

}

void R4C2ShortFunction(void)
{

}

void R4C3ShortFunction(void)
{

}

void R4C4ShortFunction(void)
{

}

void R1C1LongFunction(void)
{
	
}

void R1C2LongFunction(void)
{
	
}

void R1C3LongFunction(void)
{
	
}

void R1C4LongFunction(void)
{
	
}

void R2C1LongFunction(void)
{
	
}

void R2C2LongFunction(void)
{
	
}

void R2C3LongFunction(void)
{
	
}

void R2C4LongFunction(void)
{
	
}

void R3C1LongFunction(void)
{
	
}

void R3C2LongFunction(void)
{
	
}

void R3C3LongFunction(void)
{
	
}

void R3C4LongFunction(void)
{
	
}

void R4C1LongFunction(void)
{
	
}

void R4C2LongFunction(void)
{
	
}

void R4C3LongFunction(void)
{
	
}

void R4C4LongFunction(void)
{
	
}

void ElseFunction(void)
{

}

