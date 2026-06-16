/*
Date : 14/06/2026
Objet : Build OK
*/
#include <stdio.h>
#include "esp_log.h" // Pour les fonctions de log d'ESP-IDF
#include "capteurs.h"
#include "tasks.h"

static const char *TAG = "MY_APP";

void setup(void){
    /* Ressembler à Arduino : 
    Dans Arduino deux fonctions sont présentes : 
    setup() et app_main(). 
    */
    
}

void app_main(void)
{
    setup();
	ESP_LOGI(TAG, "Application principale (app_main) démarrée.");

	// Init ADC 
	adc_init();
	
	//
    // Création de la task ADC
    //
    xTaskCreate(
        task_adc,
        "task_adc",
        4096,
        NULL,
        5,
        NULL);
}
