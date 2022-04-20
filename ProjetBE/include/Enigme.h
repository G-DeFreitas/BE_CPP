#ifndef ENIGME_H
#define ENIGME_H

#include <string>

class Enigme
{
private:
    static int nbEnigmes;

protected:
    std::string texteEnigme;
public:
    virtual void poserEnigme() = 0;
    virtual void resolutionEnigme() = 0;

public:

    /*
    Usage  : Incrémente la Variable nbEnigmes
    Testé  : Non
    */
    Enigme();

    /*
    Usage  : Décrémente la Variable nbEnigmes
    Testé  : Non
    */
    ~Enigme();
};

#endif // ENIGME_H