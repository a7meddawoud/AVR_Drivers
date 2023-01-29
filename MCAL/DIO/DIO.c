/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO.c
 *        \brief  include functions that control Microcontroller PINS
 *
 *      \details  this file is used to Set Microcontroller PORTs/PINs as output or input, SET Outputs voltage(0,5)
 *      ,and Get the value of Input PORTs/PINs (0,1(5v))
 *
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "DIO.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

 /******************************************************************************
 * \Syntax          : void DIO_vSetPortDirection(u8 Loc_u8PortID, u8 Loc_u8PortDirection)
 * \Description     : setting all port pins take port name(PortA,PortB,PortC,PortD),and take the port direction (Port_InPut or Port_OutPut)
 *

 * \Parameters (in) : Loc_u8PortID   PORT wanted to change it's Direction
 * 					Loc_u8PortDirection	    choose direction Input or Output
 * \Parameters (out): None
 *******************************************************************************/
void DIO_vSetPortDirection(u8 Loc_u8PortID, u8 Loc_u8PortDirection){
	if(Loc_u8PortID<=PortD){
		if(Loc_u8PortID==PortA){
			DDRA = Loc_u8PortDirection;
		}
		else if(Loc_u8PortID==PortB){
			DDRB = Loc_u8PortDirection;
		}
		else if(Loc_u8PortID==PortC){
			DDRC = Loc_u8PortDirection;
		}
		else if(Loc_u8PortID==PortD){
			DDRD = Loc_u8PortDirection;
		}
		else{
			//do nothing
		}
	}
	else{
		//do nothing
	}
}
/******************************************************************************
* \Syntax          : void DIO_vSetPortValue(u8 Loc_u8PortID, u8 Loc_u8PortValue)
* \Description     : setting all to a value (Port_High or Port_Low)
*

* \Parameters (in) : Loc_u8PortID   PORT wanted to change it's value
* 					Loc_u8PortDirection	    choose value High or Low
* \Parameters (out): None
*******************************************************************************/
void DIO_vSetPortValue(u8 Loc_u8PortID, u8 Loc_u8PortValue){
	if(Loc_u8PortID<=PortD){
		if(Loc_u8PortID==PortA){
			PORTA = Loc_u8PortValue;
		}
		else if(Loc_u8PortID==PortB){
			PORTB = Loc_u8PortValue;
		}
		else if(Loc_u8PortID==PortC){
			PORTC = Loc_u8PortValue;
		}
		else if(Loc_u8PortID==PortD){
			PORTD = Loc_u8PortValue;
		}
		else{
			//do nothing
		}
	}
	else{
		//do nothing
	}
}
/******************************************************************************
* \Syntax          : u8 DIO_u8PGetPortValue(u8 Loc_u8PortID)
* \Description     : get all port value ( 0 to 255)
*

* \Parameters (in) : Loc_u8PortID   PORT wanted to Read it's value
* \Parameters (out): PINx
*  \Return value:   : unsigned char
*******************************************************************************/
u8 DIO_u8PGetPortValue(u8 Loc_u8PortID){
	if(Loc_u8PortID<=PortD){
		if(Loc_u8PortID==PortA){
			return PINA;
		}
		else if(Loc_u8PortID==PortB){
			return PINB;
		}
		else if(Loc_u8PortID==PortC){
			return PINC;
		}
		else if(Loc_u8PortID==PortD){
			return PIND;
		}
		else{
			//do nothing
		}
	}
	else{
		//do nothing
	}
	return 0xff;
}
/******************************************************************************
* \Syntax          : void DIO_vTogPortValue(u8 Loc_u8PortID)
* \Description     : toggle the value of all port bits
*

* \Parameters (in) : Loc_u8PortID  PORT wanted to Toggle it's value
* \Parameters (out): None
*******************************************************************************/
void DIO_vTogPortValue(u8 Loc_u8PortID){
	if(Loc_u8PortID<=PortD){
		if(Loc_u8PortID==PortA){
			PORTA = ~PORTA;
		}
		else if(Loc_u8PortID==PortB){
			PORTB = ~PORTB;
		}
		else if(Loc_u8PortID==PortC){
			PORTC = ~PORTC;
		}
		else if(Loc_u8PortID==PortD){
			PORTD = ~PORTD;
		}
		else{
			//do nothing
		}
	}
	else{
		//do nothing
	}
}
/******************************************************************************
* \Syntax          : void DIO_vSetPinDirection(u8 Loc_u8PortID, u8 Loc_u8PinID, u8 Loc_u8PinDirection)
* \Description     : sit direction of a bit this function takes portID(PortA,PortB,PortC,PortD)
* 					and pin number(Pin1,Pin2........,Pin7)
* 					and pin wanted direction (Pin_InPut or pin_OutPut)
*
*
* \Parameters (in) : Loc_u8PortID   PIN PORT
* 					Loc_u8PinID		PIN wanted to change it's direction
* 					Loc_u8PinDirection  choose PIN direction (InPut,OutPut)
* \Parameters (out): None
*******************************************************************************/
void DIO_vSetPinDirection(u8 Loc_u8PortID, u8 Loc_u8PinID, u8 Loc_u8PinDirection){
	if (Loc_u8PinDirection==Pin_OutPut){

		if(Loc_u8PortID<=PortD){
			if(Loc_u8PortID==PortA){
				DDRA = SET_BIT(DDRA, Loc_u8PinID);
			}
			else if(Loc_u8PortID==PortB){
				DDRB = SET_BIT(DDRB, Loc_u8PinID);
			}
			else if(Loc_u8PortID==PortC){
				DDRC = SET_BIT(DDRC, Loc_u8PinID);
			}
			else if(Loc_u8PortID==PortD){
				DDRD = SET_BIT(DDRD, Loc_u8PinID);
			}
			else{
				//do nothing
			}
		}
		else{
			//do nothing
		}

	}
	else if(Loc_u8PinDirection==Pin_InPut){

		if(Loc_u8PortID<=PortD){
			if(Loc_u8PortID==PortA){
				DDRA = CLR_BIT(DDRA, Loc_u8PinID);
			}
			else if(Loc_u8PortID==PortB){
				DDRB = CLR_BIT(DDRB, Loc_u8PinID);
			}
			else if(Loc_u8PortID==PortC){
				DDRC = CLR_BIT(DDRC, Loc_u8PinID);
			}
			else if(Loc_u8PortID==PortD){
				DDRD = CLR_BIT(DDRD, Loc_u8PinID);
			}
			else{
				//do nothing
			}
		}
		else{
			//do nothing
		}
	}
	else{
		//do nothing
	}

}
/******************************************************************************
* \Syntax          : void DIO_vSetPinValue(u8 Loc_u8PortID, u8 Loc_u8PinID, u8 Loc_u8PinValue)
* \Description     : sit value of a bit (Pin_High or Pin_Low)
*
*
* \Parameters (in) : Loc_u8PortID   PIN PORT
* 					Loc_u8PinID		PIN wanted to change it's value
* 					Loc_u8PinDirection  choose PIN value (Pin_High,Pin_Low)
* \Parameters (out): None
*******************************************************************************/
void DIO_vSetPinValue(u8 Loc_u8PortID, u8 Loc_u8PinID, u8 Loc_u8PinValue){
	if(Loc_u8PinValue==Pin_High){
		if(Loc_u8PortID<=PortD){
			if(Loc_u8PortID==PortA){
				SET_BIT(PORTA, Loc_u8PinID);
			}
			else if(Loc_u8PortID==PortB){
				SET_BIT(PORTB, Loc_u8PinID);
			}
			else if(Loc_u8PortID==PortC){
				SET_BIT(PORTC, Loc_u8PinID);
			}
			else if(Loc_u8PortID==PortD){
				SET_BIT(PORTD, Loc_u8PinID);
			}
			else{
				//do nothing
			}
		}
		else{
			//do nothing
		}
	}
	else if(Loc_u8PinValue==Pin_Low){

		if(Loc_u8PortID<=PortD){
			if(Loc_u8PortID==PortA){
				CLR_BIT(PORTA, Loc_u8PinID);
			}
			else if(Loc_u8PortID==PortB){
				CLR_BIT(PORTB, Loc_u8PinID);
			}
			else if(Loc_u8PortID==PortC){
				CLR_BIT(PORTC, Loc_u8PinID);
			}
			else if(Loc_u8PortID==PortD){
				CLR_BIT(PORTD, Loc_u8PinID);
			}
			else{
				//do nothing
			}
		}
		else{
			//do nothing
		}
	}
}
/******************************************************************************
* \Syntax          : u8 DIO_u8PGetPinValue(u8 Loc_u8PortID, u8 Loc_u8PinID)
* \Description     : get the value of Pin (0 or 1)
*
*
* \Parameters (in) : Loc_u8PortID   PIN PORT
* 					Loc_u8PinID		PIN wanted to read it's value
* \Parameters (out): PINx  value(0,1)
*  \Return value:   : unsigned char
*******************************************************************************/
u8 DIO_u8PGetPinValue(u8 Loc_u8PortID, u8 Loc_u8PinID){
	if(Loc_u8PortID<=PortD){
		if(Loc_u8PortID==PortA){
			return GET_BIT(PINA, Loc_u8PinID);
		}
		else if(Loc_u8PortID==PortB){
			return GET_BIT(PINB, Loc_u8PinID);
		}
		else if(Loc_u8PortID==PortC){
			return GET_BIT(PINC, Loc_u8PinID);
		}
		else if(Loc_u8PortID==PortD){
			return GET_BIT(PIND, Loc_u8PinID);
		}
		else{
			//do nothing
		}
	}
	else{
		//do nothing
	}
	return 0xff;
}
/******************************************************************************
* \Syntax          : void DIO_vTogPinValue(u8 Loc_u8PortID, u8 Loc_u8PinID)
* \Description     : Toggle value of a bit
*
*
* \Parameters (in) : Loc_u8PortID   PIN PORT
* 					Loc_u8PinID		PIN wanted to Toggle it's value
* \Parameters (out): None
*******************************************************************************/
void DIO_vTogPinValue(u8 Loc_u8PortID, u8 Loc_u8PinID){
	if(Loc_u8PortID<=PortD){
		if(Loc_u8PortID==PortA){
			TOG_BIT(PORTA, Loc_u8PinID);
		}
		else if(Loc_u8PortID==PortB){
			TOG_BIT(PORTB, Loc_u8PinID);
		}
		else if(Loc_u8PortID==PortC){
			TOG_BIT(PORTC, Loc_u8PinID);
		}
		else if(Loc_u8PortID==PortD){
			TOG_BIT(PORTD, Loc_u8PinID);
		}
		else{
			//do nothing
		}
	}
	else{
		//do nothing
	}
}
/**********************************************************************************************************************
 *  END OF FILE: DIO.c
 *********************************************************************************************************************/
