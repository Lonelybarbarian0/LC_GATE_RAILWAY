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
		HAL_GPIO_WritePin(Lock_Trigger_GPIO_Port, Lock_Trigger_Pin, GPIO_PIN_SET); /* Turn ON */
		temp_tx_buff[8] = 0x01;
	}
	else if (temp_rx_buff[0] == 0x00)
	{
		HAL_GPIO_WritePin(Lock_Trigger_GPIO_Port, Lock_Trigger_Pin, GPIO_PIN_RESET); /* Turn OFF */
		temp_tx_buff[8] = 0x00;
	}
	temp_tx_buff[8] = 0xFF;

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
		HAL_GPIO_WritePin(Alarm_Trigger1_GPIO_Port, Alarm_Trigger1_Pin, GPIO_PIN_SET); /* Turn ON */
		HAL_GPIO_WritePin(Alarm_Trigger2_GPIO_Port, Alarm_Trigger2_Pin, GPIO_PIN_SET); /* Turn ON */
		temp_tx_buff[9] = 0x01;
	}
	else if (temp_rx_buff[1] == 0x00)
	{
		HAL_GPIO_WritePin(Alarm_Trigger1_GPIO_Port, Alarm_Trigger1_Pin, GPIO_PIN_RESET); /* Turn OFF */
		HAL_GPIO_WritePin(Alarm_Trigger2_GPIO_Port, Alarm_Trigger2_Pin, GPIO_PIN_RESET); /* Turn OFF */
		temp_tx_buff[9] = 0x00;
	}
	temp_tx_buff[9] = 0xFF;
}
/* Function Def END */
