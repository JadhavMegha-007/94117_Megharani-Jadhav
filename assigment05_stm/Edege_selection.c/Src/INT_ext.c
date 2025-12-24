/*
 * INT_ext.c
 *
 *  Created on: Dec 19, 2025
 *      Author: nk
 */
#include"LED_ext.h"
void extint_init(void)
{
	RCC->AHB1ENR |= BV(0);

	GPIOA->MODER &= ~(BV(0) | BV(1));

	GPIOA->PUPDR &= ~(BV(0) | BV(1));

	SYSCFG->EXTICR[0] &= ~(BV(0) | BV(1) | BV(2) | BV(3));

	  EXTI->IMR |= BV(0);

	  EXTI->FTSR |= BV(0);

	    NVIC_EnableIRQ(EXTI0_IRQn);
}
void EXTI0_IRQHandler(void)
{
	 EXTI->PR |= BV(0);
	 led_toggle(15);

	 }

