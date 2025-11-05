/*
 * POLL.c
 *
 *  Created on: Aug 28, 2025
 *      Author: kailas
 */

/* Includes Begin */
#include "POLL.h"
#include "main.h"
/* Includes END */


/* Function Def Begin */

/**
  * @brief  Reads the two adjacent Lidar values
  *         Compare it with TRAIN_DIST MACRO and changes temp_tx_buff[2] - UP direction
  * @param  None
  * @retval None
  */
void UP_Train_Status(void)
{
	volatile uint16_t data1[3] = {0xFFFF};
	volatile uint16_t data2[3] = {0xFFFF};

	for(uint8_t i=0;i<3;i++)
	{
	    data1[i] = TF02_Get_Dist(&huart1);
	    data2[i] = TF02_Get_Dist(&huart5);
	}


    if((data1[0] == 0xFFFF) && (data1[1] == 0xFFFF) && (data1[2] == 0xFFFF))
    {
    	temp_tx_buff[2] = 0x11; /* Sensor Error */
    }
   if((data1[2] != 0xFFFF) && (data2[2] != 0xFFFF))
   {
	   if((data1[2] <= TRAIN_DIST && data2[2] <= TRAIN_DIST) && (data1[2] > TRAIN_DIST_LOW && data2[2] > TRAIN_DIST_LOW))
	   {
		   temp_tx_buff[2] = 0x01;  /* Train Detected */
	   }
	   else if ((data1[2] >= TRAIN_DIST && data2[2] >= TRAIN_DIST))
	   {
		   temp_tx_buff[2] = 0x00;  /* No Train Detected */
	   }
   }

}

/**
  * @brief  Reads the two adjacent Lidar values
  *         Compare it with TRAIN_DIST MACRO and changes temp_tx_buff[3] - DOWN direction
  * @param  None
  * @retval None
  */
void DOWN_Train_Status(void)
{
	volatile uint16_t data3[3] = {0xFFFF};
	volatile uint16_t data4[3] = {0xFFFF};

	for(uint8_t i=0;i<3;i++)
	{
	    data3[i] = TF02_Get_Dist(&huart3);
	    data4[i] = TF02_Get_Dist(&huart4);
	}

    if((data3[0] == 0xFFFF) && (data3[1] == 0xFFFF) && (data3[2] == 0xFFFF))
    {
    	temp_tx_buff[3] = 0x11; /* Sensor Error */
    }
    if((data3[2] != 0xFFFF) && (data4[2] != 0xFFFF))
    {
 	   if( (data3[2] <= TRAIN_DIST && data4[2] <= TRAIN_DIST) && (data3[2] > TRAIN_DIST_LOW && data4[2] > TRAIN_DIST_LOW) )
 	   {
 		   temp_tx_buff[3] = 0x01;  /* Train Detected */
 	   }
 	   else if (data3[2] >= TRAIN_DIST && data4[2] >= TRAIN_DIST)
 	   {
 		   temp_tx_buff[3] = 0x00;  /* No Train Detected */
 	   }
    }

}

/**
  * @brief  Check the status of Boom 1
  * @param  None
  * @retval None
  */
void Boom1_Status(void)
{
	if( ( (HAL_GPIO_ReadPin(BOOM1_LS11_GPIO_Port, BOOM1_LS11_Pin) == GPIO_PIN_RESET) &&
		  (HAL_GPIO_ReadPin(BOOM1_LS12_GPIO_Port, BOOM1_LS12_Pin) == GPIO_PIN_SET) ) ||
		( (HAL_GPIO_ReadPin(BOOM1_LS21_GPIO_Port, BOOM1_LS21_Pin) == GPIO_PIN_RESET) &&
		  (HAL_GPIO_ReadPin(BOOM1_LS22_GPIO_Port, BOOM1_LS22_Pin) == GPIO_PIN_SET) ) )
	{
		temp_tx_buff[4] = 0x01; /* BOOM 1 CLOSED */
		temp_tx_buff[6] = 0x01; /* BOOM 1 Healthy */

	}
	else if( ( (HAL_GPIO_ReadPin(BOOM1_LS11_GPIO_Port, BOOM1_LS11_Pin) == GPIO_PIN_SET) &&
		       (HAL_GPIO_ReadPin(BOOM1_LS12_GPIO_Port, BOOM1_LS12_Pin) == GPIO_PIN_RESET) ) ||
		     ( (HAL_GPIO_ReadPin(BOOM1_LS21_GPIO_Port, BOOM1_LS21_Pin) == GPIO_PIN_SET) &&
		       (HAL_GPIO_ReadPin(BOOM1_LS22_GPIO_Port, BOOM1_LS22_Pin) == GPIO_PIN_RESET) ) )
	{
		temp_tx_buff[4] = 0x00; /* BOOM 1 OPEN */
		temp_tx_buff[6] = 0x01; /* BOOM 1 Healthy */
	}
	else
	{
		temp_tx_buff[4] = 0xFF;
		temp_tx_buff[6] = 0x00; /* BOOM 1 HEALTH BAD */
	}
}

