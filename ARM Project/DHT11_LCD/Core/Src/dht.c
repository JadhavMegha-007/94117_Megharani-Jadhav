/*
 * dht.c
 *
 *  Created on: Dec 31, 2025
 *      Author: nk
 */
#include "dht.h"
#include "main.h"

#define DHT11_TIMEOUT 10000

/* ---------- Microsecond delay using DWT ---------- */

static int DWT_Delay_Init(void)
{
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
    DWT->CYCCNT = 0;
    return 0;
}

void delay_us(uint32_t us)
{
    uint32_t start = DWT->CYCCNT;
    uint32_t ticks = us * (SystemCoreClock / 1000000);
    while ((DWT->CYCCNT - start) < ticks);
}

/* ---------- GPIO direction ---------- */

static void DHT11_Pin_Output(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = DHT11_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(DHT11_PORT, &GPIO_InitStruct);
}

static void DHT11_Pin_Input(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = DHT11_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(DHT11_PORT, &GPIO_InitStruct);
}

/* ---------- Init ---------- */

void DHT11_Init(void)
{
    __HAL_RCC_GPIOA_CLK_ENABLE();
    DWT_Delay_Init();
}

/* ---------- Read byte ---------- */

static uint8_t DHT11_ReadByte(void)
{
    uint8_t i, byte = 0;
    uint32_t timeout;

    for(i = 0; i < 8; i++)
    {
        timeout = DHT11_TIMEOUT;
        while(!HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN))
            if(--timeout == 0) return 0;

        delay_us(40);

        if(HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN))
        {
            byte |= (1 << (7 - i));
            timeout = DHT11_TIMEOUT;
            while(HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN))
                if(--timeout == 0) break;
        }
    }
    return byte;
}

/* ---------- Read function ---------- */

uint8_t DHT11_Read(uint8_t *temperature, uint8_t *humidity)
{
    uint8_t data[5] = {0};
    uint32_t timeout;

    /* Start signal */
    DHT11_Pin_Output();
    HAL_GPIO_WritePin(DHT11_PORT, DHT11_PIN, GPIO_PIN_RESET);
    HAL_Delay(18);
    HAL_GPIO_WritePin(DHT11_PORT, DHT11_PIN, GPIO_PIN_SET);
    delay_us(30);
    DHT11_Pin_Input();

    /* Response check */
    timeout = DHT11_TIMEOUT;
    while(HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN))
        if(--timeout == 0) return DHT11_NO_RESPONSE;

    timeout = DHT11_TIMEOUT;
    while(!HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN))
        if(--timeout == 0) return DHT11_NO_RESPONSE;

    timeout = DHT11_TIMEOUT;
    while(HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN))
        if(--timeout == 0) return DHT11_NO_RESPONSE;

    for(uint8_t i = 0; i < 5; i++)
        data[i] = DHT11_ReadByte();

    if(data[4] != (data[0]+data[1]+data[2]+data[3]))
        return DHT11_CHECKSUM_ERR;

    *humidity = data[0];
    *temperature = data[2];

    return DHT11_OK;
}


