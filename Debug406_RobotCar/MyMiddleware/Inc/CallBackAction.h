#ifndef CALLBACKACTION_H_
#define CALLBACKACTION_H_

#include "usart.h"
#include "Gyro.h"

//��������ز���
extern uint8_t GyroReceiveNum;
extern uint8_t GyroReceiveBuffer[11];
extern uint8_t GyroOpenFlag;

//�Ҷȴ�������ز���
extern uint8_t GraySensorConfigConfirm[2];
extern uint8_t GraySensorReceiveBuffer[18];
extern uint8_t GraySensorInstructionNum;

#endif