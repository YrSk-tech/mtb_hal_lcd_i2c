/*******************************************************************************
* Header Files
*******************************************************************************/
#include "cyhal.h"
#include "cybsp.h"
#include <stdio.h>
#include <string.h>
#include "lcd_i2c.h"

/*******************************************************************************
* Macros
*******************************************************************************/

/* I2C slave address to communicate with */
#define I2C_SLAVE_ADDR          (0x27)

/* I2C bus frequency */
#define I2C_FREQ                (400000UL)





/*******************************************************************************
* Global Variables
*******************************************************************************/

// Define global variable for backlight state
uint8_t backlight_state = 1;

/*******************************************************************************
* Function Name: main
*******************************************************************************/

int main(void)
{
	cyhal_i2c_t mI2C; // This is the declaration of mI2C
    /* Initialize the device and board peripherals */
	cyhal_i2c_cfg_t mI2C_cfg;
    cybsp_init();

    char *text = "Hello LCD I2C";
    char *number = "101 second line";


    mI2C_cfg.is_slave = false;
    mI2C_cfg.address = 0;
    mI2C_cfg.frequencyhal_hz = I2C_FREQ;

    /* Init I2C master */
    cyhal_i2c_init(&mI2C, CYBSP_I2C_SDA, CYBSP_I2C_SCL, NULL);

    /* Configure I2C Master */
    cyhal_i2c_configure(&mI2C, &mI2C_cfg);

    /* Enable interrupts */
    __enable_irq();

	lcd_init(&mI2C);

	lcd_clear(&mI2C);
	lcd_set_cursor(&mI2C, 0, 0);
	lcd_write_string(&mI2C, text);
	lcd_set_cursor(&mI2C, 1, 1);
	lcd_write_string(&mI2C, number);
	cyhal_system_delay_ms(1500);
    for (;;)
    {

    }

}
