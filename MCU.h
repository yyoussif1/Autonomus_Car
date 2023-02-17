


#ifndef MCU_H_
#define MCU_H_


/**************************** DIO ******************************/

#define PORTA	(*(volatile char*)(0x3B))
#define DDRA	(*(volatile char*)(0x3A))
#define PINA	(*(volatile char*)(0x39))

#define PORTB	(*(volatile char*)(0x38))
#define DDRB	(*(volatile char*)(0x37))
#define PINB	(*(volatile char*)(0x36))

#define PORTC	(*(volatile char*)(0x35))
#define DDRC	(*(volatile char*)(0x34))
#define PINC	(*(volatile char*)(0x33))

#define PORTD	(*(volatile char*)(0x32))
#define DDRD	(*(volatile char*)(0x31))
#define PIND	(*(volatile char*)(0x30))
 

/**************************** External Interrupts ******************************/

#define SREG	(*(volatile char*)(0x5F))
#define GICR	(*(volatile char*)(0x5B))
#define GIFR	(*(volatile char*)(0x5A))
#define MCUCR	(*(volatile char*)(0x55))
#define MCUCSR	(*(volatile char*)(0x54))

/**************************** ADC ***************************/

#define SFIOR	(*(volatile char*)(0x50))
#define ADMUX	(*(volatile char*)(0x27)) 
#define ADCSRA	(*(volatile char*)(0x26)) 
#define ADCH	(*(volatile char*)(0x25)) 
#define ADCL	(*(volatile char*)(0x24))
#define ADCR	(*(volatile Uint16*)(0x24))

/**************************** Timer_0 ***************************/

#define OCR0	(*(volatile char*)(0x5C))
#define TIMSK	(*(volatile char*)(0x59))
#define TIFR	(*(volatile char*)(0x58))
#define TCCR0	(*(volatile char*)(0x53))
#define TCNT0	(*(volatile char*)(0x52))

/**************************** UART ***************************/
#define UDR		(*(volatile char*)(0x2C))
#define UCSRA	(*(volatile char*)(0x2B))
#define UCSRB	(*(volatile char*)(0x2A))
#define UCSRC	(*(volatile char*)(0x40))
#define UBRRH	(*(volatile char*)(0x40))
#define UBRRL	(*(volatile char*)(0x29))


#endif /* MCU_H_ */