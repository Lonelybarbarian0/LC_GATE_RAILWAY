/*
 * POLL.h
 *
 *  Created on: Aug 28, 2025
 *      Author: kailas
 *
 *  Used to Detect Train , Boom Status , Health etc.
 */

#ifndef INC_POLL_H_
#define INC_POLL_H_

#endif /* INC_POLL_H_ */

#include "main.h"
#include "TF02.h"
#include "COM.h"

#define TRAIN_DIST 60

extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern volatile uint8_t temp_tx_buff[10];

void Boom1_Status();
void Boom2_Status();
void UP_Train_Status();
void DOWN_Train_Status();



