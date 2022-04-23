#include "../include/EnigmeBouton.h"
#include <string>
#include "..\include\Afficher.h"
#include "..\include\Enigme.h"
#include "..\include\Bouton.h"

#include <Arduino.h>
#include "user_interface.h"

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
    this->ecran->printlnEcran("Bravo, Enigme 1 terminee");
}