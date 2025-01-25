/**
 * Jon Durrant.
 *
 * Blink LEDs on my RPI2040Zero Plugin board
 *
 */

#include "pico/stdlib.h"

#include "RP2040-Plugin.h"
#include <cstdio>


#define DELAY 500 // in microseconds
#define NUM_LEDS 3

int main() {
    uint leds[3] = {PICO_DEFAULT_LED_PIN, LED1, LED2};

    stdio_init_all();
    sleep_ms(2000);

    printf("GO\n");

    for (int i=0; i < NUM_LEDS; i++){
		gpio_init(leds[i]);
		gpio_set_dir(leds[i], GPIO_OUT);
		gpio_put(leds[i], 0);
    }

    for (;;){
    	for (int i=0; i < NUM_LEDS; i++){
    		printf("LED %d\n", i);
			gpio_put(leds[i], 1);
			sleep_ms(DELAY);
			gpio_put(leds[i], 0);
    	}
    }

}
