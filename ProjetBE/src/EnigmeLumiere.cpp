#include "..\include\EnigmeLumiere.h"
#include "..\include\Pins.h"
#include "..\include\data.h"
#include <string>
#include <Arduino.h>
#include <iostream> // A supprimer une fois mise en place de l'écran

EnigmeLumiere::EnigmeLumiere(Afficher *ecran, CapteurLuminosite *captLum, float seuilLum) : Enigme::Enigme(ecran)
{
    this->capteurLum = captLum;
    this->texteEnigme = "Je suis si présente dans ta vie que tu ne me remarques que quand je suis absente. Sans moi, tes peurs resurgissent...  Chasse mon ennemi pour avancer !";
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
        if (valeurCapteur.flottant >= this->seuilLuminosite)
        {
            enigme_validee = true; // Inverser inégalité pour après, mais plus facile à tester comme ça
        }
    }
    this->ecran->printlnEcran(" ");
    this->ecran->printlnEcran("Houra En 2 terminee");
}