/*
 * eeprom.h
 *
 *  Created on: Mar 31, 2018
 *      Author: Marcus
 */

#ifndef EEPROM_H_
#define EEPROM_H_

HAL_StatusTypeDef writeEepromByte(uint32_t address, uint8_t data);
uint8_t readEepromByte(uint32_t address/*, uint8_t* data*/);
HAL_StatusTypeDef writeEepromFloat(uint32_t address, float data);
float readEepromFloat(uint32_t address/*, uint8_t* data*/);

#endif /* EEPROM_H_ */
