#include "..\include\EnigmeInitiale.h"
#include "..\include\Afficher.h"
#include "..\include\Enigme.h"
#include "..\include\Bouton.h"

#include <Arduino.h>
#include <string>

EnigmeInitiale::EnigmeInitiale(Afficher *ecran, Bouton *b, Buzzer *buzz, std::string texte) : Enigme::Enigme(ecran, texte)
{
    this->bouton = b;
    this->buzzer = buzz;
}

void EnigmeInitiale::poserEnigme()
{
    this->buzzer->jouerNote(0);
    this->ecran->clearEcran();
    this->ecran->printlnEcran(this->texteEnigme);
}

void EnigmeInitiale::resolutionEnigme()
{
    while (this->bouton->acquisition().entier == 0)
    {
    }
    this->ecran->printlnEcran(" ");
    this->ecran->printlnEcran("Votre partie va bientot demarrer...");
}