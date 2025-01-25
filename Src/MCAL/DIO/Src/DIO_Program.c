#include "../../../Common/BitMath.h"
#include "../../../Common/Definition.h"
#include "../../../Common/stdType.h"

#include "../Header/DIO_Interface.h"
#include "../Header/DIO_Register.h"

void DIO_SelectDirectionForPin(u8 GroupName,u8 PinNumber,u8 DirectionState)
{

	if(GroupName<=GroupD && GroupName>=GroupA)
	{
		if(PinNumber<=Pin7 && PinNumber>=Pin0)
		{
			if(DirectionState==Input)
			{
				switch(GroupName)
				{
				case GroupA:ClrBit(DIO_DDRA,PinNumber);break;
				case GroupB:ClrBit(DIO_DDRB,PinNumber);break;
				case GroupC:ClrBit(DIO_DDRC,PinNumber);break;
				case GroupD:ClrBit(DIO_DDRD,PinNumber);break;
				}
			}
			else if (DirectionState== Output)
			{
				switch(GroupName)
				{
				case GroupA:SetBit(DIO_DDRA,PinNumber);break;
				case GroupB:SetBit(DIO_DDRB,PinNumber);break;
				case GroupC:SetBit(DIO_DDRC,PinNumber);break;
				case GroupD:SetBit(DIO_DDRD,PinNumber);break;
				}
			}
			else
			{
				//Invaild Direction State
			}
		}
		else
		{
			//Invaild Pin Number
		}
	}
	else
	{
		//Invaild Group Name
	}

}



void DIO_SelectOutputValueForPin(u8 GroupName,u8 PinNumber,u8 OutputValue)
{
	if(GroupName<=GroupD && GroupName>=GroupA)
	{
		if(PinNumber<=Pin7&&PinNumber>=Pin0)
		{
			if(OutputValue==Low)
			{
				switch(GroupName)
				{
				case GroupA:ClrBit(DIO_PORTA,PinNumber);break;
				case GroupB:ClrBit(DIO_PORTB,PinNumber);break;
				case GroupC:ClrBit(DIO_PORTC,PinNumber);break;
				case GroupD:ClrBit(DIO_PORTD,PinNumber);break;
				}
			}
			else if (OutputValue==High)
			{
				switch(GroupName)
				{
				case GroupA:SetBit(DIO_PORTA,PinNumber);break;
				case GroupB:SetBit(DIO_PORTB,PinNumber);break;
				case GroupC:SetBit(DIO_PORTC,PinNumber);break;
				case GroupD:SetBit(DIO_PORTD,PinNumber);break;
				}
			}
			else
			{

			}
		}
		else
		{
			//Invaild Pin Number
		}
	}
	else
	{
		//Invaild Group Name
	}
}


void DIO_ReadInputValueForPin(u8 GroupName,u8 PinNumber, u8 *InputValue)
{
	if(InputValue!=Null)
	{
		if (GroupName<=GroupD&& GroupName>=GroupA)
		{
			if(PinNumber<=Pin7&&PinNumber>=Pin0)
			{
				switch(GroupName)
				{
				case GroupA: *InputValue = GetBit(DIO_PINA,PinNumber);break;
				case GroupB: *InputValue = GetBit(DIO_PINB,PinNumber);break;
				case GroupC: *InputValue = GetBit(DIO_PINC,PinNumber);break;
				case GroupD: *InputValue = GetBit(DIO_PIND,PinNumber);break;
				}
			}
			else
			{
				//Invaild Pin Number
			}
		}
		else
		{
			// Invaild GroupName
		}
	}
	else
	{
		// Invaild Pointer
	}
}

void DIO_SelectDirectionForGroup(u8 GroupName,u8 DirectionState)
{
	if(GroupName<=GroupD && GroupName>=GroupA)
	{
		if(DirectionState <= 0xFF && DirectionState >=0x00)
		{
			switch(GroupName)
			{
			case GroupA: DIO_DDRA = DirectionState ; break;
			case GroupB: DIO_DDRB = DirectionState ; break;
			case GroupC: DIO_DDRC = DirectionState ; break;
			case GroupD: DIO_DDRD = DirectionState ; break;

			}
		}
		else
		{
			//Invaild Out Of Range
		}
	}
}
void DIO_SelectOutputValueForGroup(u8 GroupName,u8 OutputValue)
{
	if(GroupName<=GroupD && GroupName>=GroupA)
	{
		if(OutputValue <= 0xFF && OutputValue >=0x00)
		{
			switch(GroupName)
			{
			case GroupA: DIO_PORTA = OutputValue ; break;
			case GroupB: DIO_PORTB = OutputValue ; break;
			case GroupC: DIO_PORTC = OutputValue ; break;
			case GroupD: DIO_PORTD = OutputValue ; break;

			}
		}
		else
		{
			//Invaild Out Of Range
		}
	}
}
void  DIO_ReadInputValueForGroup(u8 GroupName, u8 *InputValue)
{
	if(InputValue!=Null)
	{
		if(GroupName<=GroupD && GroupName>=GroupA)
		{

			switch(GroupName)
			{
			case GroupA: *InputValue = DIO_PINA ; break;
			case GroupB: *InputValue = DIO_PINB ; break;
			case GroupC: *InputValue = DIO_PINC ; break;
			case GroupD: *InputValue = DIO_PIND ; break;

			}
		}
		else
		{
			//Invaild Out Of Range
		}
	}
}



void DIO_ToggelValueForPin(u8 GroupName,u8 PinNumber)
{
	if(GroupName<=GroupD&&GroupName>=GroupA)
	{
		if(PinNumber<=Pin7&&PinNumber>=Pin0)
		{
			switch(GroupName)
			{
			case GroupA : TogBit(DIO_PORTA,PinNumber);break;
			case GroupB : TogBit(DIO_PORTB,PinNumber);break;
			case GroupC : TogBit(DIO_PORTC,PinNumber);break;
			case GroupD : TogBit(DIO_PORTD,PinNumber);break;
			}
		}
	}
}

void DIO_ToggelValueForGroup(u8 GroupName)
{
	if(GroupName<=GroupD&&GroupName>=GroupA)
	{

			switch(GroupName)
			{
			case GroupA : DIO_PORTA=~DIO_PORTA;break;
			case GroupB : DIO_PORTB=~DIO_PORTB;break;
			case GroupC : DIO_PORTC=~DIO_PORTC;break;
			case GroupD : DIO_PORTD=~DIO_PORTD;break;
			}

	}
}


void DIO_ControlInternalPullUpForPin(u8 GroupName,u8 PinNumber,u8 State)
{
	DIO_SelectDirectionForPin(GroupName,PinNumber,Input);
	if(State==Enable)
	{

		DIO_SelectOutputValueForPin(GroupName,PinNumber,High);
	}
	else
	{
		DIO_SelectOutputValueForPin(GroupName,PinNumber,Low);

	}

}
