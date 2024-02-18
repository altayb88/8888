//*****************************************************************************************************************************************************
//************** Auther: Mohamed Abdeen  &&  Ahmed M.Rabie *****************************************************************************************
//************** File  : Program of Ultrasonic   		   ****************************************************************************************
//************** Date  : 15/2/2023    				       ********************************************************************************************
//************** Var   : V1        			               ********************************************************************************************
//*****************************************************************************************************************************************************
//*****************************************************************************************************************************************************


#include "../../04-LIB/STD_TYPES.h"
#include "../../04-LIB/Bit-math.h"

#include "../../03-MCAL/DIO/DIO_interface.h"

#include "../../03-MCAL/EXTI _INT/INT_interface.h"
#include "../../03-MCAL/EXTI _INT/INT_privet.h"

#include "../../03-MCAL/TIMERS/TIMER1_interface.h"
#include "../../03-MCAL/TIMERS/TIMERS_interface.h"

#include "ULTRASONIC_SENSOR_interface.h"
#include "ULTRASONIC_SENSOR_privet.h"

extern u16 Distance_in_cm ;

void ULTRASONIC_VoidInit(void)
{

	INT_VoidInit();

	TIMER_1_VidInit();       // timer 1 used with servo motor
	TIMER_2_VidInit();       // timer 2 used with ultrasonic with help of external INT0

	// the settings of Ultra sonic

	// echo pin as an input
	DIO_VidSetPinDirectoin(PORTD,PIN2,INPUT);
	DIO_VidSetPinValue(PORTD,PIN2,HIGH);

	//Triger pin out
	DIO_VidSetPinDirectoin(PORTD,4,OUTPUT);
	DIO_VidSetPinValue(PORTD,4,LOW);

	TIMER_2_VidSetCompareMatchValue(250);
	TIMER_1_VidSetCompareMatchValueOn_OCR1B(10);
	TIMER_1_VidSetCompareMatchValueOn_ICR1(24);
}

u16 ULTRASONIC_SENSOR_GetDistance(void)
{
	return	Distance_in_cm ;
}
