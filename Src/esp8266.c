/*
 * esp8266.c
 *
 *  Created on: Mar 31, 2018
 *      Author: Marcus
 */

#include "stm32l1xx_hal.h"
#include "ra6963.h"
#include "esp8266.h"
#include <string.h>

extern UART_HandleTypeDef huart4;

void esp8266Write(char* command, uint16_t readBytes, uint32_t timeout)
{
	char rcvBuffer[80] = "";
	uint16_t length = strlen(command);
	HAL_UART_Transmit(&huart4, (uint8_t*)command, length, 50);
	HAL_UART_Transmit(&huart4, (uint8_t*)"\r\n", 2, 50);
	HAL_UART_Receive(&huart4, (uint8_t*)rcvBuffer, readBytes, timeout);
	ra6963ClearText();
	ra6963WriteString(rcvBuffer);
}

void serverWrite(char* command, uint32_t timeout)
{
	uint16_t length = strlen(command);
	HAL_UART_Transmit(&huart4, (uint8_t*)command, length, 50);
}
