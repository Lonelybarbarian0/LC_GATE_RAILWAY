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

#define TRAIN_DIST 1000
#define TRAIN_DIST_LOW 200

extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart5;
extern UART_HandleTypeDef huart3;
extern volatile uint8_t temp_tx_buff[13];

void Boom1_Status(void);
void Boom2_Status(void);
void UP_Train_Status(void);
void DOWN_Train_Status(void);
void Lever_Status(void);
void LeverLock_Status(void);
void Sys_rst(void);

