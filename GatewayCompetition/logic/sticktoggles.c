/* Region: Stick Layout Toggles */

// This returns true if a switch was made, or false if no switch made. Thus, it can be executed whenever with no consequences.
bool handleLayoutSwitch(leftButton, upButton) // Btn7L: one stick; Btn7U: two stick;
{
	if (leftButton == 1) //if((vexRT[Btn7L] == 1))
	{
		isOneStickLayout = true;
		return true;
	}

	else if (upButton == 1) // ((vexRT[Btn7U] == 1))
	{
		isOneStickLayout = false;
		return true;
	}

	else
	{
		// Neither button pressed, so no changes.
		return false;
	}
}
