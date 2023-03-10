/*
 * DIO_Program.c
 *
 * Created: 9/3/2022 11:37:25 AM
 *  Author: A S U S
 */ 

/* Utiles Lib */
#include "STDIN_TYPES.h"
#include "BIT_MATH.h"
//#include "ATMEGA32_REG.h"
#include "MCU.h"

/* MCAL */
#include "DIO_interface.h"

/* Pin Apis */
void DIO_setPinDirection(u8 PortId, u8 PinId, u8 PinDirection)
{
	if( (PortId<=3) && (PinId<=7) && ((PinDirection ==DIO_PIN_OUTPUT) || (PinDirection ==DIO_PIN_INPUT)) ) //PortId kda kda akbr mn zero 3shan hwa unsigned
	{
		switch(PortId)
		{
			case DIO_PORTA:
			if(DIO_PIN_OUTPUT == PinDirection)
			{
				SET_BIT(DDRA,PinId);
			}
			else
			{
				CLR_BIT(DDRA,PinId);
			}
			break;
			
			case DIO_PORTB:
			if(DIO_PIN_OUTPUT == PinDirection)
			{
				SET_BIT(DDRB,PinId);
			}
			else
			{
				CLR_BIT(DDRB,PinId);
			}
			break;
			
			case DIO_PORTC:
			if(DIO_PIN_OUTPUT == PinDirection)
			{
				SET_BIT(DDRC,PinId);
			}
			else
			{
				CLR_BIT(DDRC,PinId);
			}
			break;
			
			case DIO_PORTD:
			if(DIO_PIN_OUTPUT == PinDirection)
			{
				SET_BIT(DDRD,PinId);
			}
			else
			{
				CLR_BIT(DDRD,PinId);
			}
			break;
		}
	}
}

void DIO_setPinValue    (u8 PortId, u8 PinId, u8 PinValue)
{
	if( (PortId<=3) && (PinId<=7) && ((PinValue ==DIO_PIN_HIGH) || (PinValue ==DIO_PIN_LOW)) )
	{
		switch(PortId)
		{
			case DIO_PORTA:
			if(DIO_PIN_HIGH == PinValue)
			{
				SET_BIT(PORTA,PinId);
			}
			else
			{
				CLR_BIT(PORTA,PinId);
			}
			break;
			
			case DIO_PORTB:
			if(DIO_PIN_HIGH == PinValue)
			{
				SET_BIT(PORTB,PinId);
			}
			else
			{
				CLR_BIT(PORTB,PinId);
			}
			break;
			
			case DIO_PORTC:
			if(DIO_PIN_HIGH == PinValue)
			{
				SET_BIT(PORTC,PinId);
			}
			else
			{
				CLR_BIT(PORTC,PinId);
			}
			break;
			
			case DIO_PORTD:
			if(DIO_PIN_HIGH == PinValue)
			{
				SET_BIT(PORTD,PinId);
			}
			else
			{
				CLR_BIT(PORTD,PinId);
			}
			break;
		}
		
	}
	
}

void DIO_getPinValue    (u8 PortId, u8 PinId, u8* PinValue)  //input memory
{
	if( (PortId<=3) && (PinId<=7) && (PinValue!= NULL))
	{
		switch(PortId)
		{
			case DIO_PORTA:
			 if ( DIO_PIN_HIGH == GET_BIT(PINA,PinId) )
			 {
				 *PinValue = DIO_PIN_HIGH;
			 }
			 else
			 {
				 *PinValue = DIO_PIN_LOW;
			 }
			break;
			
			case DIO_PORTB:
			if ( DIO_PIN_HIGH == GET_BIT(PINB,PinId) )
			{
				*PinValue = DIO_PIN_HIGH;
			}
			else
			{
				*PinValue = DIO_PIN_LOW;
			}
			break;
			
			case DIO_PORTC:
			if ( DIO_PIN_HIGH == GET_BIT(PINC,PinId) )
			{
				*PinValue = DIO_PIN_HIGH;
			}
			else
			{
				*PinValue = DIO_PIN_LOW;
			}
			break;
			
			case DIO_PORTD:
			if ( DIO_PIN_HIGH == GET_BIT(PIND,PinId) )
			{
				*PinValue = DIO_PIN_HIGH;
			}
			else
			{
				*PinValue = DIO_PIN_LOW;
			}
			break;
		}
		
	}
	
}

void DIO_togglePinValue (u8 PortId, u8 PinId)  //output memory
{
	if( (PortId<=3) && (PinId<=7) )
	{
		switch(PortId)
		{
			case DIO_PORTA:
			TOG_BIT(PORTA,PinId);
			break;
			
			case DIO_PORTB:
			TOG_BIT(PORTB,PinId);
			break;
			
			case DIO_PORTC:
			TOG_BIT(PORTC,PinId);
			break;
			
			case DIO_PORTD:
			TOG_BIT(PORTD,PinId);
			break;
		}
	}
	
}

/* Ports Apis */
void DIO_setPortDirection(u8 PortId, u8 PortDirection)
{
	if( (PortId<=3) && ((PortDirection == DIO_PORT_OUTPUT) || (PortDirection ==  DIO_PORT_INPUT)) )
	{
		switch(PortId)
		{
			case DIO_PORTA:
			if(DIO_PORT_OUTPUT == PortDirection)
			{
				DDRA = 0xff;
			}
			else
			{
				DDRA = 0x00;
			}
			break;
			
			case DIO_PORTB:
			if(DIO_PORT_OUTPUT == PortDirection)
			{
				DDRB = 0xff;
			}
			else
			{
				DDRB = 0x00;
			}
			break;
			
			case DIO_PORTC:
			if(DIO_PORT_OUTPUT == PortDirection)
			{
				DDRC = 0xff;
			}
			else
			{
				DDRC = 0x00;
			}
			break;
			
			case DIO_PORTD:
			if(DIO_PORT_OUTPUT == PortDirection)
			{
				DDRD = 0xff;
			}
			else
			{
				DDRD = 0x00;
			}
			break;
		}
	}
}

void DIO_setPortValue    (u8 PortId, u8 PortValue)
{
	if(PortId<=3)
	{
		switch(PortId)
		{
			case DIO_PORTA:
			PORTA = PortValue;
			break;
			
			case DIO_PORTB:
			PORTB = PortValue;
			break;
			
			case DIO_PORTC:
			PORTC = PortValue;
			break;
			
			case DIO_PORTD:
			PORTD = PortValue;
			break;
		}
	}	
	
}

void DIO_getPortValue    (u8 PortId, u8* PortValue)
{
	if((PortId<=3) && (PortValue != NULL))
	{
		switch(PortId)
		{
			case DIO_PORTA:
			*PortValue = PINA;
			break;
			
			case DIO_PORTB:
			*PortValue = PINB;
			break;
			
			case DIO_PORTC:
			*PortValue = PINC;
			break;
			
			case DIO_PORTD:
			*PortValue = PIND;
			break;
			
		}
	}
}
void DIO_togglePortValue (u8 PortId)
{
	if(PortId<=3)
	{
		switch(PortId)
		{
			case DIO_PORTA:
			PORTA = ~PORTA;
			break;
			
			case DIO_PORTB:
			PORTB = ~PORTB;
			break;
			
			case DIO_PORTC:
			PORTC = ~PORTC;
			break;
			
			case DIO_PORTD:
			PORTD = ~PORTD;
			break;
		}
	}
	
}

