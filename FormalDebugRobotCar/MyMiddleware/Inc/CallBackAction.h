#ifndef CALLBACKACTION_H_
#define CALLBACKACTION_H_

#include "usart.h"
#include "Gyro.h"
#include "GraySensor.h"

//��������ز���
extern uint8_t GyroOpenFlag;
extern uint8_t GyroReceiveNum;
extern uint8_t GyroReceiveBuffer[11];

//�Ҷȴ�������ز���
extern uint8_t GraySensorReceiveBuffer[18];

#endif