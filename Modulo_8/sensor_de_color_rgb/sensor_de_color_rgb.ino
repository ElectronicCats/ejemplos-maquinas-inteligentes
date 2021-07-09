/*
  APDS9960 - Sensor de Color RGB

  Este ejemplo lee la información del sensor identificador de color RGB
  que esta integrado en la tarjeta Nano 33 BLE Sense e imprime los valores de
  los colores RGB (rojo,verde,azul) en el monitor Serial.


 Este ejemplo es de dominio publico
*/

#include <Arduino_APDS9960.h>

void setup() {
  Serial.begin(115200);
  while (!Serial);

  if (!APDS.begin()) 
  {
    Serial.println("Error al iniciar el sensor APDS9960");
  }
}

void loop()
{
  // Verifica si el color esta disponible
  while (! APDS.colorAvailable()) 
  {
    delay(5);
  }
  int r, g, b;

  // Lee la información del color en R,G,B
  APDS.readColor(r, g, b);

  // Imprime los valores en formato CSV
  Serial.print(r);
  Serial.print(",");
  Serial.print(g);
  Serial.print(",");
  Serial.println(b);

}
