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
#include "..\include\EnigmeInitiale.h"
#include "..\include\Afficher.h"
#include "..\include\Buzzer.h"

#include <Arduino.h>
#include <map>
#include <string>
#include <vector>

#define SEUIL_LUM 15.0
#define LABY1 "#--------- ----#"
#define LABY2 "|    - ||-  - ||"
#define LABY LABY1+LABY2

std::vector<char> melodie = {'A', 'A', 'C', 'B', 'A'};

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

    std::string texteEnBienvenue = "Appuyez sur le bouton A pour demarrer une nouvelle partie" ;
    std::string texteEnEchauffement = "Comme echauffement, un test de coordination. Une simple pression sur le front, c'est tout ce qu'il faut pour verifier ta cognition";
    std::string texteEnLumos = "Je suis si presente dans ta vie que tu ne me remarques que quand je suis absente. Sans moi, tes peurs resurgissent...  Chasse mon ennemi pour avancer !";
    std::string texteEnRetourner = "Une meilleure enigme doit etre ecrite mais le but est de retourner la boite";
    std::string texteEnMelodie = "Laisse toi porter par la musique bb";
    std::string texteEnLaby = "Aide-moi a sortir de la chambre!"; // 32 caractères obligatoirement

    // std::string laby1 = "#--------- ----#" ;
    // std::string laby2 = "|    - ||-  - ||" ;
    // std::string laby3 = "|-- |   |  -|  |" ;
    // std::string laby4 = "|   | | -|  |- |" ;
    // std::string laby5 = "| |-  |  |-   -|" ;
    // std::string laby6 = "| |  |-- |  |  |" ;
    // std::string laby7 = "|  | |    --   |" ;
    // std::string laby8 = "|- | ---   |- -|" ;
    // std::string laby9 = "|      ||  |  ||" ;
    // std::string laby10= "| |-   |     |-|" ;
    // std::string laby11= "| | -|  -|---| |" ;
    // std::string laby12= "|    |   |   | |" ;
    // std::string laby13= "| |    |   |   |" ;
    // std::string laby14= "# -------------#" ;
    // std::string laby = laby1+laby2+laby3+laby4+laby5+laby6+laby7+laby8+laby9+laby10+laby11+laby12+laby13+laby14;

    // Initialisation des Enigmes
    EnigmeInitiale *enBienvenue = new EnigmeInitiale(ecran, boutonA, buzzer, texteEnBienvenue);
    EnigmeBouton *enEchauffement = new EnigmeBouton(ecran, boutonA, texteEnEchauffement);
    EnigmeLumiere *enLumos = new EnigmeLumiere(ecran, capteurLum, SEUIL_LUM, texteEnLumos);
    EnigmeRetourner *enRetourner = new EnigmeRetourner(ecran, accelero, texteEnRetourner);
    EnigmeMelodie *enMelodie = new EnigmeMelodie(ecran, melodie, boutonA, boutonB, boutonX, buzzer, texteEnMelodie);
    EnigmeLabyrinthe *enLaby = new EnigmeLabyrinthe(ecran, boutonA, boutonB, boutonX, boutonY, texteEnLaby, (std::string) LABY);

    this->listeEnigme.insert({0, enBienvenue});    
    this->listeEnigme.insert({1, enEchauffement});
    this->listeEnigme.insert({2, enLumos});
    this->listeEnigme.insert({3, enRetourner});
    this->listeEnigme.insert({4, enMelodie});
    this->listeEnigme.insert({5, enLaby});
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