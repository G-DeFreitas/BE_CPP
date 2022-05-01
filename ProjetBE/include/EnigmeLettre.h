#ifndef ENIGME_LETTRE_H
#define ENIGME_LETTRE_H

#include <map>
#include "Enigme.h"
#include "Afficher.h"
#include "Bouton.h"

#define X_INIT_LETTRE 15
#define Y_INIT_LETTRE 0

class EnigmeLettre : public Enigme
{
private:
    std::string phrase;
    std::map<int, char> lettre;
    Bouton *boutonA;
    Bouton *boutonB;
    Bouton *boutonX;
    Bouton *boutonY;
    int posX; // lignes
    int posY; // colonnes
    void placementLettre(char caractere);
public:
    EnigmeLettre(Afficher *ecran, Bouton *bA, Bouton *bB, Bouton *bX, Bouton *bY, std::string texte, std::string phrase, std::vector<int> vectLettre );
    /*
    Usage       : 
    Testé       : 
    */
    virtual void poserEnigme();
    /*
    Usage       :
    Testé       :
    */
    virtual void resolutionEnigme();
};

#endif // ENIGME_LETTRE_H