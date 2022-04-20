#include "..\include\EnigmeMelodie.h"

EnigmeMelodie::EnigmeMelodie(Afficher *ecran, std::vector<char> vecteurRef, Bouton *bA, Bouton *bB, Bouton *bC) : Enigme::Enigme(ecran)
{
    this->vectMelodieRef = vecteurRef;
    this->texteEnigme = "Laisse toi porter par la musique bb";
    this->boutonA = bA;
    this->boutonB = bB;
    this->boutonC = bC;
}

void EnigmeMelodie::poserEnigme()
{
    this->ecran->clearEcran();
    this->ecran->printlnEcran(this->texteEnigme);
}

void EnigmeMelodie::resolutionEnigme()
{
    bool enigme_validee = false;
    bool acquisition = false;
    bool en_attente = true ;
    std::vector<char> vecteur_test;
    std::vector<char>::iterator it_ref;
    it_ref = this->vectMelodieRef.begin();

    while (!enigme_validee)
    {
        // Acquisition d'un bouton si tous les boutons sont relâchés
        if (en_attente == true)
        {
            if (this->boutonA->acquisition().entier != 0)
            { // appui bouton A
                vecteur_test.push_back('A');
                acquisition = true;
                en_attente = false;
            }
            else if (this->boutonB->acquisition().entier != 0)
            { // appui bouton B
                vecteur_test.push_back('B');
                acquisition = true;
                en_attente = false;
            }
            else if (this->boutonC->acquisition().entier != 0)
            { // appui bouton C
                vecteur_test.push_back('C');
                acquisition = true;
                en_attente = false;
            }
        }
        else
        {
            if (this->boutonA->acquisition().entier == 0 && this->boutonB->acquisition().entier == 0 && this->boutonC->acquisition().entier == 0)
            {
                en_attente = true;
            }
        }

        // Si acquisition, il faut comparer avec la mélodie de référence
        if (acquisition)
        {
            acquisition = false;
            if (*vecteur_test.end() == *it_ref)
            {
                it_ref++; // Pas d'erreur : on attend la prochaine acquisition
            }
            else
            {
                // Il y a eu erreur -> réinitialisation
                it_ref = this->vectMelodieRef.begin();
                vecteur_test.clear();
                this->jouerMelodie();
            }

            if (it_ref == this->vectMelodieRef.end())
            {
                enigme_validee = true; // Fin de la mélodie atteinte -> énigme validée
            }
        }
    }
}