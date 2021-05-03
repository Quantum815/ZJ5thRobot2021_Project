#ifndef CALLBACKACTION_H_
#define CALLBACKACTION_H_

#include "Miscellaneous.h"
#include "Gyro.h"
#include "GraySensor.h"

//LED
#define LED_GPIO_PORT  GPIOC      
#define LED_GPIO_PIN   GPIO_PIN_13 

//��������ز���
extern uint8_t GyroOpenFlag;
extern uint8_t GyroReceiveNum;
extern uint8_t GyroReceiveBuffer[11];

//�Ҷȴ�������ز���
extern uint8_t GraySensorReceiveBuffer[18];

#endif