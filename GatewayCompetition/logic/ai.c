/* Region: AIs */

/* Field details:

12ft by 12ft, divided into 4 boxes by 4 boxes. Each region = 2 boxes by 2 boxes. Thus, each box = 3ft by 3ft = 36in. by 36in.
Locations:

Corners:
	(0,0): corner of red-free region
	(2,0) to (2,2): red dividing wall
	(2,2) to (2,4): blue dividing wall
	(0,4): corner of blue-free region
	(4,0): corner of red-trapped region
	(4,4): corner of blue-trapped region

Starting positions:
	red free:
		(0, 1): back
		(2/3, 1): front
	blue free:
		(0, 3): back
		(2/3, 3): front
	red trapped:
		(8/3, 0): back
		(8/3, 2/3): front
	blue trapped:
		(8/3, 4): back
		(8/3, 10/3): front


Stuff to pick up:
	red trap:
		(3, 1)
		(2 + 1/3, 1 + 2/3)
		(2 + 2/3, 1 + 1/3)
		(3 + 1/3, 1 + 1/3)
		(3 + 2/3, 1 + 2/3)
	blue trap:
		(3, 3)
		(2 + 1/3, 3 + 1/3)
		(2 + 2/3, 3 + 2/3)
		(3 + 1/3, 3 + 2/3)
		(3 + 2/3, 3 + 1/3)
	free:
		(1 - 3/6, 2): blue barrel bottom, red ball top
		(1 - 2/6, 2): red barrel bottom, blue barrel middle, red ball top
		(1 - 1/6, 2): blue barrel bottom, red barrel middle bottom, blue barrel middle top, red ball top
		(1 + 1/6, 2): red barrel bottom, blue barrel middle bottom, red barrel middle top, blue ball top
		(1 + 2/6, 2): blue barrel bottom, red barrel middle, blue ball top
		(1 + 3/6, 2): red barrel bottom, blue ball top

*/

float boxLength = 20; // TODO: measure length of each box (I think sonar uses inches?)
float sonarThreshold = 5;

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
bool IsWall(distance)
{
	// TODO: see how close sonar is
	float x = SensorValue(sonarSensor);
	if(x <= distance + sonarThreshold || x >= distance - sonarThreshold)
	{
		return true;
	}
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
	rotate(180);
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
	if(rotate(-90) && isWall() && rotate(90)) // redAITrapped
	{
		// TODO: set X and Y
		currentX = 0;
		currentY = 0;
		redAITrapped();
	}
	else if(rotate(90) && isWall(0) && rotate(-90)) // blueAITrapped
	{
		// TODO: set X and Y
		currentX = 0;
		currentY = 0;
		blueAITrapped();
	}
	else if(rotate(90) && isWall(boxLength) && rotate(-90)) // redAIFree
	{
		// TODO: set X and Y
		currentX = 0;
		currentY = 0;
		redAIFree();
	}
	else if(rotate(-90) && isWall(boxLength) && rotate(90)) // blueAIFree
	{
		// TODO: set X and Y
		currentX = 0;
		currentY = 0;
		blueAIFree();
	}
	else // couldn't detect which region we're in
	{
		// TODO: set X and Y
		currentX = 0;
		currentY = 0;
		randomAttacksUsingSonar();
	}
}
