/**
  ******************************************************************************
  * @file    PID.c
  * @author  ����
  * @brief   PID�ײ��㷨
  *
  @verbatim

	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "PID.h"

/* Define\Declare ------------------------------------------------------------*/

//PID��ʼ��
void PIDInit(Pid_ArgumentTypeDef *Pid_Argument, const double middleValue, const double deadBandValue, const double kp, 
	const double ki, const double kd, const double alpha1, const double alpha2)
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
	
	Pid_Argument->NowErrorValue = 0;
	Pid_Argument->PreviousErrorValue = 0;
}

//PID�㷨  Ϊ��Ϸ�������Ҫ��֤�㷨��ȷ��
double GetPIDValue(Pid_ArgumentTypeDef *Pid_Argument, double outputValue)
{
	double ProportionErrorValue, DifferentialErrorValue;
	static double IntegralErrorValue = 0;

	//���ֵ
	Pid_Argument->OutputValue = outputValue;
	
	//��������ж�
	if(fabs(Pid_Argument->NowErrorValue) >= Pid_Argument->DeadBandValue)
		Pid_Argument->NowErrorValue = Pid_Argument->Alpha1 * Pid_Argument->PreviousErrorValue + (1 - Pid_Argument->Alpha1) * 
			(Pid_Argument->OutputValue - Pid_Argument->MiddleValue);
	else
		Pid_Argument->NowErrorValue = 0;
	
	ProportionErrorValue = Pid_Argument->NowErrorValue;
	IntegralErrorValue += Pid_Argument->NowErrorValue;
	DifferentialErrorValue = Pid_Argument->NowErrorValue - Pid_Argument->PreviousErrorValue;
	
	//��¼��ǰ�����Ϊǰһ�����
	Pid_Argument->PreviousErrorValue = Pid_Argument->NowErrorValue;

	//PID�㷨
	Pid_Argument->CurrentPidValue = Pid_Argument->Kp * ProportionErrorValue + Pid_Argument->Ki * IntegralErrorValue + 
		Pid_Argument->Kd * DifferentialErrorValue;
	
	Pid_Argument->CurrentPidValue = Pid_Argument->Alpha2 * Pid_Argument->PreviousPidValue + (1 - Pid_Argument->Alpha2) *
		Pid_Argument->CurrentPidValue;
	
	//��¼��ǰPID���Ϊǰһ��PID���
	Pid_Argument->PreviousPidValue = Pid_Argument->CurrentPidValue;
	
	printf("%lf\r\n", 1000 * Pid_Argument->CurrentPidValue);
	return (1000 * Pid_Argument->CurrentPidValue);
}
