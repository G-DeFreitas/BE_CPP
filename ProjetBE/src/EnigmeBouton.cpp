#include "../include/EnigmeBouton.h"
#include <string>
#include "..\include\Afficher.h"
#include "..\include\Enigme.h"
#include "..\include\Bouton.h"

#include <Arduino.h>
#include "user_interface.h"

EnigmeBouton::EnigmeBouton(Afficher *ecran, Bouton *b) : Enigme::Enigme(ecran)
{
    this->bouton = b;
    this->texteEnigme = "Comme echauffement, un test de coordination. Une simple pression, sur le front, c'est tout ce qu'il faut pour vérifier ta cognition";
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
    this->ecran->clearEcran();
    this->ecran->printlnEcran("Houra En 1 terminee");
}