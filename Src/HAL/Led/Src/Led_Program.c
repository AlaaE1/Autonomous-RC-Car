#include "../../../Common/BitMath.h"
#include "../../../Common/Definition.h"
#include "../../../Common/stdType.h"

#include "../../../MCAL/DIO/Header/DIO_Interface.h"
#include "../Header/Led_Interface.h"

void LedInit(u8 LedNo)
{
	switch(LedNo)
	{
	case Led1 : DIO_SelectDirectionForPin(Led1Group,Led1Pin,Output);break;
	case Led2 : DIO_SelectDirectionForPin(Led2Group,Led2Pin,Output);break;
	case Led3 : DIO_SelectDirectionForPin(Led3Group,Led3Pin,Output);break;
	case Led4 : DIO_SelectDirectionForPin(Led4Group,Led4Pin,Output);break;
	case Led5 : DIO_SelectDirectionForPin(Led5Group,Led5Pin,Output);break;
	case Led6 : DIO_SelectDirectionForPin(Led6Group,Led6Pin,Output);break;
	case Led7 : DIO_SelectDirectionForPin(Led7Group,Led7Pin,Output);break;
	case Led8 : DIO_SelectDirectionForPin(Led8Group,Led8Pin,Output);break;
	}
}

void LedOn(u8 LedNo)
{
	switch(LedNo)
	{
	case Led1 : DIO_SelectOutputValueForPin(Led1Group,Led1Pin,High);break;
	case Led2 : DIO_SelectOutputValueForPin(Led2Group,Led2Pin,High);break;
	case Led3 : DIO_SelectOutputValueForPin(Led3Group,Led3Pin,High);break;
	case Led4 : DIO_SelectOutputValueForPin(Led4Group,Led4Pin,High);break;
	case Led5 : DIO_SelectOutputValueForPin(Led5Group,Led5Pin,High);break;
	case Led6 : DIO_SelectOutputValueForPin(Led6Group,Led6Pin,High);break;
	case Led7 : DIO_SelectOutputValueForPin(Led7Group,Led7Pin,High);break;
	case Led8 : DIO_SelectOutputValueForPin(Led8Group,Led8Pin,High);break;
	}
}

void LedOff(u8 LedNo)
{
	switch(LedNo)
	{
	case Led1 : DIO_SelectOutputValueForPin(Led1Group,Led1Pin,Low);break;
	case Led2 : DIO_SelectOutputValueForPin(Led2Group,Led2Pin,Low);break;
	case Led3 : DIO_SelectOutputValueForPin(Led3Group,Led3Pin,Low);break;
	case Led4 : DIO_SelectOutputValueForPin(Led4Group,Led4Pin,Low);break;
	case Led5 : DIO_SelectOutputValueForPin(Led5Group,Led5Pin,Low);break;
	case Led6 : DIO_SelectOutputValueForPin(Led6Group,Led6Pin,Low);break;
	case Led7 : DIO_SelectOutputValueForPin(Led7Group,Led7Pin,Low);break;
	case Led8 : DIO_SelectOutputValueForPin(Led8Group,Led8Pin,Low);break;
	}
}

void LedToggel(u8 LedNo)
{
	switch(LedNo)
	{
	case Led1 : DIO_ToggelValueForPin(Led1Group,Led1Pin);break;
	case Led2 : DIO_ToggelValueForPin(Led2Group,Led2Pin);break;
	case Led3 : DIO_ToggelValueForPin(Led3Group,Led3Pin);break;
	case Led4 : DIO_ToggelValueForPin(Led4Group,Led4Pin);break;
	case Led5 : DIO_ToggelValueForPin(Led5Group,Led5Pin);break;
	case Led6 : DIO_ToggelValueForPin(Led6Group,Led6Pin);break;
	case Led7 : DIO_ToggelValueForPin(Led7Group,Led7Pin);break;
	case Led8 : DIO_ToggelValueForPin(Led8Group,Led8Pin);break;
	}
}
