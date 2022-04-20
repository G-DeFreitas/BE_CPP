#include "..\include\EnigmeRetourner.h"
#include "..\include\Pins.h"
#include "..\include\data.h"
#include <string>
#include <Arduino.h>

EnigmeRetourner::EnigmeRetourner(Afficher *ecran, Accelerometre *accelero) : Enigme::Enigme(ecran)
{
    this->accelero = accelero;
    this->texteEnigme = "Une enigme mieux doit être écrite mais le but est de retourner la boite";
}

void EnigmeRetourner::poserEnigme()
{
    this->ecran->clearEcran();
    this->ecran->printlnEcran(this->texteEnigme);
}

void EnigmeRetourner::resolutionEnigme()
{
    data valeurCapteur;
    bool enigme_validee = false;
    while (!enigme_validee)
    {
        valeurCapteur = this->accelero->acquisition();
        if ((valeurCapteur.tab_float[0] > SEUIL_INF_1) && (valeurCapteur.tab_float[0] < SEUIL_SUP_1) && (valeurCapteur.tab_float[1] > SEUIL_INF_2) && (valeurCapteur.tab_float[1] < SEUIL_SUP_2) )
        {
            enigme_validee = true; // la boite a été retournée
        }
    }
    this->ecran->printlnEcran(" ");
    this->ecran->printlnEcran("Bravo, Enigme retournagationement terminee");
}