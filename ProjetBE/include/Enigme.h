#ifndef ENIGME_H
#define ENIGME_H

#include "Afficher.h"

#include <string>

class Enigme
{
private:
    static int nbEnigmes;

protected:
    Afficher *ecran;
    std::string texteEnigme;

public:
    virtual void poserEnigme() = 0;
    virtual void resolutionEnigme() = 0;

public:
    /*
    Usage  : Incrémente la Variable nbEnigmes et donne la ref de l'affichage
    Testé  : Non
    */
    Enigme(Afficher *ecran);

    /*
    Usage  : Décrémente la Variable nbEnigmes
    Testé  : Non
    */
    ~Enigme();
};

#endif // ENIGME_H