#ifndef ENIGME_MELODIE_H
#define ENIGME_MELODIE_H

#include <vector>
#include "Enigme.h"

class EnigmeMelodie : public Enigme
{
private:
    std::vector<char> vectMelodieRef;

public:

    /*
    Usage       : Affecte la mélodie de référence
    Argument    : Vecteur de notes (char) de référence pour la mélodie
    Testé       : Non
    */
    EnigmeMelodie(std::vector<char> vecteurRef);

    /*
    Usage       : Joue la mélodie de référence
    Testé       : Non
    */
    void jouerMelodie();
};

#endif // ENIGME_MELODIE_H