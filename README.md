# BE_CPP


## Diagramme de classe
@startuml
title Boite à enigme - Diagramme de Classe


class Jeu {
  -std::vector<Enigme> liste
  +void init()
  +void loop()
}
class Enigme {
  -static int nbEnigme
  -std::string speech
  #virtual bool poserEnigme()
}
class EnigmeSimon
class EnigmeRetourner
class EnigmeLumiere

class Capteur{
+ Data acquire()
}
class Bouton
class Accelerometre

class Afficher{
+ void afficherMsg()
}
class EcranLCD

class Data

Jeu "1" *-up- " " Enigme: Composition

Enigme <|-down- EnigmeSimon: Inheritance
Enigme <|-down- EnigmeRetourner: Inheritance
Enigme <|-down- EnigmeLumiere: Inheritance
Enigme "1" *-up- "many" Capteur: Compostion

Enigme "1" *-up- "1" Afficher: Compostion

EcranLCD "1" *-down- "1" Afficher: Compostion


Capteur <|-down- Bouton: Inheritance
Capteur <|-down- Accelerometre: Inheritance
Capteur "1" *-up- "many" Data: Compostion
@enduml
