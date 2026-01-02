/*
 * dht11.h
 *
 *  Created on: Dec 22, 2025
 *  Author: Administrator
 */

#ifndef INC_DHT11_H_
#define INC_DHT11_H_

#include "stm32f4xx_hal.h"   // HAL include

/* DHT11 GPIO configuration */
#define DHT11_PORT GPIOA
#define DHT11_PIN  GPIO_PIN_0

/* DHT11 return status */
#define DHT11_OK            0
#define DHT11_NO_RESPONSE   1
#define DHT11_CHECKSUM_ERR  2

/* Function prototypes */
void DHT11_Init(void);
uint8_t DHT11_Read(uint8_t *temperature, uint8_t *humidity);
void delay_us(uint32_t us);

#endif /* INC_DHT11_H_ */
