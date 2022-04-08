#ifndef JEU_H
#define JEU_H

#include <vector>
#include <map>
#include <string>
#include "Enigme.h"
#include "Capteur.h"

class Jeu
{
private:
    std::map<std::string,Capteur*> ensembleCapteur;
    std::vector<Enigme> listeEnigme;
    int indexEnigme;

public:
    /*
    Usage       : Initialise le Jeu
    Testé       : Non
    */
    void init();

    /*
    Usage       : Déroulement du Jeu
    Testé       : Non
    */
    void loop();
};

#endif // JEU_H