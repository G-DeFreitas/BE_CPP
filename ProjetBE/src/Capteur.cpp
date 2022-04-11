#include "..\include\Capteur.h"
#include <Arduino.h>

Capteur::Capteur(char pin)
{
    this->pin = pin;
    //pinMode(pin, INPUT); // A ne surtout pas utiliser. Le µc fonctionne sans ¯\_(ツ)_/¯
}