/* Region: AIs */

bool rotate(angle)
{
	// TODO: rotate by that angle
	return true;
}
bool SeeBlock()
{
	// TODO: read sonar to detect a block; return true if block visible; return false if no block.
	return false;
}
bool IsWall()
{
	// TODO: see how close sonar is
	return false;
}

bool blueAIFree()
{
	while (true)
	{
		if (handleLayoutSwitch(vexRT[Btn7L], vexRT[Btn7U])) // combination to switch to a layout
		{
			// one of those buttons was pressed, so we switched to a controller layout and now we deactivate AI.
			return false; break; // exit AI, proceed to user-controlled mode
		}

		// Do AI stuff
		motor[leftMotor] = 127;
		motor[rightMotor] = 127;

	}
}

bool redAIFree()
{
	while (true)
	{
		if (handleLayoutSwitch(vexRT[Btn7L], vexRT[Btn7U])) // combination to switch to a layout
		{
			// one of those buttons was pressed, so we switched to a controller layout and now we deactivate AI.
			return false; break; // exit AI, proceed to user-controlled mode
		}

		// Do AI stuff
		motor[leftMotor] = 127;
		motor[rightMotor] = 127;

	}
}

bool blueAITrapped()
{
	while (true)
	{
		if (handleLayoutSwitch(vexRT[Btn7L], vexRT[Btn7U])) // combination to switch to a layout
		{
			// one of those buttons was pressed, so we switched to a controller layout and now we deactivate AI.
			return false; break; // exit AI, proceed to user-controlled mode
		}

		// Do AI stuff
		motor[leftMotor] = 127;
		motor[rightMotor] = 127;

	}
}

bool redAITrapped()
{
	while (true)
	{
		if (handleLayoutSwitch(vexRT[Btn7L], vexRT[Btn7U])) // combination to switch to a layout
		{
			// one of those buttons was pressed, so we switched to a controller layout and now we deactivate AI.
			return false; break; // exit AI, proceed to user-controlled mode
		}

		// Do AI stuff
		motor[leftMotor] = 127;
		motor[rightMotor] = 127;

	}
}

bool captureWithSonar()
{
	float x;
	while((x = SensorValue(sonarSensor)) > 5) // advance to it
	{
		motor[rightMotor] = 127;
		motor[leftMotor]  = 127;
		wait1Msec(100); // Take 10 readings per second.
	}
	// now, make sure y becomes greater than that x after we "eat" the block
	float y;
	int numberReps = 0;
	while(numberReps < 1000)
	{
		y = SensorValue(sonarSensor);
		if(y > x)
		{
			// we've eaten it successfully
			return true;
		}
		numberReps++;
		wait1Msec(100);
	}

	// looks like we failed to eat it.
	// go back, restart
	motor[rightMotor] = -127;
	motor[leftMotor] = -127;
	wait10Msec(50);
	return false;

}
bool randomAttacksUsingSonar()
{
	// peaceful mode
	while(true)
	{
		while(rotate(15))
		{
			float x = SensorValue(sonarSensor);
			if(x != -1)
			{
				wait1Msec(10);
				if(SensorValue(sonarSensor) == x) // if object hasn't moved, it's probably a block
				{
					captureWithSonar();
				}
			}
		}
		while(SensorValue(sonarSensor) > 20  || SensorValue(sonarSensor) == -1)		// Loop while robot's Ultrasonic sensor is further than 20 inches away from an object
		{                                                                         // || (or) it is '-1'.  (-1 is the value returned when nothing is in it's visable range)
			motor[rightMotor] = 63;			// Motor on port2 is run at half (63) power forward
			motor[leftMotor]  = 63;			// Motor on port3 is run at half (63) power forward
		}
		// something was found

		// scan sonar
		// if found
		// pause, rescan
		// if still sonar, capture()
	}

	return true;
}

void launchCompetitionAI()
{
	if(rotate(-90) && isWall())
	{
		rotate(90); // face forward again
		// todo: set X and Y
		currentX = 0;
		currentY = 0;
		redAITrapped();
	}
	else if(rotate(180) && isWall())
	{
		rotate(-90); // face forward again
		// todo: set X and Y
		currentX = 0;
		currentY = 0;
		blueAITrapped();
	}
	else if(true)
	{

	}
	else if(true)
	{

	}
	else
	{
		randomAttacksUsingSonar();
	}
}
