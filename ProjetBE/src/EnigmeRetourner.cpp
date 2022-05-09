#include "..\include\EnigmeRetourner.h"
#include "..\include\data.h"
#include <string>
#include <Arduino.h>

EnigmeRetourner::EnigmeRetourner(Afficher *ecran, Accelerometre *accelero, std::string texte) : Enigme::Enigme(ecran, texte)
{
    this->accelero = accelero;
}

void EnigmeRetourner::poserEnigme()
{
    this->ecran->clearEcran();
    this->ecran->printlnEcran(this->texteEnigme);
}

void EnigmeRetourner::resolutionEnigme()
{
    data valeurCapteur;
    bool enigmeValidee = false;
    while (!enigmeValidee)
    {
        valeurCapteur = this->accelero->acquisition();
        if ((valeurCapteur.tab_float[0] > SEUIL_INF_1) && (valeurCapteur.tab_float[0] < SEUIL_SUP_1) && (valeurCapteur.tab_float[1] > SEUIL_INF_2) && (valeurCapteur.tab_float[1] < SEUIL_SUP_2))
        {
            enigmeValidee = true; // la boite a été retournée
        }
    }
    this->ecran->printlnEcran(" ");
    this->ecran->printlnEcran("Ahhh ok ! J'ai  des souvenirs   qui remontent");
}