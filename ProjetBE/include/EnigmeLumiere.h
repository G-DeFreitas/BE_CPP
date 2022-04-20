#ifndef ENIGME_LUMIERE_H
#define ENIGME_LUMIERE_H

#include "Enigme.h"
#include "CapteurLuminosite.h"

class EnigmeLumiere : public Enigme
{
private:
    CapteurLuminosite *capteurLum;
    float seuilLuminosite;

public:
    EnigmeLumiere(CapteurLuminosite *captLum, float seuilLum);
    virtual void poserEnigme();
    virtual void resolutionEnigme();
};

#endif // ENIGME_LUMIERE_H