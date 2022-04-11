# BE_CPP


## Diagramme de classe
![alt text](https://github.com/G-DeFreitas/BE_CPP/blob/main/dclass.png)

```
@startuml title Boite à enigme - Diagramme de Classe

class Jeu  << principale >> { 
- std::map<std::string,Capteur*> ensembleCapteur
- std::map<std::string,Actionneur*> ensembleActionneur
- std::vector<Enigme> listeEnigme
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

abstract class Capteur {
+char Pin
#virtual data acquisition()
+Capteur(char pin)
} 

class Bouton {
+Bouton(char pin)
+data acquisition()
}

class Accelerometre
class CapteurLuminosite{
+CapteurLuminosite(char pin)
+data acquisition()
}

class Afficher {
void afficherMsg() 
}


abstract class Actionneur
class EcranLCD
class EcranOLED{
    - SeeedOLED ecran
}
class Buzzer

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

Enigme <|-down- EnigmeMelodie
Enigme <|-down- EnigmeRetourner
Enigme <|-down- EnigmeLumiere

EnigmeRetourner "1" -up- "1"  Accelerometre
EnigmeMelodie     "1" -up- "4"  Bouton
EnigmeMelodie     "1" -up- "1"  Buzzer
EnigmeLumiere   "1" -up- "1"  CapteurLuminosite

Actionneur <|-down- EcranLCD
Actionneur <|-down- EcranOLED
Actionneur <|-down- Buzzer

EcranLCD "1" *-down- "1" Afficher
EcranOLED "1" *-down- "1" Afficher

Capteur <|-down- Bouton
Capteur <|-down- Accelerometre
Capteur <|-down- CapteurLuminosite

@enduml
```
