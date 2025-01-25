#include "../Header/EEPROM_Interface.h"

extern u8 SystemState;

void EEPROM_Read(u16 Address , u8 * DataRead)
{
	if(DataRead != NULL)
	{
		u32 Counter = 0;
		//Check if dont have any write operation
		while((EEPROM_EECR & (1<<EEPROM_EEWE)))
		{
			if(SystemState == 1 || SystemState == 2)
			{
				return;
			}
			else
			{

			}
		}
		//Update Byte Address
		EEPROM_EEARL = Address;
		//Enable Read Operation
		SetBit(EEPROM_EECR,EEPROM_EERE);
		//Read Data
		*DataRead=EEPROM_EEDR;
	}
}

void EEPROM_Write(u16 Address , u8 DataWrite)
{
	u32 Counter = 0;
	while((EEPROM_EECR & (1<<EEPROM_EEWE)))
	{
		if(SystemState == 1 || SystemState == 2)
		{
			return;
		}
		else
		{

		}
	}
	EEPROM_EEARL = Address;
	EEPROM_EEDR = DataWrite;
	EEPROM_EECR |= 0b00000110; //Way1
	//EEPROM_EECR |= (1<<EEPROM_EEMWE) | (1<<EEPROM_EEWE); //Way2
}
