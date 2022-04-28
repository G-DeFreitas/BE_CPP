#ifndef ENIGME_CODE_H
#define ENIGME_CODE_H

#include "Enigme.h"
#include "Afficher.h"
#include "Bouton.h"

#define LIGNE_CODE 10

class EnigmeCode : public Enigme
{
private:
    char code [4];
    char codeRef [4];
    int selection;
    Bouton *boutonA;
    Bouton *boutonB;
    Bouton *boutonX;
    Bouton *boutonY;
    void afficherCode();
public:
    /*
    Usage       : Constructeur avec initialisation du code à trouver
    Testé       : Ok 25/04
    */
    EnigmeCode(Afficher *ecran, char code[4], Bouton *bA, Bouton *bB, Bouton *bX, Bouton *bY, std::string texte);
    /*
    Usage       : Affiche le code à 0000, premier chiffre sélectionné
    Testé       : Ok 25/04
    */
    virtual void poserEnigme();
    /*
    Usage       : Incrémentation/décrémentation avec boutons X et B, déplacements A et Y, ok quand code affiché égal au code de référence
    Testé       : Ok 25/04
    */
    virtual void resolutionEnigme();
};


#endif // ENIGME_CODE_H