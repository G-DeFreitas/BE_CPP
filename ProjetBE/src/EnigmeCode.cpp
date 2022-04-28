#include "..\include\EnigmeCode.h"

EnigmeCode::EnigmeCode(Afficher *ecran, char code[4], Bouton *bA, Bouton *bB, Bouton *bX, Bouton *bY, std::string texte) : Enigme::Enigme(ecran, texte)
{
    this->boutonA = bA;
    this->boutonB = bB;
    this->boutonX = bX;
    this->boutonY = bY;
    for (int i = 0; i < 4; i++)
    {
        this->codeRef[i] = code[i];
    }
}

void EnigmeCode::afficherCode()
{
    this->ecran->putCharXY(LIGNE_CODE, 3, this->code[0]);
    this->ecran->putCharXY(LIGNE_CODE, 6, this->code[1]);
    this->ecran->putCharXY(LIGNE_CODE, 9, this->code[2]);
    this->ecran->putCharXY(LIGNE_CODE, 12, this->code[3]);
    this->ecran->putCharXY(LIGNE_CODE + 1, 3 * (this->selection) + 3, '^');
}

void EnigmeCode::poserEnigme()
{
    this->ecran->clearEcran();
    this->ecran->printlnEcran(this->texteEnigme);
    this->code[0] = '0';
    this->code[1] = '0';
    this->code[2] = '0';
    this->code[3] = '0';
    this->selection = 0;
    this->afficherCode();
}

void EnigmeCode::resolutionEnigme()
{
    int dS = 0;
    bool testCode;
    bool enigme_validee = false;
    bool acquisition = false;
    bool en_attente = true;

    while (!enigme_validee)
    {
        yield();
        if (en_attente == true)
        {
            if (this->boutonA->acquisition().entier != 0) // appui bouton A
            {
                if (this->selection < 3) // déplacement possible vers la droite
                {
                    acquisition = true;
                    en_attente = false;
                    dS = 1;
                }
            }
            else if (this->boutonB->acquisition().entier != 0) // appui bouton B
            {
                acquisition = true;
                en_attente = false;
                if (this->code[this->selection] > '0') // on décrémente le chiffre sélectionné
                {
                    this->code[this->selection] -= 1;
                }
                else
                {
                    this->code[this->selection] = '9';
                }
            }
            else if (this->boutonX->acquisition().entier != 0) // appui bouton X
            {
                acquisition = true;
                en_attente = false;
                if (this->code[this->selection] < '9') // on incrémente le chiffre sélectionné
                {
                    this->code[this->selection] += 1;
                }
                else
                {
                    this->code[this->selection] = '0';
                }
            }
            else if (this->boutonY->acquisition().entier != 0) // appui bouton Y
            {
                if (this->selection > 0) // déplacement possible vers la gauche
                {
                    acquisition = true;
                    en_attente = false;
                    dS = -1;
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

        // Si acquisition, il faut afficher le nouveau code
        if (acquisition)
        {
            acquisition = false;
            this->ecran->putCharXY(LIGNE_CODE + 1, 3 * (this->selection) + 3, ' ');
            this->selection += dS;
            dS = 0;
            this->afficherCode();

            testCode = (this->code[0] == this->codeRef[0]) && (this->code[1] == this->codeRef[1]) && (this->code[2] == this->codeRef[2]) && (this->code[3] == this->codeRef[3]);

            if (testCode)
            {
                delay(400);
                enigme_validee = true;
            }
        }
    }

    this->ecran->printlnEcran(" ");
    this->ecran->printlnEcran("Ah merci, t'as une meilleure memoire que moi");
}