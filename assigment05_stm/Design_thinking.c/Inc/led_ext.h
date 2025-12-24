/*
 * led_ext.h
 *
 *  Created on: Dec 19, 2025
 *      Author: nk
 */

#ifndef LED_EXT_H_
#define LED_EXT_H_
#include <stdint.h>
#include <stdio.h>
#include"stm32f407xx.h"

#define BV(n) (1 << (n))

#define GREEN_LED     12
#define ORANGE_LED    13
#define RED_LED       14
#define BLUE_LED      15

#define LED_PORT GPIOD


void led_init(void);
void led_on(uint8_t pin);
void led_off(uint8_t pin);

void led_toggle(uint8_t pin);


#endif /* LED_EXT_H_ */
