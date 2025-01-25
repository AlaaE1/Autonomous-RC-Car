/*
 * EEPROM_Interface.h
 *
 *  Created on: Oct 18, 2024
 *      Author: alaae
 */

#ifndef MCAL_EEPROM_HEADER_EEPROM_INTERFACE_H_
#define MCAL_EEPROM_HEADER_EEPROM_INTERFACE_H_

#include "../../../Common/BitMath.h"
#include "../../../Common/Definition.h"
#include "../../../Common/stdType.h"

#include "EEPROM_Config.h"
#include "EEPROM_Private.h"
#include "EEPROM_Register.h"

/*Read Operation*/
void EEPROM_Read(u16 Address , u8 * DataRead);

/*Write Operation*/
void EEPROM_Write(u16 Address , u8 DataWrite);

#endif /* MCAL_EEPROM_HEADER_EEPROM_INTERFACE_H_ */
