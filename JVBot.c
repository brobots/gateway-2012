#pragma config(Motor,  port1,           leftwheel,     tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port2,           rightwheel,    tmotorNormal, openLoop)
#pragma config(Motor,  port3,           clawbaseleft,  tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port4,           clawbaseright, tmotorNormal, openLoop)
#pragma config(Motor,  port5,           clawmidleft,   tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port6,           clawmidright,  tmotorNormal, openLoop)
#pragma config(Motor,  port7,           clawwheel,     tmotorNormal, openLoop)

int threshold = 12.7;

void main()
{
  while (true)
  {
  //Base Wheels
  //Left Base Wheel
  if (abs(vexRT[Ch3]) > threshold)
  {
    motor[leftwheel] = (vexRT[Ch3]);//Left joystick Y value
  }
  if (abs(vexRT[Ch3]) < threshold)
  {
    motor[leftwheel] = 0;//Stop the left motor
  }
  //Right Base Wheel
  if (abs(vexRT[Ch2]) > threshold)
  {
    motor[rightwheel] = (vexRT[Ch3]);//Right joystick Y value
  }
  if (abs(vexRT[Ch2]) < threshold)
  {
    motor[rightwheel] = 0;//Stop the right motor
  }
  return;
  }
}
