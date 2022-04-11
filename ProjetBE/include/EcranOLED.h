#ifndef _ECRANOLED_H_
#define _ECRANOLED_H_

#include "Actionneur.h"
#include "SeeedOLED.h"

class EcranOLED : public Actionneur
{
private:
    SeeedOLED ecran; // mettre affichage en friend

public:
};

#endif