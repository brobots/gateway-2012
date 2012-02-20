#pragma config(Motor,  port1,           leftwheel,     tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port2,           rightwheel,    tmotorNormal, openLoop)
#pragma config(Motor,  port3,           clawbaseleft,  tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port4,           clawbaseright, tmotorNormal, openLoop)
#pragma config(Motor,  port5,           clawmidleft,   tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port6,           clawmidright,  tmotorNormal, openLoop)
#pragma config(Motor,  port7,           clawwheel,     tmotorNormal, openLoop)
#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)
#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/* BroBots - The Bishop's School 2011-2012 Robotics Team JV Bot */

int threshold = 12.7;

void pre_auton()
{
	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...

}
task autonomous()
{
  // .....................................................................................
  // Insert user code here.
  // .....................................................................................
	AI();
}
task usercontrol()
{
	// User control code here, inside the loop

	while (true)
	{
	  // This is the main execution loop for the user control program. Each time through the loop
	  // your program should update motor + servo values based on feedback from the joysticks.

	  // .....................................................................................
	  // Insert user code here. This is where you use the joystick values to update your motors, etc.
	  // .....................................................................................

	  ManualControl();
	}
}

void AI()
{
	return;
}


void ManualControl()
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
