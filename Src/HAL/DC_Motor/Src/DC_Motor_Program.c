#include "../../../MCAL/DIO/Header/DIO_Interface.h"
#include "../Header/DC_Motor_Interface.h"

void DC_MotorInit(u8 Motor)
{
	if(Motor == DC_RightMotor)
	{
		DIO_SelectDirectionForPin(DC_MotorGroup,DC_RightMotorPin0,Output);
		DIO_SelectDirectionForPin(DC_MotorGroup,DC_RightMotorPin1,Output);
	}
	else if(Motor == DC_LeftMotor)
	{
		DIO_SelectDirectionForPin(DC_MotorGroup,DC_LeftMotorPin2,Output);
		DIO_SelectDirectionForPin(DC_MotorGroup,DC_LeftMotorPin3,Output);
	}
}

void DC_MotorOn(u8 Motor , u8 DirectionOfMovement)
{
	if(DirectionOfMovement == Clock_Wise)
	{
		if(Motor == DC_RightMotor)
		{
			DIO_SelectOutputValueForPin(DC_MotorGroup,DC_RightMotorPin0,High);
			DIO_SelectOutputValueForPin(DC_MotorGroup,DC_RightMotorPin1,Low);
		}
		else if(Motor == DC_LeftMotor)
		{
			DIO_SelectOutputValueForPin(DC_MotorGroup,DC_LeftMotorPin2,High);
			DIO_SelectOutputValueForPin(DC_MotorGroup,DC_LeftMotorPin3,Low);
		}
	}
	else if(DirectionOfMovement == Unti_Clock_Wise)
	{
		if(Motor == DC_RightMotor)
		{
			DIO_SelectOutputValueForPin(DC_MotorGroup,DC_RightMotorPin0,Low);
			DIO_SelectOutputValueForPin(DC_MotorGroup,DC_RightMotorPin1,High);
		}
		else if(Motor == DC_LeftMotor)
		{
			DIO_SelectOutputValueForPin(DC_MotorGroup,DC_LeftMotorPin2,Low);
			DIO_SelectOutputValueForPin(DC_MotorGroup,DC_LeftMotorPin3,High);
		}
	}
}

void DC_MotorOff(u8 Motor)
{
	if(Motor == DC_RightMotor)
	{
		DIO_SelectOutputValueForPin(DC_MotorGroup,DC_RightMotorPin0,Low);
		DIO_SelectOutputValueForPin(DC_MotorGroup,DC_RightMotorPin1,Low);
	}
	else if(Motor == DC_LeftMotor)
	{
		DIO_SelectOutputValueForPin(DC_MotorGroup,DC_LeftMotorPin2,Low);
		DIO_SelectOutputValueForPin(DC_MotorGroup,DC_LeftMotorPin3,Low);
	}
}
