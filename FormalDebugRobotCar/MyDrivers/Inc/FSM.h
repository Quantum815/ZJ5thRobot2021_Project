#ifndef FSM_H_
#define FSM_H_

#include "main.h"
#include "stdio.h"

typedef void (*EventAction_t)(void);  //��ǰ״ִ̬�к�����ָ��
typedef uint8_t (*EventJumpCondition_t)(void);   //��ת�¼�����������ָ�루����ֻ�ܷ���1��0��

typedef struct FSMTable  //״̬��
{
	uint8_t CurState;  //��ǰ״̬��ö�����ʹ�0��ʼ��
	EventAction_t EventAction;  //��ǰ״ִ̬�к�����ָ��
	EventJumpCondition_t EventJumpCondition;   //��ת�¼�����������ָ��
	uint8_t NextState;  //��һ��״̬
}FSMTable_t;

typedef struct FSM  //״̬��
{
	uint8_t CurState;  //��ǰ״̬��ö�����ʹ�0��ʼ��
	FSMTable_t *FsmTable;  //״̬��
	uint8_t Size;  //�������
}FSM_t;


void FSMInit(FSM_t *fsm, uint8_t state, FSMTable_t *fsmtable);
void FSMRun(FSM_t *fsm);
uint8_t FSMTransfer(FSM_t *fsmA, FSM_t *fsmB, EventJumpCondition_t eventJumpCondition);
uint8_t FSMStateGet(FSM_t *fsm);

#endif