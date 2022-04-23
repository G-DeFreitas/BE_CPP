#include <Arduino.h>
#include <string>

#include "../include/Jeu.h"

// Variables globales
Jeu boiteEnigme;

void setup()
{
  Serial.begin(9600, SERIAL_8N1);
  Serial.println("-Lancement setup-");
  boiteEnigme.init();
  Serial.println("-Fin setup-");
}

void loop()
{
  Serial.println("-Iteration Loop-");
  boiteEnigme.loop();
}