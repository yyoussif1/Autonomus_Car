/*
 * LCD.c
 *
 * Created: 9/23/2022 1:44:10 PM
 *  Author: machd
 */ 

#define F_CPU  16000000
#include <util/delay.h>
#include "LCD.h"

void LCD_Init()
{
	
				/* Control Pins Direction */
	DIO_SetPin_Dir(LCD_4_Bit_CMD_Port , LCD_Pin_RS , DIO_PIN_OUT);
	DIO_SetPin_Dir(LCD_4_Bit_CMD_Port , LCD_Pin_RW , DIO_PIN_OUT);
	DIO_SetPin_Dir(LCD_4_Bit_CMD_Port , LCD_Pin_E ,  DIO_PIN_OUT);
	
				/* Data Pins Direction */
	DIO_SetPin_Dir(LCD_4_Bit_Data_Port , LCD_Pin4 , DIO_PIN_OUT);
	DIO_SetPin_Dir(LCD_4_Bit_Data_Port , LCD_Pin5 , DIO_PIN_OUT);
	DIO_SetPin_Dir(LCD_4_Bit_Data_Port , LCD_Pin6 , DIO_PIN_OUT);
	DIO_SetPin_Dir(LCD_4_Bit_Data_Port , LCD_Pin7 , DIO_PIN_OUT);
	
				/* Control Pins Values */
	DIO_SetPin_Value(LCD_4_Bit_CMD_Port , LCD_Pin_RS , DIO_PIN_OFF);
	DIO_SetPin_Value(LCD_4_Bit_CMD_Port , LCD_Pin_RW , DIO_PIN_OFF);
	DIO_SetPin_Value(LCD_4_Bit_CMD_Port , LCD_Pin_E ,  DIO_PIN_OFF);
	
				/* Data Pins Values */
	DIO_SetPin_Value(LCD_4_Bit_Data_Port , LCD_Pin4 , DIO_PIN_OFF);
	DIO_SetPin_Value(LCD_4_Bit_Data_Port , LCD_Pin5 , DIO_PIN_OFF);
	DIO_SetPin_Value(LCD_4_Bit_Data_Port , LCD_Pin6 , DIO_PIN_OFF);
	DIO_SetPin_Value(LCD_4_Bit_Data_Port , LCD_Pin7 , DIO_PIN_OFF);
	
	_delay_ms(50);
	
	LCD_Write_CMD(0X33);
	LCD_Write_CMD(0X32);
	LCD_Write_CMD(LCD_4_Bit_Mode_2_Line_5_8_Dots);
	LCD_Write_CMD(Clear_Display_Screen);
	LCD_Write_CMD(Return_Home);
	LCD_Write_CMD(Shift_Cursor_Right_Per_Read_Write);
	LCD_Write_CMD(Display_ON_Cursor_Blink_OFF);
	
}

void LCD_Write_CMD(Uint8 cmd)
{
				/* Values of Control Pins */
	DIO_SetPin_Value(LCD_4_Bit_CMD_Port , LCD_Pin_RS , DIO_PIN_OFF);
	DIO_SetPin_Value(LCD_4_Bit_CMD_Port , LCD_Pin_RW , DIO_PIN_OFF);
	DIO_SetPin_Value(LCD_4_Bit_CMD_Port , LCD_Pin_E ,  DIO_PIN_OFF);
	
				/* High nipple of cmd to be written */
	LCD_4_Bit_Data_Bus = (cmd & 0XF0) | (LCD_4_Bit_Data_Bus & 0X0F);
	
				/* Enable writing to data pins */
	DIO_SetPin_Value(LCD_4_Bit_CMD_Port , LCD_Pin_E , DIO_PIN_ON);
	_delay_ms(2);
	DIO_SetPin_Value(LCD_4_Bit_CMD_Port , LCD_Pin_E , DIO_PIN_OFF);
	
				/* Low nipple of cmd to be written */
	LCD_4_Bit_Data_Bus = (cmd << 4) | (LCD_4_Bit_Data_Bus & 0X0F);
	
				/* Enable writing to data pins */
	DIO_SetPin_Value(LCD_4_Bit_CMD_Port , LCD_Pin_E , DIO_PIN_ON);
	_delay_ms(2);
	DIO_SetPin_Value(LCD_4_Bit_CMD_Port , LCD_Pin_E , DIO_PIN_OFF);
	
	_delay_ms(5);
}

