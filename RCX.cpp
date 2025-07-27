#include "arduino.h"
#include "RCX.h"

#define Motor_A_1 3
#define Motor_A_2 5

#define Motor_B_1 6
#define Motor_B_2 9

#define Motor_C_1 10
#define Motor_C_2 11

#define Sensor_1 4
#define Sensor_2 7
#define Sensor_3 8

RCX::RCX()
{}

void RCX::begin()
{
	pinMode(Motor_A_1, OUTPUT);
 	pinMode(Motor_A_2, OUTPUT);

 	pinMode(Motor_B_1, OUTPUT);
	pinMode(Motor_B_2, OUTPUT);

 	pinMode(Motor_C_1, OUTPUT);
	pinMode(Motor_C_2, OUTPUT);

	pinMode(Sensor_1, INPUT);
	pinMode(Sensor_2, INPUT);
	pinMode(Sensor_3, INPUT);
}

void RCX::Spin_Motor(char name,int direction,int intensity)
{
  if (intensity<0||intensity>100)
  {
  	//DEU ERRO
  }
  else if(name == "A")
  {
    if(direction == 1)
    {
      analogWrite(Motor_A_1,map(intensity,0,100,0,255));
      digitalWrite(Motor_A_2, LOW);
    }
    else if(direction == 2)
    {
      digitalWrite(Motor_A_1, LOW);
      analogWrite(Motor_A_2,map(intensity,0,100,0,255));
    }
    else
    {
      //DEU ERRO
    }
  }
  else if(name == "B")
  {
    if(direction == 1)
    {
      analogWrite(Motor_B_1,map(intensity,0,100,0,255));
      digitalWrite(Motor_B_2, LOW);
    }
    else if(direction == 2)
    {
      digitalWrite(Motor_B_1, LOW);
      analogWrite(Motor_B_2,map(intensity,0,100,0,255));
    }
    else
    {
      //DEU ERRO
    }
  }
  else if(name == "c")
  {
    if(direction == 1)
    {
      digitalWrite(Motor_B_2, LOW);
      analogWrite(Motor_C_1,map(intensity,0,100,0,255));
    }
    else if(direction == 2)
    {
      digitalWrite(Motor_C_1, LOW);
      analogWrite(Motor_C_2,map(intensity,0,100,0,255));
    }
    else
    {
      //DEU ERRO
    }
  }
  else
  {
    //DEU ERRO
  }

}

float RCX::Read_Sensor(int sensorNum)
{
  if(sensorNum == 1)
  {
    return map(analogRead(Sensor_1),0,1023,0,1);
  }
  else if(sensorNum == 2)
  {
    return map(analogRead(Sensor_2),0,1023,0,1);
  }
  else if(sensorNum == 3)
  {
    return map(analogRead(Sensor_3),0,1023,0,1);
  }
  else
  {
    //DEU ERRO
  }
}
