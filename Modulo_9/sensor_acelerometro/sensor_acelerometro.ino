/*
Este programa captura la información leida en el sensor acelerometro del integrado LSM9DS1
incluido en la tarjeta Nano 33 BLE Sense e imprime en el monitor serial sus valores en formato CSV

Este código es de dominio publico

 
*/

//Libreria del sensor
#include <Arduino_LSM9DS1.h>

#define CONVERT_G_TO_MS2    9.80665f
#define FREQUENCY_HZ        50
#define INTERVAL_MS         (1000 / (FREQUENCY_HZ + 1))

void setup() {
    Serial.begin(115200);
    Serial.println("Comenzar");

    if (!IMU.begin()) {
        Serial.println("Existe un error al iniciar IMU!");
        while (1);
    }
}

void loop() {
    static unsigned long last_interval_ms = 0;
    float x, y, z;

    if (millis() > last_interval_ms + INTERVAL_MS)
    {
        last_interval_ms = millis();
//Lee los valores del acelerometro
        IMU.readAcceleration(x, y, z);

//Imprime los valores del acelerometro en formato CSV
        Serial.print(x * CONVERT_G_TO_MS2);
        Serial.print('\t');
        Serial.print(y * CONVERT_G_TO_MS2);
        Serial.print('\t');
        Serial.println(z * CONVERT_G_TO_MS2);
    }
}
