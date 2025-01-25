#include "../Header/GIE_Interface.h"

void GIE_Enable()
{
	SetBit(GIE_SREG,GIE_I);
}

void GIE_Disable()
{
	ClrBit(GIE_SREG,GIE_I);
}
