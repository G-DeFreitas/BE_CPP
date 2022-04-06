#ifndef JEU_H
#define JEU_H

#include <vector>
#include "Enigme.h" 

class Jeu
{
private:
    std::vector<Enigme> listeEnigme ;
    int indexEnigme ;
public:
    void init() ;
    void loop() ;
};

#endif // JEU_H