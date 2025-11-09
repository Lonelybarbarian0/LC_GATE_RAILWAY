/*
 * TF02.c
 *
 *  Created on: Aug 22, 2025
 *      Author: kailas
 */

/* Includes Begin */

#include "TF02.h"

/* Includes End */

/**
  * @brief  Receives the distance data from lidar in blocking mode.
  * @param  UART_BUS is a pointer to a UART_HandleTypeDef structure that contains
  *               the configuration information for the specified UART module.
  * @note   Uses a while loop with 100ms timeout for checking for any sensor failure
  * @retval 16-bit distance data in cm (by default)
  */



uint16_t TF02_Get_Dist(UART_HandleTypeDef *UART_BUS)
{
	volatile uint32_t start = HAL_GetTick();   // current tick
	const uint32_t timeout = 100;          // 100 ms - 10 samples time period for the 100Hz sensor rx

	volatile uint8_t data[8] = {0xFF};

	while (1)
	{
		if(HAL_UART_Receive(UART_BUS,(uint8_t*)data, 8, 100)== HAL_OK)
		{
			if (data[1] == 0x59 && data[2] == 0x59)
			{
				return (data[4] << 8 | data[3]);
			}
		}

	    if ((HAL_GetTick() - start) >= timeout)
	    {
			return 0xFFFF;
	    }
	}

}

