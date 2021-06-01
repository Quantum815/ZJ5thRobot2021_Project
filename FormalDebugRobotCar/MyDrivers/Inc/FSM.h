#ifndef FSM_H_
#define FSM_H_

#include "main.h"
#include "stdio.h"

typedef void (*EventAction_t)(void);  //当前状态执行函数的指针
typedef uint8_t (*EventJumpCondition_t)(void);   //跳转事件条件函数的指针（函数只能返回1或0）

typedef struct FSMTable  //状态表
{
	uint8_t CurState;  //当前状态（枚举类型从0开始）
	EventAction_t EventAction;  //当前状态执行函数的指针
	EventJumpCondition_t EventJumpCondition;   //跳转事件条件函数的指针
	uint8_t NextState;  //下一个状态
}FSMTable_t;

typedef struct FSM  //状态机
{
	uint8_t CurState;  //当前状态（枚举类型从0开始）
	FSMTable_t *FsmTable;  //状态表
	uint8_t Size;  //表的项数
}FSM_t;


void FSMInit(FSM_t *fsm, uint8_t state, FSMTable_t *fsmtable);
void FSMRun(FSM_t *fsm);
uint8_t FSMTransfer(FSM_t *fsmA, FSM_t *fsmB, EventJumpCondition_t eventJumpCondition);
uint8_t FSMStateGet(FSM_t *fsm);

#endif