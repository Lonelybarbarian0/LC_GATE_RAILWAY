/*
 * ACT.c
 *
 *  Created on: Aug 28, 2025
 *      Author: kailas
 */

/* Includes Begin */
#include "ACT.h"
/* Includes End */

/* Function Definition Begin */

/**
  * @brief  Actuates/Trigger the Relay which in-turn actuates a solenoid for the EKT.
  *         Uses temp_rx_buff[0] to determine
  * @param  None
  * @retval None
  */
void EKT_Lock()
{

 if (temp_rx_buff[0] == 0x00) /* Turn ON the Relay to Unlock the EKT */
	{
	  if(HAL_GPIO_ReadPin(LOCK_EKT_NO_GPIO_Port, LOCK_EKT_NO_Pin) == GPIO_PIN_SET) //EKT in Lock Condition
	  {
	    HAL_GPIO_WritePin(Lock_Trigger_GPIO_Port, Lock_Trigger_Pin, GPIO_PIN_RESET); //Relay on - Key can be unlocked
	  }
	  else {
		  HAL_GPIO_WritePin(Lock_Trigger_GPIO_Port, Lock_Trigger_Pin, GPIO_PIN_SET);
		  temp_rx_buff[0] = 0xFF;
	  }
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
		HAL_GPIO_WritePin(Alarm_Trigger1_GPIO_Port, Alarm_Trigger1_Pin, GPIO_PIN_RESET); /* Turn ON */
		temp_tx_buff[9] = 0x01;
	}
	else if (temp_rx_buff[1] == 0x00)
	{
		HAL_GPIO_WritePin(Alarm_Trigger1_GPIO_Port, Alarm_Trigger1_Pin, GPIO_PIN_SET); /* Turn OFF */
		temp_tx_buff[9] = 0x00;
	}
	else temp_tx_buff[9] = 0xFF; /* Unknown State */

}
/* Function Def END */
