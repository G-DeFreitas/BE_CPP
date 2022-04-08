#ifndef CAPTEUR_H
#define CAPTEUR_H

#include "data.h"

class Capteur
{
protected:
    virtual data acquisition() = 0;
    char pin;
public:
    /*
    Usage  : Constructeur. Iinitialise le pin en entrée et affecte this->pin
    Testé  : Non
    */
    Capteur(char pin);
};

#endif // CAPTEUR_H