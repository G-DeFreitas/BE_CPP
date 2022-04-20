#include "../include/Bouton.h"
#include <Arduino.h>
Bouton::Bouton(char pin)
{
    this->pin = pin;
}

data Bouton::acquisition()
{
    data d;
    d.entier = digitalRead(this->pin);
    yield();
    return d;
}
