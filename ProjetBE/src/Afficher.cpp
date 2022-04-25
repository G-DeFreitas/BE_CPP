#include "Afficher.h"
#include <Wire.h>
#include "SeeedOLED.h"

Afficher::Afficher()
{
    this->cursorX = 0;
    this->cursorY = 0;
}

void Afficher::initEcran()
{
    Wire.begin();
    this->ecran.init();                                  // initialize SEEED OLED display
    this->ecran.setNormalDisplay();                      // Set display to normal mode (i.e non-inverse mode)
    this->ecran.setPageMode();                           // Set addressing mode to Page Mode
    this->ecran.setTextXY(this->cursorX, this->cursorY); // Set the cursor to Xth Page, Yth Column
    this->ecran.deactivateScroll();                      // Desactive le scrolling horizontal
}

void Afficher::clearEcran()
{
    this->cursorX = 0;
    this->cursorY = 0;
    this->ecran.clearDisplay(); // clear the screen and set start position to top left corner
}

void Afficher::printlnEcran(std::string s)
{
    this->ecran.setTextXY(this->cursorX, this->cursorY); // Set the cursor to Xth Page, Yth Column
    std::string sp, srem;
    if (s.length() > 256)
    {
        sp = s.substr(0, 256);
    }
    else
    {
        sp = s;
    }

    while (sp.length() > 16)
    {
        srem = sp.substr(0, 16);
        sp = sp.substr(16, sp.length() - 16);
        this->ecran.putString(srem.c_str()); // Print the String
        this->cursorX++;
        this->ecran.setTextXY(this->cursorX, this->cursorY); // Set the cursor to Xth Page, Yth Column
    }
    this->ecran.putString(sp.c_str()); // Print the String
    this->cursorX++;
    this->ecran.setTextXY(this->cursorX, this->cursorY); // Set the cursor to Xth Page, Yth Column
}

void Afficher::printEcran(std::string s)
{

    this->ecran.setTextXY(this->cursorX, this->cursorY); // Set the cursor to Xth Page, Yth Column
    std::string sp, srem;
    if (s.length() > 256)
    {
        sp = s.substr(0, 256);
    }
    else
    {
        sp = s;
    }

    while (sp.length() > 16)
    {
        srem = sp.substr(0, 16);
        sp = sp.substr(16, sp.length() - 16);
        this->ecran.putString(srem.c_str()); // Print the String
        this->cursorX++;
        this->ecran.setTextXY(this->cursorX, this->cursorY); // Set the cursor to Xth Page, Yth Column
    }
    this->ecran.putString(sp.c_str()); // Print the String
    this->cursorY = sp.length();
}

void Afficher::putCharXY(unsigned char Row, unsigned char Column, char caractere)
{
    this->ecran.setTextXY(Row, Column);
    this->ecran.putChar(caractere);
}