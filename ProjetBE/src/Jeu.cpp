#include "..\include\Jeu.h"
#include "..\include\Bouton.h"
#include "..\include\Pins.h"
#include "..\include\CapteurLuminosite.h"

#include <Arduino.h>
#include <map>
#include <string>

void Jeu::init(){
    Bouton *boutonA = new Bouton(BOUTON_A);
    this->ensembleCapteur.insert({"BoutonA",boutonA});
    CapteurLuminosite *capteurLum = new CapteurLuminosite(A0);
    this->ensembleCapteur.insert({"CapteurLum",capteurLum}); 
}

void Jeu::loop(){

}

Jeu::~Jeu(){
    std::map<std::string, Capteur*>::iterator it, it2;
    for (it = this->ensembleCapteur.begin(); it != this->ensembleCapteur.end() ; it++)
    {
        it2 = it;
        delete it->second;
        this->ensembleCapteur.erase(it2);
    }

    std::map<std::string, Actionneur*>::iterator it3, it4;
    for (it3 = this->ensembleActionneur.begin(); it3 != this->ensembleActionneur.end() ; it3++)
    {
        it4 = it3;
        delete it3->second;
        this->ensembleActionneur.erase(it4);
    }
}