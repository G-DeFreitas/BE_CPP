#ifndef AFFICHER_H
#define AFFICHER_H
#include "SeeedOLED.h"
#include "Actionneur.h"
#include <string>
class Afficher : public Actionneur
{
private:
    SeeedOLED ecran;
    int cursorX;
    int cursorY; // horizontal
public:
    /*
    Usage       : Créé un écran et initialise le curseur
    Testé       : Ok 11/04
    */
    Afficher();

    /*
    Usage       : Initialisation de l'écran
    Testé       : Ok 11/04
    */
    void initEcran();

    /*
    Usage       : Flush de l'écran
    Testé       : Ok 11/04
    */
    void clearEcran();

    /*
    Usage       : Affiche 256 caractères ASCII standards max sur l'écran OLED. Termine par un retour chariot
    Testé       : Ok 11/04
    */
    void printlnEcran(std::string s);
    /*
    Usage       : Affiche 256 caractères ASCII standards max sur l'écran OLED.
    Testé       : Ok 11/04
    */
    void printEcran(std::string s);
    /*
    Usage       : Place le caractere aux coordonnées Row (X) et Column (Y) sur l'écran
    Testé       : Ok 24/04
    */
    void putCharXY(unsigned char Row, unsigned char Column, char caractere);
};

#endif // AFFICHER_H