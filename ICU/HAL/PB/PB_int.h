/*
 * PB_int.h
 *
 *  Created on: ٠٢‏/٠٢‏/٢٠٢٣
 *      Author: houras
 */

#ifndef PB_PB_INT_H_
#define PB_PB_INT_H_
/*
 * choose from :
 * PB_ID : 1,2,3,4
 * PB_port :PORTA_ID,....PORTD_ID
 * PB_PI: PIN0,.......PIN7
 */
#define NOT_PRESSED_ACTIVE_LOW 1
#define PRESSED_ACTIVE_LOW     0

#define NOT_PRESSED_ACTIVEHIGH 1
#define PRESSED_ACTIVE_HIGH     0
typedef enum {ACTIVE_LOW,ACTIVE_HIGH}Active_t;
typedef struct pushButton{
u8 PB_ID;
u8 PB_port;
u8 PB_pin;
Active_t PB_activeMood;

}PB_t;
void H_PB_void_init(const PB_t *ptr);
void H_PB_void_read(const PB_t *ptr,VALUE_T *pvalue);


#endif /* PB_PB_INT_H_ */
