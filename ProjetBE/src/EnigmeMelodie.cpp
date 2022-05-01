#include "..\include\EnigmeMelodie.h"

EnigmeMelodie::EnigmeMelodie(Afficher *ecran, std::vector<char> vecteurRef, Bouton *bA, Bouton *bB, Bouton *bX, Bouton *bY, Buzzer *buzz, std::string texte) : Enigme::Enigme(ecran, texte)
{
    this->vectMelodieRef = vecteurRef;
    this->boutonA = bA;
    this->boutonB = bB;
    this->boutonX = bX;
    this->boutonY = bY;
    this->buzzer = buzz;
}

void EnigmeMelodie::poserEnigme()
{
    this->ecran->clearEcran();
    this->ecran->printlnEcran(this->texteEnigme);
    this->jouerMelodie();
}

void EnigmeMelodie::jouerMelodie()
{
    std::vector<char>::iterator it;
    for (it = this->vectMelodieRef.begin(); it != this->vectMelodieRef.end(); it++)
    {
        if (*it == 'A')
        {
            this->buzzer->jouerNote(NOTE_A);
        }
        else if (*it == 'B')
        {
            this->buzzer->jouerNote(NOTE_B);
        }
        else if (*it == 'X')
        {
            this->buzzer->jouerNote(NOTE_X);
        }
        else // *it == 'Y'
        {
            this->buzzer->jouerNote(NOTE_Y);
        }
    }
}

void EnigmeMelodie::resolutionEnigme()
{
    bool enigmeValidee = false;
    bool acquisition = false;
    bool enAttente = true;
    std::vector<char> vecteur_test;
    std::vector<char>::iterator it_ref, i;
    it_ref = this->vectMelodieRef.begin();

    while (!enigmeValidee)
    {
        // Acquisition d'un bouton si tous les boutons sont relâchés
        if (enAttente == true)
        {
            if (this->boutonA->acquisition().entier != 0)
            { // appui bouton A
                vecteur_test.push_back('A');
                this->buzzer->jouerNote(NOTE_A);
                acquisition = true;
                enAttente = false;
            }
            else if (this->boutonB->acquisition().entier != 0)
            { // appui bouton B
                vecteur_test.push_back('B');
                this->buzzer->jouerNote(NOTE_B);
                acquisition = true;
                enAttente = false;
            }
            else if (this->boutonX->acquisition().entier != 0)
            { // appui bouton X
                vecteur_test.push_back('X');
                this->buzzer->jouerNote(NOTE_X);
                acquisition = true;
                enAttente = false;
            }
            else if (this->boutonY->acquisition().entier != 0)
            { // appui bouton Y
                vecteur_test.push_back('Y');
                this->buzzer->jouerNote(NOTE_Y);
                acquisition = true;
                enAttente = false;
            }
        }
        else
        {
            if (this->boutonA->acquisition().entier == 0 && this->boutonB->acquisition().entier == 0 && this->boutonX->acquisition().entier == 0 && this->boutonY->acquisition().entier == 0)
            {
                enAttente = true;
            }
        }

        // Si acquisition, il faut comparer avec la mélodie de référence
        if (acquisition)
        {
            acquisition = false;

            if (vecteur_test.back() == *it_ref)
            {
                it_ref++; // Pas d'erreur : on attend la prochaine acquisition
            }
            else
            {
                // Il y a eu erreur -> réinitialisation
                it_ref = this->vectMelodieRef.begin();
                vecteur_test.clear();
                delay(200);
                this->jouerMelodie();
            }

            if (it_ref == this->vectMelodieRef.end())
            {
                enigmeValidee = true; // Fin de la mélodie atteinte -> énigme validée
            }
        }
    }

    this->ecran->printlnEcran(" ");
    this->ecran->printlnEcran("Bravo, Enigme 4 terminee");
}