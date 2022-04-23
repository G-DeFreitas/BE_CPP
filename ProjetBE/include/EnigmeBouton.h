#ifndef _ENIGMEBOUTON_H
#define _ENIGMEBOUTON_H

#include "Enigme.h"
#include "Bouton.h"
#include "Afficher.h"

class EnigmeBouton : public Enigme
{
private:
    Bouton *bouton;

public:
    EnigmeBouton(Afficher *ecran, Bouton *b, std::string texte);
    /*
    Usage  : Pose l'enigme du bouton
    Testé  : OK 16/04
    */
    virtual void poserEnigme();
    /*
    Usage  : L'utilisateur doit appuyer sur le boutonA
    Testé  : Ok 16/04
    */
    virtual void resolutionEnigme();
};

#endif