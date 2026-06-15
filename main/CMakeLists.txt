idf_component_register(SRCS "main.c" "capteurs.c" "tasks.c" "drivers.c"
                    REQUIRES esp_adc esp_driver_gpio
                    INCLUDE_DIRS ".")



