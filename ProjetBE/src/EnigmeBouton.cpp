#include "../include/EnigmeBouton.h"
#include <string>
#include "Afficher.h"
#include "Enigme.h"
#include "Bouton.h"

#include <Arduino.h>
#include "user_interface.h"

EnigmeBouton::EnigmeBouton(Bouton *b) : Enigme::Enigme()
{
    this->bouton = b;
    this->texteEnigme = "Comme echauffement, un test de coordination. Une simple pression, sur le front, c'est tout ce qu'il faut pour vérifier ta cognition";
}

void EnigmeBouton::poserEnigme()
{
    Afficher Aff;
    Aff.initEcran();
    Aff.clearEcran();
    Aff.printlnEcran(this->texteEnigme);
}

void EnigmeBouton::resolutionEnigme()
{
    while (this->bouton->acquisition().entier == 0)
    {
        Serial.println("Nope");
    }
    Serial.println("Houra");
}