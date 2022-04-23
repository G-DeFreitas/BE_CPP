#include "..\include\EnigmeLabyrinthe.h"

EnigmeLabyrinthe::EnigmeLabyrinthe(Afficher *ecran, Bouton *bA, Bouton *bB, Bouton *bC, Bouton *bD, std::string texte, std::string laby) : Enigme::Enigme(ecran, texte)
{
    this->boutonA = bA;
    this->boutonB = bB;
    this->boutonC = bC;
    this->boutonD = bD;
    this->labyrinthe = laby;
    this->posX = 1;
    this->posY = 0;
}

void EnigmeLabyrinthe::poserEnigme()
{
    this->ecran->clearEcran();
    this->ecran->printlnEcran(this->texteEnigme + this->labyrinthe);
}

void EnigmeLabyrinthe::resolutionEnigme()
{
    while (this->boutonA->acquisition().entier == 0)
    {
    }
}