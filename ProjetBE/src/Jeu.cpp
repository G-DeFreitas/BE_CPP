#include "..\include\Jeu.h"
#include "..\include\Bouton.h"
#include "..\include\Pins.h"
#include "..\include\EcranOLED.h"
#include <map>
#include <string>

void Jeu::init(){
    Bouton *boutonA = new Bouton(BOUTON_A);
    this->ensembleCapteur.insert({"BoutonA",boutonA}); // Pas sur de la durée de vie

    EcranOLED *ecranOled = new EcranOLED(I2C_SCL, I2C_SDA);
    this->ensembleActionneur.insert({"EcranOled",ecranOled});
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