/*
 * buttons.h
 *
 *  Created on: Mar 31, 2018
 *      Author: Marcus
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_

void buttonsInit();
uint8_t getKey();
void delay(uint32_t milliseconds);
uint8_t getCol(uint8_t row);
uint8_t readRow(uint8_t row);
void setAllCols();

#endif /* BUTTONS_H_ */
