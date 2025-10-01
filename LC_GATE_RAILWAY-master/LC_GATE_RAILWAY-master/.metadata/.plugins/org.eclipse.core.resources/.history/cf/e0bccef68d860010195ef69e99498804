/*
 * POLL.c
 *
 *  Created on: Aug 28, 2025
 *      Author: kailas
 */

/* Includes Begin */
#include "POLL.h"
/* Includes END */


/* Function Def Begin */

/**
  * @brief  Reads the state of BOOM 1
  *         Changes temp_tx_msg[4] - UP/DOWN and temp_tx_msg[6] - GOOD/BAD  accordingly...
  * @param  None
  * @retval None.
  */
void Boom1_Status()
{
	if( ( (HAL_GPIO_ReadPin(BOOM1_LS11_GPIO_Port, BOOM1_LS11_Pin) == GPIO_PIN_RESET) &&
		  (HAL_GPIO_ReadPin(BOOM1_LS12_GPIO_Port, BOOM1_LS12_Pin) == GPIO_PIN_SET) ) ||
		( (HAL_GPIO_ReadPin(BOOM1_LS21_GPIO_Port, BOOM1_LS21_Pin) == GPIO_PIN_RESET) &&
		  (HAL_GPIO_ReadPin(BOOM1_LS22_GPIO_Port, BOOM1_LS22_Pin) == GPIO_PIN_SET) ) )
	{
		temp_tx_buff[4] = 0x00; /* BOOM 1 CLOSED */
		temp_tx_buff[6] = 0x01; /* BOOM 1 Healthy */

	}
	else if( ( (HAL_GPIO_ReadPin(BOOM1_LS11_GPIO_Port, BOOM1_LS11_Pin) == GPIO_PIN_SET) &&
		       (HAL_GPIO_ReadPin(BOOM1_LS12_GPIO_Port, BOOM1_LS12_Pin) == GPIO_PIN_RESET) ) ||
		     ( (HAL_GPIO_ReadPin(BOOM1_LS21_GPIO_Port, BOOM1_LS21_Pin) == GPIO_PIN_SET) &&
		       (HAL_GPIO_ReadPin(BOOM1_LS22_GPIO_Port, BOOM1_LS22_Pin) == GPIO_PIN_RESET) ) )
	{
		temp_tx_buff[4] = 0x01; /* BOOM 1 OPEN */
		temp_tx_buff[6] = 0x01; /* BOOM 1 Healthy */
	}
	else
	{
		temp_tx_buff[4] = 0xFF;
		temp_tx_buff[6] = 0x00; /* BOOM 1 HEALTH BAD */
	}

}

/**
  * @brief  Reads the state of BOOM 2
  *         Changes temp_tx_msg[5] - UP/DOWN and temp_tx_msg[7] - GOOD/BAD  accordingly...
  * @param  None
  * @retval None.
  */
void Boom2_Status()
{
	if( ( (HAL_GPIO_ReadPin(BOOM2_LS11_GPIO_Port, BOOM2_LS11_Pin) == GPIO_PIN_RESET) &&
		  (HAL_GPIO_ReadPin(BOOM2_LS12_GPIO_Port, BOOM2_LS12_Pin) == GPIO_PIN_SET) ) ||
		( (HAL_GPIO_ReadPin(BOOM2_LS21_GPIO_Port, BOOM2_LS21_Pin) == GPIO_PIN_RESET) &&
		  (HAL_GPIO_ReadPin(BOOM2_LS22_GPIO_Port, BOOM2_LS22_Pin) == GPIO_PIN_SET) ) )
	{
		temp_tx_buff[5] = 0x00; /* BOOM 2 CLOSED */
		temp_tx_buff[7] = 0x01; /* BOOM 2 Healthy */

	}
	else if( ( (HAL_GPIO_ReadPin(BOOM2_LS11_GPIO_Port, BOOM2_LS11_Pin) == GPIO_PIN_SET) &&
		       (HAL_GPIO_ReadPin(BOOM2_LS12_GPIO_Port, BOOM2_LS12_Pin) == GPIO_PIN_RESET) ) ||
		     ( (HAL_GPIO_ReadPin(BOOM2_LS21_GPIO_Port, BOOM2_LS21_Pin) == GPIO_PIN_SET) &&
		       (HAL_GPIO_ReadPin(BOOM2_LS22_GPIO_Port, BOOM2_LS22_Pin) == GPIO_PIN_RESET) ) )
	{
		temp_tx_buff[5] = 0x01; /* BOOM 2 OPEN */
		temp_tx_buff[7] = 0x01; /* BOOM 2 Healthy */
	}
	else
	{
		temp_tx_buff[5] = 0xFF;
		temp_tx_buff[7] = 0x00; /* BOOM 2 HEALTH BAD */
	}

}

/**
  * @brief  Reads the two adjacent Lidar values
  *         Compare it with TRAIN_DIST MACRO and changes temp_tx_buff[2] - UP direction
  * @param  None
  * @retval None
  */
void UP_Train_Status()
{
	volatile uint16_t data1[5] = {0xFFFF};
	volatile uint16_t data2[5] = {0xFFFF};

	for(uint8_t i=0;i<5;i++)
	{
	    data1[i] = TF02_Get_Dist(&huart1);
	    data2[i] = TF02_Get_Dist(&huart3);
	}


    if( ((data1[0] == 0xFFFF) && (data1[1] == 0xFFFF) && (data1[2] == 0xFFFF) && (data1[3] == 0xFFFF) && (data1[4] == 0xFFFF))
     || ((data2[0] == 0xFFFF) && (data2[1] == 0xFFFF) && (data2[2] == 0xFFFF) && (data2[3] == 0xFFFF) && (data2[4] == 0xFFFF)) )
    {
    	temp_tx_buff[2] = 0xFF; /* Sensor Error */
    }
   if((data1[4] != 0xFFFF) && (data2[4] != 0xFFFF))
   {
	   if(data1[4] <= TRAIN_DIST && data2[4] <= TRAIN_DIST)
	   {
		   temp_tx_buff[2] = 0x01;  /* Train Detected */
	   }
	   else if (data1[4] >= TRAIN_DIST && data2[4] >= TRAIN_DIST)
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
void DOWN_Train_Status()
{
	volatile uint16_t data3[5] = {0xFFFF};
	volatile uint16_t data4[5] = {0xFFFF};

	for(uint8_t i=0;i<5;i++)
	{
	    data3[i] = TF02_Get_Dist(&huart3);
	    data4[i] = TF02_Get_Dist(&huart4);
	}

    if( ((data3[0] == 0xFFFF) && (data3[1] == 0xFFFF) && (data3[2] == 0xFFFF) && (data3[3] == 0xFFFF) && (data3[4] == 0xFFFF))
     || ((data4[0] == 0xFFFF) && (data4[1] == 0xFFFF) && (data4[2] == 0xFFFF) && (data4[3] == 0xFFFF) && (data4[4] == 0xFFFF)) )
    {
    	temp_tx_buff[3] = 0xFF; /* Sensor Error */
    }
    if((data3[4] != 0xFFFF) && (data4[4] != 0xFFFF))
    {
 	   if(data3[4] <= TRAIN_DIST && data4[4] <= TRAIN_DIST)
 	   {
 		   temp_tx_buff[3] = 0x01;  /* Train Detected */
 	   }
 	   else if (data3[4] >= TRAIN_DIST && data4[4] >= TRAIN_DIST)
 	   {
 		   temp_tx_buff[3] = 0x00;  /* No Train Detected */
 	   }
    }

}

/* Function Def END */
