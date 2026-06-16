/*
date : 15/06/2026
auteur : Ch Doriath
fichier : deep_sleep.c
description : le code pour utiliser le mode 'deep sleep' 

*/



// Déclarer une variable dans la mémoire RTC qui conserve sa valeur durant le mode DEEP SLEEP
// "wake_for_alert" sert à mémoriser AVANT la mise en sommeil l'état qui servira à réveiller l'ESP32. 
RTC_DATA_ATTR static bool wake_for_alert = false;
// wake_for_alert = false si on attend que le contact se FERME
// wake_for_alert = true si on attend que le contact s'OUVRE