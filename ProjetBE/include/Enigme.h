#ifndef ENIGME_H
#define ENIGME_H

#include <string>

class Enigme
{
private:
    static int nbEnigmes ;
protected:
    std::string texteEnigme ;
    virtual void poserEnigme() = 0 ;
    virtual void resolutionEnigme() = 0 ;
public:
    Enigme();
    ~Enigme();
};

#endif // ENIGME_H