/*
  HTS221 - Lee el sensor de temperatura

Este ejemplo lee la información del sensor HTS221 de la tarjeta Nano 33 BLE Sense
e imprime los valores de temperatura en el monitor serial una vez cada segundo.


  Este ejemplo es de dominio publico
*/

#include <Arduino_HTS221.h>

#define FREQUENCY_HZ        50
#define INTERVAL_MS         (1000 / (FREQUENCY_HZ + 1))

void setup() 
{
  Serial.begin(115200);
  while (!Serial);

  if (!HTS.begin()) 
  {
    Serial.println("Existe un error al iniciar el sensor de temperatura!");
    while (1);
  }
}

void loop() 
{
  //
  static unsigned long last_interval_ms = 0;
  
    if (millis() > last_interval_ms + INTERVAL_MS) 
    {
      last_interval_ms = millis();
        
      // Lee el sensor de temperatura
      float temperature = HTS.readTemperature();

      // Imprime el valor de la temperatura en formato CSV
      Serial.println(temperature);

    }
}
