#ifndef RECEIVE_MSG_H
#define RECEIVE_MSG_H

#include <ESPAsyncWebServer.h>

// Declare the WebSocket object
extern AsyncWebSocket ws;

enum subSystem
{
  SERVO,
  LIGHT,
  SOUND
};

subSystem subsystem;

struct subSystemMap {
  const char* name;
  subSystem value;
};

void SwitchSubSystem(String cmd);

String SubSystem;
String modifiedMsg;

// Function to initialize WebSocket and bind event handler
void initWebSocket();

// Internal WebSocket event handler
void onWebSocketEvent(AsyncWebSocket *server,
                      AsyncWebSocketClient *client,
                      AwsEventType type,
                      void *arg,
                      uint8_t *data,
                      size_t len);

#endif // WEBSOCKETHANDLER_H