#ifndef _ECRANOLED_H_
#define _ECRANOLED_H_

#include "Actionneur.h"

class EcranOLED : public Actionneur
{
private:
    char pinSDA;
    char pinSCL;
public:
    EcranOLED(char pinSDA, char pinSCL);
};


EcranOLED::EcranOLED(char pinSDA, char pinSCL)
{
    this->pinSCL = pinSCL;
    this->pinSDA = pinSDA;

    // U8G2_SSD1306_128X64_ALT0_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); // SSD1306 and SSD1308Z are compatible
}




#endif