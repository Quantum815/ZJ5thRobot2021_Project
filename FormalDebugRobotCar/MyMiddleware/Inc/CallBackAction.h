#ifndef CALLBACKACTION_H_
#define CALLBACKACTION_H_

#include "usart.h"
#include "Gyro.h"
#include "GraySensor.h"

//陀螺仪相关参数
extern uint8_t GyroReceiveNum;
extern uint8_t GyroReceiveBuffer[11];
extern uint8_t GyroOpenFlag;

//灰度传感器相关参数
extern uint8_t GraySensorConfirmOrReceiveBuffer[18];
extern uint8_t GraySensorInstructionNum;

#endif