/*
 * main.c
 *
 *  Created on: Nov 25, 2024
 *      Author: alaae
 */

/*Include some user libraries*/
#include "MCAL/DIO/Header/DIO_Interface.h"
#include "MCAL/USART/Header/USART_Interface.h"
#include "MCAL/EXTI/Header/EXTI_Interface.h"
#include "MCAL/GIE/Header/GIE_Interface.h"
#include "MCAL/EEPROM/Header/EEPROM_Interface.h"
#include "HAL/DC_Motor/Header/DC_Motor_Interface.h"
#include "HAL/Right_IR/Header/RightIR_Interface.h"
#include "HAL/Left_IR/Header/LeftIR_Interface.h"
#include "HAL/LCD/Header/LCD_Interface.h"
#include "HAL/Button/Header/Button_Interface.h"
#include "HAL/Led/Header/Led_Interface.h"
#include "HAL/Ultrasonic_Sensor/Header/Ultrasonic_Interface.h"
#include "Common/GlobalVariable.h"
/*Include some system libraries*/
#include <util/delay.h>

/*Prototyping the vector_1 ISR Function*/
void __vector_1(void) __attribute__((signal));

/*Check the start of the Bluetooth mode to stop the motors*/
static u8 Start = 0;

/*Number of Obstacle_Avoided*/
u8 Obstacle_Avoided = 0;

/*Chars sent by Bluetooth module*/
typedef enum
{
	STOP = '0',
	FORWARD = '1',
	BACKWARD = '2',
	RIGHT = '3',
	LEFT = '4'
}ControlMovements;

