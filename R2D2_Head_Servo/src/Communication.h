#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <Wire.h>

extern String lastCommand;
extern int commandData;


enum commandType
{
  BASE,
  OPEN,
  CLOSE,
  WAVE
};

extern commandType Command;

// Function prototype for request event handler
void requestEvent();
void receiveEvent(int numBytes);

#endif // COMMUNICATION_H