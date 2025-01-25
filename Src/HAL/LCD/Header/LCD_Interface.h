/*
 * LCD_Interface.h
 *
 *  Created on: Aug 30, 2024
 *      Author: alaae
 */

#ifndef HAL_LCD_HEADER_LCD_INTERFACE_H_
#define HAL_LCD_HEADER_LCD_INTERFACE_H_

#include "../../../Common/BitMath.h"
#include "../../../Common/Definition.h"
#include "../../../Common/stdType.h"

#include "LCD_Private.h"
#include "LCD_Config.h"

/*For 8 bit mode*/
void LCD_SendDataDisplay8bitMode(u8 Data);
void LCD_SendDataCommand8BitMode(u8 Command);
void LCD_Init8BitMode();

/*For 4 bit mode*/
void LCD_SendDataDisplay4bitMode(u8 Data);
void LCD_SendDataCommand4BitMode(u8 Command);
void LCD_Init4BitMode();

/*General*/
void LCD_DisplayString(u8 * String);
void LCD_GoToXY(u8 XPOS, u8 YPOS);
void LCD_ShiftOperation(u8 ShiftDirection);
void LCD_StoreSpecialChar(u8  BlockNo , u8 * SpecialArray);

#endif /* HAL_LCD_HEADER_LCD_INTERFACE_H_ */
