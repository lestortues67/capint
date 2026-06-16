/*
date : 15/06/2026
auteur : Ch Doriath
fichier : logique_metier.c
description : le code pour faire fonctionner le capteur d'intrusion. 

Il se trouve dans le mode 'deep sleep' 99% du temps 
et qui se réveille pour ces évènements : 
1) le contact reed change d'état
2) un POR suite au remplacement des piles.
3) timer périodique (tous les dimanches à 2h00) de vérification des màj par OTA

Quand un esp32 est réveillé pour sortir de son mode "DEEP SLEEP" 
le code est exécuté comme un RESET à savoir depuis la 1ère ligne de code de "main.c". 
A chaque re-démarrage il faut déterminer si la raison est l'ouverture d'une porte ou fenêtre. 
Si c'est le cas une ALERTE doit être donnée par le TX d'un message vers MASTER RX avec ESP NOW. 

Une machine à états finis est utilisée. L'ENUM "capteurState" informe sur l'état. 
*/

typedef enum {
    alerteReason,
    noAlertReason,
    porReason,
    verifUpdate
} enumReStartReason;
enumReStartReason reStartReason=porReason;

/*
"reStartReason" contient "alerteReason" quand la raison du réveil a été le contact 
qui s'est fermé "wake Up Reason for deep sleep on falling edge ou 0"

"reStartReason" contient "nonAlertReason" quand la raison du réveil a été le contact 
qui s'est ouvert "wake Up Reason for deep sleep on rising edge ou 1"

"reStartReason" contient "porReason" quand la raison du réveil a été 
une autre raison que "alerteReason" ou "nonAlertReason". Par exemple un reset pur
provoqué par le remplacement des piles ou une pression sur le BP reset.

"reStartReason" contient "verifUpdate" quand la raison du réveil a été le réveil
par le timer "timerVerifUpdate" qui se déclenche tous les dimanches à 2h00
afin de contacter par esp-now la centrale d'alarme pour savoir si un nouveau
firmware de màj est disponible sur le serveur distant (bio220.fr ou rpi4 local). 
Si c'est le cas le WIFI est utilisé pour màj avec OTA. 


*/

typedef enum {
    attenteOuvertureContactReed,
    readUBatt,
    signalerAlerteIntrusion,
    verifUpdate,
    attenteFermetureContactReed
} enumActionSetup;
enumActionSetup capteurState=attenteFermetureContactReed;