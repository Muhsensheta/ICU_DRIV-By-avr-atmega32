/*
 * main.c
 *
 *  Created on: ١٤‏/٠٢‏/٢٠٢٣
 *      Author: houras
 */
#include<math.h>
#include <util/delay.h>
#include  "STD_TYPES.h"
#include"TIMER_int.h"
#include "TIMER1_int.h"
#include"DIO_int.h"
#include "LCD_int.h"
#include"GIE_int.h"

#if (1)

void main(){

	H_LCD_void_Init();
	H_LCD_void_sendString("aH");
}
#endif

#if(0)
static u16 Reading1=0;
static u16 Reading2=0;
static u8 stateCounter=0;
//u16 NumberOfTicks;
void ICU_HW(void)
{
	if (stateCounter==0)
	{
		//take reading 1
		Reading1=M_TIMER1_ICU_u16_takeReading();
		//change trigger to fallin edge
		M_TIMER1_ICU_void_setTrigg(TIMER1_ICU_FALL_TRIGG);
	}
	else if (stateCounter==1)
	{
		//take reading 2
		Reading2=M_TIMER1_ICU_u16_takeReading();
		M_TIMER1_ICU_void_INTDisable();

	}

	stateCounter++;
}
void main()
{

	// LCD INIT
	H_LCD_void_Init();
	//SET DIR FOR PWM PIN TO BE OUT
	M_DIO_void_setPinDir(PORTB_ID,PIN3, OUT);
	//SET DIR FOR ICU PIN TO BE IN
	M_DIO_void_setPinDir(PORTD_ID,PIN6, IN);
	//SET DIR FOR trigger PIN TO BE out
	M_DIO_void_setPinDir(PORTC_ID,PIN5, OUT);
	//ICU INIT
	M_TIMER1_ICU_void_Init();
	// ENABLE INTERRUPT
	M_TIMER1_ICU_void_INTEnable();
	M_TIMER1_ICU_void_setCallback(ICU_HW);
	//TIMER0 INIT

	// GIE ENABLE
	M_GIE_void_enable();
	 //TIMER 1 INITIALIZAION
		M_TIMER1_void_Init();
	//send trigger
	M_DIO_void_setPinValue(PORTC_ID,PIN5, HIGH);
	_delay_ms(1);
	while (stateCounter<=1);//busy waitind untill all reading are ready
	u16 NumberOfTicks=Reading2-Reading1;
	f32 time =(NumberOfTicks*16)/1000000.0;
    u32 Distance =ceil((time/2)*34300);
	while(1)
	{


		//display reading 1
		H_LCD_void_sendString("Reading1");
		H_LCD_void_gotXY(1,5);
		H_LCD_void_sendIntNum(Reading1);
		_delay_ms(2000);
		H_LCD_void_clear();
		//display reading 2
		H_LCD_void_sendString("Reading2");
		H_LCD_void_gotXY(1,5);
		H_LCD_void_sendIntNum(Reading2);
		_delay_ms(2000);
		H_LCD_void_clear();
		//display distance
		H_LCD_void_sendString("Distance");
		H_LCD_void_gotXY(1,5);
		H_LCD_void_sendIntNum(Distance);
		_delay_ms(2000);
		H_LCD_void_clear();


	}
}


#endif


#if(0)
void ICU_HW(void);
static u16 Reading1=0;
static u16 Reading2=0;
static u16 Reading3=0;
static u8 stateCounter=0;

void main (){

	// LCD INIT
	H_LCD_void_Init();
	//SET DIR FOR PWM PIN TO BE OUT
	M_DIO_void_setPinDir(PORTB_ID,PIN3, OUT);
	//SET DIR FOR ICU PIN TO BE IN
	M_DIO_void_setPinDir(PORTD_ID,PIN6, IN);
    //TIMER 1 INITIALIZAION
	M_TIMER1_void_Init();
	//ICU INIT
	M_TIMER1_ICU_void_Init();
	// ENABLE INTERRUPT
	M_TIMER1_ICU_void_INTEnable();
	M_TIMER1_ICU_void_setCallback(ICU_HW);
	//TIMER0 INIT
	M_TIMER0_void_Init();

	M_TIMER0_void_setFastPWM(60);

	M_TIMER0_void_start();
	// GIE ENABLE
	M_GIE_void_enable();
	while (stateCounter<=2);//busy waitind untill all reading are ready

	 u16 period_Ticks=Reading2-Reading1;
	u16 ON_Ticks=Reading3-Reading2;
	u8 Duty =(ON_Ticks*100)/period_Ticks;
	while(1)
	{
		//display output duty
		H_LCD_void_sendString("period_Ticks");
		H_LCD_void_gotXY(1,5);
		H_LCD_void_sendIntNum(period_Ticks);
		_delay_ms(2000);
		H_LCD_void_clear();
		//display on time
		H_LCD_void_sendString("ON_Ticks");
		H_LCD_void_gotXY(1,5);
		H_LCD_void_sendIntNum(ON_Ticks);
		_delay_ms(2000);
		H_LCD_void_clear();
		//display DUTY CYCLE
		H_LCD_void_sendString("Duty_cycle ");
		H_LCD_void_gotXY(1,5);
		H_LCD_void_sendIntNum(Duty);
		_delay_ms(2000);
		H_LCD_void_clear();


	}

}

void ICU_HW(void)
{
	if (stateCounter==0)
	{
		//take reading 1
		Reading1=M_TIMER1_ICU_u16_takeReading();
	}
	else if (stateCounter==1)
	{
		//take reading 2
		Reading2=M_TIMER1_ICU_u16_takeReading();
		//change trigger to fallin edge
		M_TIMER1_ICU_void_setTrigg(TIMER1_ICU_FALL_TRIGG);

	}
	else if (stateCounter==2)
	{
		//take reading 3
		Reading3=M_TIMER1_ICU_u16_takeReading();
		//stop icu interrupt
		M_TIMER1_ICU_void_INTDisable();
	}
	stateCounter++;
}
#endif
