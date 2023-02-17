/*
 * LCD_CFG.h
 *
 * Created: 9/23/2022 1:43:50 PM
 *  Author: machd
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#include "DIO.h"

/* Interface 4-Bit-Mode */
#define LCD_4_Bit_Data_Port		 DIO_PORTA
#define LCD_4_Bit_Data_Bus		 PORTA
#define LCD_4_Bit_CMD_Port		 DIO_PORTB

/* LCD Pins */
#define LCD_Pin_RS				 DIO_PIN1
#define LCD_Pin_RW				 DIO_PIN2
#define LCD_Pin_E				 DIO_PIN3

/* LCD Data Pins */
#define LCD_Pin0				 DIO_PIN0
#define LCD_Pin1				 DIO_PIN1
#define LCD_Pin2				 DIO_PIN2
#define LCD_Pin3				 DIO_PIN3
#define LCD_Pin4				 DIO_PIN4
#define LCD_Pin5				 DIO_PIN5
#define LCD_Pin6				 DIO_PIN6
#define LCD_Pin7				 DIO_PIN7


#endif /* LCD_CFG_H_ */