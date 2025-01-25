/*
 * EXTI_Config.h
 *
 *  Created on: Sep 7, 2024
 *      Author: alaae
 */

#ifndef MCAL_EXTI_HEADER_EXTI_CONFIG_H_
#define MCAL_EXTI_HEADER_EXTI_CONFIG_H_

#include "EXTI_Private.h"


/*1- LowLevel
 *2-AnyLogic
 *3-FallingEdge
 *4-RisingEdge
 */
#define EXTI0_SensType	FallingEdge

/*1- LowLevel
 *2-AnyLogic
 *3-FallingEdge
 *4-RisingEdge
 */
#define EXTI1_SensType	FallingEdge

/*1-FallingEdge
 *2-RisingEdge
 */
#define EXTI2_SensType	FallingEdge

#endif /* MCAL_EXTI_HEADER_EXTI_CONFIG_H_ */
