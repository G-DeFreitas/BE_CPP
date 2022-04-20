#ifndef ENIGME_MELODIE_H
#define ENIGME_MELODIE_H

#include <vector>
#include "Enigme.h"
#include "Bouton.h"

class EnigmeMelodie : public Enigme
{
private:
    std::vector<char> vectMelodieRef;
    Bouton *boutonA ;
    Bouton *boutonB ;
    Bouton *boutonC ;

public:

    /*
    Usage       : Affecte la mélodie de référence
    Argument    : Vecteur de notes (char) de référence pour la mélodie
    Testé       : Non
    */
    EnigmeMelodie(Afficher *ecran,std::vector<char> vecteurRef, Bouton * bA, Bouton *bB, Bouton * bC);

    /*
    Usage       : Joue la mélodie de référence
    Testé       : Non
    */
    void jouerMelodie();

    /*
    Usage       : Pose l'énigme
    Testé       : Non
    */
    virtual void poserEnigme();

    /*
    Usage       : L'utilisateur doit rejouer la musique de référence avec les boutons
    Testé       : Non
    */
    virtual void resolutionEnigme();
};

#endif // ENIGME_MELODIE_H