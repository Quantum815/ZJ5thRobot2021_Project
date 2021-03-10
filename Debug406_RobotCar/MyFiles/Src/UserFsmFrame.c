/**
  ******************************************************************************
  * @file    UserFsmFrame.c
  * @author  YL
  * @brief   ״̬��
  *
	@verbatim
	
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "UserFsmFrame.h"

FsmTable_t CarFsmTable[] =
{ 
//            ��ǰ״̬      ��ת����                 ִ�к���                 ��һ״̬
//	    ����ִ��״̬��
	{      Waiting_To_Start,  NoCondition,         WaitingToStart,        Waiting_To_Start      },
	
	
	
//	  ǿ��ֹͣ״̬��

};
Fsm_t CarFsm;


/**
 ******************************************************************************
 *  @defgroup ״̬�����ܺ���
 *  @brief 
 *
**/

/**
  * @brief  ״̬����ʼע��
  * @param  ��
  * @retval ��
  */
void FsmFirstRegister(Fsm_t *fsm, int firstState, FsmTable_t *fsmtable)
{
	fsm->CurrentState = firstState;
	fsm->FsmTable = fsmtable;
	fsm->Size = sizeof(&fsmtable) / sizeof(FsmTable_t);
}

/**
  * @brief  ״̬��״̬��ת
  * @param  ��
  * @retval ��
  */
void FsmStateTransfer(Fsm_t* fsm, uint8_t (*eventcondition)())
{
	FsmTable_t *fsmTable = fsm->FsmTable;
	int currentState = fsm->CurrentState;
	void (*eventAction)();
	int nextState = -1;
	int size = fsm->Size;
	int i;

	//��ȡ��ǰ��������
	for (i=0; i<size; i++)
	{
			//���ҽ�����ǰ״̬������ָ�����¼����Ҳ�ִ����
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
  * @brief  ״̬����ǰ״̬��ȡ
  * @param  ��
  * @retval ��
  */
int ReturnFsmCurrentState(Fsm_t *fsm)
{
	return fsm->CurrentState;
}

/**
  * @brief  ״̬��ִ������
  * @param  ��
  * @retval ��
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
//    && (ADCValueHandle(0) > ADCvalueLL || ADCValueHandle(4) > ADCvalueRR) && ReturnFsmState(&CarFsm) == GoLine)//����Բ
//    {
//    	IntoRoundaboutCount++;
//    	if(IntoRoundaboutCount >= 3)//�����������
//    	{
//    		if(ADCValueHandle(1) > ADCValueHandle(3))//�ж���Բ����Բ
//			{
////    	    	uart_putchar(UART_3,0X01);//״̬���1
//				LRoundaboutFlag = 1;//��Բ
//				RRoundaboutFlag = 0;
//			}
//			else
//			{
//				LRoundaboutFlag = 0;
//				RRoundaboutFlag = 1;//��Բ
//			}
//    		GyroYawAngleInit(InRAngle);
//            CleanDistance();
//            InitCulAngle();
//            OutRAroll = YawAngle;
//            FsmEventHandle(&CarFsm, FINDROUNDABOUT);
////            FsmEventHandle(&CarFsm, RUNSTOP);
//    	}
//    }
//    else if(GetDistance() >= 0.8 && ReturnFsmState(&CarFsm) == InRoundabout)//Բ�ڹ���
//    {
////    	uart_putchar(UART_3,0X04);//״̬���4
//    	CleanPIDValue();
//    	FsmEventHandle(&CarFsm, ENDINROUNDABOUT);
//    }
//    else if(CulAngle() >= 360 && ReturnFsmState(&CarFsm) == PassRoundabout)//����Բ
//    {
////    	uart_putchar(UART_3,0X05);//״̬���5
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