/*
date : 14/06/2026
auteur : Ch Doriath
fichier : capteurs.c
description : le code pour les capteurs : intrusion et mesure tension des piles

*/
#include "capteurs.h"
#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"
#include "esp_err.h"

#include "esp_adc/adc_oneshot.h"
#include "esp_adc/adc_cali.h"
#include "esp_adc/adc_cali_scheme.h"


// Variable système pour les logs ESP-IDF (privée à ce fichier)
static const char *TAG = "LES_CAPTEURS";


// Variable globale ou locale pour stocker la poignée de calibration
// adc_cali_handle_t cali_handle = NULL;
// bool cali_disponible = false;


// --- LES VARIABLES ---

// Définition de la variable globale publique (déclarée en extern dans le .h)
uint8_t capteur_est_pret = 0; 

// Variable PRIVÉE (static) : Impossible à lire ou modifier depuis un autre fichier .c
static adc_oneshot_unit_handle_t adc_handle;
static adc_cali_handle_t cali_handle = NULL;
static bool calibrated = false;
static esp_err_t ret;




// --- LES FONCTIONS ---

// Fonction PRIVÉE (static) : Aide interne pour calibrer le capteur.
// Les autres modules ne peuvent pas l'appeler.


void init_capteur_intrusion_INT_NEG(void){

    // L'entrée de mesure du capteur d'intrusion, configurée pour : INT Front DESCENDANT 
    gpio_config_t input_capteur_intrusion_gpio_NEG = {
        .pin_bit_mask = 1ULL << capteur_intrusion_gpio,
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_ENABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_NEGEDGE // Front DESCENDANT pour l'INT
    };
    ESP_ERROR_CHECK(gpio_config(&input_capteur_intrusion_gpio_NEG));   
}

void init_capteur_intrusion_INT_POS(void){

    // L'entrée de mesure du capteur d'intrusion, configurée pour : INT Front MONTANT 
    gpio_config_t input_capteur_intrusion_gpio_POS = {
        .pin_bit_mask = 1ULL << capteur_intrusion_gpio,
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_ENABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_POSEDGE // Front MONTANT pour l'INT
    };
    ESP_ERROR_CHECK(gpio_config(&input_capteur_intrusion_gpio_POS));   
}

void adc_init(void){
    //
    // Initialisation ADC oneshot
    //
    adc_oneshot_unit_init_cfg_t init_cfg = {
        .unit_id = ADC_UNIT,
    };
    ESP_ERROR_CHECK(
        adc_oneshot_new_unit(&init_cfg, &adc_handle));
    //
    // Configuration du canal ADC
    //
    adc_oneshot_chan_cfg_t chan_cfg = {
        .bitwidth = ADC_BITWIDTH_DEFAULT, // 12 bits
        .atten = ADC_ATTEN,
    };

    ESP_ERROR_CHECK(
        adc_oneshot_config_channel(
            adc_handle,
            ADC_CHANNEL,
            &chan_cfg));
    //
    // Calibration
    //
    #if ADC_CALI_SCHEME_CURVE_FITTING_SUPPORTED
        adc_cali_curve_fitting_config_t cali_cfg = {
            .unit_id = ADC_UNIT,
            .atten = ADC_ATTEN,
            .bitwidth = ADC_BITWIDTH_DEFAULT,
        };

        ret = adc_cali_create_scheme_curve_fitting(
                &cali_cfg,
                &cali_handle);

        if (ret == ESP_OK) {
            calibrated = true;
            ESP_LOGI(TAG, "ADC calibration enabled");
        } else {
            ESP_LOGW(TAG,
                     "ADC calibration unavailable: %s",
                     esp_err_to_name(ret));
        }

    #endif


}

// SECTION pour la lecture de la TENSION : 
int get_tension_piles(){
    uint32_t raw_sum = 0;

    // Acquisition de 16 échantillons
    for (int i = 0; i < ADC_SAMPLES; i++) {
        int raw;

        ESP_ERROR_CHECK(
            adc_oneshot_read(
                adc_handle,
                ADC_CHANNEL,
                &raw));

        raw_sum += raw;

        // Petite pause facultative
        // ets_delay_us(100);
    }

    // Moyenne des 16 mesures
    int raw_avg = raw_sum / ADC_SAMPLES;

    if (calibrated) {

        int voltage_mv;

        ESP_ERROR_CHECK(
            adc_cali_raw_to_voltage(
                cali_handle,
                raw_avg,
                &voltage_mv));

        ESP_LOGI(TAG,
                 "RAW=%4d  Voltage=%4d mV (%.3f V)",
                 raw_avg,
                 voltage_mv,
                 voltage_mv / 1000.0f);
        return voltage_mv;

    } 
    else {
        float voltage = 3.3f * raw_avg / 4095.0f;
        ESP_LOGI(TAG,
                 "RAW=%4d  Voltage=%.3f V",
                 raw_avg,
                 voltage);
        return raw_avg;
    }
};

uint8_t get_capteur_intrusion_level(void){
    return gpio_get_level(capteur_intrusion_gpio);
};