void LCD_Write_Data(Uint8 data)
{
				/* Values of Control Pins */
	DIO_SetPin_Value(LCD_4_Bit_CMD_Port , LCD_Pin_RS , DIO_PIN_ON);
	DIO_SetPin_Value(LCD_4_Bit_CMD_Port , LCD_Pin_RW , DIO_PIN_OFF);
	DIO_SetPin_Value(LCD_4_Bit_CMD_Port , LCD_Pin_E ,  DIO_PIN_OFF);
	
				/* High nipple of cmd to be written */
	LCD_4_Bit_Data_Bus = (data & 0XF0) | (LCD_4_Bit_Data_Bus & 0X0F);
	
				/* Enable writing to data pins */
	DIO_SetPin_Value(LCD_4_Bit_CMD_Port , LCD_Pin_E , DIO_PIN_ON);
	_delay_ms(2);
	DIO_SetPin_Value(LCD_4_Bit_CMD_Port , LCD_Pin_E , DIO_PIN_OFF);
	
				/* Low nipple of cmd to be written */
	LCD_4_Bit_Data_Bus = (data << 4) | (LCD_4_Bit_Data_Bus & 0X0F);
	
				/* Enable writing to data pins */
	DIO_SetPin_Value(LCD_4_Bit_CMD_Port , LCD_Pin_E , DIO_PIN_ON);
	_delay_ms(2);
	DIO_SetPin_Value(LCD_4_Bit_CMD_Port , LCD_Pin_E , DIO_PIN_OFF);

}

void LCD_Write_String(Uint8 *str)
{
	Uint8 i = 0;
	while(str[i] != '\0')
	{
		LCD_Write_Data(str[i]);
		i++;
	}

}

void LCD_Write_Integer(int data)
{
	Uint8 i = 0;
	int num = 0;
	Uint32 multiplier = 1;
	
	if (!data)
	{
		LCD_Write_Data(48);
	}
	if (data < 0)
	{
		LCD_Write_Data('-');
		data *= -1;
	}
	
	while (data)
	{
		num = (num * 10) + (data % 10);
		multiplier = !(num) ? multiplier * 10 : multiplier;
		data /= 10;
	}
	while (num != i)
	{
		LCD_Write_Data((num % 10) + 48);
		num /= 10;
		if(!num)
		{
			num = multiplier;
			i = 1;
		}
	}
	
}

void LCD_Write_Decimal(f32 data)
{
	// -123.665
	Uint8 i = 0;
	int num = 0;
	if (data < 0)
	{
		LCD_Write_Data('-');
		data *= -1;
	}
	num = data;
	LCD_Write_Integer(num);
	LCD_Write_Data('.');
	data -= num;
	
	for (i = 0 ; i < 4 ; i++)
	{
		data *= 10;
		num = data;
		data -= num;
		LCD_Write_Integer(num);
	}
	
}

void LCD_Write_Custom_Char(Uint8 position , Uint8 *arr)
{
	LCD_Write_CMD(CGRAM_First_Address_First_Charachter + (position * 8));
	Uint8 i = 0;
	for (i = 0 ; i < 8 ; i++)
	{
		LCD_Write_Data(arr[i]);
	}
	
}

void LCD_Goto(Uint8 row , Uint8 col)
{
	Uint8 arr[2] = { DDRAM_Cursor_Begin_1st_Line , DDRAM_Cursor_Begin_2nd_Line };
	LCD_Write_CMD(arr[row] + col);
	
}

void LCD_Clear()
{
	LCD_Write_CMD(Clear_Display_Screen);
}