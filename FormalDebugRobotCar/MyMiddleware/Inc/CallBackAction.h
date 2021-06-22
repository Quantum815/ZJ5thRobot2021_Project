#ifndef CALLBACKACTION_H_
#define CALLBACKACTION_H_

#include "Miscellaneous.h"
#include "Gyro.h"
#include "GraySensor.h"
#include "DiffuseReflectionLaser.h"
#include "RangingLaser.h"
#include "MatrixKeyBoard.h"
#include "FSM.h"
#include "UserFSM.h"

//状态机相关参数
extern FSM_t CarFSM;
extern FSMTable_t CarTable[];

//陀螺仪相关参数
extern uint8_t GyroReceiveNum;
extern uint8_t GyroReceiveBuffer[11];

//灰度传感器相关参数
extern uint8_t GraySensorReceiveBuffer[18];
extern uint8_t GraySensorTransferFlag, GraySensorRecieveFlag;

//漫反射激光传感器相关参数
extern DiffuseReflectionLaser_Change_State Left_DFLaser_Change_State;
extern DiffuseReflectionLaser_Change_State Right_DFLaser_Change_State;

//矩阵键盘相关参数
extern uint8_t KeyState;

#endif