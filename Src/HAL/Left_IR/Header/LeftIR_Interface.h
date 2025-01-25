/*
 * LeftIR_Interface.h
 *
 *  Created on: Nov 28, 2024
 *      Author: alaae
 */

#ifndef HAL_LEFT_IR_LEFTIR_INTERFACE_H_
#define HAL_LEFT_IR_LEFTIR_INTERFACE_H_

#include "../../../Common/BitMath.h"
#include "../../../Common/Definition.h"
#include "../../../Common/StdType.h"

#include "LeftIR_Config.h"
#include "LeftIR_Private.h"
#include "LeftIR_Register.h"

void LeftIRSensor_Init();
u8  Read_LeftIRSensor();

#endif /* HAL_LEFT_IR_LEFTIR_INTERFACE_H_ */
