#ifndef ENIGME_MELODIE_H
#define ENIGME_MELODIE_H

#include <vector>
#include "Enigme.h"
#include "Buzzer.h"
#include "Bouton.h"

#define NOTE_A 50
#define NOTE_B 90
#define NOTE_C 255

class EnigmeMelodie : public Enigme
{
private:
    std::vector<char> vectMelodieRef;
    Bouton *boutonA;
    Bouton *boutonB;
    Bouton *boutonC;
    Buzzer *buzzer;

public:
    /*
    Usage       : Affecte la mélodie de référence
    Argument    : Vecteur de notes (char) de référence pour la mélodie
    Testé       : Ok 20/04
    */
    EnigmeMelodie(Afficher *ecran, std::vector<char> vecteurRef, Bouton *bA, Bouton *bB, Bouton *bC, Buzzer *buzz, std::string texte);

    /*
    Usage       : Joue la mélodie de référence
    Testé       : Ok 20/04
    */
    void jouerMelodie();

    /*
    Usage       : Pose l'énigme
    Testé       : Ok 20/04
    */
    virtual void poserEnigme();

    /*
    Usage       : L'utilisateur doit rejouer la musique de référence avec les boutons
    Testé       : Ok 20/04
    */
    virtual void resolutionEnigme();
};

#endif // ENIGME_MELODIE_H