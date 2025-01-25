#include <util/delay.h>
#include "../../../MCAL/DIO/Header/DIO_Interface.h"
#include "../Header/LCD_Interface.h"

static char LCDMode = 0;

void LCD_SendDataDisplay8bitMode(u8 Data)
{
	/*RS*/
	DIO_SelectOutputValueForPin(LcdControl_Group, LcdControl_RS, High);
	/*RW*/
	DIO_SelectOutputValueForPin(LcdControl_Group, LcdControl_RW, Low);
	/*Enable E*/
	DIO_SelectOutputValueForPin(LcdControl_Group, LcdControl_E, High);
	/*Data*/
	DIO_SelectOutputValueForGroup(LcdDataGroup, Data);
	/*Disable E*/
	DIO_SelectOutputValueForPin(LcdControl_Group, LcdControl_E, Low);
}

void LCD_SendDataCommand8BitMode(u8 Command)
{
	/*RS*/
	DIO_SelectOutputValueForPin(LcdControl_Group, LcdControl_RS, Low);
	/*RW*/
	DIO_SelectOutputValueForPin(LcdControl_Group, LcdControl_RW, Low);
	/*Enable E*/
	DIO_SelectOutputValueForPin(LcdControl_Group, LcdControl_E, High);
	/*Data*/
	DIO_SelectOutputValueForGroup(LcdDataGroup, Command);
	/*Disable E*/
	DIO_SelectOutputValueForPin(LcdControl_Group, LcdControl_E, Low);
	_delay_ms(2);
}

void LCD_Init8BitMode()
{
	/*Select the direction for Pin and Data Group*/
	DIO_SelectDirectionForPin(LcdControl_Group, LcdControl_RS, Output);
	DIO_SelectDirectionForPin(LcdControl_Group, LcdControl_RW, Output);
	DIO_SelectDirectionForPin(LcdControl_Group, LcdControl_E, Output);
	DIO_SelectDirectionForGroup(LcdDataGroup, 0xFF);
	/*-----------------------------------------*/
	/*Initi*/
	LCDMode = _8BitMode;
	_delay_ms(35);
	/*Function Set*/
	LCD_SendDataCommand8BitMode(0x38);
	//_delay_ms(2);
	/*Display ON/OFF*/
	LCD_SendDataCommand8BitMode(0x0C);
	//_delay_ms(2);
	/*Clear Display*/
	LCD_SendDataCommand8BitMode(0x01);
	//_delay_ms(2);
	/*Entry Mode*/
	LCD_SendDataCommand8BitMode(0x06);
	//_delay_ms(2);
}

void LCD_SendDataDisplay4bitMode(u8 Data)
{

}

void LCD_SendDataCommand4BitMode(u8 Command)
{

}

void LCD_Init4BitMode()
{

}

void LCD_DisplayString(u8 * String)
{
	u8 Count = 0;
	if(String != NULL)
	{
		while(String[Count] != '\0')
		{
			if(LCDMode == _8BitMode)
			{
				LCD_SendDataDisplay8bitMode(String[Count]);
				Count++;
			}
			else if(LCDMode == _4BitMode)
			{
				LCD_SendDataDisplay4bitMode(String[Count]);
				Count++;
			}
		}
	}
}

void LCD_GoToXY(u8 XPOS, u8 YPOS)
{
	//Cal DDRAM Address
	//X Row 'Line'
	//Y Column 'Digit'
	u8 DDRAM_Adderss = 0;
	switch(XPOS)
	{
	case 0 : DDRAM_Adderss = 0x00 + YPOS; break;
	case 1 : DDRAM_Adderss = 0x40 + YPOS; break;
	}
	if(LCDMode == _8BitMode)
	{
		LCD_SendDataCommand8BitMode(0x80 + DDRAM_Adderss);
	}
	else if(LCDMode == _4BitMode)
	{
		LCD_SendDataCommand4BitMode(0x80 + DDRAM_Adderss);
	}
}

void LCD_ShiftOperation(u8 ShiftDirection)
{
	u8 counter = 0;
	if(LCDMode == _8BitMode)
	{
		for(counter = 0; counter <= 15; counter++)
		{
			LCD_SendDataCommand8BitMode(ShiftDirection);
			_delay_ms(300);
		}
	}
}

void LCD_StoreSpecialChar(u8  BlockNo , u8 * SpecialArray)
{
	if(SpecialArray != NULL)
	{
		u8 CGRAMAddress = BlockNo * 8;
		u8 counter = 0;
		if(LCDMode == _8BitMode)
		{
			LCD_SendDataCommand8BitMode(0x40 | CGRAMAddress);
			for(counter = 0; counter < 8; counter++)
			{
				LCD_SendDataDisplay8bitMode(SpecialArray[counter]);
			}
		}
		else if (LCDMode==_4BitMode)
		{

		}
	}
}
