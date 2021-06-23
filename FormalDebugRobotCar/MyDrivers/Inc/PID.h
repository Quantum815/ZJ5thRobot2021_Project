#ifndef PID_H_
#define PID_H_

#include "math.h"

typedef struct 
{
	//需要预先设定的参数
	double MiddleValue;             //目标量
	double DeadBandValue;           //死区量
	double Kp;                      //比例系数
	double Ki;                      //积分系数
	double Kd;                      //微分系数
	double Alpha1;                  //一阶低通滤波系数
	double Alpha2;                  //二阶低通滤波系数

	//由PID算法自主得到的参数
	double OutputValue;             //输出量	
	double CurrentPidValue;         //当前给定量
	double PreviousPidValue;        //前一次给定量
	double SecondToLastPidValue;    //前两次给定量
		
	double NowErrorValue;           //当前误差量
	double PreviousErrorValue;      //上一次误差量
	double SecondToLastErrorValue;  //上两次误差量

}Pid_ArgumentTypeDef;

void PIDInit(Pid_ArgumentTypeDef *Pid_Argument, double middleValue, double deadBandValue, double kp, double ki, double kd, double alpha1, double alpha2);
double GetPIDValue(Pid_ArgumentTypeDef *Pid_Argument, double outputValue);

#endif
