#include "Receive_Msg.h"

AsyncWebSocket ws("/ws");

subSystem subsystem;
String SubSystem;
String modifiedMsg;

String command = "";

const subSystemMap subsystemMap[] = 
{
  {"servo", SERVO},
  {"light", LIGHT},
  {"sound", SOUND}
};

void SwitchSubSystem(String cmd) 
{
  for (auto& entry : subsystemMap) 
  {
    if (cmd == entry.name) 
    {
      subsystem = entry.value;
      break;
    }
  }
}

void initWebSocket() 
{
  ws.onEvent(onWebSocketEvent);
}

void onWebSocketEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) 
{
  if (type == WS_EVT_CONNECT) 
  {
    Serial.println("WebSocket client connected");
  } 
  else if (type == WS_EVT_DISCONNECT) 
  {
    Serial.println("WebSocket client disconnected");
  } 
  else if (type == WS_EVT_DATA) 
  {
    String lastCommand;

    for (size_t i = 0; i < len; i++) 
    {
      lastCommand += (char)data[i];
    }

    if (lastCommand.startsWith("#") && lastCommand.endsWith("%")) 
    {
      // Remove start and end markers for easier parsing
      String cleanMsg = lastCommand.substring(1, lastCommand.length() - 1); // "servo,open,3"

      int commaIndex = cleanMsg.indexOf(',');

      if (commaIndex != -1) 
      {
        SubSystem = cleanMsg.substring(0, commaIndex); // "servo"
        String remaining = cleanMsg.substring(commaIndex + 1); // "open,3"

        // Reconstruct message with type removed but markers kept
        modifiedMsg = "#" + remaining + "%";
      }

      SwitchSubSystem(SubSystem);
    } 
    else 
    {
      Serial.println("Invalid message format");
    }
  }
}