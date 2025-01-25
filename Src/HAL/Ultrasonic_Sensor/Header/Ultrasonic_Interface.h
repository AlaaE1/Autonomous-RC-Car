/*
 * Ultrasonic_Interface.h
 *
 *  Created on: Nov 28, 2024
 *      Author: alaae
 */

#ifndef HAL_ULTRASONIC_SENSOR_ULTRASONIC_INTERFACE_H_
#define HAL_ULTRASONIC_SENSOR_ULTRASONIC_INTERFACE_H_

#include "../../../Common/BitMath.h"
#include "../../../Common/Definition.h"
#include "../../../Common/StdType.h"

#include "Ultrasonic_Private.h"
#include "Ultrasonic_Config.h"
#include "Ultrasonic_Register.h"

void ultrasonic_timer();
u16 Ultrasonic_Read_Echo();

#endif /* HAL_ULTRASONIC_SENSOR_ULTRASONIC_INTERFACE_H_ */
