#include "..\include\Jeu.h"
#include "..\include\Bouton.h"
#include "..\include\Pins.h"
#include <map>
#include <string>

void Jeu::init(){
    Bouton *boutonA = new Bouton(BOUTON_A);
    this->ensembleCapteur.insert({"BoutonA",boutonA}); // Pas sur de la durée de vie
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
}