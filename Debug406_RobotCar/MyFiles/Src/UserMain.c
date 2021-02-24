#include "UserMain.h"
#include "main.h"
#include "Gyro.h"

/**
  * @brief  Main program initialization
  * @param  None
  * @retval None
  */
void UserInit(void)
{
	
}

/**
  * @brief  Main program loop
  * @param  None
  * @retval None
  */
void UserLoop(void)
{
		HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_GPIO_PIN);
		HAL_Delay(1000);
}