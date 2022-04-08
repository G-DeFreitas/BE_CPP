#include "..\include\Capteur.h"
#include <Arduino.h>

Capteur::Capteur(char pin)
{
    this->pin = pin;
    pinMode(pin, INPUT);
}