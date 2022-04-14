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
    // while (digitalRead(8)==0){}       //La lecture du GPIO fait un segfault
    // while (GPIO_INPUT_GET(15) ==0){}  //La lecture du GPIO fait un segfault

    /*while (this->bouton->acquisition().entier == 0) // Segfault
    {
    }*/

    /*while (this->bouton->acquisition().entier != 0) // Pas Segfault
    {
    }
    Serial.println("Houra");*/
}