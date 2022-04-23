#include "..\include\EnigmeLumiere.h"
#include "..\include\Pins.h"
#include "..\include\data.h"
#include <string>
#include <Arduino.h>

EnigmeLumiere::EnigmeLumiere(Afficher *ecran, CapteurLuminosite *captLum, float seuilLum, std::string texte) : Enigme::Enigme(ecran, texte)
{
    this->capteurLum = captLum;
    this->seuilLuminosite = seuilLum;
}

void EnigmeLumiere::poserEnigme()
{
    this->ecran->clearEcran();
    this->ecran->printlnEcran(this->texteEnigme);
}

void EnigmeLumiere::resolutionEnigme()
{
    data valeurCapteur;
    bool enigme_validee = false;
    while (!enigme_validee)
    {
        valeurCapteur = this->capteurLum->acquisition();
        if (valeurCapteur.flottant <= this->seuilLuminosite)
        {
            enigme_validee = true;
        }
    }
    this->ecran->printlnEcran(" ");
    this->ecran->printlnEcran("Bravo, Enigme 2 terminee");
}