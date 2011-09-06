/*************************************************************************
VEX - Point Turns

Description: This program instructs your robot turn right for .75 seconds
and then turn left for .75 seconds. There is a two second pause at the
beginning of the program.

Configuration: This program is written to work with the Squarebot model.
	Right Motor - port2
	Left	Motor - port3

Additional Notes:
-	The "bMotorReflected[port2] = 1;" is needed with the Squarebot model,
	but may not be needed for all robot configurations.
-	Point Turns, or turns in place, are achieved by having the motors spin
	in opposite directions.
*************************************************************************/




void stopBot()
{
  	motor[port2] = 0;		//Motor on port2 is run at full (-127) power reverse
	motor[port3] = 0;			//Motor on port3 is run at full (127) power forward
}

void goRight()
{
	//Turn Right at full power for .75 seconds
	motor[port2] = -127;		//Motor on port2 is run at full (-127) power reverse
	motor[port3] = 127;			//Motor on port3 is run at full (127) power forward
}
void goLeft()
{
  //Turn Left at full power for .75 seconds
	motor[port2] = 127;		//Motor on port2 is run at full (127) power forward
	motor[port3] = -127;			//Motor on port3 is run at full (-127) power reverse
}
void goStraight()
{
  //Turn straight at full power for .75 seconds
	motor[port2] = 127;		//Motor on port2 is run at full (127) power forward
	motor[port3] = 127;			//Motor on port3 is run at full (-127) power reverse
}
void goBack()
{
  //Turn straight at full power for .75 seconds
	motor[port2] = -127;		//Motor on port2 is run at full (127) power forward
	motor[port3] = -127;			//Motor on port3 is run at full (-127) power reverse
}


void testLeftTread()
{
  motor[port2] = 0;		//Motor on port2 is run at full (-127) power reverse
	motor[port3] = 127;			//Motor on port3 is run at full (127) power forward
}

void testRightTread()
{
  motor[port2] = 127;		//Motor on port2 is run at full (-127) power reverse
	motor[port3] = 0;			//Motor on port3 is run at full (127) power forward
}

task main()
{
	wait1Msec(2000);						//Robot waits for 2000 milliseconds before executing program
	bMotorReflected[port2] = 1;	//Reflects the direction of the motor on port2

	goRight();
	wait1Msec(10*1000);					//Robot runs previous code for 10*1000 milliseconds before moving on

	stopBot();
	wait1Msec(1000);

	goLeft();
	wait1Msec(10*1000);					//Robot runs previous code for 10*1000 milliseconds before moving on

	stopBot();
	wait1Msec(1000);

		goStraight();
	wait1Msec(10*1000);					//Robot runs previous code for 10*1000 milliseconds before moving on

	stopBot();
	wait1Msec(1000);

		goBack();
	wait1Msec(10*1000);					//Robot runs previous code for 10*1000 milliseconds before moving on

	stopBot();
	wait1Msec(1000);
}													//Program ends, and the robot stops
