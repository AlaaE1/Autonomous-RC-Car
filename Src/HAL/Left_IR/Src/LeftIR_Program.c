/*
 * LeftIR_Program.c
 *
 *  Created on: Nov 28, 2024
 *      Author: alaae
 */

#include "../Header/LeftIR_Interface.h"
#include "../../../MCAL/DIO/Header/DIO_Interface.h"

void LeftIRSensor_Init()
{
	 DIO_SelectDirectionForPin(IRSensors_Group ,IR_Sensors_pinLeft ,Input);
	 DIO_SelectOutputValueForPin(IRSensors_Group,IR_Sensors_pinLeft,High);
}

u8  Read_LeftIRSensor()
{
	u8 read_valueleft=0xff;

	DIO_ReadInputValueForPin(IRSensors_Group ,IR_Sensors_pinLeft ,&read_valueleft);

	return read_valueleft;
}
