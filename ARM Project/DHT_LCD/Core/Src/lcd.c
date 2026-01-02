#include "lcd.h"

static I2C_HandleTypeDef *lcd_i2c;
static uint8_t lcd_addr;

/* Low-level send */
static void lcd_send(uint8_t data)
{
    uint8_t buf[2];
    buf[0] = data | LCD_EN | LCD_BL;
    buf[1] = data | LCD_BL;
    HAL_I2C_Master_Transmit(lcd_i2c, lcd_addr, buf, 2, 100);
}

static void lcd_cmd(uint8_t cmd)
{
    lcd_send(cmd & 0xF0);
    lcd_send((cmd << 4) & 0xF0);
    HAL_Delay(2);
}

static void lcd_data(uint8_t data)
{
    lcd_send((data & 0xF0) | LCD_RS);
    lcd_send(((data << 4) & 0xF0) | LCD_RS);
}

bool lcd_init(I2C_HandleTypeDef *hi2c)
{
    lcd_i2c = hi2c;
    HAL_Delay(50);

    if (HAL_I2C_IsDeviceReady(hi2c, LCD_ADDR_0, 3, 100) == HAL_OK)
        lcd_addr = LCD_ADDR_0;
    else if (HAL_I2C_IsDeviceReady(hi2c, LCD_ADDR_1, 3, 100) == HAL_OK)
        lcd_addr = LCD_ADDR_1;
    else
        return false;

    lcd_cmd(0x33);
    lcd_cmd(0x32);
    lcd_cmd(0x28);
    lcd_cmd(0x0C);
    lcd_cmd(0x06);
    lcd_clear();

    return true;
}

void lcd_clear(void)
{
    lcd_cmd(0x01);
    HAL_Delay(2);
}

void lcd_setCursor(uint8_t row, uint8_t col)
{
    lcd_cmd((row == 0 ? 0x80 : 0xC0) + col);
}

void lcd_print(char *str)
{
    while (*str)
        lcd_data(*str++);
}
