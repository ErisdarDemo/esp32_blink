/* Blink Example - FreeRTOS example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.

   @section 	Pin Configuration
   	   Using GPIO12 (#14) for blink demonstration @ 0.5 Hz
*/

//--------------------------------- Includes ---------------------------------//

//Standard Library Includes
#include <stdio.h>

//FreeRTOS Includes
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

//SDK Includes
#include "driver/gpio.h"
#include "esp_log.h"
#include "led_strip.h"
#include "sdkconfig.h"


//-------------------------------- Constants ---------------------------------//

static const char *TAG = "example";


//------------------------------- Definitions --------------------------------//

#define BLINK_GPIO 	(12)						/* @prev CONFIG_BLINK_GPIO    */


//-------------------------------- Variables ---------------------------------//

uint8_t s_led_state = 0;


//--------------------------------- Routines ---------------------------------//
/*
 * @todo 	header
 */
void blink_led(void)
{
    /* Set the GPIO level according to the state (LOW or HIGH)*/
    gpio_set_level(BLINK_GPIO, s_led_state);

    return;
}


/*
 * @todo 	header
 */
static void configure_led(void)
{
    ESP_LOGI(TAG, "Example configured to blink GPIO LED!");

    gpio_reset_pin(BLINK_GPIO);

    /* Set the GPIO as a push/pull output */
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

    return;
}


/*
 * @todo 	header
 */
void app_main(void)
{

    /* Configure the peripheral according to the LED type */
    configure_led();

	printf("\r\n\r\n\r\n\r\n");
	printf("//----------------------------------------------------------------------------//\r\n");
	printf("//-                                                                          -//\r\n");
	printf("//----------------------------------------------------------------------------//\r\n");
	printf("Hello world!\n\r\n\r");

    while (1) {
        ESP_LOGI(TAG, "Turning the LED %s!", s_led_state == true ? "ON" : "OFF");

        blink_led();

        /* Toggle the LED state */
        s_led_state = !s_led_state;

        vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
    }
}

