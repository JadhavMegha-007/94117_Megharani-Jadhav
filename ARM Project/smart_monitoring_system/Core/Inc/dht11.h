/*
 * DHT11.h
 *
 *  Created on: Dec 31, 2025
 *      Author: HP
 */

#ifndef INC_DHT11_H_
#define INC_DHT11_H_
#include "stm32f407xx.h"
#define DHT11_PORT GPIOB
#define DHT11_PIN  GPIO_PIN_1

void DHT11_Init(void);
uint8_t DHT11_Read(uint8_t *temperature, uint8_t *humidity);
void delay_us(uint32_t us);


#endif /* INC_DHT11_H_ */
