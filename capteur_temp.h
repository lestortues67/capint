/*
date : 14/06/2026
auteur : Ch Doriath
fichier : capteur_temp.h
description : un exemple de HEADER fourni par GEMINI

*/

#ifndef CAPTEUR_TEMP_H
#define CAPTEUR_TEMP_H

#include <stdint.h>

// 1. Structure spécifique publique (accessible par les autres modules)
typedef struct {
    float temperature_celsius;
    uint32_t derniere_lecture_ms;
} donnees_capteur_t;

// 2. Variable globale "extern" (Si un autre module doit ABSOLUMENT lire cette variable directement)
// Note : La variable est définie dans le .c, ici on dit juste au compilateur "elle existe quelque part".
extern uint8_t capteur_est_pret; 

// 3. Prototypes des fonctions publiques (l'interface du module)
void capteur_temp_init(int pin_gpio);
donnees_capteur_t capteur_temp_lire(void);

#endif // CAPTEUR_TEMP_H