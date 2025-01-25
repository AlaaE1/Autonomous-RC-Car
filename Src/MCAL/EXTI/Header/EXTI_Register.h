/*
 * EXTI_Register.h
 *
 *  Created on: Sep 7, 2024
 *      Author: alaae
 */

#ifndef MCAL_EXTI_HEADER_EXTI_REGISTER_H_
#define MCAL_EXTI_HEADER_EXTI_REGISTER_H_

/*MCUCR*/
#define EXTI_MCUCR *((volatile u8*)0x55)

/*MCUCSR*/
#define EXTI_MCUCSR *((volatile u8*)0x54)

/*GICR*/
#define EXTI_GICR *((volatile u8*)0x5B)

/*GIFR*/
#define EXTI_GIFR *((volatile u8*)0x5A)

#endif /* MCAL_EXTI_HEADER_EXTI_REGISTER_H_ */
