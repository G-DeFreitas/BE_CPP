#ifndef ENIGME_LABYRINTHE_H
#define ENIGME_LABYRINTHE_H

#include "Enigme.h"
#include "Afficher.h"
#include "Bouton.h"

#define LIGNE_MAX 16
#define COLONNE_MAX 16
#define X_INIT 15
#define Y_INIT 1
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
    uint8_t posX; // lignes
    uint8_t posY; // colonnes
    /*
    Usage       : Renvoie true si la case située à la position actuelle +dX, +dY est libre
    Testé       : Ok 24/04
    */
    bool caseEstLibre (int8_t dX, int8_t dY);

public:
    /*
    Usage       : Constructeur
    Testé       : Ok 24/04
    */
    EnigmeLabyrinthe(Afficher *ecran, Bouton *bA, Bouton *bB, Bouton *bX, Bouton *bY, std::string texte, std::string laby);
    /*
    Usage       : Affiche le labyrinthe
    Testé       : Ok 24/04
    */
    virtual void poserEnigme();
    /*
    Usage       : Résolution du labyrinthe avec déplacement par appui bouton
    Testé       : Ok 24/04
    */
    virtual void resolutionEnigme();
};

#endif // ENIGME_LABYRINTHE_H