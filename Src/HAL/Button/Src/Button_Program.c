#include "../../../Common/BitMath.h"
#include "../../../Common/Definition.h"
#include "../../../Common/stdType.h"

#include "../../../MCAL/DIO/Header/DIO_Interface.h"
#include "../Header/Button_Interface.h"

void ButtonInit(u8 ButtonNo)
{
	switch(ButtonNo)
		{
			case Button1 : DIO_ControlInternalPullUpForPin(Button1Group,Button1Pin,Enable);break;
			case Button2 : DIO_ControlInternalPullUpForPin(Button2Group,Button2Pin,Enable);break;
			case Button3 : DIO_ControlInternalPullUpForPin(Button3Group,Button3Pin,Enable);break;
			case Button4 : DIO_ControlInternalPullUpForPin(Button4Group,Button4Pin,Enable);break;
			case Button5 : DIO_ControlInternalPullUpForPin(Button5Group,Button5Pin,Enable);break;
			case Button6 : DIO_ControlInternalPullUpForPin(Button6Group,Button6Pin,Enable);break;
			case Button7 : DIO_ControlInternalPullUpForPin(Button7Group,Button7Pin,Enable);break;
			case Button8 : DIO_ControlInternalPullUpForPin(Button8Group,Button8Pin,Enable);break;
		}
}

void ButtonStateForPin(u8 ButtonNo , u8 * State)
{
	switch(ButtonNo)
		{
			case Button1 : DIO_ReadInputValueForPin(Button1Group,Button1Pin,State);break;
			case Button2 : DIO_ReadInputValueForPin(Button2Group,Button2Pin,State);break;
			case Button3 : DIO_ReadInputValueForPin(Button3Group,Button3Pin,State);break;
			case Button4 : DIO_ReadInputValueForPin(Button4Group,Button4Pin,State);break;
			case Button5 : DIO_ReadInputValueForPin(Button5Group,Button5Pin,State);break;
			case Button6 : DIO_ReadInputValueForPin(Button6Group,Button6Pin,State);break;
			case Button7 : DIO_ReadInputValueForPin(Button7Group,Button7Pin,State);break;
			case Button8 : DIO_ReadInputValueForPin(Button8Group,Button8Pin,State);break;
		}
}
