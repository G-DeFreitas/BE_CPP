#ifndef _BOUTON_H_
#define _BOUTON_H_
#include "data.h"
#include "Capteur.h"

class Bouton : public Capteur
{
private:
    char pin;

public:
    /*
    Usage  : Constructeur. Appelle le constructeur de Capteur
    Testé  : Ok 20/04
    */
    Bouton(char pin);

    /*
    Usage  : Renvoie la valeur lue du bouton (booleen)
    Retour : data
    Testé  : Ok 20/04
    */
    virtual data acquisition();
};

#endif