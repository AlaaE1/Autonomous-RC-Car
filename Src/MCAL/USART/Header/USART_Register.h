/*
 * USART_Register.h
 *
 *  Created on: Nov 26, 2024
 *      Author: alaae
 */

#ifndef MCAL_USART_HEADER_USART_REGISTER_H_
#define MCAL_USART_HEADER_USART_REGISTER_H_

/*Define the USART registers*/
#define USART_UDR 	*((volatile u8*)0x2C)	/*USART I/O Data Register*/
#define USART_UCSRA *((volatile u8*)0x2B)	/*USART Control and Status Register A*/
#define USART_UCSRB *((volatile u8*)0x2A)	/*USART Control and Status Register B*/
#define USART_UCSRC *((volatile u8*)0x40)	/*USART Control and Status Register C*/
#define USART_UBRRH	*((volatile u8*)0x40)	/*USART Baud Rate Register H*/
#define USART_UBRRL	*((volatile u8*)0x29)	/*USART Baud Rate Register L*/

#endif /* MCAL_USART_HEADER_USART_REGISTER_H_ */
