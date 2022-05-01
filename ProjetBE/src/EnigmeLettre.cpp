#include "..\include\EnigmeLettre.h"
#include <string>

EnigmeLettre::EnigmeLettre(Afficher *ecran, Bouton *bA, Bouton *bB, Bouton *bX, Bouton *bY, std::string texte, std::string phrase, std::vector<int> vectLettre) : Enigme::Enigme(ecran, texte)
{
    this->boutonA = bA;
    this->boutonB = bB;
    this->boutonX = bX;
    this->boutonY = bY;
    this->phrase = phrase;
    for (unsigned int i = 0; i < vectLettre.size(); i++)
    {
        this->lettre.insert({vectLettre[i], this->phrase[vectLettre[i]]});
        this->phrase[vectLettre[i]] = '_';
    }
}

void EnigmeLettre::poserEnigme()
{
    std::string ligne;
    int i;
    this->ecran->clearEcran();
    while (this->phrase.length() > 14)
    {
        i = 0;
        while (this->phrase[13 - i] != ' ' && (13 - i) > 0)
        {
            i++;
        }
        if ((13 - i) == 0) // Mot plus long que 14 caractères, on coupe en plusieurs lignes
        {
            i = 0;
        }
        ligne = this->phrase.substr(0, 14 - i);
        this->phrase = this->phrase.substr(14 - i, this->phrase.length() - (14 - i));
        this->ecran->printlnEcran(' ' + ligne + ' ');
        this->ecran->printlnEcran("");
    }
    this->ecran->printlnEcran(' ' + this->phrase + ' ');
    this->ecran->printlnEcran("");
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
            // le caractère est à chercher : on n'incrémente pas immédiatement au cas où il faudrait
            // chercher deux fois le même caractère
            nbLettre++;
            Serial.println(caractere);
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

    Serial.println("PlacementLettre");

    this->posX = X_INIT_LETTRE;
    this->posY = Y_INIT_LETTRE;
    this->ecran->putCharXY(this->posX, this->posY, caractere);
    while (!lettreOk)
    {
        yield();
        if(enAttente)
        {
            if(this->boutonA->acquisition().entier != 0)
            {
                enAttente = false;
                acquisition = true;
            }
        }
        else
        {
            if (this->boutonA->acquisition().entier == 0)
            {
                enAttente = true;
            }
            
        }

        if(acquisition)
        {
            lettreOk = true;
        }
    }
    delay(300);
}