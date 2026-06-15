/*
date : 14/06/2026
auteur : Ch Doriath
fichier : drivers.h
description : un exemple de HEADER fourni par GEMINI

*/

#ifndef DRIVERS_H
#define DRIVERS_H

#include <stdint.h>
#include "driver/gpio.h"
#include "esp_err.h"

// Déclarations des variables dédiées aux DRIVERS
#define commande_u_batterie_gpio GPIO_NUM_4 // GPIO en sortie pour le pont diviseur qui est polarisé : GPIO N° 11


// 1. Structure spécifique publique (accessible par les autres modules)
// typedef struct {
//     float temperature_celsius;
//     uint32_t derniere_lecture_ms;
// } donnees_capteur_t;

// 2. Variable globale "extern" (Si un autre module doit ABSOLUMENT lire cette variable directement)
// Note : La variable est définie dans le .c, ici on dit juste au compilateur "elle existe quelque part".
// extern uint8_t capteur_est_pret; 
// extern uint16_t capteur_est_pret = 0; 

// 3. Prototypes des fonctions publiques (l'interface du module)
void monitor_pin_init(void);
void set_commande_output(void );
void reset_commande_output(void );
// gpio_set_level(commande_u_batterie_gpio, 1);
#endif // DRIVERS_H