/*
 * USART_Private.h
 *
 *  Created on: Nov 26, 2024
 *      Author: alaae
 */

#ifndef MCAL_USART_HEADER_USART_PRIVATE_H_
#define MCAL_USART_HEADER_USART_PRIVATE_H_

/*Define the Bits of the UCSRA Register*/
typedef enum
{
	USART_MPCM,		/*Multiprocessor Communication Mode*/
	USART_U2X,		/*Double USART Transmission Speed*/
	USART_PE,		/*Parity Error*/
	USART_DOR,		/*Data Over Run*/
	USART_FE,		/*Frame Error*/
	USART_UDRE,		/*Data Register Empty*/
	USART_TXC,		/*Transmit Complete*/
	USART_RXC		/*Receive Complete*/
}USART_UCSRABits;

/*Define the Bits of the UCSRB Register*/
typedef enum
{
	USART_TXB8,		/*Transmit Data Bit 8*/
	USART_RXB8,		/*Receive Data Bit 8*/
	USART_UCSZ2,	/*Character Size*/
	USART_TXEN,		/*Transmitter Enable*/
	USART_RXEN,		/*Receiver Enable*/
	USART_UDRIE,	/*USART Data Register Empty Interrupt Enable*/
	USART_TXCIE,	/*TX Complete Interrupt Enable*/
	USART_RXCIE		/*RX Complete Interrupt Enable*/
}USART_UCSRBBits;

/*Define the Bits of the UCSRC Register*/
typedef enum
{
	USART_UCPOL,	/*Clock Polarity*/
	USART_UCSZ0,	/*Character Size Bit 0*/
	USART_UCSZ1,	/*Character Size Bit 1*/
	USART_USBS,		/*Stop Bit Select*/
	USART_UPM0,		/*Parity Mode Bit 0*/
	USART_UPM1,		/*Parity Mode Bit 1*/
	USART_UMSEL,	/*USART Mode Select*/
	USART_UCSRC_URSEL		/*Register Select*/
}USART_UCSRCBits;

/*Define the Bits of the UBRRH Register*/
typedef enum
{
	USART_UBRR8 = 8,	/*USART Baud Rate*/
	USART_UBRR9,		/*USART Baud Rate*/
	USART_UBRR10,		/*USART Baud Rate*/
	USART_UBRR11,		/*USART Baud Rate*/
	ReservedBit1,		/*Unused Bit for Atmega32*/
	ReservidBit2,		/*Unused Bit for Atmega32*/
	ReservedBit3,		/*Unused Bit for Atmega32*/
	USART_UBRRH_URSEL			/*Register Select*/
}USART_UBRRHBits;

/*Define the USART Mode*/
typedef enum
{
	USART_Asynch,
	USART_Synch
}USARTMode;

/*Define the Parity Mode*/
typedef enum
{
	Parity_Disable,
	Reserved,
	Parity_Even,
	Parity_Odd
}ParityMode;

/*Define the Stop Bit Options*/
typedef enum
{
	_1Bit,
	_2Bit
}StopBitOptions;

/*Define Speed Options*/
typedef enum
{
	NormalSpeed,
	DoubleSpeed
}DoubleSpeedOptions;

/*Define the Character size options*/
typedef enum
{
	_5BitData,
	_6BitData,
	_7BitData,
	_8BitData,
	Reserved1,
	Reserved2,
	Reserved3,
	_9BitData
}CharacterSizeOptions;

/*Define Interrupt Type*/
typedef enum
{
	RXInterrupt,
	TXInterrupt,
	UDRInterrupt
}USART_InterruptType;

#define RxType	1
#define TxType	2
#define Both	3

#endif /* MCAL_USART_HEADER_USART_PRIVATE_H_ */
