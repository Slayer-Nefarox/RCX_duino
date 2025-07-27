/*adapts the arduino to act as a pseudo Lego RCX in some way*/
#ifndef RCX_h
#define RCX_h

#include "Arduino.h"

class RCX
{
  public:
  	RCX();
    void Spin_Motor(char motorLetter, int direction, int intensity);
    float Read_Sensor(int sensorNum);
    void begin();
};
#endif