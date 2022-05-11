# BE C++ Badier, De Freitas & Laidet

## Compilation
Nous avons utilisé l'extension platformIO IDE de VSCode, si vous souhaitez l'utiliser il suffit de télécharger les sources et d'ouvrir le répertoire en tant que projet PIO puis de compiler avec PIO.

En utilisant l'IDE Arduino, il faudra veiller à garder les chemins relatifs pour les headers ```..\include\header.h```

## Interaction
- Une fois le projet téléversé, ne pas débrancher la boite (pas de batterie), ne pas ouvrir la boîte.
- Comme indiqué sur l'écran, veillez à avoir le haut-parleur allumé, à savoir l'interrupteur vers le bas.
- Si vous êtes coincés, référez-vous au rapport pour avoir la solution des énigmes.

## Diagramme de classe
![alt text](https://github.com/G-DeFreitas/BE_CPP/blob/main/dclass.png)

### Code planttext du diagramme de Classe
```
@startuml title Boite à enigme - Diagramme de Classe

class Jeu  << principale >> { 
- std::map<std::string,Capteur*> ensembleCapteur
- std::map<std::string,Actionneur*> ensembleActionneur
- std::map<int,Enigme*> listeEnigme
- int indexEnigme
+void init() 
+void loop() 
} 

class Pins << (D,yellow) >> <<definitions>>

abstract class Enigme {
-static int nbEnigmes
#std::string texteEnigme
#virtual void poserEnigme() 
#virtual void resolutionEnigme()
+Enigme()
+~Enigme()
} 

class EnigmeInitiale
class EnigmeMelodie{
-void jouerMelodie()
-std::vector<char> vectMelodieRef
+ EnigmeMelodie(std::vector<char> vecteurRef)
}
class EnigmeRetourner 
class EnigmeLumiere{
- float seuilLuminosite
+ EnigmeLumiere(float seuil)
}
class EnigmeLabyrinthe{
- std::string labyrinthe
- int posX, posY
- bool caseEstLibre(int dX, int dY)
+ EnigmeLabyrinthe(std::string laby)
}
class EnigmeLettre{
- std::string phraseRef;
- std::string phraseAffichee;
- std::map<int, char> lettre;
- std::map<char, int> solution;
- uint8_t posX;
- uint8_t posY;
- void preparerEnigme();
- void placementLettre(char caractere);
- bool caseEstLibre(int8_t dX, int8_t dY);
+ EnigmeLettre( std::string phrase, std::vector<int> vectLettre );
}
class EnigmeCode{
- char code[4]
- char codeRef[4]
- int selection
- void afficherCode()
+ EnigmeCode(char code[4])
}
class EnigmeBouton

abstract class Capteur {
#virtual data acquisition()
} 

class Bouton {
+Bouton(char pin)
+data acquisition()
}

class Accelerometre{
- float X_out, Y_out, Z_out
+ void initAccelerometre()
+ data acquisition()
}
class CapteurLuminosite{
+CapteurLuminosite(char pin)
+data acquisition()
}

class Afficher {
-SeeedOLED ecran;
-int cursorX
-int cursorY
+Afficher()
+void initEcran()
+void clearEcran()
+void printlnEcran(std::string s)
+void printEcran(std::string s)
+ void putCharXY(unsigned char Row, unsigned char Column, char caractere)
}


abstract class Actionneur
class seeedOLED
class Buzzer {
- char pin
+ Buzzer(char pin)
+ void jouerNote(char note)
}

class data << (U,orchid) >> {
bool booleen
char caractere
int  entier
float flottant
}

Jeu "1" *-up- " " Enigme
Jeu "1" -up- "1" Capteur
Jeu "1" -up- "1" Actionneur
Jeu "1" -up- "1" Afficher
Enigme "1" -up- "1" Afficher


Enigme <|-down- EnigmeInitiale
Enigme <|-down- EnigmeMelodie
Enigme <|-down- EnigmeRetourner
Enigme <|-down- EnigmeLumiere
Enigme <|-down- EnigmeLabyrinthe
Enigme <|-down- EnigmeCode
Enigme <|-down- EnigmeBouton
Enigme <|-down- EnigmeLettre



EnigmeRetourner "1" -up- "1"  Accelerometre
EnigmeMelodie     "1" -up- "4"  Bouton
EnigmeMelodie     "1" -up- "1"  Buzzer
EnigmeLumiere   "1" -up- "1"  CapteurLuminosite
EnigmeLabyrinthe     "1" -up- "4"  Bouton
EnigmeLettre     "1" -up- "4"  Bouton
EnigmeInitiale     "1" -up- "1"  Bouton
EnigmeInitiale     "1" -up- "1"  Buzzer
EnigmeCode     "1" -up- "4"  Bouton
EnigmeBouton     "1" -up- "1"  Bouton

Actionneur <|-down- Buzzer
Actionneur <|-down- Afficher

seeedOLED "1" *-down- "1" Afficher

Capteur <|-down- Bouton
Capteur <|-down- Accelerometre
Capteur <|-down- CapteurLuminosite

@enduml
```
