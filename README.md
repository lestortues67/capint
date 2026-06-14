# Ma nouvelle architecture du code C pour ESP32

Ce fichier est la source d'infos pour la nouvelle architecture : C:\esp_mesProjets\BASE_TEMPLATE\esp-idf_myBaseArchitecture\docs\gestionErreurs.pdf

Des informations se trouvent ici [notre wiki](https://lestortues67.atlassian.net/wiki/x/AQCOS)

## How to use example

```Du
a = 100;
```

# Voici la liste des fichiers à créer



### Fichiers event_loop.c et .h

Créer, utiliser une 'event loop'



### Fichiers deep_sleep.c et .h

Passer en "deep sleep" et définir les sorties possibles (réveils)

du deep sleep 



### Fichiers error_handling.c et .h

Gestion solide des erreurs



### Fichiers nvs_flash_storage.c et .h

Déclarer des variables en mémoire flash

Lire et écrire ces variables



### Fichiers wifi.c et .h

Config en mode "wifi station", 

se connecter et se déconnecter du wifi

### 

### Fichiers uart.c et .h

Config en uart TX ou RX.

TX ou RX de la data



### Fichiers esp_now.c et .h

Config en esp now TX ou RX. 

TX ou RX de la data



### Fichiers logique_metier.c et .h

QUE la "logique métier"



### Fichiers drivers.c et *.h*

Pilotage de GPIO de polarisation du pont de résistances pour mesurer U piles



### Fichiers tasks.c et .h

Déclarer 5 à 7 tâches au maximum



## fichiers capteurs.h, capteurs.c

Concernent : 

- le switch à effet hall 

- la mesure de la tension des piles



<mark>OK</mark> 
