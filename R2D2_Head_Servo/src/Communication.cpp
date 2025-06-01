#include "Communication.h"

String command = "";

void SwitchCommand(String cmd) 
{
  if (cmd == "open") Command = OPEN;
  else if (cmd == "close") Command = CLOSE;
  else if (cmd == "wave") Command = WAVE;
  else Command = BASE;
}

void requestEvent() 
{
  Wire.write(("Ack: " + lastCommand).c_str());  // Reply with the last received command
}

void receiveEvent(int numBytes) 
{
  lastCommand = "";
  while (Wire.available()) 
  {
    char c = Wire.read();
    lastCommand += c;
  }

  // Check if the message starts with '#' and ends with '%'
  if (lastCommand.startsWith("#") && lastCommand.endsWith("%")) 
  {
    // Strip start and end symbols
    String content = lastCommand.substring(1, lastCommand.length() - 1);  // e.g., "open,3"

    int commaIndex = content.indexOf(',');
    if (commaIndex > 0) 
    {
      command = content.substring(0, commaIndex);        // e.g., "open"
      String dataStr = content.substring(commaIndex + 1); // e.g., "3"
      commandData = dataStr.toInt();                      // convert to integer

      SwitchCommand(command);
    }
  }
}