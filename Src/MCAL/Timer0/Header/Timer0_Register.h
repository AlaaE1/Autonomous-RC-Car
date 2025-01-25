/*
 * Timer0_Register.h
 *
 *  Created on: Sep 21, 2024
 *      Author: alaae
 */

#ifndef MCAL_TIMER0_HEADER_TIMER0_REGISTER_H_
#define MCAL_TIMER0_HEADER_TIMER0_REGISTER_H_

#define T0_TCCR0 *((volatile u8*)0x53)
#define T0_TCNT0 *((volatile u8*)0x52)
#define T0_TIMSK *((volatile u8*)0x59)
#define T0_TIFR  *((volatile u8*)0x58)
#define T0_OCR0  *((volatile u8*)0x5C)

#endif /* MCAL_TIMER0_HEADER_TIMER0_REGISTER_H_ */
