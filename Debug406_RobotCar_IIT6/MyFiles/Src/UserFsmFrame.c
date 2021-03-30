/**
  ******************************************************************************
  * @file    UserFsmFrame.c
  * @author  YL
  * @brief   状态机
  *
	@verbatim
	
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "UserFsmFrame.h"

FsmTable_t CarFsmTable[] =
{ 
//            当前状态      跳转条件                 执行函数                 下一状态
//	    正常执行状态表
	{      Waiting_To_Start,  NoCondition,         WaitingToStart,        Waiting_To_Start      },
	
	
	
//	  强制停止状态表

};
Fsm_t CarFsm;


/**
 ******************************************************************************
 *  @defgroup 状态机功能函数
 *  @brief 
 *
**/

/**
  * @brief  状态机初始注册
  * @param  略
  * @retval 无
  */
void FsmFirstRegister(Fsm_t *fsm, int firstState, FsmTable_t *fsmtable)
{
	fsm->CurrentState = firstState;
	fsm->FsmTable = fsmtable;
	fsm->Size = sizeof(&fsmtable) / sizeof(FsmTable_t);
}

/**
  * @brief  状态机状态跳转
  * @param  略
  * @retval 无
  */
void FsmStateTransfer(Fsm_t* fsm, uint8_t (*eventcondition)())
{
	FsmTable_t *fsmTable = fsm->FsmTable;
	int currentState = fsm->CurrentState;
	void (*eventAction)();
	int nextState = -1;
	int size = fsm->Size;
	int i;

	//获取当前动作函数
	for (i=0; i<size; i++)
	{
			//当且仅当当前状态下来个指定的事件，我才执行它
			if (eventcondition == fsmTable[i].EventCondition && currentState == fsmTable[i].CurrentState)
			{
					eventAction = fsmTable[i].EventAction;
					nextState = fsmTable[i].NextState;
				if(eventAction)
					eventAction();
					fsm->CurrentState = fsmTable[i].NextState;
					break;
			}
	}	
}

/**
  * @brief  状态机当前状态获取
  * @param  略
  * @retval 无
  */
int ReturnFsmCurrentState(Fsm_t *fsm)
{
	return fsm->CurrentState;
}

/**
  * @brief  状态机执行内容
  * @param  略
  * @retval 无
  */
void FsmRun(void)
{
//    FsmRegist(&CarFsm, CarTable);
//	if(!StartFlag)
//	{
//		CarFsm.CurState = WaitBall;
//		StartFlag = 1;
//	}
//    CarFsm.Size = sizeof(CarTable) / sizeof(FsmTable_t);

//    if((KickFlag||TwoCarStateJudge()) && ReturnFsmState(&CarFsm) == WaitBall)
//    {
//    		FsmEventHandle(&CarFsm, GETBALL);
//    }


////    else if(ADCValueHandle(2) >= ADCvalueC && (ADCValueHandle(1) >= ADCvalueCL || ADCValueHandle(3) >= ADCvalueCR)\
////    && (ADCValueHandle(0) > ADCvalueLL || ADCValueHandle(4) > ADCvalueRR) && ReturnFsmState(&CarFsm) == GoLine)
////    {
////    	FsmEventHandle(&CarFsm, NOROUNDABOUT);
////    }
////    else if(GoOnFlag && ReturnFsmState(&CarFsm) == GoOn)
////    {
////    	FsmEventHandle(&CarFsm, FINISHROUND);
////    }


//    else if(GetDistance() >= 7.4/*13*/ && ADCValueHandle(2) >= ADCvalueC && (ADCValueHandle(1) >= ADCvalueCL || ADCValueHandle(3) >= ADCvalueCR)\
//    && (ADCValueHandle(0) > ADCvalueLL || ADCValueHandle(4) > ADCvalueRR) && ReturnFsmState(&CarFsm) == GoLine)//检测进圆
//    {
//    	IntoRoundaboutCount++;
//    	if(IntoRoundaboutCount >= 3)//连续检测三次
//    	{
//    		if(ADCValueHandle(1) > ADCValueHandle(3))//判断左圆或右圆
//			{
////    	    	uart_putchar(UART_3,0X01);//状态检测1
//				LRoundaboutFlag = 1;//左圆
//				RRoundaboutFlag = 0;
//			}
//			else
//			{
//				LRoundaboutFlag = 0;
//				RRoundaboutFlag = 1;//右圆
//			}
//    		GyroYawAngleInit(InRAngle);
//            CleanDistance();
//            InitCulAngle();
//            OutRAroll = YawAngle;
//            FsmEventHandle(&CarFsm, FINDROUNDABOUT);
////            FsmEventHandle(&CarFsm, RUNSTOP);
//    	}
//    }
//    else if(GetDistance() >= 0.8 && ReturnFsmState(&CarFsm) == InRoundabout)//圆内过程
//    {
////    	uart_putchar(UART_3,0X04);//状态检测4
//    	CleanPIDValue();
//    	FsmEventHandle(&CarFsm, ENDINROUNDABOUT);
//    }
//    else if(CulAngle() >= 360 && ReturnFsmState(&CarFsm) == PassRoundabout)//检测出圆
//    {
////    	uart_putchar(UART_3,0X05);//状态检测5
//    	GyroYawAngleInit(OutRAroll + OutRALeftAngle);
//        CleanPIDValue();
//    	FsmEventHandle(&CarFsm, OUTROUNDABOUT);
////    	FsmEventHandle(&CarFsm, RUNSTOP);
//    }
//    else if(GetDistance() > 1 && ReturnFsmState(&CarFsm) == OutingRoundabout)
//    {
//    	CleanPIDValue();
//      	FsmEventHandle(&CarFsm, ENDOUTROUNDABOUT);
////		FsmEventHandle(&CarFsm, RUNSTOP);
//    }
//    else if(!InGarageDirection && EnterGarageFlag && ReturnFsmState(&CarFsm) == GoLine)
//    {
//        MotorUserHandle(LMotor_F, LeftWheelDeadZone+LeftInGarageSpeed);
//        MotorUserHandle(RMotor_F, RightWheelDeadZone+RightInGarageSpeed);
//    	FsmEventHandle(&CarFsm, LEFTFINDZEBRA);
//    }
//    else if(InGarageDirection && EnterGarageFlag && ReturnFsmState(&CarFsm) == GoLine)
//    {
//        MotorUserHandle(LMotor_F, LeftWheelDeadZone+LeftInGarageSpeed);
//        MotorUserHandle(RMotor_F, RightWheelDeadZone+RightInGarageSpeed);
//    	FsmEventHandle(&CarFsm, RIGHTFINDZEBRA);
//    }
//    else if(GoGarageFinishFlag && ReturnFsmState(&CarFsm) == LeftInGarage)
//    {
//    	FsmEventHandle(&CarFsm, RUNSTOP);
//    }
//    else if(GoGarageFinishFlag && ReturnFsmState(&CarFsm) == RightInGarage)
//    {
//    	FsmEventHandle(&CarFsm, RUNSTOP);
//    }
//    else
//    {
//    	IntoRoundaboutCount = 0;
//    	FsmEventHandle(&CarFsm, NOEVENT);
//    }
}