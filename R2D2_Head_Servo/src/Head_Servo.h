#ifndef HEAD_SERVO_H
#define HEAD_SERVO_H

#include <Arduino.h>
#include <Servo.h>

// Function declarations
void InitServos();
void OpenPanel(int chosen);
void ClosePanel(int chosen);
void Wave();

#endif // HEAD_SERVO_H