#ifndef MATRIXKEYBOARD_H_
#define MATRIXKEYBOARD_H_

#include "gpio.h"

//��
#define Row1_GPIO_PORT     GPIOE
#define Row1_PIN           GPIO_PIN_2
#define Row2_GPIO_PORT     GPIOE
#define Row2_PIN           GPIO_PIN_3
#define Row3_GPIO_PORT     GPIOE
#define Row3_PIN           GPIO_PIN_4
#define Row4_GPIO_PORT     GPIOE
#define Row4_PIN           GPIO_PIN_5
//��
#define Column1_GPIO_PORT  GPIOA
#define Column1_PIN        GPIO_PIN_0
#define Column2_GPIO_PORT  GPIOA
#define Column2_PIN        GPIO_PIN_1
#define Column3_GPIO_PORT  GPIOA
#define Column3_PIN        GPIO_PIN_2
#define Column4_GPIO_PORT  GPIOA
#define Column4_PIN        GPIO_PIN_3

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
