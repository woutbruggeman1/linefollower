# Sensoren proof of concept

minimale hard- en software die aantoont dat minimaal 6 sensoren onafhankelijk van elkaar kunnen uitgelezen worden (geen calibratie, normalisatie of interpolatie). Hierbij moet een zo groot mogelijk bereik van de AD converter benut worden (indien van toepassing)

#include <QTRSensors.h> //Toevoegen van het juiste library zodat deze compactibel is met onze sensor.
QTRSensors qtr;

const uint8_t SensorCount = 6;
uint16_t sensorValues[SensorCount];



void setup()
{
  qtr.setTypeAnalog();
  qtr.setSensorPins((const uint8_t[]) {A0, A1, A2, A3, A4, A5}, SensorCount);
  qtr.setEmitterPin(2);

  Serial.begin(9600);
}


void loop()
{

  qtr.read(sensorValues); //Lezen van de raw waarden (hoe ze rechtstreeks uit de sensor komen).

  
  //Waarden omzetten als nummers tussen 0 en 1023:  (0 = max reflectie, 1023 = min reflectie)
  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.println();
  
  delay(250);
  
}
