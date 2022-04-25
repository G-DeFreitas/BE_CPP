#include "..\include\EnigmeLabyrinthe.h"
#include <string>

EnigmeLabyrinthe::EnigmeLabyrinthe(Afficher *ecran, Bouton *bA, Bouton *bB, Bouton *bX, Bouton *bY, std::string texte, std::string laby) : Enigme::Enigme(ecran, texte)
{
    this->boutonA = bA;
    this->boutonB = bB;
    this->boutonX = bX;
    this->boutonY = bY;
    this->labyrinthe = laby;
}

void EnigmeLabyrinthe::poserEnigme()
{
    this->ecran->clearEcran();
    this->ecran->printlnEcran(this->texteEnigme);
    this->ecran->printlnEcran(this->labyrinthe);
    this->posX = X_INIT;
    this->posY = Y_INIT;
    this->ecran->putCharXY(this->posX, this->posY, 'o');
}

void EnigmeLabyrinthe::resolutionEnigme()
{
    bool enigme_validee = false;
    bool acquisition = false;
    bool en_attente = true;
    int dX = 0;
    int dY = 0;

    while (!enigme_validee)
    {
        yield();
        if (en_attente == true)
        {
            if (this->boutonA->acquisition().entier != 0) // appui bouton A
            {
                if ((this->posY + 1 < COLONNE_MAX) && this->caseEstLibre(0, 1)) // déplacement possible
                {
                    dY = 1;
                    acquisition = true;
                    en_attente = false;
                }
            }
            else if (this->boutonB->acquisition().entier != 0) // appui bouton B
            {
                if ((this->posX + 1 < LIGNE_MAX) && this->caseEstLibre(1, 0)) // déplacement possible
                {
                    dX = 1;
                    acquisition = true;
                    en_attente = false;
                }
            }
            else if (this->boutonX->acquisition().entier != 0) // appui bouton X
            {
                if ((this->posX - 1 >= 0) && this->caseEstLibre(-1, 0)) // déplacement possible
                {
                    dX = -1;
                    acquisition = true;
                    en_attente = false;
                }
            }
            else if (this->boutonY->acquisition().entier != 0) // appui bouton Y
            {
                if ((this->posY - 1 >= 0) && this->caseEstLibre(0, -1)) // déplacement possible
                {
                    dY = -1;
                    acquisition = true;
                    en_attente = false;
                }
            }
        }
        else // en_attente == false
        {
            if (this->boutonA->acquisition().entier == 0 && this->boutonB->acquisition().entier == 0 && this->boutonX->acquisition().entier == 0 && this->boutonY->acquisition().entier == 0)
            {
                en_attente = true;
            }
        }

        // Si acquisition, il faut incrémenter la position et afficher le nouveau labyrinthe
        if (acquisition)
        {
            acquisition = false;
            this->ecran->putCharXY(this->posX, this->posY, ' ');
            this->posX += dX;
            this->posY += dY;
            dX = 0;
            dY = 0;
            this->ecran->putCharXY(this->posX, this->posY, 'o');

            if (this->posX == X_SORTIE && this->posY == Y_SORTIE) // le joueur a atteint la sortie
            {
                delay(400);
                enigme_validee = true;
            }
        }
    }
    this->ecran->clearEcran();
    this->ecran->printlnEcran("Bravo, Enigme Labyrinthe terminee");
}

bool EnigmeLabyrinthe::caseEstLibre(int dX, int dY)
{
    bool caseLibre = 0;
    if (dY == 0)
    {
        caseLibre = (this->labyrinthe[(this->posX - 2 + dX) * COLONNE_MAX + this->posY] == ' ') ? true : false;
    }
    else if (dX == 0)
    {
        caseLibre = (this->labyrinthe[(this->posX - 2) * COLONNE_MAX + this->posY + dY] == ' ') ? true : false;
    }
    else // n'est pas censé arriver
    {
        Serial.print("Probleme EnigmeLabyrinthe.cpp : methode caseEstLibre()");
        exit(-1);
    }
    return caseLibre;
}