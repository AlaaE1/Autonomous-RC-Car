/*
 * LCD_Private.h
 *
 *  Created on: Aug 30, 2024
 *      Author: alaae
 */

#ifndef HAL_LCD_HEADER_LCD_PRIVATE_H_
#define HAL_LCD_HEADER_LCD_PRIVATE_H_

/*Clear Display
 * DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
 * 0   0   0   0   0   0   0   1
 * */
#define Lcd_ClearDisplay    0x01
/*-----------------------------------------------------------------------------*/
/* Return Home
 * DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
 * 0   0   0   0   0   0   1    x
 * */
#define Lcd_ReturnHome     0x02
//#define Lcd_ReturnHome     0x03
/*------------------------------------------------------------------------------*/
/* Entry Mode
 * DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
 * 0   0   0   0   0   1  I/D  S
 * */
#define Lcd_EntryMode1 0x04  // ID = 0  S = 0 ; // Decrement . No Display Shift
#define Lcd_EntryMode2 0x06  // ID = 1  S = 0 ; // Increment . No Display Shift
#define Lcd_EntryMode3 0x07  // ID = 1  S = 1 ; // Increment . Display shift
#define Lcd_EntryMode4 0x05  // ID = 0  S = 1 ; // Decrement . Display shift
/*------------------------------------------------------------------------------*/
/*Display option
 * DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
 * 0   0   0   0   1   D   C   B */
#define Lcd_DisplayOff   	0x08    //D = 0 , C = 0 , B = 0
#define Lcd_DisplayOn    	0x0C    //D = 1 , C = 0 , B = 0
#define Lcd_CursorOn     	0x0E    //D = 1 , C = 1 , B = 0
#define Lcd_CursorBlinkMode 0x0F    //D = 1 , C = 1 , B = 1
/*-----------------------------------------------------------------------------*/
/*
 * Cursor Or Display Shift
 * DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
 *  0   0   0   1  S/C R/L  x   x
 *	S/C = 0  Move Cursor   S/C = 1  Screen Cursor
 *	R/L = 0  Left          R/L = 1  Right
 * */

#define Lcd_MoveCursor          0x10
#define Lcd_ShiftScreenLeft     0x18
#define Lcd_ShiftScreenRight    0x1C
/*-----------------------------------------------------------------------------*/
/*Function Set
 * DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
 *  0   0   1   DL  N   F   *   *
 *  DL => Data lenght = 0  4bit mode  // DL =1 8bit mode
 *  N  => No of Line  = 0  1 line     // N  =1 2 Line
 *  F  => Font size   = 0  5x8 size   // F  =1 5x11 size
 * */
#define Lcd_Set4Mode1Line5x8Size      0x20 // 0b 0010 0000
#define Lcd_Set4Mode2Line5x8Size      0x28 // 0b 0010 1000
#define Lcd_Set4Mode1Line5x11Size     0x24 // 0b 0010 0100
#define Lcd_Set4Mode2Line5x11Size     0x2C // 0b 0010 1100

#define Lcd_Set8Mode1Line5x8Size      0x30 // 0b 0011 0000 // restart
#define Lcd_Set8Mode2Line5x8Size      0x38 // 0b 0011 1000
#define Lcd_Set8Mode1Line5x11Size     0x34 // 0b 0011 0100
#define Lcd_Set8Mode2Line5x11Size     0x3C // 0b 0011 1100

#define Lcd_Restart                   0x30 // 0b 0011 0000 // restart
/*-----------------------------------------------------------------------------*/
/* Set CGRAM
 * DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
 * 0    1   A   A   A   A   A   A
 * 0    1   0   0   0   0   0   0
 * */
#define Lcd_SetCGRAM    0x40    //ex Lcd_SendCommand(Lcd_SetCGRAM+Location)
/*-----------------------------------------------------------------------------*/
/* Set DDRAM
 * DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
 * 1    A   A   A   A   A   A   A
 * 1    0   0   0   0   0   0   0
 * */
#define Lcd_SetDDRAM    0x80    //ex Lcd_SendCommand(Lcd_SetDDRAM+Location)
/*-------------------------------------------------------------------------------*/
#define Lcd_Line1           	 0
#define Lcd_Line2          		 1
#define Lcd_Line2Address    	0x40
#define Lcd_Line1Address    	0x00
#define Lcd_SizeOfOneLocation    8

#define _8BitMode 1
#define _4BitMode 2
#define Lcd_ShiftLeft 0x18
#define Lcd_ShiftRight 0x1C

#endif /* HAL_LCD_HEADER_LCD_PRIVATE_H_ */
