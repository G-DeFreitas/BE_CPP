#include "../include/EnigmeBouton.h"
#include "..\include\Afficher.h"
#include "..\include\Enigme.h"
#include "..\include\Bouton.h"

#include <string>

EnigmeBouton::EnigmeBouton(Afficher *ecran, Bouton *b, std::string texte) : Enigme::Enigme(ecran, texte)
{
    this->bouton = b;
}

void EnigmeBouton::poserEnigme()
{
    this->ecran->clearEcran();
    this->ecran->printlnEcran(this->texteEnigme);
}

void EnigmeBouton::resolutionEnigme()
{
    while (this->bouton->acquisition().entier == 0)
    {
    }
    this->ecran->printlnEcran(" ");
    this->ecran->printlnEcran("Hmmm... ZZZ... ZZZ... ZZZ...");
}