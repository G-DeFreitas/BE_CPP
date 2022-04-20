#ifndef ENIGME_LUMIERE_H
#define ENIGME_LUMIERE_H

#include "Enigme.h"
#include "CapteurLuminosite.h"
#include "Afficher.h"

class EnigmeLumiere : public Enigme
{
private:
    CapteurLuminosite *capteurLum;
    float seuilLuminosite;

public:
    /*
    Usage       : Définit le seuil de luminosité du capteur
    Testé       : Ok 20/04
    */
    EnigmeLumiere(Afficher *ecran, CapteurLuminosite *captLum, float seuilLum);

    /*
    Usage       : Pose l'énigme
    Testé       : Ok 20/04
    */
    virtual void poserEnigme();

    /*
    Usage       : L'utilisateur doit allumer la lumière dans la boîte
    Testé       : Ok 20/04
    */
    virtual void resolutionEnigme();
};

#endif // ENIGME_LUMIERE_H