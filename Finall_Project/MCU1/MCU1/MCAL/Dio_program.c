#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

#include	"Dio_interface.h"
#include	"Dio_private.h"

//DIO_voidSetPinDirection(PORTA , PIN0 , OUTPUT); ==> DDRA = 0b00000001; A0 is output
//DIO_voidSetPinValue(PORTA , PIN0 , HIGH); ==> PORTA = 0b00000001; A0 HIGH


void	DIO_voidSetPinDirection(u8 Port ,u8 Pin , u8 Direction )
{
	/*		Range Check				*/
	if( (Port < 4) && (Pin < 8) )
	{
		if(Direction == OUTPUT)
		{
			switch(Port)
			{
				case PORTA :	SET_BIT(DDRA_REG,Pin);	break;
				case PORTB :	SET_BIT(DDRB_REG,Pin);	break;
				case PORTC :	SET_BIT(DDRC_REG,Pin);	break;
				case PORTD :	SET_BIT(DDRD_REG,Pin);	break;
			}
		}
		else if (Direction == INPUT)
		{
			switch(Port)
			{
				case PORTA :	CLR_BIT(DDRA_REG,Pin);	break;
				case PORTB :	CLR_BIT(DDRB_REG,Pin);	break;
				case PORTC :	CLR_BIT(DDRC_REG,Pin);	break;
				case PORTD :	CLR_BIT(DDRD_REG,Pin);	break;
			}			
		}
				
	}
}
void	DIO_voidSetPinValue(u8 Port ,u8 Pin , u8 Value )
{
	/*		Range Check				*/
	if( (Port < 4) && (Pin < 8) )
	{
		if(Value == HIGH)
		{
			switch(Port)
			{
				case PORTA :	SET_BIT(PORTA_REG,Pin);	break;
				case PORTB :	SET_BIT(PORTB_REG,Pin);	break;
				case PORTC :	SET_BIT(PORTC_REG,Pin);	break;
				case PORTD :	SET_BIT(PORTD_REG,Pin);	break;
			}
		}
		else if (Value == LOW)
		{
			switch(Port)
			{
				case PORTA :	CLR_BIT(PORTA_REG,Pin);	break;
				case PORTB :	CLR_BIT(PORTB_REG,Pin);	break;
				case PORTC :	CLR_BIT(PORTC_REG,Pin);	break;
				case PORTD :	CLR_BIT(PORTD_REG,Pin);	break;
			}			
		}
				
	}	
}
u8		DIO_u8GetPinValue(u8 Port , u8 Pin)
{
	u8 Local_u8Value = 0xFF;
	/*		Range Check				*/
	if( (Port < 4) && (Pin < 8) )
	{
			switch(Port)
			{
				case PORTA :	Local_u8Value	=	GET_BIT(PINA_REG,Pin);	break;
				case PORTB :	Local_u8Value	=	GET_BIT(PINB_REG,Pin);	break;
				case PORTC :	Local_u8Value	=	GET_BIT(PINC_REG,Pin);	break;
				case PORTD :	Local_u8Value	=	GET_BIT(PIND_REG,Pin);	break;
			}		
	}		
	return Local_u8Value ;
}


void	DIO_voidSetPortDirection(u8 Port , u8 Direction )
{
	/*Range Check */
	if(Port < 4)
	{
		switch (Port)
		{
			case PORTA : DDRA_REG = Direction;
			case PORTB : DDRB_REG = Direction;
			case PORTC : DDRC_REG = Direction;
			case PORTD : DDRD_REG = Direction;
		}
	}

}
void	DIO_voidSetPortValue(u8 Port , u8 Value )
{
	/*Range Check */
	if(Port < 4)
	{
		switch (Port)
		{
			case PORTA : PORTA_REG = Value;
			case PORTB : PORTB_REG = Value;
			case PORTC : PORTC_REG = Value;
			case PORTD : PORTD_REG = Value;
		}
	}
}