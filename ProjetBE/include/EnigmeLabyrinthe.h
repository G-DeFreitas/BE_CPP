#ifndef ENIGME_LABYRINTHE_H
#define ENIGME_LABYRINTHE_H

#include "Enigme.h"
#include "Afficher.h"
#include "Bouton.h"

#define LIGNE_MAX 16
#define COLONNE_MAX 16
#define X_SORTIE 2
#define Y_SORTIE 10

class EnigmeLabyrinthe : public Enigme
{
private:
    std::string labyrinthe;
    Bouton *boutonA;
    Bouton *boutonB;
    Bouton *boutonX;
    Bouton *boutonY;
    int posX; // lignes
    int posY; // colonnes

public:
    EnigmeLabyrinthe(Afficher *ecran, Bouton *bA, Bouton *bB, Bouton *bX, Bouton *bY, std::string texte, std::string laby);
    bool caseEstLibre (int dX, int dY);
    virtual void poserEnigme();
    virtual void resolutionEnigme();
};

#endif // ENIGME_LABYRINTHE_H