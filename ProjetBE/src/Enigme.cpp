#include "..\include\Enigme.h"
#include "..\include\Afficher.h"
#include <string>

Enigme::Enigme(Afficher *ecran)
{
    this->ecran = ecran;
    nbEnigmes++;
}

Enigme::~Enigme()
{
    nbEnigmes--;
}

int Enigme::nbEnigmes = 0;