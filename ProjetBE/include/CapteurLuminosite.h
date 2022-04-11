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
    Testé  : Non
    */
    CapteurLuminosite(char pin);

    /*
    Usage  : Renvoie la résistance de la photorésistance (5 Ω : luminosité max, > 15 Ω : sombre )
    Retour : data
    Testé  : Non
    */
    data acquisition();
};

#endif // CAPTEUR_LUMINOSITE_H