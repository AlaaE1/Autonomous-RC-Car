/*
 * USART_Config.h
 *
 *  Created on: Nov 26, 2024
 *      Author: alaae
 */

#ifndef MCAL_USART_HEADER_USART_CONFIG_H_
#define MCAL_USART_HEADER_USART_CONFIG_H_

#define RXInterruptStateInit	Disable

#define TXInterruptStateInit	Disable

#define UDRInterruptStateInit	Disable

/*
 * RxType
 * TxType
 * Both
 * */
#define CommunicationTypeInit Both

/*
 * 	USART_Asynch,
 * 	USART_Synch
 * 	*/
#define OperationMode	USART_Asynch

/*
 * 	_1Bit,
 * 	_2Bit
 * */

#define StopMode	_1Bit

/*
 * 	Parity_Disable = 0,
 * 	Reserved = 32,
 * 	Parity_Even = 64,
 * 	Parity_Odd = 96
 * 	*/
#define ParityMode	Parity_Disable

/*
 * 	_5BitData,
 * 	_6BitData,
 * 	_7BitData,
 * 	_8BitData,
 * 	_9BitData
 * 	*/
#define CharSizeInit	_8BitData

#define TimeOut	500

#endif /* MCAL_USART_HEADER_USART_CONFIG_H_ */
