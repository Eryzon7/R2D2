#include "Communication.h"

String lastCommand = "";
int commandData = 0;
commandType Command = BASE;
String command = "";  // local helper

void SwitchCommand(String cmd) 
{
  if (cmd == "open") Command = OPEN;
  else if (cmd == "close") Command = CLOSE;
  else if (cmd == "wave") Command = WAVE;
  else Command = BASE;
}

void requestEvent() 
{
  Wire.write(("Ack: " + lastCommand).c_str());
}

void receiveEvent(int numBytes) 
{
  lastCommand = "";
  while (Wire.available()) 
  {
    char c = Wire.read();
    lastCommand += c;
  }

  if (lastCommand.startsWith("#") && lastCommand.endsWith("%")) 
  {
    String content = lastCommand.substring(1, lastCommand.length() - 1);
    int commaIndex = content.indexOf(',');
    if (commaIndex > 0) 
    {
      command = content.substring(0, commaIndex);
      String dataStr = content.substring(commaIndex + 1);
      commandData = dataStr.toInt();
      SwitchCommand(command);
    }
  }
}