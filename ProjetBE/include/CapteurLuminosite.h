#ifndef CAPTEUR_LUMINOSITE_H
#define CAPTEUR_LUMINOSITE_H

#include "Capteur.h"
#include "data.h"

class CapteurLuminosite : public Capteur
{
private:
public:
    /*
    Usage  : Constructeur. Appelle le constructeur de Capteur
    Testé  : Ok 11/04
    */
    CapteurLuminosite(char pin);

    /*
    Usage  : Renvoie la résistance de la photorésistance (5 Ω : luminosité max, > 15 Ω : sombre )
    Retour : data.flottant
    Testé  : Ok 11/04
    */
    data acquisition();
};

#endif // CAPTEUR_LUMINOSITE_H