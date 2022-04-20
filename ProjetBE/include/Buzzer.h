#ifndef BUZZER_H
#define BUZZER_H

#include "Actionneur.h"

class Buzzer : public Actionneur
{
private:
    char pin;

public:
    /*
    Usage  : Constructeur. Associe numéro de pin
    Testé  : Ok 20/04
    */
    Buzzer(char pin);
    /*
    Usage  : Joue la note en argument
    Testé  : Ok 20/04
    */
    void jouerNote(char note);
};

#endif // BUZZER_H