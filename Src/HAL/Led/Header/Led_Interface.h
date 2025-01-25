#ifndef HAL_LED_HEADER_LED_INTERFACE_H_
#define HAL_LED_HEADER_LED_INTERFACE_H_

#include "../../../Common/stdType.h"
#include "Led_Private.h"
#include "Led_Config.h"

void LedInit(u8 LedNo);
void LedOn(u8 LedNo);
void LedOff(u8 LedNo);
void LedToggel(u8 LedNo);

#endif /* HAL_LED_HEADER_LED_INTERFACE_H_ */
