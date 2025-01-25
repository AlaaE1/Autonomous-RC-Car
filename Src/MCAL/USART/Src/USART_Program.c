/*
 * USART_Program.c
 *
 *  Created on: Nov 26, 2024
 *      Author: alaae
 */

#include "../Header/USART_Interface.h"

extern u8 SystemState;

static u8 RXInterruptState = RXInterruptStateInit;
static u8 TXInterruptState = TXInterruptStateInit;
static u8 UDRInterruptState = UDRInterruptStateInit;
static u8 CommunicationType = CommunicationTypeInit;
static u8 CharSize = CharSizeInit;

void USART_Init()
{
	/*USCRB*/
	USART_ControlInterrupt(RXInterrupt,RXInterruptState);
	USART_ControlInterrupt(TXInterrupt,TXInterruptState);
	USART_ControlInterrupt(UDRInterrupt,UDRInterruptState);

	if(CommunicationType == TxType)
	{
		ClrBit(USART_UCSRB,USART_RXEN);
		SetBit(USART_UCSRB,USART_TXEN);
	}
	else if(CommunicationType == RxType)
	{
		SetBit(USART_UCSRB,USART_RXEN);
		ClrBit(USART_UCSRB,USART_TXEN);
	}
	else if(CommunicationType == Both)
	{
		SetBit(USART_UCSRB,USART_RXEN);
		SetBit(USART_UCSRB,USART_TXEN);
	}

	u8 UCSRCWrraper = 0;
	/*OperationMode*/
	if(OperationMode == USART_Asynch)
	{
		ClrBit(UCSRCWrraper,USART_UMSEL);
	}
	else if(OperationMode == USART_Synch)
	{
		SetBit(UCSRCWrraper,USART_UMSEL);
	}
	/*StopMode*/
	if(StopMode == _1Bit)
	{
		ClrBit(UCSRCWrraper,USART_USBS);
	}
	else if(StopMode == _2Bit)
	{
		SetBit(UCSRCWrraper,USART_USBS);
	}
	/*ParityMode*/
	if(ParityMode == Parity_Disable)
	{
		ClrBit(UCSRCWrraper,USART_UPM0);
		ClrBit(UCSRCWrraper,USART_UPM1);
	}
	else if(ParityMode == Parity_Even)
	{
		ClrBit(UCSRCWrraper,USART_UPM0);
		SetBit(UCSRCWrraper,USART_UPM1);
	}
	else if(ParityMode == Parity_Odd)
	{
		SetBit(UCSRCWrraper,USART_UPM0);
		SetBit(UCSRCWrraper,USART_UPM1);
	}
	/*CharSize*/
	if(CharSize == _5BitData)
	{
		ClrBit(UCSRCWrraper,USART_UCSZ0);
		ClrBit(UCSRCWrraper,USART_UCSZ1);
		ClrBit(USART_UCSRB,USART_UCSZ2);
	}
	else if(CharSize == _6BitData)
	{
		SetBit(UCSRCWrraper,USART_UCSZ0);
		ClrBit(UCSRCWrraper,USART_UCSZ1);
		ClrBit(USART_UCSRB,USART_UCSZ2);
	}
	else if(CharSize == _7BitData)
	{
		ClrBit(UCSRCWrraper,USART_UCSZ0);
		SetBit(UCSRCWrraper,USART_UCSZ1);
		ClrBit(USART_UCSRB,USART_UCSZ2);
	}
	else if(CharSize == _8BitData)
	{
		SetBit(UCSRCWrraper,USART_UCSZ0);
		SetBit(UCSRCWrraper,USART_UCSZ1);
		ClrBit(USART_UCSRB,USART_UCSZ2);
	}
	else if(CharSize == _9BitData)
	{
		SetBit(UCSRCWrraper,USART_UCSZ0);
		SetBit(UCSRCWrraper,USART_UCSZ1);
		SetBit(USART_UCSRB,USART_UCSZ2);
	}
	SetBit(UCSRCWrraper,7);
	USART_UCSRC = UCSRCWrraper;

	/*Double Speed Mode*/
	ClrBit(USART_UCSRC,USART_U2X);

	/*BaudRate*/
	USART_UBRRL = 51;
}

void USART_ControlInterrupt(u8 InterruptType , u8 State)
{
	if(InterruptType == RXInterrupt && State == Enable)
	{
		SetBit(USART_UCSRB,USART_RXCIE);
	}
	else if(InterruptType == RXInterrupt && State == Disable)
	{
		ClrBit(USART_UCSRB,USART_RXCIE);
	}
	else if(InterruptType == TXInterrupt && State == Enable)
	{
		SetBit(USART_UCSRB,USART_TXCIE);
	}
	else if(InterruptType == TXInterrupt && State == Disable)
	{
		ClrBit(USART_UCSRB,USART_TXCIE);
	}
	else if(InterruptType == UDRInterrupt && State == Enable)
	{
		SetBit(USART_UCSRB,USART_UDRIE);
	}
	else if(InterruptType == UDRInterrupt && State == Disable)
	{
		ClrBit(USART_UCSRB,USART_UDRIE);
	}
	else
	{

	}
}

/* Data receiving function */
void USART_RxChar(u8 * Data)
{

	while(!(USART_UCSRA & (1 << USART_RXC)))					/* Wait until new data receive */
	{
		if(SystemState == 2)
		{
			*Data = '0';
			return;
		}
		else
		{

		}
	}
	*Data = USART_UDR;											/* Get and return received data */
}

/* Data transmitting function */
void USART_TxChar(u8 Data)
{
	while (!(USART_UCSRA & (1<<USART_UDRE)));					/* Wait until data transmit and buffer get empty */
	USART_UDR = Data;											/* Write data to be transmitting in UDR */
}
