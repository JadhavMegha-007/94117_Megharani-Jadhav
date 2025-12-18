/*
 * Led_seq.h
 *
 *  Created on: Dec 18, 2025
 *      Author: nk
 */

#ifndef LED_SEQ_H_
#define LED_SEQ_H_
#include <stdint.h>
#include <stdio.h>
#include"stm32f407xx.h"

#define BV(n) (1 << (n))
#define GREEN_LED    12
#define BLUE_LED     15

#define LED_PORT GPIOD


void led_init(void);
void led_on(void);
void led_off(void);


#endif /* LED_SEQ_H_ */
