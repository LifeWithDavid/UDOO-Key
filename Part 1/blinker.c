#include <stdio.h>

#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#define B_LED_PIN GPIO_NUM_32
#define Y_LED_PIN GPIO_NUM_33


void led_blinker_task () {
    esp_rom_gpio_pad_select_gpio(B_LED_PIN);
    gpio_set_direction (B_LED_PIN, GPIO_MODE_OUTPUT);
    esp_rom_gpio_pad_select_gpio(Y_LED_PIN);
    gpio_set_direction (Y_LED_PIN, GPIO_MODE_OUTPUT);

    while (1) {
        gpio_set_level(Y_LED_PIN, 0);
        gpio_set_level(B_LED_PIN, 0);

        gpio_set_level(B_LED_PIN, 1);
        vTaskDelay(pdMS_TO_TICKS(128));
        gpio_set_level(B_LED_PIN, 0);
        vTaskDelay(pdMS_TO_TICKS(128));
        gpio_set_level(B_LED_PIN, 1);
        vTaskDelay(pdMS_TO_TICKS(128));
        gpio_set_level(B_LED_PIN, 0);
        
        gpio_set_level(Y_LED_PIN, 1);
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}


void app_main(void) {
    xTaskCreate (&led_blinker_task, "led_blinker_task", 1024, NULL, 2, NULL);
}
