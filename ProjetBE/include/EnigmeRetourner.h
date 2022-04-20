#ifndef ENIGME_RETOURNER_H
#define ENIGME_RETOURNER_H

#include "Enigme.h"
#include "Accelerometre.h"
#include "Afficher.h"

#define SEUIL_INF_1 38
#define SEUIL_SUP_1 52

#define SEUIL_INF_2 -52
#define SEUIL_SUP_2 -38

class EnigmeRetourner : public Enigme
{
private:
    Accelerometre *accelero;

public:
    EnigmeRetourner(Afficher *ecran, Accelerometre *accelero);
    virtual void poserEnigme();
    virtual void resolutionEnigme();
};

#endif // ENIGME_RETOURNER_H