/**
  ******************************************************************************
  * @file    PID.c
  * @author  俞立
  * @brief   PID底层算法
  *
  @verbatim

	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "PID.h"

/* Define\Declare ------------------------------------------------------------*/

//PID初始化
void PIDInit(Pid_ArgumentTypeDef *Pid_Argument, double middleValue, double deadBandValue, double kp, double ki, double kd, double alpha1, double alpha2)
{
	Pid_Argument->MiddleValue = middleValue;
	Pid_Argument->DeadBandValue = deadBandValue;
	Pid_Argument->Kp = kp;
	Pid_Argument->Ki = ki;
	Pid_Argument->Kd = kd;
	Pid_Argument->Alpha1 = alpha1;
	Pid_Argument->Alpha2 = alpha2;
	
	Pid_Argument->OutputValue = 0;
	Pid_Argument->CurrentPidValue = 0;
	Pid_Argument->PreviousPidValue = 0;
	Pid_Argument->SecondToLastPidValue = 0;
	
	Pid_Argument->NowErrorValue = 0;
	Pid_Argument->PreviousErrorValue = 0;
	Pid_Argument->SecondToLastErrorValue = 0;
}

//PID算法  为混合方案，需要验证算法正确性
double GetPIDValue(Pid_ArgumentTypeDef *Pid_Argument, double outputValue)
{	
	Pid_Argument->OutputValue = outputValue;
	if(fabs(Pid_Argument->NowErrorValue) > Pid_Argument->DeadBandValue)
		Pid_Argument->NowErrorValue = Pid_Argument->Alpha1 * Pid_Argument->PreviousErrorValue + (1 - Pid_Argument->Alpha1) * 
			(Pid_Argument->OutputValue - Pid_Argument->MiddleValue);
	else
		Pid_Argument->NowErrorValue = 0;
	
	double ProportionErrorValue = Pid_Argument->NowErrorValue - Pid_Argument->PreviousErrorValue;
	double IntegralErrorValue = Pid_Argument->NowErrorValue;
	double DifferentialErrorValue = Pid_Argument->NowErrorValue - 2 * Pid_Argument->PreviousErrorValue + Pid_Argument->SecondToLastErrorValue;

	Pid_Argument->CurrentPidValue = Pid_Argument->PreviousPidValue + Pid_Argument->Alpha2 * (Pid_Argument->PreviousPidValue - 
		Pid_Argument->SecondToLastPidValue) + (1 - Pid_Argument->Alpha2) * (Pid_Argument->Kp * ProportionErrorValue + 
			Pid_Argument->Ki * IntegralErrorValue + Pid_Argument->Kd * DifferentialErrorValue);
	
	Pid_Argument->SecondToLastPidValue = Pid_Argument->PreviousPidValue;
	Pid_Argument->PreviousPidValue = Pid_Argument->CurrentPidValue;
	Pid_Argument->SecondToLastErrorValue = Pid_Argument->PreviousErrorValue;
	Pid_Argument->PreviousErrorValue = Pid_Argument->NowErrorValue;
	
	return Pid_Argument->CurrentPidValue;
}
