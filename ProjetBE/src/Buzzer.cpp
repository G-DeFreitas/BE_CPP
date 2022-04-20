#include "..\include\Buzzer.h"
#include <Arduino.h>

Buzzer::Buzzer(char pin)
{
    this->pin = pin;
}

void Buzzer::jouerNote(char note)
{
    analogWrite(this->pin, note);
    delay(500);
    analogWrite(this->pin, 0);
    delay(200);
}