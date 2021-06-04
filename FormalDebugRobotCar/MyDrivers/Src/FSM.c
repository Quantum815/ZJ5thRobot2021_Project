/**
  ******************************************************************************
  * @file    FSM.c
  * @author  YL
  * @brief   ״̬��
  *
  @verbatim
	��
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "FSM.h"

/* Define\Declare ------------------------------------------------------------*/

/**
 ******************************************************************************
 *  @defgroup �ⲿ����
 *  @brief
 *
**/
//״̬����ʼ��
void FSMInit(FSM_t *fsm, uint8_t state, FSMTable_t *fsmtable)
{
	fsm->CurState = state;
  fsm->FsmTable = fsmtable;
	fsm->Size = sizeof(*fsmtable) / sizeof(FSMTable_t);
}

//״̬�����У��Զ�������ת��
void FSMRun(FSM_t *fsm)
{
	uint8_t curState = fsm->CurState;  //״̬����ǰ״̬
	FSMTable_t *fsmTable = fsm->FsmTable;  //״̬��״̬��
	void (*eventAction)(void) = fsmTable[curState].EventAction;  //״̬����ǰ״ִ̬�к���
	uint8_t (*eventJumpCondition)(void) = fsmTable[curState].EventJumpCondition;  //״̬����ת�¼���������
	uint8_t size = fsm->Size;  //״̬��״̬��
	
	if(eventJumpCondition())
	{
		fsm->CurState = fsmTable[curState].NextState;
		eventAction = fsmTable[fsm->CurState].EventAction;
	}
	eventAction();
}

//״̬������ת  ����1��0
uint8_t FSMTransfer(FSM_t *fsmA, FSM_t *fsmB, EventJumpCondition_t eventJumpCondition)
{
	uint8_t curStateA = fsmA->CurState;
	uint8_t curStateB = fsmB->CurState;
	uint8_t sizeA = fsmA->Size;
	
	if(curStateA == sizeA-1 && eventJumpCondition())
		return 1;
	else
		return 0;
}

//״̬����ǰ״̬��ȡ
uint8_t FSMStateGet(FSM_t *fsm)
{
	return fsm->CurState;
}