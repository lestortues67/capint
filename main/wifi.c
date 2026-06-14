/*
Date : 14/06/2026
Objet : Ce fichier est modifiable. Il contient les SSID/PSWD dans la STRUCT 'nos_reseaux_wifi'.
# Ignorer dans GIT le fichier contenant les vrais mots de passe "main/wifi.c"
Au déploiement : Chaque utilisateur copie sur sa machine le fichier "wifi.c.template", 
le renomme en "wifi.c" et y inscrit ses propres identifiants.
*/


#include "wifi.h"

mes_reseaux_wifi_t nos_reseaux_wifi[MAX_NETWORKS] = {
    {"SSID01", "PSWD01"},
    {"SSID02", "PSWD02"},
    {"SSID03", "PSWD03"}
};



void wifi_configuration(void){

}
void wifi_connexion(void){

}
void wifi_deconnexion(void){

}