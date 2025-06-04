#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <Wire.h>

String lastCommand;
int commandData;


enum commandType
{
  BASE,
  FLASHLIGHT,
  SOUND
};

commandType Command;

// Function prototype for request event handler
void requestEvent();
void receiveEvent(int numBytes);

#endif // COMMUNICATION_H