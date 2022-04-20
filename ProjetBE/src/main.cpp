#include <Arduino.h>
#include "../include/Jeu.h"
#include "../include/Pins.h"
#include "../include/EnigmeMelodie.h"

#include "../include/Afficher.h"
#include "../include/SeeedOLED.h"
#include <string>

#include "../include/EnigmeBouton.h"

// Variables globales
Jeu boiteEnigme;

void setup()
{
  Afficher Aff;
  Serial.begin(9600, SERIAL_8N1);
  Serial.println("-Lancement setup-");
  boiteEnigme.init();
  Serial.println("-Fin setup-");
  // Aff.initEcran();
  // Aff.clearEcran();
  // Aff.printlnEcran("Vous savez, moi, je ne crois pas qu`il y ait de bonne ou de mauvaise situation.Moi, si je devais resumer ma vie aujourd`hui avec vous, je dirais que c`est d`abord des rencontres. Des gens qui m`ont tendu la main, peut-etre a un moment ou je ne pouvais pas, ou j`étais seul chez-moi. Et c`est assez curieux de se dire que les hasards, les rencontres forgent une destinee... Parce que quand on a le goût de la chose, quand on a le goût de la chose bien faite, le beau geste, parfois, on ne trouve pas l`interlocuteur en face, je dirais, le miroir qui vous aide à avancer. Alors ca nest pas mon cas, comme je disais la, puisque moi au contraire, j`ai pu : et je dis merci à la vie,je lui dis merci, je chante la vie, je danse la vie... Je ne suis qu`amour ! Et finalement, quand beaucoup de gens, aujourd`hui, me disent « Mais comment fais-tu pour avoir cette humanité ? » , et bien je leur réponds très simplement, je leur dis que c`est ce gout de l`amour ce gout donc qui m`a poussé aujourd`hui à entreprendre une construction mecanique, mais demain qui sait ? Peut-etre simplement à me mettre au service de la communaute, a faire le don, le don de soi...");
  // boiteEnigme.listeEnigme.find(0)->second->poserEnigme(); //
  // boiteEnigme.listeEnigme.find(0)->second->resolutionEnigme();
  boiteEnigme.listeEnigme.find(1)->second->poserEnigme();
  boiteEnigme.listeEnigme.find(1)->second->resolutionEnigme();
}

void loop()
{
  Serial.println("-Iteration Loop-");
  // Serial.println(boiteEnigme.ensembleCapteur.find("CapteurLum")->second->acquisition().flottant);
  // Clignotement par sécurité
  digitalWrite(LED_BUILTIN, LOW);
  delay(200);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(200);
}