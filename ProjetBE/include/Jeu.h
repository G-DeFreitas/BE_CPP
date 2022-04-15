#ifndef JEU_H
#define JEU_H

#include <vector>
#include <map>
#include <string>
#include "Enigme.h"
#include "Capteur.h"
#include "Actionneur.h"

class Jeu
{
public: //changer a private
    std::map<std::string,Capteur*> ensembleCapteur;
    std::map<std::string,Actionneur*> ensembleActionneur;
    std::map<int,Enigme*> listeEnigme; // changé de vector à map pour des raisons de visibilité de la classe fille lors de l'appel de methodes virtuelles
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

    /*
    Usage       : Destructeur des elements dynamiquements alloués (ensembleCapteur)
    Testé       : Intestable
    */
    ~Jeu();
};

#endif // JEU_H