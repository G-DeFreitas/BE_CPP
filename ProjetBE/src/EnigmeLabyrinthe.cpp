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
    bool enigmeValidee = false;
    bool acquisition = false;
    bool enAttente = true;
    int8_t dX = 0;
    int8_t dY = 0;

    while (!enigmeValidee)
    {
        yield();
        if (enAttente == true)
        {
            if (this->boutonA->acquisition().entier != 0) // appui bouton A
            {
                if ((this->posY + 1 < COLONNE_MAX) && this->caseEstLibre(0, 1)) // déplacement possible
                {
                    dY = 1;
                    acquisition = true;
                    enAttente = false;
                }
            }
            else if (this->boutonB->acquisition().entier != 0) // appui bouton B
            {
                if ((this->posX + 1 < LIGNE_MAX) && this->caseEstLibre(1, 0)) // déplacement possible
                {
                    dX = 1;
                    acquisition = true;
                    enAttente = false;
                }
            }
            else if (this->boutonX->acquisition().entier != 0) // appui bouton X
            {
                if ((this->posX - 1 >= 0) && this->caseEstLibre(-1, 0)) // déplacement possible
                {
                    dX = -1;
                    acquisition = true;
                    enAttente = false;
                }
            }
            else if (this->boutonY->acquisition().entier != 0) // appui bouton Y
            {
                if ((this->posY - 1 >= 0) && this->caseEstLibre(0, -1)) // déplacement possible
                {
                    dY = -1;
                    acquisition = true;
                    enAttente = false;
                }
            }
        }
        else // enAttente == false
        {
            if (this->boutonA->acquisition().entier == 0 && this->boutonB->acquisition().entier == 0 && this->boutonX->acquisition().entier == 0 && this->boutonY->acquisition().entier == 0)
            {
                enAttente = true;
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
                enigmeValidee = true;
            }
        }
    }
    this->ecran->clearEcran();
    this->ecran->printlnEcran("Vous l’apercevez dans la piece, il dort profond-ement, il va     vous falloir le reveiller.");
}

bool EnigmeLabyrinthe::caseEstLibre(int8_t dX, int8_t dY)
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