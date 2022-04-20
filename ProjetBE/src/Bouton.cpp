#include "../include/Bouton.h"
#include <Arduino.h>
Bouton::Bouton(char pin)
{
    this->pin = pin;
    //pinMode(pin, INPUT); // A ne surtout pas utiliser. Le µc fonctionne sans ¯\_(ツ)_/¯
}

data Bouton::acquisition()
{
    data d;
    d.entier = digitalRead(this->pin);
    yield();
    return d;
}
