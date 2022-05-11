#include "..\include\Jeu.h"
#include "..\include\Bouton.h"
#include "..\include\Pins.h"
#include "..\include\CapteurLuminosite.h"
#include "..\include\Accelerometre.h"
#include "..\include\EnigmeBouton.h"
#include "..\include\EnigmeLumiere.h"
#include "..\include\EnigmeRetourner.h"
#include "..\include\EnigmeMelodie.h"
#include "..\include\EnigmeLabyrinthe.h"
#include "..\include\EnigmeLettre.h"
#include "..\include\EnigmeCode.h"
#include "..\include\EnigmeInitiale.h"
#include "..\include\Afficher.h"
#include "..\include\Buzzer.h"

#include <Arduino.h>
#include <map>
#include <string>
#include <vector>

#define SEUIL_LUM 15.0
#define L1 "#--------- ----#"
#define L2 "|    - ||-  - ||"
#define L3 "|-- |   |  -|  |"
#define L4 "|   | | -|  |- |"
#define L5 "| |-  |  |-   -|"
#define L6 "| |  |-- |  |  |"
#define L7 "|  | |    --   |"
#define L8 "|- | ---   |- -|"
#define L9 "|      ||  |  ||"
#define L10 "|---   |     |-|"
#define L11 "| | -|  -|---| |"
#define L12 "|    |   |   | |"
#define L13 "| |    |   |   |"
#define L14 "# -------------#"
#define LABY L1 + L2 + L3 + L4 + L5 + L6 + L7 + L8 + L9 + L10 + L11 + L12 + L13 + L14

std::vector<char> melodie = {'Y', 'B', 'X', 'X', 'A', 'B'}; // 130 90 255 255 130 50 90
char code [4] = {'5', '6', '4', '2'};


void Jeu::init()
{
    // Inititalisation des capteurs
    Bouton *boutonA = new Bouton(BOUTON_A);
    Bouton *boutonB = new Bouton(BOUTON_B);
    Bouton *boutonX = new Bouton(BOUTON_X);
    Bouton *boutonY = new Bouton(BOUTON_Y);
    CapteurLuminosite *capteurLum = new CapteurLuminosite(CAPTEUR_LUM);
    Accelerometre *accelero = new Accelerometre;

    this->ensembleCapteur.insert({"BoutonA", boutonA});
    this->ensembleCapteur.insert({"BoutonB", boutonB});
    this->ensembleCapteur.insert({"BoutonX", boutonX});
    this->ensembleCapteur.insert({"BoutonY", boutonY});
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

    std::string texteEnBienvenue = "Allumez le haut-parleur puis    appuyez sur le  bouton Noir pourdemarrer une    nouvelle partie";
    std::string texteEnBouton = "zzz... zzz...       zzz...";
    std::string texteEnLumos = "Hmm... Laisse...dormir... Ouvre pas... volets...";
    std::string texteEnRetourner = "Ou est-ce que jesuis ?  C'est   quoi cet endroitFait voir";
    std::string texteEnMelodie = "Hier soir vous  etes rentre tardet avez perdu   votre ami en finde soiree.      Inquiet, vous   voulez le retrou-ver. Par chancevous entendez   un telephone    sonner ";
    std::string texteEnLaby = " "; // entre 16 et 32 caractères obligatoirement
    std::string texteEnCode = "J'ai un message sur mon portablemais j'arrive   pas a le deverr-ouiller. On a dume changer mon  code hier soir  T'as pas une    idee ? "; 
    std::string phraseEnLettre = "Non, c'est pas possible, depuis le coup de la chevre, c'est mort, je veux plus te voir ";
    std::vector<int> lettres = {12,20,22,36,38,47,49,60,63,84}; //hvopmtbeai

    // Initialisation des Enigmes
    EnigmeInitiale *enBienvenue = new EnigmeInitiale(ecran, boutonA, buzzer, texteEnBienvenue);
    EnigmeBouton *enBouton = new EnigmeBouton(ecran, boutonA, texteEnBouton);
    EnigmeLumiere *enLumos = new EnigmeLumiere(ecran, capteurLum, SEUIL_LUM, texteEnLumos);
    EnigmeRetourner *enRetourner = new EnigmeRetourner(ecran, accelero, texteEnRetourner);
    EnigmeMelodie *enMelodie = new EnigmeMelodie(ecran, melodie, boutonA, boutonB, boutonX, boutonY, buzzer, texteEnMelodie);
    EnigmeLabyrinthe *enLaby = new EnigmeLabyrinthe(ecran, boutonA, boutonB, boutonX, boutonY, texteEnLaby, (std::string)LABY);
    EnigmeCode *enCode = new EnigmeCode(ecran, code, boutonA, boutonB, boutonX, boutonY, texteEnCode);
    EnigmeLettre *enLettre = new EnigmeLettre(ecran, boutonA, boutonB, boutonX, boutonY, "", phraseEnLettre, lettres);

    this->listeEnigme.insert({0, enBienvenue});
    this->listeEnigme.insert({1, enMelodie});
    this->listeEnigme.insert({2, enLaby});
    this->listeEnigme.insert({3, enBouton});
    this->listeEnigme.insert({4, enLumos});
    this->listeEnigme.insert({5, enRetourner});
    this->listeEnigme.insert({6, enCode});
    this->listeEnigme.insert({7, enLettre});

}

void Jeu::loop()
{
    std::map<int, Enigme *>::iterator indEnigme;
    for (indEnigme = listeEnigme.begin(); indEnigme != listeEnigme.end(); indEnigme++)
    {
        indEnigme->second->poserEnigme();
        indEnigme->second->resolutionEnigme();
        delay(10000);
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