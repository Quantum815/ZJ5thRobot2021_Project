#ifndef PID_H_
#define PID_H_

#include "math.h"

typedef struct 
{
	//��ҪԤ���趨�Ĳ���
	double MiddleValue;             //Ŀ����
	double DeadBandValue;           //������
	double Kp;                      //����ϵ��
	double Ki;                      //����ϵ��
	double Kd;                      //΢��ϵ��
	double Alpha1;                  //һ�׵�ͨ�˲�ϵ��
	double Alpha2;                  //���׵�ͨ�˲�ϵ��

	//��PID�㷨�����õ��Ĳ���
	double OutputValue;             //�����	
	double CurrentPidValue;         //��ǰ������
	double PreviousPidValue;        //ǰһ�θ�����
	double SecondToLastPidValue;    //ǰ���θ�����
		
	double NowErrorValue;           //��ǰ�����
	double PreviousErrorValue;      //��һ�������
	double SecondToLastErrorValue;  //�����������

}Pid_ArgumentTypeDef;

void PIDInit(Pid_ArgumentTypeDef *Pid_Argument, double middleValue, double deadBandValue, double kp, double ki, double kd, double alpha1, double alpha2);
double GetPIDValue(Pid_ArgumentTypeDef *Pid_Argument, double outputValue);

#endif
