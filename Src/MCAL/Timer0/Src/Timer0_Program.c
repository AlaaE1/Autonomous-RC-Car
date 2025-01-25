#include"../Header/Timer0_Interface.h"

void(*timer0_ctc_isr)(void);

void timer_vid_set_isr_timer0_ctc (void (*callback_function) (void))
{
	timer0_ctc_isr=callback_function;
}

void __vector_10 (void) __attribute__ ((signal));

void __vector_10 (void)
{
	timer0_ctc_isr();
}

void timer_vid_init0_ctc (u16 prescalar, u8 top, u8 interrupt)
{
	/*CTC MODE*/
	SetBit(T0_TCCR0, T0_WGM01);
	ClrBit(T0_TCCR0, T0_WGM00);

	/*SETTING PRESCALAR*/
	switch (prescalar) {
		case 1:
			T0_TCCR0 = T0_TCCR0| 0b00000001;
		break;
		case 8:
			T0_TCCR0 = T0_TCCR0| 0b00000010;
		break;
		case 64:
			T0_TCCR0 = T0_TCCR0| 0b00000011;
		break;
		case 256:
			T0_TCCR0 = T0_TCCR0| 0b00000100;
		break;
		case 1024:
			T0_TCCR0 = T0_TCCR0| 0b00000101;
		break;
		default:
		break;
	}

	/*SETTING THE TOP VALUE*/
	T0_OCR0 = top;

	/*ENABLE INTERRUPT*/
	if (interrupt) {
		/*ENABLE TIMER0 INTERRUPT*/
		SetBit(T0_TIMSK, T0_OCIE0);
	}
	else {
		ClrBit(T0_TIMSK, T0_OCIE0);
	}
}
