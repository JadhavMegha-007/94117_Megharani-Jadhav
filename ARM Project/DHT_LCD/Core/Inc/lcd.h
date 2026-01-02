#ifndef LCD_H_
#define LCD_H_

#include "stm32f4xx_hal.h"
#include <stdbool.h>

/* PCF8574 pins */
#define LCD_RS   (1 << 0)
#define LCD_EN   (1 << 2)
#define LCD_BL   (1 << 3)

/* I2C addresses */
#define LCD_ADDR_0  0x4E
#define LCD_ADDR_1  0x7E

bool lcd_init(I2C_HandleTypeDef *hi2c);
void lcd_clear(void);
void lcd_setCursor(uint8_t row, uint8_t col);
void lcd_print(char *str);

#endif
