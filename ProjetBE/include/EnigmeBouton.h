#ifndef _ENIGMEBOUTON_H
#define _ENIGMEBOUTON_H

#include "Enigme.h"
#include "Bouton.h"

class EnigmeBouton : public Enigme
{
private:
    Bouton *bouton;
public:
    EnigmeBouton(Bouton *b);
    void poserEnigme();
    void resolutionEnigme();
};


#endif