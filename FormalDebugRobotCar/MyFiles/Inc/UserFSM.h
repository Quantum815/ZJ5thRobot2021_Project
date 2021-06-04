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

void AA(FSM_t* FSM);
void BB(FSM_t* FSM);
void CC(FSM_t* FSM);

uint8_t Axxx(void);
uint8_t Bxxx(void);
uint8_t Cxxx(void);

#endif