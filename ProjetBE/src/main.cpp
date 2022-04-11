#include <Arduino.h>
#include "../include/Jeu.h"
#include "../include/Pins.h"
#include "../include/EnigmeMelodie.h"

#include "..\include\u8g2-master\csrc\U8g2lib.h"


#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8G2_SSD1306_128X64_ALT0_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); // SSD1306 and SSD1308Z are compatible
 
// Variables globales
Jeu boiteEnigme;
void setup()
{
  Serial.begin(9600, SERIAL_8N1);
  Serial.println("-Lancement setup-");
  pinMode(LED_BUILTIN, OUTPUT);
  boiteEnigme.init();

  u8g2.begin();

  
  Serial.println("-Fin setup-");
}

void loop()
{
  Serial.println("-Iteration Loop-");


  // Clignotement par sécurité
  digitalWrite(LED_BUILTIN, HIGH);
  delay(200);
  digitalWrite(LED_BUILTIN, LOW);
  delay(200);


  // 
  u8g2.clearBuffer();                   // clear the internal memory
  u8g2.setFont(u8g2_font_ncenB08_tr);   // choose a suitable font
  u8g2.drawStr(0,10,"Hello World!");    // write something to the internal memory
  u8g2.sendBuffer();                    // transfer internal memory to the display
  delay(1000);  
}