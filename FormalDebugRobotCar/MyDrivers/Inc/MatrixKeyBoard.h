#ifndef MATRIXKEYBOARD_H_
#define MATRIXKEYBOARD_H_

#include "gpio.h"

//��
#define Row1_GPIO_PORT     GPIOD
#define Row1_PIN           GPIO_PIN_0
#define Row2_GPIO_PORT     GPIOD
#define Row2_PIN           GPIO_PIN_1
#define Row3_GPIO_PORT     GPIOD
#define Row3_PIN           GPIO_PIN_2
#define Row4_GPIO_PORT     GPIOD
#define Row4_PIN           GPIO_PIN_3
//��
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
	Key_Up = 0U,     //��������
	Key_Shake,       //��������
	Key_ShortPress,  //�����̰�
	Key_LongPress,   //��������
} Matrix_KeyState;  //����״̬

typedef enum
{
	Key_NoPress = 0U,  //����δ��
	Key_ShortClip,     //�����̻�
	Key_LongClip,      //��������
} Matrix_KeyMode;  //����ģʽ

void MatrixKeyboardScanning(void);
void R1C1ShortFunction(void);
void R1C2ShortFunction(void);
void R1C3ShortFunction(void);
void R1C4ShortFunction(void);
void R2C1ShortFunction(void);
void R2C2ShortFunction(void);
void R2C3ShortFunction(void);
void R2C4ShortFunction(void);
void R3C1ShortFunction(void);
void R3C2ShortFunction(void);
void R3C3ShortFunction(void);
void R3C4ShortFunction(void);
void R4C1ShortFunction(void);
void R4C2ShortFunction(void);
void R4C3ShortFunction(void);
void R4C4ShortFunction(void);

void R1C1LongFunction(void);
void R1C2LongFunction(void);
void R1C3LongFunction(void);
void R1C4LongFunction(void);
void R2C1LongFunction(void);
void R2C2LongFunction(void);
void R2C3LongFunction(void);
void R2C4LongFunction(void);
void R3C1LongFunction(void);
void R3C2LongFunction(void);
void R3C3LongFunction(void);
void R3C4LongFunction(void);
void R4C1LongFunction(void);
void R4C2LongFunction(void);
void R4C3LongFunction(void);
void R4C4LongFunction(void);

void ElseFunction(void);

#endif
