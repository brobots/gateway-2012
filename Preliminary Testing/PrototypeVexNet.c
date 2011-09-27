// Prototype bot: VEXNet movement tester 

/* This is for the joystick layout where the left analog stick controls robot movement and the right one controls the elevator.
* Controls:

	Left stick:
		Up: leftMotor = 127, rightMotor = 127: both wheels forward
		Down: leftMotor = -127, rightMotor = -127: both wheels backward
		Left: leftMotor = -127, rightMotor = 127: turn left
		Right: leftMotor = 127, rightMotor = -127: turn right
	Right stick:
		Up: elevatorOneMotor = 127, elevatorTwoMotor = 127: both elevator motors up
		Down: elevatorOneMotor = -127, elevatorTwoMotor = -127: both elevator motors down
		Left: lateralMotor goes left
		Right: lateralMotor goes right
	<strike>Back buttons:
		5 LH, U button: lateralMotor = 127: lateral goes left
		6 RH, U button: lateralMotor = -127: lateral goes right</strike>
	Front buttons:
		// No assignments

*/

// Define motors here: port numbers, isReversed
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)
#pragma config(Motor,  port4,           lateralMotor,     tmotorNormal, openLoop)
#pragma config(Motor,  port5,           elevatorOneMotor,     tmotorNormal, openLoop)
#pragma config(Motor,  port6,           elevatorTwoMotor,     tmotorNormal, openLoop)


/*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Ch1 is the X axis and Ch2 is the Y axis for the RIGHT joystick.                             *|
|*    2)  Ch3 is the Y axis and Ch4 is the X axis for the LEFT joystick.                              *|
|*    3)  'abs(z)' is the ABSOLUTE VALUE of 'z'.                                                      */

task main ()
{
    int ljoy_x;   // This is the X value of the LEFT analog stick.
    int ljoy_y;   // This is the Y value of the LEFT analog stick.
	
	int rjoy_x;   // This is the X value of the RIGHT analog stick.
	int rjoy_y;   // This is the Y value of the RIGHT analog stick.
	
	int threshold = 10;   // helps to eliminate 'noise' from a joystick that isn't perfectly at (0,0)

  while(true) // while(1==1)
  {
    ljoy_x = vexRT[Ch4];   // This is the X value of the LEFT analog stick.
    ljoy_y = vexRT[Ch3];   // This is the Y value of the LEFT analog stick.
	
	rjoy_x = vexRT[Ch1];   // This is the X value of the RIGHT analog stick.
	rjoy_y = vexRT[Ch2];   // This is the Y value of the RIGHT analog stick.
	
	// Step 1: process left analog stick
	if((abs(ljoy_x) > threshold) && (abs(ljoy_y) > threshold)) // Left analog stick position is above threshold
	{
		// Let's move!
		if(ljoy_y > 0) // Is the analog stick pointing up or down?
		{
			// Move forward
			motor[leftMotor]  = (joy_y + joy_x)/2;
			motor[rightMotor] = (joy_y - joy_x)/2;
		}
		else
		{
			// Move backward
			motor[leftMotor]  = (joy_y - joy_x)/2;
			motor[rightMotor] = (joy_y + joy_x)/2;
		}
	}
    else if((abs(ljoy_x) > threshold) && (abs(ljoy_y) < threshold)) // Analog stick is pointing right or left(abs(X) is above the threshold, abs(Y) is below the threshold)
    {
      motor[leftMotor]  = ljoy_x;
      motor[rightMotor] = (-1 * ljoy_x);
	  //motor[lateralMotor] = ljoy_x;
    }
	else // Left analog stick position is below threshold
	{
		// Stop moving
		motor[leftMotor]  = 0;
        motor[rightMotor] = 0;
		//motor[lateralMotor] = 0;
	}
	
	// Step 2: process right analog stick
	if((abs(rjoy_x) > threshold) && (abs(rjoy_y) > threshold)) // Right analog stick position is above threshold
	{
		// Let's move!
		if(rjoy_y > 0) // Is the analog stick pointing up or down?
		{
			// Move forward
			motor[elevatorOneMotor]  = (joy_y + joy_x)/2;
			motor[elevatorTwoMotor] = (joy_y - joy_x)/2;
		}
		else
		{
			// Move backward
			motor[elevatorOneMotor]  = (joy_y - joy_x)/2;
			motor[elevatorTwoMotor] = (joy_y + joy_x)/2;
		}
	}
	else if((abs(rjoy_x) > threshold) && (abs(rjoy_y) < threshold)) // Analog stick is pointing right or left(abs(X) is above the threshold, abs(Y) is below the threshold)
    {
      //motor[leftMotor]  = rjoy_x;
      //motor[rightMotor] = (-1 * rjoy_x);
	  motor[lateralMotor] = rjoy_x;
    }
	else // Right analog stick position is below threshold
	{
		// Stop moving
		motor[elevatorOneMotor]  = 0;
        motor[elevatorTwoMotor] = 0;
		motor[lateralMotor] = 0;
	}
	
	/* original sample code (from Remote Control\Single Joystick Control ADVANCED.c):

    // Forward, and swing turns: (both abs(X) and abs(Y) are above the threshold, and Y is POSITIVE)
    if((abs(joy_x) > threshold) && (abs(joy_y) > threshold) && (joy_y > 0))
    {
      motor[leftMotor]  = (joy_y + joy_x)/2;
      motor[rightMotor] = (joy_y - joy_x)/2;
    }
    // Backwards and swing turns: (both abs(X) and abs(Y) are above the threshold, and Y is NEGATIVE)
    else if((abs(joy_x) > threshold) && (abs(joy_y) > threshold) && (joy_y < 0))
    {
      motor[leftMotor]  = (joy_y - joy_x)/2;
      motor[rightMotor] = (joy_y + joy_x)/2;
    }
    // Turning in place: (abs(X) is above the threshold, abs(Y) is below the threshold)
    else if((abs(joy_x) > threshold) && (abs(joy_y) < threshold))
    {
      motor[leftMotor]  = joy_x;
      motor[rightMotor] = (-1 * joy_x);
    }
    // Standing still: (both abs(X) and abs(Y) are below the threshold)
    else
    {
      motor[leftMotor]  = 0;
      motor[rightMotor] = 0;
    }
	*/
  }
}
//++++++++++++++++++++++++