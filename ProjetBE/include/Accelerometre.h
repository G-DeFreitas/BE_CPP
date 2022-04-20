#ifndef ACCELEROMETRE_H
#define ACCELEROMETRE_H

#include "Capteur.h"
#include "data.h"

class Accelerometre : public Capteur
{
private:
public:
    /*
    Usage  : Constructeur. Appelle le constructeur de Capteur
    Testé  : 
    */
    Accelerometre();

    /*
    Usage       : Initialisation de l'écran
    Testé       : Ok 11/04
    */
    void initAccelerometre();

    /*
    Usage  : Renvoie la résistance de la photorésistance (5 Ω : luminosité max, > 15 Ω : sombre )
    Retour : data.flottant
    Testé  : 
    */
    data acquisition();
};

#endif // ACCELEROMETRE_H