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
    this->ecran->clearEcran();
    this->preparerEnigme();
    this->ecran->printlnEcran(this->phraseAffichee);
}

void EnigmeLettre::preparerEnigme()
{
    int i;
    std::string ligne, phrase;
    phrase = this->phraseRef;  // Phrase de référence avec des _ pour les lettres manquantes
    this->phraseAffichee = ""; // Phrase formatée qui sera affichée

    /* Formatage de l'affichage -> on veut :
    - 14 caractères par lignes pour laisser un espace au début et à la fin
    - sauter une ligne entre deux lignes pour permettre le déplacement du caractère
    - un mot est affiché sur une ligne et non coupé entre deux */
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
            this->phraseAffichee += ' '; // combler une ligne avec des espaces
        }
        this->phraseAffichee += "                "; // Ligne libre, 16 caractères espaces
    }
    this->phraseAffichee = this->phraseAffichee + ' ' + phrase + ' ';
    while (this->phraseAffichee.length() % 256 != 0)
    {
        this->phraseAffichee += ' '; // combler jusqu'à la fin de l'écran, ici 256 caractères
    }

    /* Mise à jour de la table des solutions :
    à chaque _ affiché sur l'écran correspond une position entre 0 et 256
    la première lettre manquante correspond à la première entrée dans la map lettre 
    à chaque caractère, on fait correspondre l'emplacement sur l'écran */
    std::map<int, char>::iterator it;
    it = this->lettre.begin();
    for (unsigned int i = 0; i < this->phraseAffichee.length(); i++)
    {
        if (this->phraseAffichee[i] == '_')
        {
            this->solution.insert({it->second, i});
            it++;
        }
    }
}

void EnigmeLettre::resolutionEnigme()
{
    bool enigmeValidee = false;
    bool lettreManquante;
    unsigned int nbLettre = 0; // indique le nombre de lettre manquantes trouvées
    char caractere = 'A';
    std::map<int, char>::iterator it;
    std::string phraseAcompleter = this->phraseRef;

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
    delay(4000);
    this->ecran->clearEcran();
    this->ecran->printlnEcran("Rhoo c'est pas  vrai, je vais   me recoucher, jete raconte      l'histoire du   mouton et de la chevre aussi,   plus tard ");
    delay(5000);
}

void EnigmeLettre::placementLettre(char caractere)
{
    bool acquisition = false;
    bool enAttente = true;
    bool lettreOk = false;
    bool verifierPosition = false;
    int8_t dX = 0;
    int8_t dY = 0;

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
            acquisition = false;
            this->ecran->putCharXY(this->posX, this->posY, ' ');
            this->posX += dX;
            this->posY += dY;

            // Le caractère se trouve sur une lettre manquante, lance le processus de vérification
            if (this->phraseAffichee[(this->posX) * 16 + this->posY] == '_')
            {
                verifierPosition = true;
            }
            dX = 0;
            dY = 0;
            this->ecran->putCharXY(this->posX, this->posY, caractere);
        }

        if (verifierPosition)
        {
            verifierPosition = false;
            delay(200);

            // La position actuelle correspond à la solution, on passe à la prochaine lettre
            if ((this->posX * 16 + this->posY) == this->solution.find(caractere)->second)
            {
                lettreOk = true;
                this->phraseAffichee[this->posX * 16 + this->posY] = caractere;
            }
            // La position actuelle n'est pas bonne, on remet le caractère à sa place initiale
            else
            {
                this->ecran->putCharXY(this->posX, this->posY, '_');
                this->posX = X_INIT_LETTRE;
                this->posY = Y_INIT_LETTRE;
                this->ecran->putCharXY(this->posX, this->posY, caractere);
            }
        }
    }
}

bool EnigmeLettre::caseEstLibre(int8_t dX, int8_t dY)
{
    bool caseLibre = 0;
    if (dY == 0)
    {
        caseLibre = (this->phraseAffichee[(this->posX + dX) * 16 + this->posY] == ' ' || this->phraseAffichee[(this->posX + dX) * 16 + this->posY] == '_') ? true : false;
    }
    else if (dX == 0)
    {
        caseLibre = (this->phraseAffichee[(this->posX) * 16 + this->posY + dY] == ' ' || this->phraseAffichee[(this->posX) * 16 + this->posY + dY] == '_') ? true : false;
    }
    else // n'est pas censé arriver
    {
        Serial.print("Probleme EnigmeLettre.cpp : methode caseEstLibre()");
        exit(-1);
    }
    return caseLibre;
}