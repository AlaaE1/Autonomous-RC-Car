/*
 * USART_Interface.h
 *
 *  Created on: Nov 26, 2024
 *      Author: alaae
 */

#ifndef MCAL_USART_HEADER_USART_INTERFACE_H_
#define MCAL_USART_HEADER_USART_INTERFACE_H_

#include "../../../Common/BitMath.h"
#include "../../../Common/Definition.h"
#include "../../../Common/StdType.h"

#include "USART_Register.h"
#include "USART_Private.h"
#include "USART_Config.h"

/*Global Functions*/
void USART_ControlInterrupt(u8 InterruptType , u8 State);

/*USART Functions*/
void USART_Init();

void USART_RxChar(u8 * Data);

void USART_TxChar(u8 Data);



#endif /* MCAL_USART_HEADER_USART_INTERFACE_H_ */
