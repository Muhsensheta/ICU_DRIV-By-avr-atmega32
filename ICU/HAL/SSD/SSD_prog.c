/*
 * SSD_prog.c
 *
 *  Created on: ٠١‏/٠٢‏/٢٠٢٣
 *      Author: muhsen
 */
#include "STD_TYPES.h"
#include"DIO_int.h"

#include"SSD_priv.h"
#include"SSD_config.h"
#include"SSD_init.h"
#include<util/delay.h>




//u8 arr[]={0x3f,};
void H_SSD_void_init(void)
{
	M_DIO_void_setPinDir(SSD_LED_A_PORT,  SSD_LED_A_PIN , OUT);
	M_DIO_void_setPinDir(SSD_LED_B_PORT,  SSD_LED_B_PIN , OUT);
	M_DIO_void_setPinDir(SSD_LED_C_PORT,  SSD_LED_C_PIN , OUT);
	M_DIO_void_setPinDir(SSD_LED_D_PORT,  SSD_LED_D_PIN , OUT);
	M_DIO_void_setPinDir(SSD_LED_E_PORT,  SSD_LED_E_PIN , OUT);
	M_DIO_void_setPinDir(SSD_LED_F_PORT,  SSD_LED_F_PIN , OUT);
	M_DIO_void_setPinDir(SSD_LED_G_PORT,  SSD_LED_G_PIN , OUT);
	M_DIO_void_setPinDir(SSD_LED_DOT_PORT,  SSD_LED_DOT_PIN , OUT);

	//ENABLE DIGITS 1

	M_DIO_void_setPinDir(SSD_DIG_1_EN_PORT,  SSD_DIG_1_EN_PIN , OUT);
	M_DIO_void_setPinDir(SSD_DIG_2_EN_PORT,  SSD_DIG_2_EN_PIN , OUT);
}
void H_SSD_void_DisplayNumber(u8 number)
{
	if(number>99)
	{
		return;
	}
	u32 i ;
	u8 units =number % 10;
	u8 tens = number/10;
	for(i=0;i<SSD_DISPLAYY_TIME ;i++){

		switch (units)
		{
		case 0:
			M_DIO_void_setPinValue(SSD_LED_A_PORT,SSD_LED_A_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_B_PORT,SSD_LED_B_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_C_PORT,SSD_LED_C_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_D_PORT,SSD_LED_D_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_E_PORT,SSD_LED_E_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_F_PORT,SSD_LED_F_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_A_PORT,SSD_LED_A_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_G_PORT,SSD_LED_G_PIN,LOW);
			M_DIO_void_setPinValue(SSD_LED_DOT_PORT,SSD_LED_DOT_PIN,LOW);
			break;

		case 1:
			M_DIO_void_setPinValue(SSD_LED_A_PORT,SSD_LED_A_PIN,LOW);
			M_DIO_void_setPinValue(SSD_LED_B_PORT,SSD_LED_B_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_C_PORT,SSD_LED_C_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_D_PORT,SSD_LED_D_PIN,LOW);
			M_DIO_void_setPinValue(SSD_LED_E_PORT,SSD_LED_E_PIN,LOW);
			M_DIO_void_setPinValue(SSD_LED_F_PORT,SSD_LED_F_PIN,LOW);
			M_DIO_void_setPinValue(SSD_LED_G_PORT,SSD_LED_G_PIN,LOW);
			M_DIO_void_setPinValue(SSD_LED_DOT_PORT,SSD_LED_DOT_PIN,LOW);
			break;

		case 2:
			M_DIO_void_setPinValue(SSD_LED_A_PORT,SSD_LED_A_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_B_PORT,SSD_LED_B_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_C_PORT,SSD_LED_C_PIN,LOW);
			M_DIO_void_setPinValue(SSD_LED_D_PORT,SSD_LED_D_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_E_PORT,SSD_LED_E_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_F_PORT,SSD_LED_F_PIN,LOW);
			M_DIO_void_setPinValue(SSD_LED_G_PORT,SSD_LED_G_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_DOT_PORT,SSD_LED_DOT_PIN,LOW);
			break;

		case 3:
			M_DIO_void_setPinValue(SSD_LED_A_PORT,SSD_LED_A_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_B_PORT,SSD_LED_B_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_C_PORT,SSD_LED_C_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_D_PORT,SSD_LED_D_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_E_PORT,SSD_LED_E_PIN,LOW);
			M_DIO_void_setPinValue(SSD_LED_F_PORT,SSD_LED_F_PIN,LOW);
			M_DIO_void_setPinValue(SSD_LED_G_PORT,SSD_LED_G_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_DOT_PORT,SSD_LED_DOT_PIN,LOW);
			break;

		case 4:
			M_DIO_void_setPinValue(SSD_LED_A_PORT,SSD_LED_A_PIN,LOW);
			M_DIO_void_setPinValue(SSD_LED_B_PORT,SSD_LED_B_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_C_PORT,SSD_LED_C_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_D_PORT,SSD_LED_D_PIN,LOW);
			M_DIO_void_setPinValue(SSD_LED_E_PORT,SSD_LED_E_PIN,LOW);
			M_DIO_void_setPinValue(SSD_LED_F_PORT,SSD_LED_F_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_G_PORT,SSD_LED_G_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_DOT_PORT,SSD_LED_DOT_PIN,LOW);
			break;

		case 5:
			M_DIO_void_setPinValue(SSD_LED_A_PORT,SSD_LED_A_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_B_PORT,SSD_LED_B_PIN,LOW);
			M_DIO_void_setPinValue(SSD_LED_C_PORT,SSD_LED_C_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_D_PORT,SSD_LED_D_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_E_PORT,SSD_LED_E_PIN,LOW);
			M_DIO_void_setPinValue(SSD_LED_F_PORT,SSD_LED_F_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_G_PORT,SSD_LED_G_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_DOT_PORT,SSD_LED_DOT_PIN,LOW);
			break;
		case 6:
			M_DIO_void_setPinValue(SSD_LED_A_PORT,SSD_LED_A_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_B_PORT,SSD_LED_B_PIN,LOW);
			M_DIO_void_setPinValue(SSD_LED_C_PORT,SSD_LED_C_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_D_PORT,SSD_LED_D_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_E_PORT,SSD_LED_E_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_F_PORT,SSD_LED_F_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_G_PORT,SSD_LED_G_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_DOT_PORT,SSD_LED_DOT_PIN,LOW);
			break;
		case 7:
			M_DIO_void_setPinValue(SSD_LED_A_PORT,SSD_LED_A_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_B_PORT,SSD_LED_B_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_C_PORT,SSD_LED_C_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_D_PORT,SSD_LED_D_PIN,LOW);
			M_DIO_void_setPinValue(SSD_LED_E_PORT,SSD_LED_E_PIN,LOW);
			M_DIO_void_setPinValue(SSD_LED_F_PORT,SSD_LED_F_PIN,LOW);
			M_DIO_void_setPinValue(SSD_LED_G_PORT,SSD_LED_G_PIN,LOW);
			M_DIO_void_setPinValue(SSD_LED_DOT_PORT,SSD_LED_DOT_PIN,LOW);
			break;
		case 8:
			M_DIO_void_setPinValue(SSD_LED_A_PORT,SSD_LED_A_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_B_PORT,SSD_LED_B_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_C_PORT,SSD_LED_C_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_D_PORT,SSD_LED_D_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_E_PORT,SSD_LED_E_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_F_PORT,SSD_LED_F_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_G_PORT,SSD_LED_G_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_DOT_PORT,SSD_LED_DOT_PIN,LOW);
			break;
		case 9:
			M_DIO_void_setPinValue(SSD_LED_A_PORT,SSD_LED_A_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_B_PORT,SSD_LED_B_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_C_PORT,SSD_LED_C_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_D_PORT,SSD_LED_D_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_E_PORT,SSD_LED_E_PIN,LOW);
			M_DIO_void_setPinValue(SSD_LED_F_PORT,SSD_LED_F_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_G_PORT,SSD_LED_G_PIN,HIGH);
			M_DIO_void_setPinValue(SSD_LED_DOT_PORT,SSD_LED_DOT_PIN,LOW);
			break;



		}
		//enable digit 1
		//disable digit 2
		M_DIO_void_setPinValue(SSD_DIG_1_EN_PORT,SSD_DIG_1_EN_PIN,HIGH);
		M_DIO_void_setPinValue(SSD_DIG_2_EN_PORT,SSD_DIG_2_EN_PIN,LOW);
		_delay_ms(1);
		M_DIO_void_setPinValue(SSD_DIG_1_EN_PORT,SSD_DIG_1_EN_PIN,LOW);
		switch (tens)
		{
		case 0:
					M_DIO_void_setPinValue(SSD_LED_A_PORT,SSD_LED_A_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_B_PORT,SSD_LED_B_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_C_PORT,SSD_LED_C_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_D_PORT,SSD_LED_D_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_E_PORT,SSD_LED_E_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_F_PORT,SSD_LED_F_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_A_PORT,SSD_LED_A_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_G_PORT,SSD_LED_G_PIN,LOW);
					M_DIO_void_setPinValue(SSD_LED_DOT_PORT,SSD_LED_DOT_PIN,LOW);
					break;

				case 1:
					M_DIO_void_setPinValue(SSD_LED_A_PORT,SSD_LED_A_PIN,LOW);
					M_DIO_void_setPinValue(SSD_LED_B_PORT,SSD_LED_B_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_C_PORT,SSD_LED_C_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_D_PORT,SSD_LED_D_PIN,LOW);
					M_DIO_void_setPinValue(SSD_LED_E_PORT,SSD_LED_E_PIN,LOW);
					M_DIO_void_setPinValue(SSD_LED_F_PORT,SSD_LED_F_PIN,LOW);
					M_DIO_void_setPinValue(SSD_LED_G_PORT,SSD_LED_G_PIN,LOW);
					M_DIO_void_setPinValue(SSD_LED_DOT_PORT,SSD_LED_DOT_PIN,LOW);
					break;

				case 2:
					M_DIO_void_setPinValue(SSD_LED_A_PORT,SSD_LED_A_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_B_PORT,SSD_LED_B_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_C_PORT,SSD_LED_C_PIN,LOW);
					M_DIO_void_setPinValue(SSD_LED_D_PORT,SSD_LED_D_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_E_PORT,SSD_LED_E_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_F_PORT,SSD_LED_F_PIN,LOW);
					M_DIO_void_setPinValue(SSD_LED_G_PORT,SSD_LED_G_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_DOT_PORT,SSD_LED_DOT_PIN,LOW);
					break;

				case 3:
					M_DIO_void_setPinValue(SSD_LED_A_PORT,SSD_LED_A_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_B_PORT,SSD_LED_B_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_C_PORT,SSD_LED_C_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_D_PORT,SSD_LED_D_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_E_PORT,SSD_LED_E_PIN,LOW);
					M_DIO_void_setPinValue(SSD_LED_F_PORT,SSD_LED_F_PIN,LOW);
					M_DIO_void_setPinValue(SSD_LED_G_PORT,SSD_LED_G_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_DOT_PORT,SSD_LED_DOT_PIN,LOW);
					break;

				case 4:
					M_DIO_void_setPinValue(SSD_LED_A_PORT,SSD_LED_A_PIN,LOW);
					M_DIO_void_setPinValue(SSD_LED_B_PORT,SSD_LED_B_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_C_PORT,SSD_LED_C_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_D_PORT,SSD_LED_D_PIN,LOW);
					M_DIO_void_setPinValue(SSD_LED_E_PORT,SSD_LED_E_PIN,LOW);
					M_DIO_void_setPinValue(SSD_LED_F_PORT,SSD_LED_F_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_G_PORT,SSD_LED_G_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_DOT_PORT,SSD_LED_DOT_PIN,LOW);
					break;

				case 5:
					M_DIO_void_setPinValue(SSD_LED_A_PORT,SSD_LED_A_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_B_PORT,SSD_LED_B_PIN,LOW);
					M_DIO_void_setPinValue(SSD_LED_C_PORT,SSD_LED_C_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_D_PORT,SSD_LED_D_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_E_PORT,SSD_LED_E_PIN,LOW);
					M_DIO_void_setPinValue(SSD_LED_F_PORT,SSD_LED_F_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_G_PORT,SSD_LED_G_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_DOT_PORT,SSD_LED_DOT_PIN,LOW);
					break;
				case 6:
					M_DIO_void_setPinValue(SSD_LED_A_PORT,SSD_LED_A_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_B_PORT,SSD_LED_B_PIN,LOW);
					M_DIO_void_setPinValue(SSD_LED_C_PORT,SSD_LED_C_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_D_PORT,SSD_LED_D_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_E_PORT,SSD_LED_E_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_F_PORT,SSD_LED_F_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_G_PORT,SSD_LED_G_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_DOT_PORT,SSD_LED_DOT_PIN,LOW);
					break;
				case 7:
					M_DIO_void_setPinValue(SSD_LED_A_PORT,SSD_LED_A_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_B_PORT,SSD_LED_B_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_C_PORT,SSD_LED_C_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_D_PORT,SSD_LED_D_PIN,LOW);
					M_DIO_void_setPinValue(SSD_LED_E_PORT,SSD_LED_E_PIN,LOW);
					M_DIO_void_setPinValue(SSD_LED_F_PORT,SSD_LED_F_PIN,LOW);
					M_DIO_void_setPinValue(SSD_LED_G_PORT,SSD_LED_G_PIN,LOW);
					M_DIO_void_setPinValue(SSD_LED_DOT_PORT,SSD_LED_DOT_PIN,LOW);
					break;
				case 8:
					M_DIO_void_setPinValue(SSD_LED_A_PORT,SSD_LED_A_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_B_PORT,SSD_LED_B_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_C_PORT,SSD_LED_C_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_D_PORT,SSD_LED_D_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_E_PORT,SSD_LED_E_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_F_PORT,SSD_LED_F_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_G_PORT,SSD_LED_G_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_DOT_PORT,SSD_LED_DOT_PIN,LOW);
					break;
				case 9:
					M_DIO_void_setPinValue(SSD_LED_A_PORT,SSD_LED_A_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_B_PORT,SSD_LED_B_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_C_PORT,SSD_LED_C_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_D_PORT,SSD_LED_D_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_E_PORT,SSD_LED_E_PIN,LOW);
					M_DIO_void_setPinValue(SSD_LED_F_PORT,SSD_LED_F_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_G_PORT,SSD_LED_G_PIN,HIGH);
					M_DIO_void_setPinValue(SSD_LED_DOT_PORT,SSD_LED_DOT_PIN,LOW);
					break;



				}
		//enable digit 2
		M_DIO_void_setPinValue(SSD_DIG_2_EN_PORT,SSD_DIG_2_EN_PIN,HIGH);

		_delay_ms(1);
		M_DIO_void_setPinValue(SSD_DIG_2_EN_PORT,SSD_DIG_2_EN_PIN,LOW);
	}
}

