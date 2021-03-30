#ifndef USERFSMFRAME_H_
#define USERFSMFRAME_H_

#include "UserMain.h"
#include "stm32h7xx_hal.h"
#include "UserFsmCondition.h"
#include "UserFsmJump.h"

enum CarState  //状态  带下划线大驼峰命名
{
	Waiting_To_Start,
	Stop
};

enum CarEvent  //事件  带下划线全大写命名
{
	NO_EVENT,
	BAFFLE_REMOVED
};

typedef struct FsmTable{
	int CurrentState;  //当前状态
	uint8_t (*EventCondition)();  //状态跳转条件判断函数指针
	void (*EventAction)();  //状态跳转执行函数指针
	int NextState;  //下一个状态
}FsmTable_t;
extern FsmTable_t CarFsmTable[];

typedef struct Fsm{
    int CurrentState;  //当前状态
    FsmTable_t *FsmTable;  //状态表
    int Size;  //表的项数
}Fsm_t;
extern Fsm_t CarFsm;

//状态机功能函数
void FsmFirstRegister(Fsm_t *fsm, int firstState, FsmTable_t *fsmtable);
void FsmStateTransfer(Fsm_t* fsm, uint8_t (*eventcondition)());
int ReturnFsmCurrentState(Fsm_t *fsm);
void FsmRun(void);

#endif