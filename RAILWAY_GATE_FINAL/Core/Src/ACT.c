/*
 * ACT.c
 *
 *  Created on: Aug 28, 2025
 *      Author: kailas
 */

/* Includes Begin */
#include "ACT.h"
/* Includes End */

/* Function Def Begin */

/**
  * @brief  Actuates/Trigger the Relay which in-turn actuates a Mechanical Lock.
  *         Uses temp_rx_buff[0] to determine
  * @param  None
  * @retval None
  */
void Lever_Lock()
{
	if(temp_rx_buff[0] == 0x01)
	{
		HAL_GPIO_WritePin(LT_GPIO_Port, LT_Pin, GPIO_PIN_SET); /* Turn ON */
	}
	else if (temp_rx_buff[0] == 0x00)
	{
		HAL_GPIO_WritePin(LT_GPIO_Port, LT_Pin, GPIO_PIN_RESET); /* Turn OFF */
	}
}


/**
  * @brief  Trigger a relay which in-turn turns on an Alarm
  *         Uses temp_rx_buff[1] to determine
  * @param  None
  * @retval None
  */
void Alarm_ON()
{
	if(temp_rx_buff[1] == 0x01)
	{
		HAL_GPIO_WritePin(AT_GPIO_Port, AT_Pin, GPIO_PIN_SET); /* Turn ON */
	}
	else if (temp_rx_buff[1] == 0x00)
	{
		HAL_GPIO_WritePin(AT_GPIO_Port, AT_Pin, GPIO_PIN_RESET); /* Turn OFF */
	}
}
/* Function Def END */
