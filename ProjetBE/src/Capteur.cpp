#include "..\include\Capteur.h"
#include <Arduino.h>

Capteur::Capteur(char pin)
{
    pinMode(pin, INPUT) ;
}