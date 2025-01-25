#include "../Header/EXTI_Interface.h"



//Post Configuration INT0
void EXTI0_Init(u8 SensType)
{
	//Configure the Sens Control for EXTI0
	if(SensType==LowLevel)
	{
		//Use MCUCR ISC01 ISC00
		//ISC00 -> low (0)
		//ISC01 -> low (0)
		ClrBit(EXTI_MCUCR,EXTI_ISC00);
		ClrBit(EXTI_MCUCR,EXTI_ISC01);

	}
	else if (SensType==AnyLogic)
	{
		//Use MCUCR ISC01 ISC00
		//ISC00 -> High (1)
		//ISC01 -> low (0)
		SetBit(EXTI_MCUCR,EXTI_ISC00);
		ClrBit(EXTI_MCUCR,EXTI_ISC01);
	}
	else if (SensType==FallingEdge)
	{
		//Use MCUCR ISC01 ISC00
		//ISC00 -> low (0)
		//ISC01 -> High (1)
		ClrBit(EXTI_MCUCR,EXTI_ISC00);
		SetBit(EXTI_MCUCR,EXTI_ISC01);
	}
	else //SensType == Rising
	{
		//Use MCUCR ISC01 ISC00
		//ISC00 -> High (1)
		//ISC01 -> High (1)
		SetBit(EXTI_MCUCR,EXTI_ISC00);
		SetBit(EXTI_MCUCR,EXTI_ISC01);
	}
	//Enable PIE for EXTI0
	//Use GICR ->  INT0 -> 6
	SetBit(EXTI_GICR,EXTI_INT0);
}

//Pre Configuration INT0
void EXTI0_InitPre(void)
{
	//Configure the Sens Control For INT0
#if EXTI0_SensType==LowLevel
	ClrBit(EXTI_MCUCR,EXTI_ISC00);
	ClrBit(EXTI_MCUCR,EXTI_ISC01);
#elif EXTI0_SensType==AnyLogic
	SetBit(EXTI_MCUCR,EXTI_ISC00);
	ClrBit(EXTI_MCUCR,EXTI_ISC01);
#elif EXTI0_SensType==FallingEdge
	ClrBit(EXTI_MCUCR,EXTI_ISC00);
	SetBit(EXTI_MCUCR,EXTI_ISC01);
#elif EXTI0_SensType==RisingEdge
	SetBit(EXTI_MCUCR,EXTI_ISC00);
	SetBit(EXTI_MCUCR,EXTI_ISC01);
#endif
	//Enable Interrupt
	SetBit(EXTI_GICR,EXTI_INT0);
}





//Post Configuration INT1
void EXTI1_Init(u8 SensType)
{
	//Configure the Sens Control for EXTI0
	if(SensType==LowLevel)
	{
		//Use MCUCR ISC11 ISC10
		//ISC10 -> low (0)
		//ISC11 -> low (0)
		ClrBit(EXTI_MCUCR,EXTI_ISC10);
		ClrBit(EXTI_MCUCR,EXTI_ISC11);

	}
	else if (SensType==AnyLogic)
	{
		//Use MCUCR ISC01 ISC00
		//ISC10 -> High (1)
		//ISC11 -> low (0)
		SetBit(EXTI_MCUCR,EXTI_ISC10);
		ClrBit(EXTI_MCUCR,EXTI_ISC11);
	}
	else if (SensType==FallingEdge)
	{
		//Use MCUCR ISC01 ISC00
		//ISC10 -> low (0)
		//ISC11 -> High (1)
		ClrBit(EXTI_MCUCR,EXTI_ISC10);
		SetBit(EXTI_MCUCR,EXTI_ISC11);
	}
	else //SensType == Rising
	{
		//Use MCUCR ISC01 ISC00
		//ISC10 -> High (1)
		//ISC11 -> High (1)
		SetBit(EXTI_MCUCR,EXTI_ISC10);
		SetBit(EXTI_MCUCR,EXTI_ISC11);
	}
	//Enable PIE for EXTI0
	//Use GICR ->  INT1 -> 7
	SetBit(EXTI_GICR,EXTI_INT1);
}

//Pre Configuration INT1
void EXTI1_InitPre(void)
{
	//Configure the Sens Control For INT1
#if EXTI1_SensType==LowLevel
	ClrBit(EXTI_MCUCR,EXTI_ISC10);
	ClrBit(EXTI_MCUCR,EXTI_ISC11);
#elif EXTI1_SensType==AnyLogic
	SetBit(EXTI_MCUCR,EXTI_ISC10);
	ClrBit(EXTI_MCUCR,EXTI_ISC11);
#elif EXTI1_SensType==FallingEdge
	ClrBit(EXTI_MCUCR,EXTI_ISC10);
	SetBit(EXTI_MCUCR,EXTI_ISC11);
#elif EXTI1_SensType==RisingEdge
	SetBit(EXTI_MCUCR,EXTI_ISC10);
	SetBit(EXTI_MCUCR,EXTI_ISC11);
#endif
	//Enable Interrupt
	SetBit(EXTI_GICR,EXTI_INT1);
}





//Post Configuration INT2
void EXTI2_Init(u8 SensType)
{
	if (SensType==FallingEdge)
	{
		//Use MCUCSR ISC2F ISC2R
		//ISC2F -> Low (0)
		ClrBit(EXTI_MCUCSR,EXTI_ISC2F);
	}
	else //SensType == Rising
	{
		//Use MCUCR ISC2F ISC2R
		//ISC2R -> High (1)
		SetBit(EXTI_MCUCSR,EXTI_ISC2R);
	}
	//Enable PIE for EXTI0
	//Use GICR ->  INT2 -> 5
	SetBit(EXTI_GICR,EXTI_INT2);
}

//Pre Configuration INT2
void EXTI2_InitPre(void)
{
	//Configure the Sens Control For INT2
#if EXTI2_SensType==FallingEdge
	ClrBit(EXTI_MCUCSR,EXTI_ISC2F);
#elif EXTI2_SensType==RisingEdge
	SetBit(EXTI_MCUCSR,EXTI_ISC2R);
#endif
	//Enable Interrupt
	SetBit(EXTI_GICR,EXTI_INT2);
}
