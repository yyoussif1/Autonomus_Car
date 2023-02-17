/*
 * Autonomous Car.c
 *
 * Created: 1/2/2023 1:48:07 PM
 * Author : Youssif Sherif
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>


/* Utiles Lib */
#include "STDIN_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "DIO_interface.h"
#include "tmr1_interface.h"

/* HAL */
#include "Sensor_interface.h"
#include "servo_interface.h"
#include "MOTOR_interface.h"
#include "LCD.h"

int distance = 0;

int main(void)
{	
	
	SERVO_init();
	SENSOR_init();
	MOTOR_init();
	LCD_Init();
	
	static volatile u16 D_left;
	static volatile u16 D_right;
	
	
	while (1)
	{
		
		u16 dis = SENSOR_LOOP(); //DISTANCE MEASURED FROM SENSOR IN CM
		while( dis >= 20 )
		{
			LCD_Clear();
			LCD_Goto(0,2);
			LCD_Write_String("Move Forward");
			MOTOR_Forward();
			
			dis = SENSOR_LOOP();
			if ( dis < 20)
			{
				break;
			}
		}
		
		LCD_Clear();
		LCD_Goto(0,6);
		LCD_Write_String("Stop");
		MOTOR_stop();
		_delay_ms(1500);
		
		SERVO_positive90Degree(); // FOR SCANING LEFT SIDE
		_delay_ms(2000);
		dis = SENSOR_LOOP();
		D_left = dis;
		SERVO_0Degree();
		_delay_ms(1500);
		
		SERVO_negative90Degree(); // FOR SCANING RIGHT SIDE
		_delay_ms(2000);
		dis = SENSOR_LOOP();
		D_right = dis;
		SERVO_0Degree();
		_delay_ms(1500);
		
		//CHOOSING THE RIGHT SIDE TO MOVE
		if ( D_left > D_right && D_left > 20)
		{
			LCD_Clear();
			LCD_Goto(0,4);
			LCD_Write_String("Turn Left");
			MOTOR_turnLeft();
			_delay_ms(600);     //ROTATE 90 DEGREE MEASURED BY OUR BATTERIES
			
		}
		
		else if ( D_right > D_left && D_right > 20)
		{
			LCD_Clear();
			LCD_Goto(0,4);
			LCD_Write_String("Turn Right");
			MOTOR_turnRight();
			_delay_ms(600);    //ROTATE 90 DEGREE MEASURED BY OUR BATTERIES
			
		}
		
		else
		{
			LCD_Clear();
			LCD_Goto(0,1);
			LCD_Write_String("Move Backward");
			MOTOR_BackWard();
			
			_delay_ms(2000);
			
			LCD_Clear();
			LCD_Goto(0,4);
			LCD_Write_String("Turn Right");
			MOTOR_turnRight();
			_delay_ms(1200);    //ROTATE 180 DEGREE
		}
		
	}
	
}