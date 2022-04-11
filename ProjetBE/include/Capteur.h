#ifndef CAPTEUR_H
#define CAPTEUR_H

#include "data.h"

class Capteur
{
protected:
    char pin;
public:
    virtual data acquisition() = 0;
    /*
    Usage  : Constructeur. Iinitialise le pin en entrée et affecte this->pin
    Testé  : Non
    */
    Capteur(char pin);
};

#endif // CAPTEUR_H