#include "..\include\Enigme.h"
#include "..\include\Afficher.h"
#include <string>

Enigme::Enigme(Afficher *ecran, std::string texte)
{
    this->ecran = ecran;
    this->texteEnigme = texte;
    nbEnigmes++;
}

Enigme::~Enigme()
{
    nbEnigmes--;
}

int Enigme::nbEnigmes = 0;