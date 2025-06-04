#include "Head_Servo.h"
#include "Communication.h"

void setup() 
{
  Wire.begin(0x08);  // Slave address
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);

  Serial.begin(9600);

  InitServos();
}

void loop() 
{
  OpenPanel(0);
  delay(5000);
  
  ClosePanel(0);
  delay(5000);


  /*
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
  }*/
}