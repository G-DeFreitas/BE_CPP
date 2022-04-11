#include <Arduino.h>
#include "../include/Jeu.h"
#include "../include/Pins.h"
#include "../include/EnigmeMelodie.h"


#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif
 
// Variables globales
Jeu boiteEnigme;
void setup()
{
  Serial.begin(9600, SERIAL_8N1);
  Serial.println("-Lancement setup-");
  pinMode(LED_BUILTIN, OUTPUT);
  boiteEnigme.init();
  Serial.println("-Fin setup-");
}

void loop()
{
  Serial.println("-Iteration Loop-");


  // Clignotement par sécurité
  digitalWrite(LED_BUILTIN, HIGH);
  delay(200);
  digitalWrite(LED_BUILTIN, LOW);
  delay(200);
}