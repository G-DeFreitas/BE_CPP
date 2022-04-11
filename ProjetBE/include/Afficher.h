#ifndef AFFICHER_H
#define AFFICHER_H
#include "SeeedOLED.h"
#include <string>
class Afficher
{
private:
    SeeedOLED ecran;
    int cursorX;
    int cursorY; //horizontale
public:

    /*
    Usage       : Cree un écran et initialise le curseur
    Testé       : Ok 11/04
    */
    Afficher();

    /*
    Usage       : Initialisation de l'Ecran
    Testé       : Ok 11/04
    */
    void initEcran();

    /*
    Usage       : Flush de l'ecran
    Testé       : Ok 11/04
    */
    void clearEcran();

    /*
    Usage       : Affiche 256 caractères ASCII standards max sur l'ecran OLED. Termine par un retour chariot
    Testé       : Ok 11/04
    */
    void printlnEcran(std::string s);
    /*
    Usage       : Affiche 256 caractères ASCII standards max sur l'ecran OLED.
    Testé       : Ok 11/04
    */
    void printEcran(std::string s);
};

#endif // AFFICHER_H