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
    std::string phraseRef;
    std::string phraseAffichee;
    std::map<int, char> lettre;
    std::map<char, int> solution;
    Bouton *boutonA;
    Bouton *boutonB;
    Bouton *boutonX;
    Bouton *boutonY;
    int posX; // lignes
    int posY; // colonnes
    void placementLettre(char caractere);
    bool caseEstLibre(int dX, int dY);
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