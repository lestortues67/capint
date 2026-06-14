/*
date : 14/06/2026
auteur : Ch Doriath
fichier : wifi.h
description : SSID et PSWD du wifi

*/


#define MAX_NETWORKS 3

typedef struct {
    const char *ssid;
    const char *password;
} mes_reseaux_wifi_t;

// Déclaration du tableau de réseaux connus
extern mes_reseaux_wifi_t mes_reseaux_wifi[MAX_NETWORKS];






#ifndef WIFI_H
#define WIFI_H

#include <stdint.h>

#define wifi_ssid GPIO_NUM_3 // Le capteur est relié à l'entrée GPIO N° 3
#define wifi_pswd GPIO_NUM_4 // GPIO en sortie pour le pont diviseur qui est polarisé : GPIO N° 11


// 1. Structure spécifique publique (accessible par les autres modules)
typedef struct {
    float temperature_celsius;
    uint32_t derniere_lecture_ms;
} donnees_capteur_t;

// 2. Variable globale "extern" (Si un autre module doit ABSOLUMENT lire cette variable directement)
// Note : La variable est définie dans le .c, ici on dit juste au compilateur "elle existe quelque part".
extern uint8_t capteur_est_pret; 

// 3. Prototypes des fonctions publiques (l'interface du module)
void wifi_configuration(void);
void wifi_connexion(void);// Passer SSID et PSWD
void wifi_deconnexion(void);

void wifi_make_get_request(int p_url);
void wifi_make_post_request(int p_url, int p_data);



#endif // WIFI_H