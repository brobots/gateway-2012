/* Region: AI Toggles */

// This returns true if a switch was made, or false if no switch made. Thus, it can be executed whenever with no consequences.
bool handleAISwitch(left, right, up, down)
{
	if (left == 1 || right == 1 || up == 1 || down == 1)
	{
		return true; // if it's time to switch to AI, return true.
	}

	else
	{
		// No AI overide buttons pressed, so no changes are necessary.
		return false;
	}
}
