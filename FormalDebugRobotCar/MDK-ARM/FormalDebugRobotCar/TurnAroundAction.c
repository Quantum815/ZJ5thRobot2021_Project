/**
  ******************************************************************************
  * @file    TurnAction.c
  * @author  ����
  * @brief   ת����
  *
	@verbatim
	
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "TurnAroundAction.h"

/* Define\Declare ------------------------------------------------------------*/
Pid_ArgumentTypeDef Pid_Turn;

/**
 ******************************************************************************
 *  @defgroup �ⲿ����
 *  @brief 
 *
**/

//ת���� ����������ת��ĳһ�Ƕȣ�
void TurnAngle(double angle)
{
    double currentAngle = GyroYawAngleGet();
    if(currentAngle < 0)
    {
            currentAngle = 360 + currentAngle;//��ǰ������ǰΪ0���������Ӷ���
    }
    if((currentAngle>=0)&&(currentAngle<=180)&&(angle>=0)&&(angle<=180))
    {
        if((angle-currentAngle)>0)//��ת 
        {
            int16_t LSpeed = 1000 + GetPIDValue(&Pid_Turn, currentAngle); 
            int16_t RSpeed = 1000 - GetPIDValue(&Pid_Turn, currentAngle);
            SetMotorSpeed(LMOTOR, &LSpeed);
      	    SetMotorSpeed(RMOTOR, &RSpeed);
        }
        else //��ת
        {
            int16_t LSpeed = 1000 + GetPIDValue(&Pid_Turn, currentAngle); 
            int16_t RSpeed = 1000 - GetPIDValue(&Pid_Turn, currentAngle);
            SetMotorSpeed(LMOTOR, &LSpeed);
      	    SetMotorSpeed(RMOTOR, &RSpeed);
        }
    }
    else if((currentAngle>=0)&&(currentAngle<=180)&&(angle>180)&&(angle<360))
    {
        if((angle-currentAngle)>180)//��ת
        {
            int16_t LSpeed = 1000 + GetPIDValue(&Pid_Turn, currentAngle); 
            int16_t RSpeed = 1000 - GetPIDValue(&Pid_Turn, currentAngle);
            SetMotorSpeed(LMOTOR, &LSpeed);
      	    SetMotorSpeed(RMOTOR, &RSpeed);
        }
        else //��ת
        {
            int16_t LSpeed = 1000 + GetPIDValue(&Pid_Turn, currentAngle); 
            int16_t RSpeed = 1000 - GetPIDValue(&Pid_Turn, currentAngle);
            SetMotorSpeed(LMOTOR, &LSpeed);
      	    SetMotorSpeed(RMOTOR, &RSpeed);
        }
    }
     else if((currentAngle>180)&&(currentAngle<360)&&(angle>=0)&&(angle<=180))
    {
        if((angle-currentAngle)>180)//��ת
        {
            int16_t LSpeed = 1000 + GetPIDValue(&Pid_Turn, currentAngle); 
            int16_t RSpeed = 1000 - GetPIDValue(&Pid_Turn, currentAngle);
            SetMotorSpeed(LMOTOR, &LSpeed);
      	    SetMotorSpeed(RMOTOR, &RSpeed);
        }
        else //��ת
        {
            int16_t LSpeed = 1000 + GetPIDValue(&Pid_Turn, currentAngle); 
            int16_t RSpeed = 1000 - GetPIDValue(&Pid_Turn, currentAngle);
            SetMotorSpeed(LMOTOR, &LSpeed);
      	    SetMotorSpeed(RMOTOR, &RSpeed);
        }
    }
    else if((currentAngle>180)&&(currentAngle<360)&&(angle>180)&&(angle<360))
    {
        if((angle-currentAngle)>0)//��ת
        {
            int16_t LSpeed = 1000 + GetPIDValue(&Pid_Turn, currentAngle); 
            int16_t RSpeed = 1000 - GetPIDValue(&Pid_Turn, currentAngle);
            SetMotorSpeed(LMOTOR, &LSpeed);
      	    SetMotorSpeed(RMOTOR, &RSpeed);
        }
        else //��ת
        {
            int16_t LSpeed = 1000 + GetPIDValue(&Pid_Turn, currentAngle); 
            int16_t RSpeed = 1000 - GetPIDValue(&Pid_Turn, currentAngle);
            SetMotorSpeed(LMOTOR, &LSpeed);
      	    SetMotorSpeed(RMOTOR, &RSpeed);
        }
    }
}








