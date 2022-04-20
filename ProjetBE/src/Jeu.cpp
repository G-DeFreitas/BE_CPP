#include "..\include\Jeu.h"
#include "..\include\Bouton.h"
#include "..\include\Pins.h"
#include "..\include\CapteurLuminosite.h"
#include "..\include\Accelerometre.h"
#include "..\include\EnigmeBouton.h"
#include "..\include\EnigmeLumiere.h"
#include "..\include\EnigmeRetourner.h"
#include "..\include\EnigmeMelodie.h"
#include "..\include\Afficher.h"
#include "..\include\Buzzer.h"

#include <Arduino.h>
#include <map>
#include <string>
#include <vector>

#define SEUIL_LUM 15.0

std::vector<char> melodie = {'A', 'A', 'C', 'B', 'A'};

void Jeu::init()
{
    // Inititalisation des capteurs
    Bouton *boutonA = new Bouton(BOUTON_A);
    Bouton *boutonB = new Bouton(BOUTON_B);
    Bouton *boutonC = new Bouton(BOUTON_C);
    CapteurLuminosite *capteurLum = new CapteurLuminosite(CAPTEUR_LUM);
    Accelerometre *accelero = new Accelerometre;

    this->ensembleCapteur.insert({"BoutonA", boutonA});
    this->ensembleCapteur.insert({"BoutonB", boutonB});
    this->ensembleCapteur.insert({"BoutonC", boutonC});
    this->ensembleCapteur.insert({"CapteurLum", capteurLum});
    this->ensembleCapteur.insert({"Accelero", accelero});

    // Initialisation de l'accelerometre
    accelero->initAccelerometre();

    // Initialisation des actionneurs
    Afficher *ecran = new Afficher();
    Buzzer *buzzer = new Buzzer(BUZZER);

    // Initialisation de l'ecran
    ecran->initEcran();
    ecran->clearEcran();

    this->ensembleActionneur.insert({"Ecran", ecran});
    this->ensembleActionneur.insert({"Buzzer", buzzer});

    // Initialisation des Enigmes
    EnigmeBouton *enEchauffement = new EnigmeBouton(ecran, boutonA);
    EnigmeLumiere *enLumos = new EnigmeLumiere(ecran, capteurLum, SEUIL_LUM);
    EnigmeRetourner *enRetourner = new EnigmeRetourner(ecran, accelero);
    EnigmeMelodie *enMelodie = new EnigmeMelodie(ecran, melodie, boutonA, boutonB, boutonC, buzzer);

    this->listeEnigme.insert({0, enEchauffement});
    this->listeEnigme.insert({1, enLumos});
    this->listeEnigme.insert({2, enRetourner});
    this->listeEnigme.insert({3, enMelodie});
}

void Jeu::loop()
{
    std::map<int, Enigme *>::iterator indEnigme;
    for (indEnigme = listeEnigme.begin() ; indEnigme != listeEnigme.end() ; indEnigme++)
    {
        indEnigme->second->poserEnigme();
        indEnigme->second->resolutionEnigme();
        delay(2000);
    }

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