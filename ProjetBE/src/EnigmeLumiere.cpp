#include "..\include\EnigmeLumiere.h"
#include "..\include\Pins.h"
#include <string>
#include <Arduino.h>
#include <iostream> // A supprimer une fois mise en place de l'écran

EnigmeLumiere::EnigmeLumiere(CapteurLuminosite *captLum, float seuilLum) : Enigme::Enigme()
{
    this->capteurLum = captLum;
    // this->texteEnigme = "Je suis si présente dans ta vie que tu ne me remarques que quand je suis absente. Sans moi, tes peurs resurgissent...  Chasse mon ennemi pour avancer !";
    this->texteEnigme = "Attention, lancement Enigme Lumiere" ;
    this->seuilLuminosite = seuilLum;
}

void EnigmeLumiere::poserEnigme()
{
    std::cout << this->texteEnigme << std::endl << std::flush ; // A remplacer par printlnEcran
}

void EnigmeLumiere::resolutionEnigme()
{
    int valeurCapteur;
    float resistanceCapteur;
    bool enigme_validee = false;
    while (!enigme_validee)
    {
        valeurCapteur = analogRead(CAPTEUR_LUM);
        resistanceCapteur = (float)(1023 - valeurCapteur) * 10 / valeurCapteur;
        if (resistanceCapteur >= this->seuilLuminosite)
        {
            enigme_validee = true; // Inverser inégalité pour après, mais plus facile à tester comme ça
        }
    }
    std::cout << "HOURRA" << std::endl << std::flush  ;
}