#ifndef ENIGME_MELODIE_H
#define ENIGME_MELODIE_H

#include <vector>
#include "Enigme.h"

class EnigmeMelodie : public Enigme
{
private:
    std::vector<char> vectMelodieRef ;
public:
    EnigmeMelodie(std::vector<char> vecteurRef);
    void jouerMelodie() ;
};

#endif // ENIGME_MELODIE_H