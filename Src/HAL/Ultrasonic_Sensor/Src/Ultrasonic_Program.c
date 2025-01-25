/*
 * Ultrasonic_Program.c
 *
 *  Created on: Nov 28, 2024
 *      Author: alaae
 */

#include "../../../MCAL/DIO/Header/DIO_Interface.h"
#include "../../../MCAL/EXTI/Header/EXTI_Interface.h"
#include "../../../MCAL/GIE/Header/GIE_Interface.h"
#include "../../../MCAL/Timer0/Header/Timer0_Interface.h"
#include "../Header/Ultrasonic_Interface.h"
#include <util/delay.h>

extern u8 SystemState;

volatile u16 ultrasonic_counter=0;

void ultrasonic_timer()
{
	ultrasonic_counter++;
}

u16 Ultrasonic_Read_Echo()
{
	u16 ultrasonic_timer_ticks = 0;
	u16 distance = 0;

	/*Set TRIG_PIN as OUTPUT, ECHO_PIN as INPUT*/
	DIO_SelectDirectionForPin(TRIG_PORT,TRIG_PIN,Output);
	DIO_ControlInternalPullUpForPin(ECHO_PORT,ECHO_PIN,Enable);

	timer_vid_init0_ctc(1,255,1);
	timer_vid_set_isr_timer0_ctc(ultrasonic_timer);

    /*Send a 10µs pulse on TRIG_PIN*/
    DIO_SelectOutputValueForPin(TRIG_PORT,TRIG_PIN,High);    /*Set TRIG_PIN HIGH*/
    _delay_us(10);               /*10Mcs delay*/
    DIO_SelectOutputValueForPin(TRIG_PORT,TRIG_PIN,Low);   /*Set TRIG_PIN LOW*/

	T0_TCNT0 = 0;	/* Clear Timer counter */

	//SetBit(EXTI_GICR, EXTI_INT1);

	EXTI_MCUCR = 0x0C; /*The rising edge of INT1 generates an interrupt request*/

	while (!GetBit(EXTI_GIFR, EXTI_INT1))  /*Wait for rising edge */
	{
		if(SystemState == 1)
		{
			return -1;
		}
		else
		{

		}
	}

	SetBit(EXTI_GIFR, EXTI_INT1); /*Clear the interrupt flag*/

	T0_TCNT0 = 0;	 /*Clear Timer counter */
	ultrasonic_counter = 0;

	EXTI_MCUCR = 0x08; /*The falling edge of INT1 generates an interrupt request*/

	while (!GetBit(EXTI_GIFR, EXTI_INT1))  /*Wait for falling edge */
	{
		if(SystemState == 1)
		{
			return -1;
		}
		else
		{

		}
	}

	SetBit(EXTI_GIFR, EXTI_INT1); /*Clear the interrupt flag*/

	ultrasonic_timer_ticks = T0_TCNT0 + (255 * ultrasonic_counter);
	distance = (34300 * (ultrasonic_timer_ticks/2))/8000000; /*distance = velocity*time = velocity/frequency*/

	return distance;
}
