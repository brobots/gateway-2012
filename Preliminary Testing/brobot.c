#pragma config(Motor, port10, rightMotor, tmotorNormal, openLoop) // Define motors here: port numbers, isReversed
#pragma config(Motor, port1, leftMotor, tmotorNormal, openLoop, reversed)
#pragma config(Motor, port9, lateralMotor, tmotorNormal, openLoop)
#pragma config(Motor, port7, elevatorOneMotor, tmotorNormal, openLoop)
#pragma config(Motor, port8, elevatorTwoMotor, tmotorNormal, openLoop, reversed)
#pragma config(Sensor, dgtl1, solenoid1, sensorDigitalOut)
#pragma config(Sensor, dgtl2, solenoid2, sensorDigitalOut)


/* BroBots - The Bishop's School 2011 - 2012 Robotics Club Senior Bot */

#include "settings/settings.c"

#include "logic/sticklayouts.c"
#include "logic/sticktoggles.c"

#include "logic/ai.c"
#include "logic/aitoggles.c"

#include "logic/controlflow.c"

/* Region: Main Task */

void startBot(left, right, up, down) // passed by value, so after startBot is called, these variables don't change during the execution of the method. Thus, subsequent button presses or releases have no effect on what AI is being currently used, except for the button presses that switch to one or two stick layout, which end the AI prematurely.
{
	aiControlTimed(left, right, up, down);
	// Time to go back to user control.
	userControlLooped();
} // end function

task main()
{
	while (true)
	{
		if (vexRT[Btn8L] == 1 || vexRT[Btn8R] == 1 || vexRT[Btn8U] == 1 || vexRT[Btn8D] == 1)
		{
			startBot(vexRT[Btn8L], vexRT[Btn8R], vexRT[Btn8U], vexRT[Btn8D]);
			break; // bot has been "started" (competition mode), and now the execution loop takes place in startBot()
		}

		else // pre-competition or testing mode: two stick layout is enabled
		{
			if (handleLayoutSwitch(vexRT[Btn7L], vexRT[Btn7U])) // combination to switch to a layout, if necessary
			{
				wait1Msec(20); // short reset time
			}
			if (isOneStickLayout == true)
			{
				oneStickLayout();
			}
			else
			{
				twoStickLayout();
			}
		}
	}
}
