#include "..\include\CapteurLuminosite.h"
#include <Arduino.h>

CapteurLuminosite::CapteurLuminosite(char pin) : Capteur::Capteur(pin)
{
}

data CapteurLuminosite::acquisition()
{
    data d;
    int valeurCapteur = analogRead(this->pin);
    d.flottant = (float)(1023 - valeurCapteur) * 10 / valeurCapteur;
    return d;
}