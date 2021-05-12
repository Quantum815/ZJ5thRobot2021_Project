#ifndef GYRO_H_
#define GYRO_H_

#include "usart.h"

#define GYRO_USART_TX_GPIO_PORT  GPIOE      
#define GYRO_USART_TX_GPIO_PIN   GPIO_PIN_1
#define GYRO_USART_RX_GPIO_PORT  GPIOE 
#define GYRO_USART_RX_GPIO_PIN   GPIO_PIN_0

#define GyroUartHandle huart8

typedef struct
{
	double RollAngle;  //¹ö¶¯½Ç
	
	double PitchAngle;  //¸©Ñö½Ç
	
	double YawAngle;  //Æ«º½½Ç
	
} Gyro_AngleTypeDef;

void GyroInit(void);
void GyroOpen(void);
void GyroClose(void);
double GyroRollAngleGet(void);
double GyroPitchAngleGet(void);
double GyroYawAngleGet(void);
uint8_t GyroOneOfElevenReceiveBufferGet(uint8_t num);

void Short2Char(short sData, uint8_t cData[]);
short Char2Short(uint8_t cData[]);
uint8_t GyroCheckSumJudge(void);
double GyroEulerAnglesProcess(uint8_t cData[]);
void GyroGetAllAngles(void);

#endif