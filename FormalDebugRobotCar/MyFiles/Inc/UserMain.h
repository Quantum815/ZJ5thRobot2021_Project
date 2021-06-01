#ifndef USERMAIN_H_
#define USERMAIN_H_

#include "Miscellaneous.h"
#include "CallBackAction.h"
#include "Gyro.h"
#include "GraySensor.h"
#include "DiffuseReflectionLaser.h"
#include "ServoMotor.h"
#include "MatrixKeyBoard.h"
#include "RangingLaser.h"
#include "FSM.h"
#include "UserFSM.h"

extern FSM_t CarFSM;
extern FSMTable_t CarTable[];

void UserInit(void);
void UserLoop(void);

#endif