#ifndef GYRO_H_
#define GYRO_H_

#include "usart.h"

#define GYRO_USART_TX_GPIO_PORT  GPIOB      
#define GYRO_USART_TX_GPIO_PIN   GPIO_PIN_13
#define GYRO_USART_RX_GPIO_PORT  GPIOB      
#define GYRO_USART_RX_GPIO_PIN   GPIO_PIN_12

#define GyroUartHandle huart5

typedef struct
{
	double RollAngle;  //¹ö¶¯½Ç
	
	double PitchAngle;  //¸©Ñö½Ç
	
	double YawAngle;  //Æ«º½½Ç
	
} GYRO_AngleTypeDef;


void Short2Char(short sData, uint8_t cData[]);
short Char2Short(uint8_t cData[]);
uint8_t GyroCheckSumJudge(void);
double GyroEulerAnglesProcess(uint8_t cData[]);

void GyroInit(void);
void GyroOpen(void);
void GyroClose(void);
void GyroGetAllAngles(void);
double GetGyroRollAngle(void);
double GetGyroPitchAngle(void);
double GetGyroYawAngle(void);
uint8_t* GetGyroReceiveBuffer(void);

#endif