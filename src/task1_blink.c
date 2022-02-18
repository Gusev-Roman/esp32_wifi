// task1_blink.c

#include "main.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"


void TaskBlink1(void *pvParameters) 
{
    //pinMode(LED, OUTPUT);
    gpio_set_direction(LED, GPIO_MODE_DEF_OUTPUT);
    while(1)
    {
        //digitalWrite(LED, 1);   // HIGH?
        gpio_set_level(LED, 1);
        vTaskDelay( 100 / portTICK_PERIOD_MS ); 
        //digitalWrite(LED, 0);    // LOW?
        gpio_set_level(LED, 0);
        vTaskDelay( 20 / portTICK_PERIOD_MS );  // off
        gpio_set_level(LED, 1);
        vTaskDelay( 100 / portTICK_PERIOD_MS );  // on
        gpio_set_level(LED, 0);
        vTaskDelay( 200 / portTICK_PERIOD_MS );
    }
}
