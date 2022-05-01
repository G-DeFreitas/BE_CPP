#include "..\include\EnigmeLettre.h"
#include <string>

EnigmeLettre::EnigmeLettre(Afficher *ecran, Bouton *bA, Bouton *bB, Bouton *bX, Bouton *bY, std::string texte, std::string phrase, std::vector<int> vectLettre) : Enigme::Enigme(ecran, texte)
{
    this->boutonA = bA;
    this->boutonB = bB;
    this->boutonX = bX;
    this->boutonY = bY;
    this->phraseRef = phrase;
    for (unsigned int i = 0; i < vectLettre.size(); i++)
    {
        this->lettre.insert({vectLettre[i], this->phraseRef[vectLettre[i]]});
        this->phraseRef[vectLettre[i]] = '_';
    }
}

void EnigmeLettre::poserEnigme()
{
    std::string ligne, phrase;
    int i;
    this->ecran->clearEcran();
    phrase = this->phraseRef;
    this->phraseAffichee = "";
    while (phrase.length() > 14)
    {
        i = 0;
        while (phrase[13 - i] != ' ' && (13 - i) > 0)
        {
            i++;
        }
        if ((13 - i) == 0) // Mot plus long que 14 caractères, on coupe en plusieurs lignes
        {
            i = 0;
        }
        ligne = phrase.substr(0, 14 - i);
        phrase = phrase.substr(14 - i, phrase.length() - (14 - i));
        this->phraseAffichee = this->phraseAffichee + ' ' + ligne + ' ';
        while (this->phraseAffichee.length() % 16 != 0)
        {
            this->phraseAffichee += ' ';
        }
        this->phraseAffichee += "                ";
    }
    this->phraseAffichee = this->phraseAffichee + ' ' + phrase + ' ';
    while (this->phraseAffichee.length() % 256 != 0)
    {
        this->phraseAffichee += ' ';
    }
    this->ecran->printlnEcran(this->phraseAffichee);
}

void EnigmeLettre::resolutionEnigme()
{
    bool enigmeValidee = false;
    bool lettreManquante;
    unsigned int nbLettre = 0; // indique le nombre de lettre manquantes trouvées
    std::map<int, char>::iterator it;
    char caractere = 'A';

    while (!enigmeValidee)
    {
        lettreManquante = false;

        // Algo de recherche : est-ce que le caractère actuel est dans la liste des lettres manquantes ?
        for (it = this->lettre.begin(); it != this->lettre.end(); it++)
        {
            if (it->second == caractere)
            {
                lettreManquante = true;
            }
        }

        if (lettreManquante)
        {
            nbLettre++;
            // Attendre que tous les boutons soient relâchés pour avancer
            // Comme appel à une fonction extérieure, gestion des fronts compliquée
            while ((this->boutonA->acquisition().entier != 0) || (this->boutonB->acquisition().entier != 0) || (this->boutonX->acquisition().entier != 0) || (this->boutonY->acquisition().entier != 0))
            {
            }
            placementLettre(caractere);

            if (nbLettre == this->lettre.size())
            {
                enigmeValidee = true;
            }
        }
        caractere++;
    }
}

void EnigmeLettre::placementLettre(char caractere)
{
    bool acquisition = false;
    bool enAttente = true;
    bool lettreOk = false;
    int dX = 0;
    int dY = 0;

    this->posX = X_INIT_LETTRE;
    this->posY = Y_INIT_LETTRE;
    this->ecran->putCharXY(this->posX, this->posY, caractere);
    while (!lettreOk)
    {
        yield();
        if (enAttente == true)
        {
            if (this->boutonA->acquisition().entier != 0) // appui bouton A
            {
                if ((this->posY + 1 < 16) && this->caseEstLibre(0, 1)) // déplacement possible
                {
                    dY = 1;
                    acquisition = true;
                    enAttente = false;
                }
            }
            else if (this->boutonB->acquisition().entier != 0) // appui bouton B
            {
                if ((this->posX + 1 < 16) && this->caseEstLibre(1, 0)) // déplacement possible
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

        if (acquisition)
        {
            lettreOk = true;
        }
    }
}

bool EnigmeLettre::caseEstLibre(int dX, int dY)
{
    bool caseLibre = 0;
    // if (dY == 0)
    // {
    //     caseLibre = (this->labyrinthe[(this->posX - 2 + dX) * COLONNE_MAX + this->posY] == ' ') ? true : false;
    // }
    // else if (dX == 0)
    // {
    //     caseLibre = (this->labyrinthe[(this->posX - 2) * COLONNE_MAX + this->posY + dY] == ' ') ? true : false;
    // }
    // else // n'est pas censé arriver
    // {
    //     Serial.print("Probleme EnigmeLabyrinthe.cpp : methode caseEstLibre()");
    //     exit(-1);
    // }
    return true;
}