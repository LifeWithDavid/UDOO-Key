/** RPIcomm1
 * RP2040 Blinker program to work with Udoo Key
 * The RP2040 LED telegraphs the status of GPIO 0
 * which is connected to the ESP32 IO 22
 * 
 */

#include "pico/stdlib.h"

int main() {

	uint RPI_GPIO0 = 0;  				// assign 0 to RPIcomm1
    const uint LED_PIN = 25;  			// define LED pin
    gpio_init(LED_PIN); 				// Initialize LED pin 
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_init(RPI_GPIO0); 				// Initalize GPIO0
    gpio_set_dir(RPI_GPIO0, GPIO_IN);

    while (true) {
		if (gpio_get(RPI_GPIO0)) { 		// Get value of GPIO0, if 1 then
			gpio_put(LED_PIN, 1);  		// turn LED on
		}
		else{		 					// otherwise
			gpio_put(LED_PIN, 0); 		// turn LED off
		}
	}	
		

}
