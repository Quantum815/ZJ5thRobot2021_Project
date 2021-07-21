#ifndef LINEPATROLACTION_H_
#define LINEPATROLACTION_H_

#include "PID.h"
#include "GraySensor.h"
#include "InductiveMotor.h"
#include "Miscellaneous.h"

void NormalLineSpeedPatrol(double current);
double GraySensorBiasGet(void);

#endif