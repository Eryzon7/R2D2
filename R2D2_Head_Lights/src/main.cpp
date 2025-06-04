#include <Arduino.h>
#include "Communication.h"

void setup()
{
  Wire.begin(0x09);  // Slave address
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);

  Serial.begin(9600);
}

void loop()
{
  switch (Command)
  {
  case FLASHLIGHT:
    
    break;
  
  case SOUND:
    playSound(commandData);
    break;

  default:
    break;
  }
}
