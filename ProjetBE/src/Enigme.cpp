#include "..\include\Enigme.h"
#include "..\include\Afficher.h"
#include <string>

Enigme::Enigme()
{
    nbEnigmes++ ;
}

Enigme::~Enigme()
{
    nbEnigmes-- ;
}

int Enigme::nbEnigmes = 0 ;