#ifndef MATRIXKEYBOARD_H_
#define MATRIXKEYBOARD_H_

#include "gpio.h"

//列
#define Row1_GPIO_PORT     GPIOD
#define Row1_PIN           GPIO_PIN_0
#define Row2_GPIO_PORT     GPIOD
#define Row2_PIN           GPIO_PIN_1
#define Row3_GPIO_PORT     GPIOD
#define Row3_PIN           GPIO_PIN_2
#define Row4_GPIO_PORT     GPIOD
#define Row4_PIN           GPIO_PIN_3
//行
#define Column1_GPIO_PORT  GPIOD
#define Column1_PIN        GPIO_PIN_4
#define Column2_GPIO_PORT  GPIOD
#define Column2_PIN        GPIO_PIN_5
#define Column3_GPIO_PORT  GPIOD
#define Column3_PIN        GPIO_PIN_6
#define Column4_GPIO_PORT  GPIOD
#define Column4_PIN        GPIO_PIN_7

typedef enum
{
	Key_Up = 0U,     //按键弹起
	Key_Shake,       //按键防抖
	Key_ShortPress,  //按键短按
	Key_LongPress,   //按键长按
} Matrix_KeyState;  //按键状态

typedef enum
{
	Key_NoPress = 0U,  //按键未按
	Key_ShortClip,     //按键短击
	Key_LongClip,      //按键长击
} Matrix_KeyMode;  //按键模式

void MatrixKeyboardScanning(void);
void R1C1Function(void);
void R1C2Function(void);
void R1C3Function(void);
void R1C4Function(void);
void R2C1Function(void);
void R2C2Function(void);
void R2C3Function(void);
void R2C4Function(void);
void R3C1Function(void);
void R3C2Function(void);
void R3C3Function(void);
void R3C4Function(void);
void R4C1Function(void);
void R4C2Function(void);
void R4C3Function(void);
void R4C4Function(void);
void ElseFunction(void);

#endif
