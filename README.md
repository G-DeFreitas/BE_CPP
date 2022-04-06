# BE_CPP


## Diagramme de classe
![alt text](https://github.com/G-DeFreitas/BE_CPP/blob/main/dclass06041715.png)

```
@startuml title Boite à enigme - Diagramme de Classe

class Jeu  << principale >> { 
-std::vector<Enigme> listeEnigme
- int indexEnigme()
+void init() 
+void loop() 
} 

abstract class Enigme {
-static int nbEnigme
#std::string texteEnigme
#virtual void poserEnigme() 
#virtual void resolutionEnigme()
} 

class EnigmeSimon{
-void jouerMelodie()
-std::vector<char> vectMelodieRef
}
class EnigmeRetourner 
class EnigmeLumiere

abstract class Capteur {
#virtual data acquisition() 
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
Enigme "1" -up- "1" Afficher

Enigme <|-down- EnigmeSimon
Enigme <|-down- EnigmeRetourner
Enigme <|-down- EnigmeLumiere

EnigmeRetourner "1" -up- "1"  Accelerometre
EnigmeSimon     "1" -up- "4"  Bouton
EnigmeSimon     "1" -up- "1"  Buzzer
EnigmeLumiere   "1" -up- "1"  CapteurLuminosite

EcranLCD "1" *-down- "1" Afficher

Capteur <|-down- Bouton
Capteur <|-down- Accelerometre
Capteur <|-down- CapteurLuminosite

@enduml
```
