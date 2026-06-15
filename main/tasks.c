/*
date : 14/06/2026
auteur : Ch Doriath
fichier : tasks.c
description : le code pour les tasks

*/

#include "tasks.h"
#include "capteurs.h"
#include "drivers.h"

void task_adc(void *arg)
{
    static const char *TAG = "TASKS";
    monitor_pin_init();
    ESP_LOGI(TAG,"Tester le pilotage de GPIO4");
    reset_commande_output();
    ESP_LOGI(TAG,"GPIO4 = 0");
    vTaskDelay(pdMS_TO_TICKS(5000));
    set_commande_output();
    ESP_LOGI(TAG,"GPIO4 = 1");
    vTaskDelay(pdMS_TO_TICKS(5000));
    reset_commande_output();
    ESP_LOGI(TAG,"GPIO4 = 0");
    vTaskDelay(pdMS_TO_TICKS(5000));
    while (1) {
        int tensionBatt = get_tension_piles();
        ESP_LOGI(TAG,"Tension en mV = %4d",tensionBatt);

        // Lecture toutes les secondes
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}