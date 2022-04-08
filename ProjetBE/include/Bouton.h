#ifndef _BOUTON_H_
#define _BOUTON_H_
#include "data.h"
#include "Capteur.h"

class Bouton : public Capteur
{
private:
public:
    /*
    Usage  : Renvoie la valeur lue du bouton (booleen)
    Retour : data
    Testé  : Non
    */
    data acquisition();

    /*
    Usage  : Constructeur. Appelle le constructeur de Capteur
    Testé  : Non
    */
    Bouton(char pin);
};

#endif