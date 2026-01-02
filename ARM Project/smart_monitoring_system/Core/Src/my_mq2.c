/*
 * my_mq2.c
 *
 *  Created on: Jan 1, 2026
 *      Author: nk
 */
/*
 * my_MQ2.c
 *
 *  Created on: Dec 30, 2025
 *      Author: HP
 */

#ifndef SRC_MY_MQ2_C_
#define SRC_MY_MQ2_C_

#include "my_MQ2.h"

static ADC_HandleTypeDef *mq2_adc;

void MQ2_Init(ADC_HandleTypeDef *hadc)
{
    mq2_adc = hadc;
}

uint16_t MQ2_Read(void)
{
    uint16_t val = 0;

    HAL_ADC_Start(mq2_adc);
    HAL_ADC_PollForConversion(mq2_adc, HAL_MAX_DELAY);
    val = HAL_ADC_GetValue(mq2_adc);
    HAL_ADC_Stop(mq2_adc);


    return val;
}




#endif /* SRC_MY_MQ2_C_ */


