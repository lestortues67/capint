/*
date : 14/06/2026
auteur : Ch Doriath
fichier : drivers.c
description : un exemple de HEADER fourni par GEMINI

*/
#include "drivers.h"



// 1. Structure spécifique publique (accessible par les autres modules)
// typedef struct {
//     float temperature_celsius;
//     uint32_t derniere_lecture_ms;
// } donnees_capteur_t;


void monitor_pin_init(void){
    // La sortie GPIO pour le pont diviseur qui est polarisé
    gpio_config_t output_commande_u_batterie_gpio = {
        .pin_bit_mask = 1ULL << commande_u_batterie_gpio,
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };
    ESP_ERROR_CHECK(gpio_config(&output_commande_u_batterie_gpio));    
}



// 2. Variable globale "extern" (Si un autre module doit ABSOLUMENT lire cette variable directement)
// Note : La variable est définie dans le .c, ici on dit juste au compilateur "elle existe quelque part".
// extern uint8_t capteur_est_pret; 
// extern uint16_t capteur_est_pret = 0; 

// 3. Prototypes des fonctions publiques (l'interface du module)
void set_commande_output(void ){
    gpio_set_level(commande_u_batterie_gpio, 1);
}
void reset_commande_output(void ){
    gpio_set_level(commande_u_batterie_gpio, 0);
}
// 
