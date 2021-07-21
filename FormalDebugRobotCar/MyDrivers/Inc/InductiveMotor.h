#ifndef INDUCTIVEMOTOR_H_
#define INDUCTIVEMOTOR_H_

#define RIGHTMOTOR_USART1_TX_GPIO_PORT  GPIOB  
#define RIGHTMOTOR_USART1_TX_GPIO_PIN   GPIO_PIN_14
#define RIGHTMOTOR_USART1_RX_GPIO_PORT  GPIOB 
#define RIGHTMOTOR_USART1_RX_GPIO_PIN   GPIO_PIN_15
#define RIGHTMOTOR_RST_GPIO_PORT        GPIOD
#define RIGHTMOTOR_RST_GPIO_PIN         GPIO_PIN_8

#define RIGHTMOTORUartHandle huart1

#define LEFTMOTOR_UART4_TX_GPIO_PORT  GPIOA     
#define LEFTMOTOR_UART4_TX_GPIO_PIN   GPIO_PIN_0
#define LEFTMOTOR_UART4_RX_GPIO_PORT  GPIOA
#define LEFTMOTOR_UART4_RX_GPIO_PIN   GPIO_PIN_1
#define LEFTMOTOR_RST_GPIO_PORT       GPIOA
#define LEFTMOTOR_RST_GPIO_PIN        GPIO_PIN_2

#define LEFTMOTORUartHandle huart4

#include "gpio.h"
#include "usart.h"

#define LMOTOR 			0
#define RMOTOR 			1
#define ALLMOTOR 		2

void MotorInit(void);
void SetMotorSpeed(uint8_t targetMotor, int16_t* Speed);
void StartMotor(void);
void StopMotor(void);

void DebugMotor(void);

int16_t Current2Torque(double Di);

#endif