/*
 * RightIR_Interface.h
 *
 *  Created on: Nov 28, 2024
 *      Author: alaae
 */

#ifndef HAL_RIGHT_IR_HEADER_RIGHTIR_INTERFACE_H_
#define HAL_RIGHT_IR_HEADER_RIGHTIR_INTERFACE_H_

#include "../../../Common/BitMath.h"
#include "../../../Common/Definition.h"
#include "../../../Common/StdType.h"

#include "RightIR_Config.h"
#include "RightIR_Private.h"
#include "RightIR_Register.h"

void RightIRSensor_Init();
u8  Read_RightIRSensor();

#endif /* HAL_RIGHT_IR_HEADER_RIGHTIR_INTERFACE_H_ */
