#include "..\include\EnigmeLabyrinthe.h"
#include <string>

EnigmeLabyrinthe::EnigmeLabyrinthe(Afficher *ecran, Bouton *bA, Bouton *bB, Bouton *bX, Bouton *bY, std::string texte, std::string laby) : Enigme::Enigme(ecran, texte)
{
    this->boutonA = bA;
    this->boutonB = bB;
    this->boutonX = bX;
    this->boutonY = bY;
    this->posX = 13;
    this->posY = 1;
    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; i < COLONNE_MAX; j++)
    //     {
    //         if (i == this->posX && j == this->posY)
    //         {
    //             this->labyrinthe[i][j] = 'o';
    //         }
    //         else
    //         {
    //             this->labyrinthe[i][j] = laby[(COLONNE_MAX * i) + j];
    //         }
    //     }
    // }
}

void EnigmeLabyrinthe::poserEnigme()
{
    this->printLabyrinthe();
}

void EnigmeLabyrinthe::printLabyrinthe()
{
    this->ecran->clearEcran();
    this->ecran->printlnEcran(this->texteEnigme);
    std::string sum;
    for (int i = 0; i < LIGNE_MAX; i++)
    {
        for (int j = 0; j < COLONNE_MAX; j++)
        {
            this->ecran->printEcran(&(this->labyrinthe[i][j]));
        }
        this->ecran->printlnEcran("");
    }
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
        if (en_attente == true)
        {
            if (this->boutonA->acquisition().entier != 0) // appui bouton A
            {
                if ((this->posX + 1 < LIGNE_MAX) && (labyrinthe[this->posX + 1][this->posY] == ' ')) // déplacement possible
                {
                    dX = 1;
                    acquisition = true;
                    en_attente = false;
                }
            }
            else if (this->boutonB->acquisition().entier != 0) // appui bouton B
            {
                if ((this->posY - 1 >= 0) && (labyrinthe[this->posX][this->posY - 1] == ' ')) // déplacement possible
                {
                    dY = -1;
                    acquisition = true;
                    en_attente = false;
                }
            }
            else if (this->boutonX->acquisition().entier != 0) // appui bouton X
            {
                if ((this->posY + 1 < COLONNE_MAX) && (labyrinthe[this->posX][this->posY + 1] == ' ')) // déplacement possible
                {
                    dY = 1;
                    acquisition = true;
                    en_attente = false;
                }
            }
            else if (this->boutonY->acquisition().entier != 0) // appui bouton Y
            {
                if ((this->posX - 1 >= 0) && (labyrinthe[this->posX - 1][this->posY] == ' ')) // déplacement possible
                {
                    dX = -1;
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
            labyrinthe[this->posX][this->posY] = ' ';
            this->posX += dX;
            this->posY += dY;
            this->printLabyrinthe();

            if (this->posX == X_SORTIE && this->posY == Y_SORTIE) // le joueur a atteint la sortie
            {
                enigme_validee = true;
            }
        }
    }

    this->ecran->clearEcran();
    this->ecran->printlnEcran("Bravo, Enigme Labyrinthe terminee");
}