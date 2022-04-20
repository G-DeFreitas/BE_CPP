#include "..\include\CapteurLuminosite.h"
#include <Arduino.h>

CapteurLuminosite::CapteurLuminosite(char pin)
{
    this->pin = pin;
    //pinMode(pin, INPUT); // A ne surtout pas utiliser. Le µc fonctionne sans ¯\_(ツ)_/¯
}

data CapteurLuminosite::acquisition()
{
    data d;
    yield() ;
    int valeurCapteur = analogRead(this->pin);
    d.flottant = (float)(1023 - valeurCapteur) * 10 / valeurCapteur;
    return d;
}