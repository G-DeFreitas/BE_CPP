#ifndef ENIGME_LABYRINTHE_H
#define ENIGME_LABYRINTHE_H

#include "Enigme.h"
#include "Afficher.h"
#include "Bouton.h"

#define LIGNE_MAX 14
#define COLONNE_MAX 16
#define X_SORTIE 0
#define Y_SORTIE 10

class EnigmeLabyrinthe : public Enigme
{
private:
    char labyrinthe [LIGNE_MAX][COLONNE_MAX]; // 14 lignes, 16 colonnes
    Bouton *boutonA;
    Bouton *boutonB;
    Bouton *boutonX;
    Bouton *boutonY;
    int posX; // lignes
    int posY; // colonnes

public:
    EnigmeLabyrinthe(Afficher *ecran, Bouton *bA, Bouton *bB, Bouton *bX, Bouton *bY, std::string texte, std::string laby);
    void printLabyrinthe();
    virtual void poserEnigme();
    virtual void resolutionEnigme();
};

#endif // ENIGME_LABYRINTHE_H