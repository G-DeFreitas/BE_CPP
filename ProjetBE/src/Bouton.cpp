#include "../include/Bouton.h"
#include <Arduino.h>
Bouton::Bouton(char pin) : Capteur::Capteur(pin)
{
}

data Bouton::acquisition()
{
    data d;
    d.entier = digitalRead(this->pin);
    yield();
    return d;
}
