#include "..\include\Jeu.h"
#include "..\include\Bouton.h"
#include "..\include\Pins.h"
#include "..\include\CapteurLuminosite.h"
#include "..\include\Accelerometre.h"
#include "..\include\EnigmeBouton.h"
#include "..\include\EnigmeLumiere.h"
#include "..\include\EnigmeRetourner.h"
#include "..\include\Afficher.h"

#include <Arduino.h>
#include <map>
#include <string>
#include <vector>

#define SEUIL_LUM 15.0

void Jeu::init()
{
    // Inititalisation des capteurs
    Bouton *boutonA = new Bouton(BOUTON_A);
    CapteurLuminosite *capteurLum = new CapteurLuminosite(CAPTEUR_LUM);
    Accelerometre *accelero = new Accelerometre;

    this->ensembleCapteur.insert({"BoutonA", boutonA});
    this->ensembleCapteur.insert({"CapteurLum", capteurLum});
    this->ensembleCapteur.insert({"Accelero", accelero});

    //Initialisation de l'accelerometre
    accelero->initAccelerometre();

    // Initialisation des actionneurs
    Afficher *ecran = new Afficher();

    this->ensembleActionneur.insert({"Ecran", ecran});
    // Initialisation des Enigmes
    EnigmeBouton *enEchauffement = new EnigmeBouton(ecran, boutonA);
    EnigmeLumiere *enLumos = new EnigmeLumiere(ecran, capteurLum, SEUIL_LUM);
    EnigmeRetourner *enRetourner = new EnigmeRetourner(ecran, accelero);

    this->listeEnigme.insert({0, enEchauffement});
    this->listeEnigme.insert({1, enLumos});
    this->listeEnigme.insert({2, enRetourner});

    //Initialisation de l'ecran
    ecran->initEcran();
    ecran->clearEcran();

}

void Jeu::loop()
{
}

Jeu::~Jeu()
{
    std::map<std::string, Capteur *>::iterator it, it2;
    for (it = this->ensembleCapteur.begin(); it != this->ensembleCapteur.end(); it++)
    {
        it2 = it;
        delete it2->second;
        this->ensembleCapteur.erase(it2);
    }

    std::map<std::string, Actionneur *>::iterator it3, it4;
    for (it3 = this->ensembleActionneur.begin(); it3 != this->ensembleActionneur.end(); it3++)
    {
        it4 = it3;
        delete it4->second;
        this->ensembleActionneur.erase(it4);
    }
}