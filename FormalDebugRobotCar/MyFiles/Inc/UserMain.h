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
#include "ILI9341_STM32_Driver.h"
#include "ILI9341_GFX.h"
#include "Gui.h"

extern FSM_t CarFSM;
extern FSMTable_t CarTable[];

void UserInit(void);
void UserLoop(void);

#endif