// RPIcomm1 project for the UDOO Key
// This is the ESP32 program that sends a signal to 
// the RP2040 in order to blink an LED in sync with
// the ESP32

#include <stdio.h>
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#define B_LED_PIN GPIO_NUM_32
#define Y_LED_PIN GPIO_NUM_33
#define RPI_GPIO0 GPIO_NUM_22

// Initialize the LEDs and IO 22 that will send the signal 
// from the ESP32 to the RP2040
void led_blinker_task () {
	esp_rom_gpio_pad_select_gpio(B_LED_PIN);
    gpio_set_direction (B_LED_PIN, GPIO_MODE_OUTPUT);
	esp_rom_gpio_pad_select_gpio(Y_LED_PIN);
    gpio_set_direction (Y_LED_PIN, GPIO_MODE_OUTPUT);
	esp_rom_gpio_pad_select_gpio(RPI_GPIO0);
    gpio_set_direction (RPI_GPIO0, GPIO_MODE_OUTPUT);

    while (1) {
		gpio_set_level(RPI_GPIO0, 1); // Set RPI_GPIO0
        gpio_set_level(Y_LED_PIN, 0); // blink the ESP32 LEDs
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
		//*************************
		gpio_set_level(RPI_GPIO0, 0); // Clear RPI_GPIO0
        gpio_set_level(Y_LED_PIN, 0); // blink the ESP32 LEDs
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