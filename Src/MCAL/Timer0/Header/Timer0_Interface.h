/*
 * Timer0_Interface.h
 *
 *  Created on: Sep 21, 2024
 *      Author: alaae
 */

#ifndef MCAL_TIMER0_HEADER_TIMER0_INTERFACE_H_
#define MCAL_TIMER0_HEADER_TIMER0_INTERFACE_H_

#include "../../../Common/BitMath.h"
#include "../../../Common/Definition.h"
#include "../../../Common/stdType.h"

#include "Timer0_Config.h"
#include "Timer0_Private.h"
#include "Timer0_Register.h"

void timer_vid_set_isr_timer0_ctc (void (*callback_function) (void));
void timer_vid_init0_ctc (u16 prescalar, u8 top, u8 interrupt);

#endif /* MCAL_TIMER0_HEADER_TIMER0_INTERFACE_H_ */
