#ifndef ACCELEROMETRE_H
#define ACCELEROMETRE_H

#include "Capteur.h"
#include "data.h"

class Accelerometre : public Capteur
{
public:
    /*
    Usage       : Initialisation de l'accelerometre
    Testé       :
    */
    void initAccelerometre();

    /*
    Usage  : Renvoie deux valeurs flotantes qui permettent de déduire l'orientation de la boite
    Retour : data.tab_float
    Testé  :
    */
    data acquisition();
};

#endif // ACCELEROMETRE_H