#ifndef CAPTEUR_H
#define CAPTEUR_H

#include "data.h"

class Capteur
{
protected:
    virtual data acquisition() = 0 ;
public:
    Capteur(char pin);
};

#endif // CAPTEUR_H