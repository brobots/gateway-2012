/* Region: AIs */

/* Field details:

12ft by 12ft, divided into 4 boxes by 4 boxes. Each region = 2 boxes by 2 boxes. Thus, each box = 3ft by 3ft = 36in. by 36in.

Angles: starting from (0,0), going clockwise. (1, 0) is 90 degrees.

Locations (measured always in terms of boxes):

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

float boxLength = 36; // in inches
float sonarThreshold = 5;
float wheelDiameter = 4; // in inches // TODO: measure this


/* Region: Movement methods */

// Conversions
float boxesToInches(boxes)
{
	return boxes *	3 * 12; // each box = 3 ft = 12 * 3 in.
}
float inchesToBoxes(inches)
{
	return inches / 12 / 3; // each box = 3 ft = 12 * 3 in.
}
float numRotations(distance) // distance is in inches
{
	// TODO: is this correct?
	// (360n) * (pi) * wheelDiameter = distance
	return distance / wheelDiameter / PI;
}

// Movement
bool rotate(angle)
{
	resetEncoders();
	while(SensorValue[leftEncoder] < (angle*4))  // While haven't rotated by that whole angle yet
  {


  if(angle < 0) // turn left
  {
    motor[leftMotor] = 127;
    motor[rightMotor] = -127;
  }
  else // turn right
  {
    motor[leftMotor] = -127;
    motor[rightMotor] = 127;
  }
}

resetEncoders();

  currentAngle += angle;
	return true;
}
bool goVector(changeX, changeY, changeAngle)
{
	rotate(changeAngle);

	// TODO: move by a vector

	distance/(4*pi);
	motor[leftMotor] = 127;
	motor[rightMotor] = 127;
	return true;
}
bool goToCoordinates(destinationX, destinationY)
{
	float changeX = destinationX - currentX;
	float changeY = destinationY - currentY;

	// TODO: calculate angle change
	float changeAngle = currentAngle;

	return goVector(changeX, changeY, changeAngle);
}
bool SeeBlock(distance)
{
	// read sonar to detect a block; return true if block visible; return false if no block.
	float x = SensorValue(sonarSensor);
	if(distance >= 0)
	{
		if(x <= distance + sonarThreshold || x >= distance - sonarThreshold)
		{
			return true;
		}
	}
	else // if -1, any distance
	{
		if(x != -1 && x >= sonarThreshold)
		{
			return true;
		}
	}
	return false;
}
bool IsWall(distance)
{
	// TODO: bump sensor would be better for this.
	return SeeBlock(distance);
}
bool capture()
{
	// TODO: we currently have a thing in our grasp. now, we slide it into our robot and capture it.

	return true;
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
		capture();
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

/* Region: strategy methods */

bool blueAIFree()
{
	while (true)
	{
		if (handleLayoutSwitch(vexRT[Btn7L], vexRT[Btn7U])) // combination to switch to a layout
		{
			// one of those buttons was pressed, so we switched to a controller layout and now we deactivate AI.
			return false; break; // exit AI, proceed to user-controlled mode
		}

		// TODO: Do AI stuff
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

		// TODO: Do AI stuff
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

		// Do AI stuff: capture all barrels
		goToCoordinates(3 + 2/3, 3 + 1/3);
		capture();
		goToCoordinates(3 + 1/3, 3 + 2/3);
		capture();
		goToCoordinates(3, 3);
		capture();
		goToCoordinates(3 - 1/3, 3 + 2/3); // xval = 2 + 2/3
		capture();
		goToCoordinates(3 - 2/3, 3 + 1/3); // xval = 2 + 1/3

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

		// Do AI stuff: capture all barrels
		goToCoordinates(3 + 2/3, 1 + 2/3);
		capture();
		goToCoordinates(3 + 1/3, 1 + 1/3);
		capture();
		goToCoordinates(3, 1);
		capture();
		goToCoordinates(3 - 1/3, 1 + 1/3); // xval = 2 + 2/3
		capture();
		goToCoordinates(3 - 2/3, 1 + 2/3); // xval = 2 + 1/3

	}
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
				// something was found
				wait1Msec(10); // pause, rescan to see if object moves
				if(SensorValue(sonarSensor) == x) // if object hasn't moved, it's probably a block
				{
					captureWithSonar();
				}
			}
		}
	}

	return true;
}

/* Region: control flow */

void launchCompetitionAI()
{
	if(rotate(-90) && isWall(0) && rotate(90)) // redAITrapped
	{
		currentX = 8/3;
		currentY = 0;
		currentAngle = 0;
		redAITrapped();
	}
	else if(rotate(90) && isWall(0) && rotate(-90)) // blueAITrapped
	{
		currentX = 8/3;
		currentY = 4;
		currentAngle = 180;
		blueAITrapped();
	}
	else if(rotate(90) && isWall(boxLength) && rotate(-90)) // redAIFree
	{
		currentX = 0;
		currentY = 1;
		currentAngle = 90;
		redAIFree();
	}
	else if(rotate(-90) && isWall(boxLength) && rotate(90)) // blueAIFree
	{
		currentX = 0;
		currentY = 3;
		currentAngle = 90;
		blueAIFree();
	}
	else // couldn't detect which region we're in
	{
		// "default" X and Y
		currentX = 0;
		currentY = 0;
		currentAngle = 0;
		// TODO: drive out a bit to middle or something before calling randomAttacksUsingSonar()
		randomAttacksUsingSonar();
	}
}
