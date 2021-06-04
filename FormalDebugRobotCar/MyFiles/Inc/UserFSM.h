#ifndef USERFSM_H_
#define USERFSM_H_

#include "FSM.h"
#include "UserMain.h"
#include "main.h"

enum CarState  //״̬
{
	A = 0,
	B,
	C
};

void AA(void);
void BB(void);
void CC(void);

uint8_t Axxx(void);
uint8_t Bxxx(void);
uint8_t Cxxx(void);

#endif