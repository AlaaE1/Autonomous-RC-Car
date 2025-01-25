/*
 * DCMotor_Interface.h
 *
 *  Created on: Sep 6, 2024
 *      Author: alaae
 */

#ifndef HAL_DC_MOTOR_HEADER_DC_MOTOR_INTERFACE_H_
#define HAL_DC_MOTOR_HEADER_DC_MOTOR_INTERFACE_H_

#include "../../../Common/BitMath.h"
#include "../../../Common/Definition.h"
#include "../../../Common/StdType.h"

#include "DC_Motor_Private.h"
#include "DC_Motor_Config.h"
#include "DC_Motor_Register.h"

void DC_MotorInit(u8 Motor);
void DC_MotorOn(u8 Motor , u8 DirectionOfMovement);
void DC_MotorOff(u8 Motor);

#endif /* HAL_DC_MOTOR_HEADER_DC_MOTOR_INTERFACE_H_ */
