/*
 * eeprom.c
 *
 *  Created on: Mar 31, 2018
 *      Author: Marcus
 */

#include "stm32l1xx_hal.h"
#include "eeprom.h"

HAL_StatusTypeDef writeEepromFloat(uint32_t address, float data)
{
	union Data {
		float floatData;
		uint32_t intData;
	} unionData;
	HAL_StatusTypeDef status;
	unionData.floatData = data;

	address = address + 0x08080000;
	HAL_FLASHEx_DATAEEPROM_Unlock();
	status = HAL_FLASHEx_DATAEEPROM_Program(TYPEPROGRAMDATA_WORD, address, unionData.intData);
	HAL_FLASHEx_DATAEEPROM_Lock();
	return status;
}

float readEepromFloat(uint32_t address/*, uint8_t* data*/)
{
	float tmp = 0;
	address = address + 0x08080000;
	tmp/**data*/ = *(__IO float*)address;
	return tmp;
}

HAL_StatusTypeDef writeEepromByte(uint32_t address, uint8_t data)
{
	HAL_StatusTypeDef status;
	address = address + 0x08080000;
	HAL_FLASHEx_DATAEEPROM_Unlock();
	status = HAL_FLASHEx_DATAEEPROM_Program(TYPEPROGRAMDATA_BYTE, address, data);
	HAL_FLASHEx_DATAEEPROM_Lock();
	return status;
}

uint8_t readEepromByte(uint32_t address/*, uint8_t* data*/)
{
	//HAL_StatusTypeDef status = HAL_OK;
	uint8_t tmp = 0;
	address = address + 0x08080000;
	tmp/**data*/ = *(__IO uint32_t*)address;
	return tmp;
}
