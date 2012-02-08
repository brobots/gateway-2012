/* Region: Stick Layouts */

void oneStickLayout()
{
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
	ljoy_x = vexRT[Ch4]; // This is the X value of the LEFT analog stick.
	ljoy_y = vexRT[Ch3]; // This is the Y value of the LEFT analog stick.
	rjoy_x = vexRT[Ch1]; // This is the X value of the RIGHT analog stick.
	rjoy_y = vexRT[Ch2]; // This is the Y value of the RIGHT analog stick.
	// Step 1: process left analog stick
	if ((abs(ljoy_x) > threshold) && (abs(ljoy_y) > threshold)) // Left analog stick position is above threshold
	{
		// Let's move!
		if (ljoy_y > 0) // Is the analog stick pointing up or down?
		{
			// Move forward
			motor[leftMotor] = (ljoy_y + ljoy_x) / 2;
			motor[rightMotor] = (ljoy_y - ljoy_x) / 2;
		}
		else
		{
			// Move backward
			motor[leftMotor] = (ljoy_y - ljoy_x) / 2;
			motor[rightMotor] = (ljoy_y + ljoy_x) / 2;
		}
	}
	else if ((abs(ljoy_x) > threshold) && (abs(ljoy_y) < threshold)) // Analog stick is pointing right or left(abs(X) is above the threshold, abs(Y) is below the threshold)
	{
		motor[leftMotor] = ljoy_x;
		motor[rightMotor] = (-1 * ljoy_x);
		//motor[lateralMotor] = ljoy_x;
	}
	else // Left analog stick position is below threshold
	{
		// Stop moving
		motor[leftMotor] = 0;
		motor[rightMotor] = 0;
		//motor[lateralMotor] = 0;
	}

	// Step 2: process right analog stick
	if ((abs(rjoy_x) > threshold)) // Analog stick is pointing right or left(abs(X) is above the threshold, abs(Y) is below the threshold)
	{
		motor[lateralMotor] = (-1) * rjoy_x;
	}
	else
	{
		motor[lateralMotor] = 0;
	}


	// Elevator
	if ((vexRT[Btn5D] == 1) && (vexRT[Btn5U] == 1))
	{
		motor[elevatorOneMotor] = 0;
		motor[elevatorTwoMotor] = 0;
	}
	else if (vexRT[Btn5U] == 1)
	{
		motor[elevatorOneMotor] = 127;
		motor[elevatorTwoMotor] = 127;
	}
	else if (vexRT[Btn5D] == 1)
	{
		motor[elevatorOneMotor] = -127;
		motor[elevatorTwoMotor] = -127;
	}
	else if ((vexRT[Btn5D] == 0) && (vexRT[Btn5U] == 0))
	{
		motor[elevatorOneMotor] = 0;
		motor[elevatorTwoMotor] = 0;
	}

/* A pneumatic test

	if ((vexRT[Btn6D] ==1))
	{
		SensorValue[solenoid] = 0;
	}
	else if ((vexRT[Btn6U]==1))
	{
		SensorValue[solenoid] = 1;
	} */

}

void twoStickLayout()
{

	// Main wheels
	if (abs(vexRT[Ch3]) > threshold) // If the left joystick is greater than or less than the threshold:
	{
		motor[leftMotor] = (vexRT[Ch3]); // Left Joystick Y value / 2.
	}
	if (abs(vexRT[Ch3]) < threshold) // If the left joystick is within the threshold:
	{
		motor[leftMotor] = 0; // Stop the left motor (cancel noise)
	}

	if (abs(vexRT[Ch2]) > threshold) // If the right joystick is greater than or less than the threshold:
	{
		motor[rightMotor] = (vexRT[Ch2]); // Right Joystick Y value / 2.
	}
	if (abs(vexRT[Ch2]) < threshold) // If the right joystick is within the threshold:
	{
		motor[rightMotor] = 0; // Stop the right motor (cancel noise)
	}
	if ((abs(vexRT[Ch4]) > threshold) && (abs(vexRT[Ch1]) < threshold)) //&& (abs(ljoy_y) < threshold)) // Analog stick is pointing right or left(abs(X) is above the threshold, abs(Y) is below the threshold)
	{
		motor[lateralMotor] = -vexRT[Ch4] / 2;
	}
	if ((abs(vexRT[Ch1]) > threshold) && (abs(vexRT[Ch4]) < threshold)) // Analog stick is pointing right or left(abs(X) is above the threshold, abs(Y) is below the threshold)
	{
		motor[lateralMotor] = -vexRT[Ch1] / 2;
	}
	if ((abs(vexRT[Ch4]) > threshold) && (abs(vexRT[Ch1]) > threshold))
	{
		motor[lateralMotor] = -(vexRT[Ch4] + vexRT[Ch1]) / 2;
	}
	if ((abs(vexRT[Ch4]) < threshold) && (abs(vexRT[Ch1]) < threshold))
	{
		motor[lateralMotor] = 0;
	}
	if (vexRT[Btn5U] == 1)
	{
		SensorValue[solenoid1] = 1;
		SensorValue[solenoid2] = 1;
	}
	if (vexRT[Btn5D] == 1)
	{
		SensorValue[solenoid1] = 0;
		SensorValue[solenoid2] = 0;
	}


	// Elevator
	if ((vexRT[Btn5D] == 1) && (vexRT[Btn5U] == 1))
	{
		motor[elevatorOneMotor] = 0;
		motor[elevatorTwoMotor] = 0;
	}
	else if (vexRT[Btn5U] == 1)
	{
		motor[elevatorOneMotor] = 127;
		motor[elevatorTwoMotor] = 127;
	}
	else if (vexRT[Btn5D] == 1)
	{
		motor[elevatorOneMotor] = -127;
		motor[elevatorTwoMotor] = -127;
	}
	else if ((vexRT[Btn5D] == 0) && (vexRT[Btn5U] == 0))
	{
		motor[elevatorOneMotor] = 0;
		motor[elevatorTwoMotor] = 0;
	}

}
