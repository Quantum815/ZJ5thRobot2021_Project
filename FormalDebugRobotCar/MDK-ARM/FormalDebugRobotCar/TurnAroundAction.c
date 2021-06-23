/**
  ******************************************************************************
  * @file    TurnAction.c
  * @author  俞立
  * @brief   转向动作
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
 *  @defgroup 外部调用
 *  @brief 
 *
**/

//void TurnAngle(double angle)//angle设定值为0~360，以向前为0，向左增加度数
//{   
//    double currentAngle = GyroYawAngleGet();
//    
//    if(currentAngle < 0)
//    {
//            currentAngle = 360 + currentAngle;//当前角以向前为0，向左增加度数
//    }
//    if( angle - currentAngle <= 180)//当前角小于设定角，需继续左转
//    {
//        int16_t LSpeed = 1000 + GetPIDValue(&Pid_Turn, currentAngle); 
//        int16_t RSpeed = 1000 - GetPIDValue(&Pid_Turn, currentAngle);  
//        SetMotorSpeed(LMOTOR, &LSpeed);
//	    SetMotorSpeed(RMOTOR, &RSpeed); 
//    }
//    else if( angle - currentAngle > 180)//当前角小于设定角，但差值过大，适合右转
//    {
//        int16_t LSpeed = 1000 + GetPIDValue(&Pid_Turn, currentAngle); 
//        int16_t RSpeed = 1000 - GetPIDValue(&Pid_Turn, currentAngle);  
//        SetMotorSpeed(LMOTOR, &LSpeed);
//	    SetMotorSpeed(RMOTOR, &RSpeed); 
//    }
//    else if( currentAngle > angle) //当前角大于设定角，需右转一定角度
//    {
//        if(currentAngle > 360)
//        {
//            currentAngle -= 360;
//        }
//        int16_t LSpeed = 1000 + GetPIDValue(&Pid_Turn, currentAngle); 
//        int16_t RSpeed = 1000 - GetPIDValue(&Pid_Turn, currentAngle);
//        SetMotorSpeed(LMOTOR, &LSpeed);
//	    SetMotorSpeed(RMOTOR, &RSpeed);
//    }
//}

void TurnAngle(double angle)
{
    double currentAngle = GyroYawAngleGet();
    if(currentAngle < 0)
    {
            currentAngle = 360 + currentAngle;//当前角以向前为0，向左增加度数
    }
    if((currentAngle>=0)&&(currentAngle<=180)&&(angle>=0)&&(angle<=180))
    {
        if((angle-currentAngle)>0)//左转
        {
            int16_t LSpeed = 1000 + GetPIDValue(&Pid_Turn, currentAngle); 
            int16_t RSpeed = 1000 - GetPIDValue(&Pid_Turn, currentAngle);
            SetMotorSpeed(LMOTOR, &LSpeed);
      	    SetMotorSpeed(RMOTOR, &RSpeed);
        }
        else //右转
        {
            int16_t LSpeed = 1000 + GetPIDValue(&Pid_Turn, currentAngle); 
            int16_t RSpeed = 1000 - GetPIDValue(&Pid_Turn, currentAngle);
            SetMotorSpeed(LMOTOR, &LSpeed);
      	    SetMotorSpeed(RMOTOR, &RSpeed);
        }
    }
    else if((currentAngle>=0)&&(currentAngle<=180)&&(angle>180)&&(angle<360))
    {
        if((angle-currentAngle)>180)//右转
        {
            int16_t LSpeed = 1000 + GetPIDValue(&Pid_Turn, currentAngle); 
            int16_t RSpeed = 1000 - GetPIDValue(&Pid_Turn, currentAngle);
            SetMotorSpeed(LMOTOR, &LSpeed);
      	    SetMotorSpeed(RMOTOR, &RSpeed);
        }
        else //左转
        {
            int16_t LSpeed = 1000 + GetPIDValue(&Pid_Turn, currentAngle); 
            int16_t RSpeed = 1000 - GetPIDValue(&Pid_Turn, currentAngle);
            SetMotorSpeed(LMOTOR, &LSpeed);
      	    SetMotorSpeed(RMOTOR, &RSpeed);
        }
    }
     else if((currentAngle>180)&&(currentAngle<360)&&(angle>=0)&&(angle<=180))
    {
        if((angle-currentAngle)>180)//左转
        {
            int16_t LSpeed = 1000 + GetPIDValue(&Pid_Turn, currentAngle); 
            int16_t RSpeed = 1000 - GetPIDValue(&Pid_Turn, currentAngle);
            SetMotorSpeed(LMOTOR, &LSpeed);
      	    SetMotorSpeed(RMOTOR, &RSpeed);
        }
        else //右转
        {
            int16_t LSpeed = 1000 + GetPIDValue(&Pid_Turn, currentAngle); 
            int16_t RSpeed = 1000 - GetPIDValue(&Pid_Turn, currentAngle);
            SetMotorSpeed(LMOTOR, &LSpeed);
      	    SetMotorSpeed(RMOTOR, &RSpeed);
        }
    }
    else if((currentAngle>180)&&(currentAngle<360)&&(angle>180)&&(angle<360))
    {
        if((angle-currentAngle)>0)//左转
        {
            int16_t LSpeed = 1000 + GetPIDValue(&Pid_Turn, currentAngle); 
            int16_t RSpeed = 1000 - GetPIDValue(&Pid_Turn, currentAngle);
            SetMotorSpeed(LMOTOR, &LSpeed);
      	    SetMotorSpeed(RMOTOR, &RSpeed);
        }
        else //右转
        {
            int16_t LSpeed = 1000 + GetPIDValue(&Pid_Turn, currentAngle); 
            int16_t RSpeed = 1000 - GetPIDValue(&Pid_Turn, currentAngle);
            SetMotorSpeed(LMOTOR, &LSpeed);
      	    SetMotorSpeed(RMOTOR, &RSpeed);
        }
    }
}








