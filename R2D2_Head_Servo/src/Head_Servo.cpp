#include "Head_Servo.h"

Servo myServos[6];
int baseAngle = 90;      // Starting position
int offset = 30;         // Degrees to move

void InitServos() 
{
    myServos[0].attach(3);
    myServos[1].attach(4);
    myServos[2].attach(5);
    myServos[3].attach(6);
    myServos[4].attach(7);
    myServos[5].attach(8);
    for(int i = 0; i < 6; i++)
    {
        myServos[i].write(baseAngle);    // Set to base position
    }
}

void OpenPanel(int chosen) 
{
    if(chosen >= 0 && chosen < 6)
    {
        myServos[chosen].write(baseAngle + offset); //opens the chosen panel
    }
   
}

void ClosePanel(int chosen)
{
    if(chosen >= 0 && chosen < 6)
    {
        myServos[chosen].write(baseAngle); //closes the chosen panel
    }
    
}

void Wave()
{
    for (int i = 0; i < 6; i++)
    {
        OpenPanel(i);
        delay(200);
    }

    for (int i = 0; i < 6; i++)
    {
        ClosePanel(i);
        delay(200);
    }
}
