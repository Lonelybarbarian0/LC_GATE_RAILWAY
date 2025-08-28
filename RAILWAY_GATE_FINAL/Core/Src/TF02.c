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
  * @retval 16-bit distance data in cm (by default)
  */

uint16_t TF02_Get_Dist(UART_HandleTypeDef *UART_BUS)
{
	volatile uint8_t data[8];

	if(HAL_UART_Receive(UART_BUS,(uint8_t*)data, 8, 100)== HAL_OK)
	{
		if (data[1] == 0x59 && data[2] == 0x59)
		{
			return (data[4] << 8 | data[3]);
		}
	}
	else return 0xFFFF;
	return 0xFFFF;
}

