#include "..\include\Accelerometre.h"
#include <Arduino.h>

Accelerometre::Accelerometre()
{
}

void Accelerometre::initAccelerometre(){
    
}

data Accelerometre::acquisition()
{
    data d;
    yield() ;
    d.tab_float[0] = 1.0;
    d.tab_float[1] = 2.0;
    return d;
}