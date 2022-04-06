#include <Arduino.h>
#include "../include/Enigme.h"
#include "../include/Pins.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600,SERIAL_8N1);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(TEMP_SENSOR_PIN, INPUT);
}

int temp;
const int B = 4275 ;

void loop() {
  // put your main code here, to run repeatedly:
  temp = analogRead(TEMP_SENSOR_PIN) ;
  float R = 1023.0/((float) temp) - 1.0 ;
  R = 100000.0*R;
  float temperature = 1.0/(log(R/100000.0)/B + 1/298.15) - 273.15 ;
  Serial.print("Temperature : ");
  Serial.println(temperature) ;
  digitalWrite(LED_BUILTIN, HIGH) ;
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW) ;
  delay(1000);
}