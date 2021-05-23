#ifndef MATRIXKEYBOARD_H_
#define MATRIXKEYBOARD_H_

#include "gpio.h"

//行
#define COLUMN1_GPIO_PORT     GPIOD
#define COLUMN1_PIN           GPIO_PIN_0
#define COLUMN2_GPIO_PORT     GPIOD
#define COLUMN2_PIN           GPIO_PIN_1
#define COLUMN3_GPIO_PORT     GPIOD
#define COLUMN3_PIN           GPIO_PIN_2
#define COLUMN4_GPIO_PORT     GPIOD
#define COLUMN4_PIN           GPIO_PIN_3
//列
#define ROW1_GPIO_PORT        GPIOD
#define ROW1_PIN              GPIO_PIN_4
#define ROW2_GPIO_PORT        GPIOD
#define ROW2_PIN              GPIO_PIN_5
#define ROW3_GPIO_PORT        GPIOD
#define ROW3_PIN              GPIO_PIN_6
#define ROW4_GPIO_PORT        GPIOD
#define ROW4_PIN              GPIO_PIN_7

typedef enum
{
	Key_Up = 0U,     //按键弹起
	Key_Shake,       //按键防抖
	Key_ShortClip,  //按键短按
	Key_LongClip,   //按键长按
} Matrix_KeyState;  //按键状态

void MatrixKeyboardScanning(void);
void R1C1ShortClipFunction(void);
void R1C2ShortClipFunction(void);
void R1C3ShortClipFunction(void);
void R1C4ShortClipFunction(void);
void R2C1ShortClipFunction(void);
void R2C2ShortClipFunction(void);
void R2C3ShortClipFunction(void);
void R2C4ShortClipFunction(void);
void R3C1ShortClipFunction(void);
void R3C2ShortClipFunction(void);
void R3C3ShortClipFunction(void);
void R3C4ShortClipFunction(void);
void R4C1ShortClipFunction(void);
void R4C2ShortClipFunction(void);
void R4C3ShortClipFunction(void);
void R4C4ShortClipFunction(void);

void R1C1LongClipFunction(void);
void R1C2LongClipFunction(void);
void R1C3LongClipFunction(void);
void R1C4LongClipFunction(void);
void R2C1LongClipFunction(void);
void R2C2LongClipFunction(void);
void R2C3LongClipFunction(void);
void R2C4LongClipFunction(void);
void R3C1LongClipFunction(void);
void R3C2LongClipFunction(void);
void R3C3LongClipFunction(void);
void R3C4LongClipFunction(void);
void R4C1LongClipFunction(void);
void R4C2LongClipFunction(void);
void R4C3LongClipFunction(void);
void R4C4LongClipFunction(void);

void ElseFunction(void);

#endif
