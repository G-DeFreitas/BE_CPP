#include "..\include\Jeu.h"
#include "..\include\Bouton.h"
#include "..\include\Pins.h"

void Jeu::init(){
    Bouton boutonA(BOUTON_A);
    this->ensembleCapteur.insert({"BoutonA",&boutonA}); // Pas sur de la durée de vie
}

void Jeu::loop(){

}
