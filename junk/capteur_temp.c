#include "capteur_temp.h"
#include "esp_log.h" // Exemple d'inclusion spécifique à ESP-IDF
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// Variable système pour les logs ESP-IDF (privée à ce fichier)
static const char *TAG = "CAPTEUR_TEMP";

// --- LES VARIABLES ---

// Définition de la variable globale publique (déclarée en extern dans le .h)
uint8_t capteur_est_pret = 0; 

// Variable PRIVÉE (static) : Impossible à lire ou modifier depuis un autre fichier .c
static int _gpio_utilise = -1;
static float _derniere_valeur_brute = 0.0f;


// --- LES FONCTIONS ---

// Fonction PRIVÉE (static) : Aide interne pour calibrer le capteur.
// Les autres modules ne peuvent pas l'appeler.
static float completer_calibration(float valeur) {
    return valeur + 0.5f; // Exemple de correction de calibration
}

// Fonction PUBLIQUE : Initialisation (implémentation du prototype du .h)
void capteur_temp_init(int pin_gpio) {
    _gpio_utilise = pin_gpio;
    
    // Code d'initialisation matériel ESP32 ici...
    ESP_LOGI(TAG, "Capteur initialise sur le GPIO %d", _gpio_utilise);
    
    capteur_est_pret = 1; // On passe la variable extern à vrai
}

// Fonction PUBLIQUE : Lecture (implémentation du prototype du .h)
donnees_capteur_t capteur_temp_lire(void) {
    donnees_capteur_t resultat;
    
    if (!capteur_est_pret) {
        ESP_LOGW(TAG, "Tentative de lecture alors que le capteur n'est pas pret !");
        resultat.temperature_celsius = 0.0f;
        resultat.derniere_lecture_ms = 0;
        return resultat;
    }

    // Simulation d'une lecture matérielle
    _derniere_valeur_brute = 22.5f; 
    
    // Utilisation de la fonction privée pour ajuster la valeur
    resultat.temperature_celsius = completer_calibration(_derniere_valeur_brute);
    resultat.derniere_lecture_ms = pdTICKS_TO_MS(xTaskGetTickCount());

    return resultat;
}