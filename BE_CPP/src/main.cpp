#include <Arduino.h>
#define SENSOR_PIN 6
void setup()
{

  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(SENSOR_PIN, INPUT);
  Serial.begin(9600);
  //
}
int temp;

void loop()
{
  temp = analogRead(SENSOR_PIN);
  Serial.println("test");
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);

}