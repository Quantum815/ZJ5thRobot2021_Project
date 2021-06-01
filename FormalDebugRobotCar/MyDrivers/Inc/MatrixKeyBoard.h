#ifndef MATRIXKEYBOARD_H_
#define MATRIXKEYBOARD_H_

#include "gpio.h"
#include "Miscellaneous.h"

//ÐÐ
#define ROW1_GPIO_PORT     GPIOD
#define ROW1_PIN           GPIO_PIN_0
#define ROW2_GPIO_PORT     GPIOD
#define ROW2_PIN           GPIO_PIN_1
#define ROW3_GPIO_PORT     GPIOD
#define ROW3_PIN           GPIO_PIN_2
#define ROW4_GPIO_PORT     GPIOD
#define ROW4_PIN           GPIO_PIN_3
//ÁÐ
#define COLUMN1_GPIO_PORT        GPIOD
#define COLUMN1_PIN              GPIO_PIN_4
#define COLUMN2_GPIO_PORT        GPIOD
#define COLUMN2_PIN              GPIO_PIN_5
#define COLUMN3_GPIO_PORT        GPIOD
#define COLUMN3_PIN              GPIO_PIN_6
#define COLUMN4_GPIO_PORT        GPIOD
#define COLUMN4_PIN              GPIO_PIN_7

void MatrixKeyBoardInit(void);
void MatrixKeyBoardConfirm(void);
void MatrixKeyBoardCOLUMN1Confirm(void);
void MatrixKeyBoardCOLUMN2Confirm(void);
void MatrixKeyBoardCOLUMN3Confirm(void);
void MatrixKeyBoardCOLUMN4Confirm(void);

void R1C1ClipFunction(void);
void R1C2ClipFunction(void);
void R1C3ClipFunction(void);
void R1C4ClipFunction(void);
void R2C1ClipFunction(void);
void R2C2ClipFunction(void);
void R2C3ClipFunction(void);
void R2C4ClipFunction(void);
void R3C1ClipFunction(void);
void R3C2ClipFunction(void);
void R3C3ClipFunction(void);
void R3C4ClipFunction(void);
void R4C1ClipFunction(void);
void R4C2ClipFunction(void);
void R4C3ClipFunction(void);
void R4C4ClipFunction(void);
void ElseFunction(void);

#endif
