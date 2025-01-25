/*
 * DIO_Interface.h
 *
 *  Created on: Aug 24, 2024
 *      Author: alaae
 */

#ifndef MCAL_DIO_HEADER_DIO_INTERFACE_H_
#define MCAL_DIO_HEADER_DIO_INTERFACE_H_
#include"../../../Common/stdType.h"
#include "DIO_Register.h"
#include "DIO_Private.h"
#include "DIO_Config.h"

void DIO_SelectDirectionForPin(u8 GroupName, u8 PinNumber, u8 DirectionState);
void DIO_SelectOutputValueForPin(u8 GroupName, u8 PinNumber, u8 Outputvalue);
void DIO_ReadInputValueForPin(u8 GroupName, u8 PinNumber, u8 * InputValue);

void DIO_SelectDirectionForGroup(u8 GroupName, u8 DirectionState);
void DIO_SelectOutputValueForGroup(u8 GroupName, u8 Outputvalue);
void DIO_ReadInputValueForGroup(u8 GroupName, u8 * InputValue);

void DIO_ControlInternalPullUpForPin(u8 GroupName, u8 PinNumber, u8 State);
void DIO_ToggelValueForGroup(u8 GroupName);
void DIO_ToggelValueForPin(u8 GroupName, u8 PinNumber);

#endif /* MCAL_DIO_HEADER_DIO_INTERFACE_H_ */
