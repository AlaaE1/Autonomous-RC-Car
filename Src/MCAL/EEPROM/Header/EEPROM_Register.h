/*
 * EEPROM_Register.h
 *
 *  Created on: Oct 18, 2024
 *      Author: alaae
 */

#ifndef MCAL_EEPROM_HEADER_EEPROM_REGISTER_H_
#define MCAL_EEPROM_HEADER_EEPROM_REGISTER_H_

#define EEPROM_EEARL *((volatile u16*)0x3E)
//#define EEPROM_EEARH *((volatile u8*)0x3F)
#define EEPROM_EEDR *((volatile u8*)0x3D)
#define EEPROM_EECR *((volatile u8*)0x3C)

#endif /* MCAL_EEPROM_HEADER_EEPROM_REGISTER_H_ */
