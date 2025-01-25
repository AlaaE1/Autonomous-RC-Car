/*
 * BUTTON_Interface.h
 *
 *  Created on: Aug 24, 2024
 *      Author: alaae
 */

#ifndef HAL_BUTTON_HEADER_BUTTON_INTERFACE_H_
#define HAL_BUTTON_HEADER_BUTTON_INTERFACE_H_

#include "../../../Common/stdType.h"
#include "Button_Private.h"
#include "Button_Config.h"

void ButtonInit(u8 ButtonNo);
void ButtonStateForPin(u8 ButtonNo , u8 * State);

#endif /* HAL_BUTTON_HEADER_BUTTON_INTERFACE_H_ */
