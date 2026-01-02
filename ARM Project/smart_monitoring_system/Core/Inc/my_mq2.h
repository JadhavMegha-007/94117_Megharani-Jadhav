/*
 * my_MQ2.h
 *
 *  Created on: Dec 30, 2025
 *      Author: HP
 */

#ifndef INC_MY_MQ2_H_
#define INC_MY_MQ2_H_

#include "stm32f4xx_hal.h" /* Initialize MQ-2 sensor */
void MQ2_Init(ADC_HandleTypeDef *hadc); /* Read raw ADC value from MQ-2 */
uint16_t MQ2_Read(void);

#endif /* INC_MY_MQ2_H_ */
