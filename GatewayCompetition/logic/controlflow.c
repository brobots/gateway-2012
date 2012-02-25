/* Region: Control Flow */

bool userControl()
{
	if (handleLayoutSwitch(0, vexRT[Btn7U])) // combination to switch to a layout, if necessary // HACK: 0 is instead of a 7D return, so that we never go into one-stick
	{
		return false;
		wait1Msec(20); // short reset time
	}

	if (isOneStickLayout == true)
	{
		if(!oneStickLayout())
		{
			return false;
		}
	}
	else
	{
		if(!twoStickLayout())
		{
			return false;
		}
	}

	return true; // keep going
}

void userControlLooped()
{
	while (true)
	{
		if(!userControl())
		{
			break;
		}
	}
}

bool aiControl(left, right, up, down)
{
	if (left == 1)
	{
		if(!redAITrapped())
		{
			return false; // let's break
		}
	}
	else if (right == 1)
	{
		if(!blueAITrapped())
		{
			return false; // let's break
		}
	}
	else if (up == 1)
	{
		if(!redAIFree())
		{
			return false; // let's break
		}
	}
	else if (down == 1)
	{
		if(!blueAIFree())
		{
			return false; // let's break
		}
	}
	else
	{
		// awkward
		return false; // back to user control, since our AI stuff didn't work.
	}

	return true; // keep going
}

void aiControlTimed(left, right, up, down)
{
	ClearTimer(T1);
	while (time10[T1] < 2000)
	{
		if(!(aiControl(left, right, up, down)))
		{
			break; return;
		}
	}
}