/**
  * @brief  Check the status of Boom 2
  * @param  None
  * @retval None
  */
void Boom2_Status(void)
{
	if( ( (HAL_GPIO_ReadPin(BOOM2_LS11_GPIO_Port, BOOM2_LS11_Pin) == GPIO_PIN_RESET) &&
		  (HAL_GPIO_ReadPin(BOOM2_LS12_GPIO_Port, BOOM2_LS12_Pin) == GPIO_PIN_SET) ) ||
		( (HAL_GPIO_ReadPin(BOOM2_LS21_GPIO_Port, BOOM2_LS21_Pin) == GPIO_PIN_RESET) &&
		  (HAL_GPIO_ReadPin(BOOM2_LS22_GPIO_Port, BOOM2_LS22_Pin) == GPIO_PIN_SET) ) )
	{
		temp_tx_buff[5] = 0x01; /* BOOM 2 CLOSED */
		temp_tx_buff[7] = 0x01; /* BOOM 2 Healthy */

	}
	else if( ( (HAL_GPIO_ReadPin(BOOM2_LS11_GPIO_Port, BOOM2_LS11_Pin) == GPIO_PIN_SET) &&
		       (HAL_GPIO_ReadPin(BOOM2_LS12_GPIO_Port, BOOM2_LS12_Pin) == GPIO_PIN_RESET) ) ||
		     ( (HAL_GPIO_ReadPin(BOOM2_LS21_GPIO_Port, BOOM2_LS21_Pin) == GPIO_PIN_SET) &&
		       (HAL_GPIO_ReadPin(BOOM2_LS22_GPIO_Port, BOOM2_LS22_Pin) == GPIO_PIN_RESET) ) )
	{
		temp_tx_buff[5] = 0x00; /* BOOM 2 OPEN */
		temp_tx_buff[7] = 0x01; /* BOOM 2 Healthy */
	}
	else
	{
		temp_tx_buff[5] = 0xFF;
		temp_tx_buff[7] = 0x00; /* BOOM 2 HEALTH BAD */
	}
}
/**
  * @brief  Check the status of EKT
  * @param  None
  * @retval None
  */

void Lock_Status(void)
{
	if(HAL_GPIO_ReadPin(LOCK_EKT_NO_GPIO_Port, LOCK_EKT_NO_Pin) == GPIO_PIN_SET)
	{
		temp_tx_buff[8] = 0x00; //Unlocked
	}
	else if(HAL_GPIO_ReadPin(LOCK_EKT_NO_GPIO_Port, LOCK_EKT_NO_Pin) == GPIO_PIN_RESET)
	{
		temp_tx_buff[8] = 0x01; //Locked
	}
}

/**
  * @brief  Check the status of Bypass Switch
  * @param  None
  * @retval None
  */

void Bypass_Status(void)
{
	if (HAL_GPIO_ReadPin(BYPASS_SW_NO_GPIO_Port, BYPASS_SW_NO_Pin) == GPIO_PIN_RESET) //bypass EKT Locked
	{
		temp_tx_buff[10] = 0x00; //Not Bypassed
	}
	else if(HAL_GPIO_ReadPin(BYPASS_SW_NO_GPIO_Port, BYPASS_SW_NO_Pin) == GPIO_PIN_SET) //bypass EKT not Locked
	{
		if(HAL_GPIO_ReadPin(LOCK_EKT_NO_GPIO_Port, LOCK_EKT_NO_Pin) == GPIO_PIN_RESET) //unlocked EKT
		{
			temp_tx_buff[10] = 0x0F; //Breached
		}
		else if(HAL_GPIO_ReadPin(LOCK_EKT_NO_GPIO_Port, LOCK_EKT_NO_Pin) == GPIO_PIN_SET) //Locked EKT
		{
			temp_tx_buff[10] = 0x01; //Bypassed
		}

	}
}

void Sys_rst(void)
{
    static uint8_t reset_done = 0; // prevent multiple resets in same tick

    if(HAL_GetTick() >= 86400000 && reset_done == 0)
    {
        reset_done = 1;  // ensure NVIC_SystemReset called only once
        NVIC_SystemReset();
    }
}


/* Function Def END */
