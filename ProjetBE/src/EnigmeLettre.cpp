#include "..\include\EnigmeLettre.h"
#include <string>

EnigmeLettre::EnigmeLettre(Afficher *ecran, Bouton *bA, Bouton *bB, Bouton *bX, Bouton *bY, std::string texte, std::string phrase, std::vector<int> vectLettre) : Enigme::Enigme(ecran, texte)
{
    this->boutonA = bA;
    this->boutonB = bB;
    this->boutonX = bX;
    this->boutonY = bY;
    this->phrase = phrase;
    for (int i = 0; i < vectLettre.size(); i++)
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
    this->posX = X_INIT;
    this->posY = Y_INIT;
}

void EnigmeLettre::resolutionEnigme()
{
    bool enigme_validee = false;
    bool acquisition = false;
    bool en_attente = true;
    int dX = 0;
    int dY = 0;
    std::map<int, char>::iterator it;
    char caractere = 'A';

    while (!enigme_validee)
    {
        for (char i = 'A'; i < 'z'; i++)
        {
            // Chercher s'il y a i dans la map des lettres à trouver
        //     if (this->lettre.find(i) == this->lettre.end())
        //     {
        //         break; // cette lettre n'est pas à chercher
        //     }
        }
        
        
    }
    
    // while (this->boutonA->acquisition().entier == 0)
    // {
    // }
    // this->ecran->printlnEcran(" ");
    // this->ecran->printlnEcran("Bravo, EnigmeLettre terminee");
}