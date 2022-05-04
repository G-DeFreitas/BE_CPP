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
    uint8_t posX; // lignes
    uint8_t posY; // colonnes
    /*
    Usage       : Formate la phrase pour l'affichage et met à jour la solution
    Testé       : Ok 04/05
    */
    void preparerEnigme();
    /*
    Usage       : Fonction bloquante jusqu'à ce que le caractère ait été bien placé sur l'écran
    Testé       : Ok 04/05
    */
    void placementLettre(char caractere);
    /*
    Usage       : Renvoie true si la case située à la position actuelle +dX, +dY est libre (' ' ou '_')
    Testé       : Ok 04/05
    */
    bool caseEstLibre(int8_t dX, int8_t dY);
    
public:
    EnigmeLettre(Afficher *ecran, Bouton *bA, Bouton *bB, Bouton *bX, Bouton *bY, std::string texte, std::string phrase, std::vector<int> vectLettre );
    /*
    Usage       : affiche la phrase formatée pour l'affichage
    Testé       : Ok 04/05
    */
    virtual void poserEnigme();
    /*
    Usage       : vérifie les caractères à placer et indique lorsque la phrase est complète
    Testé       : Ok 04/05
    */
    virtual void resolutionEnigme();
};

#endif // ENIGME_LETTRE_H