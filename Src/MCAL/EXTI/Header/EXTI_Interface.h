/*
 * EXTI_Interface.h
 *
 *  Created on: Sep 7, 2024
 *      Author: alaae
 */

#ifndef MCAL_EXTI_HEADER_EXTI_INTERFACE_H_
#define MCAL_EXTI_HEADER_EXTI_INTERFACE_H_

#include"../../../Common/BitMath.h"
#include"../../../Common/Definition.h"
#include"../../../Common/stdtype.h"

#include "EXTI_Register.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"

//Post Configuration
void EXTI0_Init(u8 SensType);

//PreConfiguration
void EXTI0_InitPre();

//Post Configuration
void EXTI1_Init(u8 SensType);

//PreConfiguration
void EXTI1_InitPre();

//Post Configuration
void EXTI2_Init(u8 SensType);

//PreConfiguration
void EXTI2_InitPre();

#endif /* MCAL_EXTI_HEADER_EXTI_INTERFACE_H_ */
