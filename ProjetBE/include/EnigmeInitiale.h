#ifndef ENIGME_INIT_H
#define ENIGME_INIT_H

#include "Enigme.h"
#include "Bouton.h"
#include "Afficher.h"
#include "Buzzer.h"

class EnigmeInitiale : public Enigme
{
private:
    Bouton *bouton;
    Buzzer *buzzer;

public:
    EnigmeInitiale(Afficher *ecran, Bouton *b, Buzzer *buzz, std::string texte);
    /*
    Usage  : Affiche message de bienvenue
    Testé  : Non
    */
    virtual void poserEnigme();
    /*
    Usage  : Enclenche un jeu si appui sur bouton A
    Testé  : Non
    */
    virtual void resolutionEnigme();
};

#endif // ENIGME_INIT_H