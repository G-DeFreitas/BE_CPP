# BE_CPP


## Diagramme de classe
![alt text](https://github.com/G-DeFreitas/BE_CPP/blob/main/dclass.png)

```
@startuml title Boite à enigme - Diagramme de Classe

class Jeu  << principale >> { 
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
class EnigmeLumiere

abstract class Capteur {
#virtual data acquisition()
+Capteur(char pin)
} 

class Bouton 
class Accelerometre
class CapteurLuminosite

class Afficher {
void afficherMsg() 
}

class EcranLCD
class Buzzer

class data << (U,orchid) >> {
bool booleen
char caractere
int  entier
float flottant
}

Jeu "1" *-up- " " Enigme
Jeu "1" -up- "1" Capteur
Jeu "1" -up- "1" Afficher
Enigme "1" -up- "1" Afficher

Enigme <|-down- EnigmeMelodie
Enigme <|-down- EnigmeRetourner
Enigme <|-down- EnigmeLumiere

EnigmeRetourner "1" -up- "1"  Accelerometre
EnigmeMelodie     "1" -up- "4"  Bouton
EnigmeMelodie     "1" -up- "1"  Buzzer
EnigmeLumiere   "1" -up- "1"  CapteurLuminosite

EcranLCD "1" *-down- "1" Afficher

Capteur <|-down- Bouton
Capteur <|-down- Accelerometre
Capteur <|-down- CapteurLuminosite

@enduml
```
