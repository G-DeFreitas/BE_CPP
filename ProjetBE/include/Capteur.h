#ifndef CAPTEUR_H
#define CAPTEUR_H

#include "data.h"

class Capteur
{
public:
    virtual data acquisition() = 0;
};

#endif // CAPTEUR_H