#include <Arduino.h>
#include "Head_Servo.h"
#include "Communication.h"

void setup() 
{
  Wire.begin(0x08);  // Slave address
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);

  Serial.begin(9600);
}



void loop() 
{
  switch (Command)
  {
  case OPEN:
    OpenPanel(commandData);
    break;
  
  case CLOSE:
    ClosePanel(commandData);
    break;

  case WAVE:
    Wave();
    break;

  default:
    break;
  }
}