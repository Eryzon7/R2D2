#include <Arduino.h>
#include <Wire.h>
#include "Receive_Msg.h"

#define SLAVE_SERVO 0x08
#define SLAVE_LIGHT 0x09
#define SLAVE_SOUND 0x10

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

AsyncWebServer server(80);

void setup() 
{
  Wire.begin();  // ESP32 I2C pins

  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500); Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");
  Serial.println(WiFi.localIP());

  initWebSocket();
  server.addHandler(&ws);
  server.begin();
}

void sendCommand(String cmd, int adress) 
{
  Wire.beginTransmission(adress);
  Wire.write(cmd.c_str());
  int result = Wire.endTransmission();
  if (result != 0) 
  {
    Serial.printf("I2C Error: %d sending to 0x%02X\n", result, adress);
  }
}

void loop() 
{
  ws.cleanupClients();
  switch (subsystem)
  {
  case SERVO:
    sendCommand(modifiedMsg, SLAVE_SERVO);
    break;

  case LIGHT:
    sendCommand(modifiedMsg, SLAVE_LIGHT);
    break;

  case SOUND:
    sendCommand(modifiedMsg, SLAVE_SOUND);
    break;

  default:
    break;
  }
}

