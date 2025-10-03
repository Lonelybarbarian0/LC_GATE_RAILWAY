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
  * @brief  Checks the status of the lever
  * @param  None
  * @retval None
  */
void Lever_Status(void)
{
	if( (HAL_GPIO_ReadPin(Lever_Feedback11_GPIO_Port, Lever_Feedback11_Pin) == GPIO_PIN_RESET) &&
	    (HAL_GPIO_ReadPin(Lever_Feedback12_GPIO_Port, Lever_Feedback12_Pin) == GPIO_PIN_SET) )
	{
		temp_tx_buff[10] = 0x01; /* lever ON */
	}

	else if( (HAL_GPIO_ReadPin(Lever_Feedback11_GPIO_Port, Lever_Feedback11_Pin) == GPIO_PIN_SET) &&
		     (HAL_GPIO_ReadPin(Lever_Feedback12_GPIO_Port, Lever_Feedback12_Pin) == GPIO_PIN_RESET) )
	{
		temp_tx_buff[10] = 0x00; /* lever OFF */
	}
	else
	{
		temp_tx_buff[10] = 0x11; /* lever Sensor Err */
	}
}

/**
  * @brief  Checks the status of the LeverLock Sensor
  * @param  None
  * @retval None
  */
void LeverLock_Status()
{

	/* Unlock Scenario */
	if( (HAL_GPIO_ReadPin(Lock_Feedback11_GPIO_Port, Lock_Feedback11_Pin) == GPIO_PIN_RESET) &&
	    (HAL_GPIO_ReadPin(Lock_Feedback12_GPIO_Port, Lock_Feedback12_Pin) == GPIO_PIN_SET) ) /* Lock OFF Sensor */
	{
		temp_tx_buff[8] = 0x00;  /* Lock unlocked status */
		temp_tx_buff[11] = 0x01; /* Lock OFF Sensor Healthy */
	}

	if( HAL_GPIO_ReadPin(Lock_Feedback11_GPIO_Port, Lock_Feedback11_Pin) !=
		HAL_GPIO_ReadPin(Lock_Feedback12_GPIO_Port, Lock_Feedback12_Pin)) /* Lock OFF Sensor */
	{
		temp_tx_buff[11] = 0x01; /* Lock OFF Sensor Healthy */
	}
	else
	{
		   temp_tx_buff[8] = 0x11; /* lock sensor Error */
		   temp_tx_buff[11] = 0x00; /* Lock OFF Sensor Un-Healthy */
	}


	/* Lock Scenario */
	if( (HAL_GPIO_ReadPin(Lock_Feedback21_GPIO_Port, Lock_Feedback21_Pin) == GPIO_PIN_RESET) &&
	    (HAL_GPIO_ReadPin(Lock_Feedback22_GPIO_Port, Lock_Feedback22_Pin) == GPIO_PIN_SET) ) /* Lock ON Sensor */
	{
		temp_tx_buff[8] = 0x01;  /* Lock locked status */
		temp_tx_buff[12] = 0x01; /* Lock ON Sensor Healthy */
	}

	if( HAL_GPIO_ReadPin(Lock_Feedback21_GPIO_Port, Lock_Feedback21_Pin) !=
		HAL_GPIO_ReadPin(Lock_Feedback22_GPIO_Port, Lock_Feedback22_Pin)) /* Lock ON Sensor */
	{
		temp_tx_buff[12] = 0x01; /* Lock OFF Sensor Healthy */
	}
	else
	{
		   temp_tx_buff[8] = 0x11; /* lock sensor Error */
		   temp_tx_buff[12] = 0x00; /* Lock OFF Sensor Un-Healthy */
	}

	if((HAL_GPIO_ReadPin(Lock_Feedback11_GPIO_Port, Lock_Feedback11_Pin) == GPIO_PIN_SET) &&
	   (HAL_GPIO_ReadPin(Lock_Feedback12_GPIO_Port, Lock_Feedback12_Pin) == GPIO_PIN_RESET) &&
	   (HAL_GPIO_ReadPin(Lock_Feedback21_GPIO_Port, Lock_Feedback21_Pin) == GPIO_PIN_SET) &&
	   (HAL_GPIO_ReadPin(Lock_Feedback22_GPIO_Port, Lock_Feedback22_Pin) == GPIO_PIN_RESET))
	{
		   temp_tx_buff[8] = 0xFF; /* lock sensor Being Engaged */
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
