#ifndef BUZZER_H
#define BUZZER_H

#include "Actionneur.h"

class Buzzer : public Actionneur
{
private:
    char pin ;
public:
    /*
    Usage  : Constructeur. Associe numéro de pin
    Testé  : Non
    */
    Buzzer(char pin) ;
    /*
    Usage  : Joue la note en argument
    Testé  : Non
    */
    void jouerNote(char note) ;
};


#endif // BUZZER_H