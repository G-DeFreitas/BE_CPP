#include <Arduino.h>
#include "../include/Jeu.h"
#include "../include/Pins.h"
#include "../include/EnigmeMelodie.h"

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
  Serial.println(boiteEnigme.ensembleCapteur.find("CapteurLum")->second->acquisition().flottant);

  // Clignotement par sécurité
  digitalWrite(LED_BUILTIN, LOW);
  delay(200);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(200);
}