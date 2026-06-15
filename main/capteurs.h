/*
date : 14/06/2026
auteur : Ch Doriath
fichier : capteurs.h
description : un exemple de HEADER fourni par GEMINI

*/

#ifndef CAPTEURS_H
#define CAPTEURS_H

#include <stdint.h>
#include "esp_adc/adc_oneshot.h"






// Déclarations des variables dédiées aux CAPTEURS
#define capteur_intrusion_gpio GPIO_NUM_3 // Le capteur est relié à l'entrée GPIO N° 3
#define mesure_u_batterie_gpio ADC_CHANNEL_2 // GPIO 2 sur ESP32-C3 = ADC1_CHANNEL_2

// ESP32-C3 : GPIO2 -> ADC1_CHANNEL_2
#define ADC_UNIT       ADC_UNIT_1
#define ADC_CHANNEL    ADC_CHANNEL_2
#define ADC_ATTEN      ADC_ATTEN_DB_12
#define ADC_SAMPLES     16



// 1. Structure spécifique publique (accessible par les autres modules)
typedef struct {
    float temperature_celsius;
    uint32_t derniere_lecture_ms;
} donnees_capteur_t;

// 2. Variable globale "extern" (Si un autre module doit ABSOLUMENT lire cette variable directement)
// Note : La variable est définie dans le .c, ici on dit juste au compilateur "elle existe quelque part".
// extern uint8_t capteur_est_pret; 
// extern uint16_t capteur_est_pret2 = 0; 

// 3. Prototypes des fonctions publiques (l'interface du module)
// capteur d'intrusion 
void init_capteur_intrusion_INT_NEG(void);
void init_capteur_intrusion_INT_POS(void)
uint8_t get_capteur_intrusion_level(void);

// mesure U piles
void adc_init(void);
int get_tension_piles(void);

#endif // CAPTEURS_H