/*Main function*/
int main()
{
	/*Initialize Button for interrupt*/
	ButtonInit(Button1);
	/*To Use EXTI0*/
	EXTI0_Init(FallingEdge);
	/*Enable GIE*/
	GIE_Enable();

	/*Initialize the LCD*/
	LCD_Init8BitMode();

	/*Welcome Message*/
	LCD_GoToXY(0,4);
	LCD_DisplayString("Welcome");
	LCD_GoToXY(1,0);
	LCD_DisplayString("Select Car Mode");

	/*USART Pins*/
	DIO_SelectDirectionForPin(GroupD,Pin0,Input);
	DIO_SelectDirectionForPin(GroupD,Pin1,Output);

	/*Initial move value*/
	u8 MoveCommand = STOP;

	/*Action Group Car Motors*/
	DIO_SelectDirectionForGroup(GroupC,0xFF);

	/*Initialize the USART*/
	USART_Init();

	/*Initialize the motors*/
	DC_MotorInit(DC_RightMotor);
	DC_MotorInit(DC_LeftMotor);

	/*Obstacle Avoidance Mode Led*/
	LedInit(Led1);

	/*Bluetooth Mode Led*/
	LedInit(Led2);

	/*Define some variables*/
	u8 Right_IR = 0;
	u8 Left_IR = 0;
	u16 distance = 0;

	/*Initialize the IR sensors*/
	RightIRSensor_Init();
	LeftIRSensor_Init();

	/*Super loop*/
	while(1)
	{
		/*Blutooth mode*/
		if(SystemState == 1)
		{
			/*Turn on the status Led*/
			LedOn(Led2);
			LedOff(Led1);

			/*If its the first call for the Blutooth mode by interrupt turn off the motors*/
			if(Start == 1)
			{
				DC_MotorOff(DC_RightMotor);
				DC_MotorOff(DC_LeftMotor);
				Start = 0;
			}


			/*Bluetooth Mode Instructions*/
			USART_RxChar(&MoveCommand);
			if(MoveCommand == STOP)
			{
				DC_MotorOff(DC_RightMotor);
				DC_MotorOff(DC_LeftMotor);
			}
			else if(MoveCommand == FORWARD)
			{
				DC_MotorOn(DC_RightMotor,Clock_Wise);
				DC_MotorOn(DC_LeftMotor,Clock_Wise);
			}
			else if(MoveCommand == BACKWARD)
			{
				DC_MotorOn(DC_RightMotor,Unti_Clock_Wise);
				DC_MotorOn(DC_LeftMotor,Unti_Clock_Wise);
			}
			else if(MoveCommand == RIGHT)
			{
				DC_MotorOff(DC_RightMotor);
				DC_MotorOn(DC_LeftMotor,Clock_Wise);
			}
			else if(MoveCommand == LEFT)
			{
				DC_MotorOn(DC_RightMotor,Clock_Wise);
				DC_MotorOff(DC_LeftMotor);
			}
		}
		/*Obstacle Avoidance Mode*/
		else if(SystemState == 2)
		{
			/*Turn on the status Led*/
			LedOn(Led1);
			LedOff(Led2);

			/*Read the sensors values*/
			Right_IR = Read_RightIRSensor();
			Left_IR = Read_LeftIRSensor();
			distance = Ultrasonic_Read_Echo();

			/*Obstacle Avoidance Instructions*/
			if(Right_IR == 0 && Left_IR == 0)
			{
				DC_MotorOn(DC_RightMotor,Clock_Wise);
				DC_MotorOn(DC_LeftMotor,Clock_Wise);
			}
			else if(Right_IR == 0 && Left_IR == 1)
			{
				DC_MotorOn(DC_RightMotor,Clock_Wise);
				DC_MotorOff(DC_LeftMotor);
			}
			else if(Right_IR == 1 && Left_IR == 0)
			{
				DC_MotorOff(DC_RightMotor);
				DC_MotorOn(DC_LeftMotor,Clock_Wise);
			}
			else if(Right_IR == 1 && Left_IR == 1)
			{
				DC_MotorOff(DC_RightMotor);
				DC_MotorOff(DC_LeftMotor);
			}

			/*Check the distance between the car and any object*/
			if(distance <= 10)
			{
				/*Left*/
				DC_MotorOn(DC_RightMotor,Clock_Wise);
				DC_MotorOff(DC_LeftMotor);
				_delay_ms(300);
				/*Forward*/
				DC_MotorOn(DC_RightMotor,Clock_Wise);
				DC_MotorOn(DC_LeftMotor,Clock_Wise);
				_delay_ms(800);
				/*Right*/
				DC_MotorOff(DC_RightMotor);
				DC_MotorOn(DC_LeftMotor,Clock_Wise);
				_delay_ms(300);
				/*Forward*/
				DC_MotorOn(DC_RightMotor,Clock_Wise);
				DC_MotorOn(DC_LeftMotor,Clock_Wise);
				_delay_ms(800);
				/*Right*/
				DC_MotorOff(DC_RightMotor);
				DC_MotorOn(DC_LeftMotor,Clock_Wise);
				_delay_ms(300);

				Obstacle_Avoided++;

				EEPROM_Write(0x0010,Obstacle_Avoided);
			}
		}

		if(SystemState == 3)
		{
			/*No Mode*/
			LedOff(Led1);
			LedOff(Led2);

			/*Stop the car*/
			DC_MotorOff(DC_RightMotor);
			DC_MotorOff(DC_LeftMotor);
		}
	}
	return 0;
}

/*Implementation of the vector_1 ISR Function*/
void __vector_1(void)
{
	static u8 state = 0;
	if(state == 0)
	{
		/*Show Status Message*/
		_delay_ms(500);
		LCD_SendDataCommand8BitMode(0x01);
		LCD_GoToXY(0,0);
		LCD_DisplayString("Bluetooth Mode");
		/*Ensure that the car stopped*/
		Start = 1;
		/*Switch state*/
		SystemState = 1;
		state = 1;
	}
	else if(state == 1)
	{
		/*Show Status Message*/
		_delay_ms(500);
		LCD_SendDataCommand8BitMode(0x01);
		LCD_GoToXY(0,4);
		LCD_DisplayString("Obstacle");
		LCD_GoToXY(1,1);
		LCD_DisplayString("Avoidance Mode");
		/*Ensure that the car stopped*/
		DC_MotorOff(DC_RightMotor);
		DC_MotorOff(DC_LeftMotor);
		/*Switch state*/
		SystemState = 2;
		state = 2;
	}
	else if(state == 2)
	{
		/*Show Status Message*/
		_delay_ms(500);
		LCD_SendDataCommand8BitMode(0x01);
		LCD_GoToXY(0,0);
		LCD_DisplayString("Obstacle Avoided");
		LCD_GoToXY(1,0);
		LCD_SendDataDisplay8bitMode(Obstacle_Avoided + 0x30);
		SystemState = 3;
		state = 0;
	}
}
