/*
 * Timer0_Private.h
 *
 *  Created on: Sep 21, 2024
 *      Author: alaae
 */

#ifndef MCAL_TIMER0_HEADER_TIMER0_PRIVATE_H_
#define MCAL_TIMER0_HEADER_TIMER0_PRIVATE_H_

/*Pin for Normal Mode*/
#define T0_WGM01   3
#define T0_WGM00   6
#define T0_TOIE0   0
#define T0_TOV0    0

/*Pin for CTC Mode*/
#define T0_WGM01   3
#define T0_WGM00   6
#define T0_COM01	5
#define T0_COM00	4
#define T0_OCIE0	1
#define T0_OCF0		1
#define T0_FOC0		7

/*General Pin */
#define T0_CS02  2
#define T0_CS01  1
#define T0_CS00  0

#endif /* MCAL_TIMER0_HEADER_TIMER0_PRIVATE_H_ */
