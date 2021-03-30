#ifndef USERFSMFRAME_H_
#define USERFSMFRAME_H_

#include "UserMain.h"
#include "stm32h7xx_hal.h"
#include "UserFsmCondition.h"
#include "UserFsmJump.h"

enum CarState  //״̬  ���»��ߴ��շ�����
{
	Waiting_To_Start,
	Stop
};

enum CarEvent  //�¼�  ���»���ȫ��д����
{
	NO_EVENT,
	BAFFLE_REMOVED
};

typedef struct FsmTable{
	int CurrentState;  //��ǰ״̬
	uint8_t (*EventCondition)();  //״̬��ת�����жϺ���ָ��
	void (*EventAction)();  //״̬��תִ�к���ָ��
	int NextState;  //��һ��״̬
}FsmTable_t;
extern FsmTable_t CarFsmTable[];

typedef struct Fsm{
    int CurrentState;  //��ǰ״̬
    FsmTable_t *FsmTable;  //״̬��
    int Size;  //�������
}Fsm_t;
extern Fsm_t CarFsm;

//״̬�����ܺ���
void FsmFirstRegister(Fsm_t *fsm, int firstState, FsmTable_t *fsmtable);
void FsmStateTransfer(Fsm_t* fsm, uint8_t (*eventcondition)());
int ReturnFsmCurrentState(Fsm_t *fsm);
void FsmRun(void);

#endif