/*
 * RightIR_Program.c
 *
 *  Created on: Nov 28, 2024
 *      Author: alaae
 */

#include "../../../MCAL/DIO/Header/DIO_Interface.h"
#include "../Header/RightIR_Interface.h"

void RightIRSensor_Init()
{
	 DIO_SelectDirectionForPin(IRSensors_Group,IR_Sensors_pinRIGHT,Input);
	 DIO_SelectOutputValueForPin(IRSensors_Group,IR_Sensors_pinRIGHT,High);
}

u8  Read_RightIRSensor()
{
	u8 read_valueright=0xff;

	DIO_ReadInputValueForPin(IRSensors_Group ,IR_Sensors_pinRIGHT,&read_valueright);

	return read_valueright;
}
