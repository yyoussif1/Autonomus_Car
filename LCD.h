/*
 * LCD.h
 *
 * Created: 9/23/2022 1:43:31 PM
 *  Author: machd
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "LCD_CFG.h"


#define Clear_Display_Screen					 0X01
#define Return_Home								 0X02


#define Shift_Cursor_Left_Per_Read_Write		 0X04
#define Shift_Cursor_Right_Per_Read_Write		 0X06
#define Shift_Display_Right_Per_Read_Write		 0X05
#define Shift_Display_Left_Per_Read_Write		 0X07


#define Display_Cursor_Blink_All_OFF			 0X08
#define Display_Cursor_OFF_Blink_ON				 0X09
#define Display_Blink_0FF_Cursor_ON				 0X0A
#define Display_OFF_Cursor_Blink_ON				 0X0B
#define Display_ON_Cursor_Blink_OFF				 0X0C
#define Display_Blink_ON_Cursor_OFF				 0X0D
#define Display_Cursor_ON_Blink_OFF				 0X0E
#define Display_Cursor_Blink_All_ON				 0X0F


#define Shift_Cursor_Position_Left				 0X10
#define Shift_Cursor_Position_Right				 0X14
#define Shift_Entire_Display_Left				 0X18
#define Shift_Entire_Display_Right				 0X1C


#define LCD_4_Bit_Mode_1_Line_5_8_Dots			 0X20
#define LCD_4_Bit_Mode_2_Line_5_8_Dots			 0X28
#define LCD_8_Bit_Mode_1_Line_5_8_Dots			 0X30
#define LCD_8_Bit_Mode_2_Line_5_8_Dots			 0X38


#define CGRAM_First_Address_First_Charachter	 0X40

#define DDRAM_Cursor_Begin_1st_Line				 0X80
#define DDRAM_Cursor_Begin_2nd_Line				 0XC0


void LCD_Init();
void LCD_Write_CMD(Uint8 cmd);
void LCD_Write_Data(Uint8 data);
void LCD_Write_String(Uint8 *str);
void LCD_Write_Integer(int data);
void LCD_Write_Decimal(f32 data);
void LCD_Write_Custom_Char(Uint8 position , Uint8 *arr);
void LCD_Goto(Uint8 row , Uint8 col);
void LCD_Clear();


#endif /* LCD_H_ */