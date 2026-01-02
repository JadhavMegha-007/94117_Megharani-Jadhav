#include "dht.h"

/* ---------------- DWT Delay ---------------- */
static void DWT_Init(void)
{
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
    DWT->CYCCNT = 0;
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
}

void delay_us(uint32_t us)
{
    uint32_t start = DWT->CYCCNT;
    uint32_t ticks = us * (SystemCoreClock / 1000000);
    while ((DWT->CYCCNT - start) < ticks);
}

/* ---------------- GPIO direction ---------------- */
static void DHT11_Output(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = DHT11_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(DHT11_PORT, &GPIO_InitStruct);
}

static void DHT11_Input(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = DHT11_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(DHT11_PORT, &GPIO_InitStruct);
}

void DHT11_Init(void)
{
    DWT_Init();
}

/* ---------------- Read byte ---------------- */
static uint8_t DHT11_ReadByte(void)
{
    uint8_t i, data = 0;

    for (i = 0; i < 8; i++)
    {
        while (!HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN));
        delay_us(40);

        if (HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN))
        {
            data |= (1 << (7 - i));
            while (HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN));
        }
    }
    return data;
}

/* ---------------- Read sensor ---------------- */
uint8_t DHT11_Read(uint8_t *temperature, uint8_t *humidity)
{
    uint8_t data[5] = {0};

    DHT11_Output();
    HAL_GPIO_WritePin(DHT11_PORT, DHT11_PIN, GPIO_PIN_RESET);
    HAL_Delay(18);

    DHT11_Input();
    delay_us(30);

    if (HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN))
        return 1;

    while (!HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN));
    while (HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN));

    for (uint8_t i = 0; i < 5; i++)
        data[i] = DHT11_ReadByte();

    if (data[4] != (data[0] + data[1] + data[2] + data[3]))
        return 2;

    *humidity = data[0];
    *temperature = data[2];

    return 0;
}
