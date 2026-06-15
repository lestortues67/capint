/*
date : 14/06/2026
auteur : Ch Doriath
fichier : capteurs.h
description : un exemple de HEADER fourni par GEMINI

*/

#ifndef TASKS_H
#define TASKS_H

#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"
#include "esp_err.h"



// Déclarations des variables dédiées aux CAPTEURS


// 1. Structure spécifique publique (accessible par les autres modules)
// typedef struct {
//     float temperature_celsius;
//     uint32_t derniere_lecture_ms;
// } donnees_capteur_t;

// 2. Variable globale "extern" (Si un autre module doit ABSOLUMENT lire cette variable directement)
// Note : La variable est définie dans le .c, ici on dit juste au compilateur "elle existe quelque part".
// extern uint8_t capteur_est_pret; 
// extern uint16_t capteur_est_pret2 = 0; 

// 3. Prototypes des fonctions publiques (l'interface du module)
void task_adc(void *arg);

#endif // TASKS_H