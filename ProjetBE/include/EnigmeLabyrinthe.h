#ifndef ENIGME_LABYRINTHE_H
#define ENIGME_LABYRINTHE_H

#include "Enigme.h"
#include "Afficher.h"
#include "Bouton.h"

class EnigmeLabyrinthe : public Enigme
{
private:
    std::string labyrinthe;
    Bouton *boutonA;
    Bouton *boutonB;
    Bouton *boutonC;
    Bouton *boutonD;
    int posX;
    int posY;

public:
    EnigmeLabyrinthe(Afficher *ecran, Bouton *bA, Bouton *bB, Bouton *bC, Bouton *bD, std::string texte, std::string laby);
    virtual void poserEnigme();
    virtual void resolutionEnigme();
};

#endif // ENIGME_LABYRINTHE_H