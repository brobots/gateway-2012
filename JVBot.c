#pragma config(Motor,  port1,           clawbaseleft,  tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftwheel,     tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port4,           rightwheel,    tmotorNormal, openLoop)
#pragma config(Motor,  port5,           clawmidleft,   tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port6,           clawmidright,  tmotorNormal, openLoop)
#pragma config(Motor,  port7,           clawwheel,     tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)


/* BroBots - The Bishop's School 2011-2012 Robotics Team JV Bot */

int threshold = 12.7;

/* Strategy methods */

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

/* Control flow */


void startAutonomousFunctions()
{
  // .....................................................................................
  // Insert user code here.
  // .....................................................................................
	AI();
}

task autonomous()
{
	startAutonomousFunctions(); // so we don't have to deal with multitasking weirdness
}

void startManualMode()
{
	// User control code here, inside the loop

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
  if(vexRT[Btn7D] == 1)
  {
    motor[clawwheel] = -127;
  }
  if(vexRT[Btn7D] == 0)
  {
  motor[clawwheel] = 0;
  }
	  ManualControl();
	}
}
task usercontrol()
{
	startManualMode(); // so we don't have to deal with multitasking weirdness
}

task main()
{
	startAutonomousFunctions();
	startManualMode();
}

void pre_auton()
{
	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...

	while(true) // loop for detecting debug keypress
	{
		if(vexRT[Btn7U])
		{
			startTask(main);
			break;
		}
	}

}
