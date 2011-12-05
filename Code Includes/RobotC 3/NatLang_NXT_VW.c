/*--------------------------------------------------*\
|*	- Natural Language for NXT on Virtual Worlds -	*|
|*                                      			*|
|*	This file includes all of the Natural Language	*|
|*	functions for NXT on Virtual Worlds.			*|
\*---------------------------------------------4246-*/

#pragma systemFile            	// eliminates warning for "unreferenced" functions

// enum for RIGHT and LEFT direction:
typedef enum
{
  right = 0,
  left  = 1
}tDirections;


/************************\
|*  MOVEMENT FUNCTIONS  *|
\*******************************************************************************************************************************************/

//-------------------------------------------| StartMotor |-------------------------------------------
#ifndef _STARTMOTOR_H_GUARD
#define _STARTMOTOR_H_GUARD

void startMotor(tMotor motorPort = motorA, int speed = 75)
{
  motor[motorPort] = speed;
}

#endif
//----------------------------------------------------------------------------------------------------

//--------------------------------------------| Forward |---------------------------------------------
#ifndef _FORWARD_H_GUARD
#define _FORWARD_H_GUARD

void forward(int speed = 75)//, tMotor rm = motorB, tMotor lm = motorC, tMotor am = motorA) // other motor speeds?
{
  if(speed >= 0)
  {
    motor[motorB] = speed;
    motor[motorC] = speed;
  }
  else if(speed < 0)
  {
    motor[motorB] = (-1 * speed);
    motor[motorC] = (-1 * speed);
  }
}

#endif
//----------------------------------------------------------------------------------------------------

//--------------------------------------------| Backward |--------------------------------------------
#ifndef _BACKWARD_H_GUARD
#define _BACKWARD_H_GUARD

void backward(int speed = -75)//, tMotor rm = motorB, tMotor lm = motorC, tMotor am = motorA) // other motor speeds?
{
  if(speed <= 0)
  {
    motor[motorB] = speed;
    motor[motorC] = speed;
  }
  else if(speed > 0)
  {
    motor[motorB] = (-1 * speed);
    motor[motorC] = (-1 * speed);
  }
}

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------------| SwingTurn |--------------------------------------------
#ifndef _SWINGTURN_H_GUARD
#define _SWINGTURN_H_GUARD

void swingTurn(tDirections direction = right, int speed = 75)//, tMotor rm = motorB, tMotor lm = motorC, tMotor am = motorA) // other motor speeds?
{
  if(direction == left)      // left
  {
    if(speed >= 0)
    {
      motor[motorB] = speed;
      motor[motorC] = 0;
    }
    else if(speed < 0)
    {
      motor[motorB] = 0;
      motor[motorC] = speed;
    }
  }
  else if(direction == right) // right
  {
    if(speed >= 0)
    {
      motor[motorB] = 0;
      motor[motorC] = speed;
    }
    else if(speed < 0)
    {
      motor[motorB] = speed;
      motor[motorC] = 0;
    }
  }
}

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------------| PointTurn |--------------------------------------------
#ifndef _POINTTURN_H_GUARD
#define _POINTTURN_H_GUARD

void pointTurn(tDirections direction = right, int speed = 75)//, tMotor rm = motorB, tMotor lm = motorC, tMotor am = motorA) // other motor speeds?
{
  if(direction == 1)      // left
  {
    //motor[motorB] = abs(speed) * -1;
    //motor[motorC] = abs(speed);
    if(speed >= 0)
    {
      motor[motorB] = speed;
      motor[motorC] = speed * -1;
    }
    else if(speed < 0)
    {
      motor[motorB] = speed * -1;
      motor[motorC] = speed;
    }
  }
  else if(direction == 0) // right
  {
    //motor[motorB] = abs(speed);
    //motor[motorC] = abs(speed) * -1;
    if(speed >= 0)
    {
      motor[motorB] = speed * -1;
      motor[motorC] = speed;
    }
    else if(speed < 0)
    {
      motor[motorB] = speed;
      motor[motorC] = speed * -1;
    }
  }
}

#endif
//----------------------------------------------------------------------------------------------------

//----------------------------------------------| Stop |----------------------------------------------
#ifndef _STOP_H_GUARD
#define _STOP_H_GUARD

void stop()
{
  motor[motorB] = 0;
  motor[motorC] = 0;
}

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------------| StopMotor |--------------------------------------------
#ifndef _STOPMOTOR_H_GUARD
#define _STOPMOTOR_H_GUARD

void stopMotor(tMotor motorPort = motorA)//float t = 0.0)//tMotor rm = motorB, tMotor lm = motorC, tMotor am = motorA)
{
  motor[motorPort] = 0;
}

#endif
//----------------------------------------------------------------------------------------------------

//-----------------------------------------| LineTrackTIME |------------------------------------------
#ifndef _LINETRACKTIME_H_GUARD
#define _LINETRACKTIME_H_GUARD

void lineTrackForTime(float trackTime = 5.0, int threshold = 45, tSensors sensorPort = S3)
{
  float timeStart = ((float)nPgmTime / 1000);

  while(((float)nPgmTime / 1000) - timeStart < trackTime)
  {
    //nxtDisplayBigTextLine(3, "%0.4f", ((float)nPgmTime / 1000));  // debug
    //Line Follow:
    if(SensorValue[sensorPort] < threshold)        // DARK:
    {
      motor[motorB] = 25; // 25
      motor[motorC] = 55; // 55
    }
    else if(SensorValue[sensorPort] >= threshold)  // LIGHT:
    {
      motor[motorB] = 55; // 55
      motor[motorC] = 25; // 25
    }
	wait1Msec(1);
  }
}

#endif
//----------------------------------------------------------------------------------------------------

//---------------------------------------| LineTrackROTATIONS |---------------------------------------
#ifndef _LINETRACKROTS_H_GUARD
#define _LINETRACKROTS_H_GUARD

void lineTrackForRotations(float rotations = 3.0, int threshold = 45, tSensors sensorPort = S3)
{
  nMotorEncoder[motorB] = 0;
  nMotorEncoder[motorC] = 0;

  while((nMotorEncoder[motorB] < (rotations * 360))  &&  (nMotorEncoder[motorC] < (rotations * 360)))
  {
    //nxtDisplayBigTextLine(3, "%0.4f", ((float)nPgmTime / 1000));  // debug
    //Line Follow:
    if(SensorValue[sensorPort] < threshold)        // DARK:
    {
      motor[motorB] = 25;
      motor[motorC] = 55;
    }
    else if(SensorValue[sensorPort] >= threshold)  // LIGHT:
    {
      motor[motorB] = 55;
      motor[motorC] = 25;
    }
	wait1Msec(1);
  }
}

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------| MoveStraightROTATIONS |--------------------------------------
#ifndef _MOVESTRAIGHTROTS_H_GUARD
#define _MOVESTRAIGHTROTS_H_GUARD

void moveStraightForRotations(float rotations = 1.0)
{
  nMotorEncoder[motorB] = 0;  // right
  nMotorEncoder[motorC] = 0;  // left

  while(nMotorEncoder[motorB] < (abs(rotations) * 360))
  {
		if(nMotorEncoder[motorB] == nMotorEncoder[motorC]) // If rightEncoder has counted the same amount as leftEncoder:
		{
			// Move Forward
			motor[motorB] = 85;		// Right Motor is run at power level 85
			motor[motorC] = 85;		// Left Motor is run at power level 85
		}
		else if(nMotorEncoder[motorB] > nMotorEncoder[motorC])	// If rightEncoder has counted more encoder counts
		{
			// Turn slightly right
			motor[motorB] = 65;		// Right Motor is run at power level 65
			motor[motorC] = 85;		// Left Motor is run at power level 85
		}
		else	// Only runs if leftEncoder has counted more encoder counts
		{
			// Turn slightly left
			motor[motorB] = 85;		// Right Motor is run at power level 85
			motor[motorC] = 65;		// Left Motor is run at power level 65
		}
		wait1Msec(1);
  }
}

#endif
//----------------------------------------------------------------------------------------------------

//----------------------------------------| MoveStraightTIME |----------------------------------------
#ifndef _MOVESTRAIGHTTIME_H_GUARD
#define _MOVESTRAIGHTTIME_H_GUARD

void moveStraightForTime(float seconds = 5.0)
{
  nMotorEncoder[motorB] = 0;  // right
  nMotorEncoder[motorC] = 0;  // left

  float timeStart = ((float)nPgmTime / 1000);

  while(((float)nPgmTime / 1000) - timeStart < seconds)
  {
		if(nMotorEncoder[motorB] == nMotorEncoder[motorC]) // If rightEncoder has counted the same amount as leftEncoder:
		{
			// Move Forward
			motor[motorB] = 85;		// Right Motor is run at power level 85
			motor[motorC] = 85;   // Left Motor is run at power level 85
		}
		else if(nMotorEncoder[motorB] > nMotorEncoder[motorC])	// If rightEncoder has counted more encoder counts
		{
			// Turn slightly right
			motor[motorB] = 65;		// Right Motor is run at power level 65
			motor[motorC] = 85;		// Left Motor is run at power level 85
		}
		else	// Only runs if leftEncoder has counted more encoder counts
		{
			// Turn slightly left
			motor[motorB] = 85;		// Right Motor is run at power level 85
			motor[motorC] = 65;		// Left Motor is run at power level 65
		}
		wait1Msec(1);
  }
}

#endif
//----------------------------------------------------------------------------------------------------

/********************************************************************************************************************************************\
																												|*  END MOVEMENT FUNCTIONS  *|
																												\****************************/
/**********************\
|*  "WAIT" FUNCTIONS  *|
\*******************************************************************************************************************************************/

//----------------------------------------------| Wait |----------------------------------------------
#ifndef _WAIT_H_GUARD
#define _WAIT_H_GURAD

void wait(float waitTime = 1.0)
{
  long mins       = 0;
  long secs       = 0;
  long millisecs  = 0;
  if(waitTime >= 0)
  {
    mins = (waitTime / 60.0);
    secs = ((waitTime * 1000) / 1000) - (mins * 60);
    millisecs = (waitTime * 1000) - (((long)waitTime * 1000));
  }
  else if(waitTime < 0)
  {
    mins = ((waitTime * -1) / 60.0);
    secs = (((waitTime * -1) * 1000) / 1000) - (mins * 60);
    millisecs = ((waitTime * -1) * 1000) - (((long)(waitTime * -1) * 1000));
  }

  for(long i=0; i<mins; i++)      // minutes loop
  {
    wait10Msec(6000);
  }

  for(long j=0; j<secs; j++)      // seconds loop
  {
    wait1Msec(1000);
  }

  wait1Msec(millisecs);
}

#endif
//----------------------------------------------------------------------------------------------------

//---------------------------------------| WaitInMilliseconds |---------------------------------------
#ifndef _WAITINMILLISECONDS_H_GUARD
#define _WAITINMILLISECONDS_H_GUARD

void waitInMilliseconds(long waitTime = 1000)
{
  wait1Msec((long)waitTime);
}

#endif
//----------------------------------------------------------------------------------------------------

/******************************************************************************************************************************************\
																												|*  END "WAIT" FUNCTIONS  *|
																												\**************************/
/***********************\
|*  "UNTIL" FUNCTIONS  *|
\*******************************************************************************************************************************************/

//-------------------------------------| UntilCompassDegrees |--------------------------------------
#ifndef _UNTILCOMPASSDEGREES_H_GUARD
#define _UNTILCOMPASSDEGREES_H_GUARD

void untilCompassDegrees(int degrees = 90, int buffer = 0)
{
  int goal1 = (SensorValue(S2) + degrees) % 360;   // 'goal' is be the current compass reading + our turning degrees
                                                      /* We have to use modulus 360 to keep our goal within the bounds   */
                                                      /* of the compass (1 to 360 degrees, 0 is 360).                    */

  int goal2 = abs((SensorValue(S2) - degrees) % 360);   //(goal1 + 180) % 360;

  int upperBound1 = goal1 + buffer;
  int lowerBound1 = goal1 - buffer;
  int upperBound2 = goal2 + buffer;
  int lowerBound2 = goal2 - buffer;

  //while(SensorValue(S2) != goal1 && SensorValue(S2) != goal2);    // while the compass sensor reading is not yet our goal:
  while((SensorValue(S2) > upperBound1 || SensorValue(S2) < lowerBound1)  &&  (SensorValue(S2) > upperBound2 || SensorValue(S2) < lowerBound2)){wait1Msec(1);}

}

#endif
//----------------------------------------------------------------------------------------------------

//---------------------------------------| UntilSonarLessThan |---------------------------------------
#ifndef _UNTILSONARLESSTHAN_H_GUARD
#define _UNTILSONARLESSTHAN_H_GUARD

void untilSonarLessThan(int distance = 30)
{
  while(SensorValue[S4] >= distance || SensorValue[S4] == -1){wait1Msec(1);}
}

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------| UntilSonarGreaterThan |--------------------------------------
#ifndef _UNTILSONARGREATERTHAN_H_GUARD
#define _UNTILSONARGREATERTHAN_H_GUARD

void untilSonarGreaterThan(int distance = 30)
{
  while(SensorValue[S4] < distance || SensorValue[S4] == -1){wait1Msec(1);}
}

#endif
//----------------------------------------------------------------------------------------------------

//-----------------------------------------| UntilRotations |-----------------------------------------
#ifndef _UNTILROTATIONS_H_GUARD
#define _UNTILROTATIONS_H_GUARD

void untilRotations(float rotations = 1.0, tMotor motorPort = motorB)//, int speed = 75, tMotor rm = motorB, tMotor lm = motorC, tMotor am = motorA)
{
	nMotorEncoder[motorPort] = 0;
	while((   (nMotorEncoder[motorPort] < (rotations * 360))   ||   
	(nMotorEncoder[motorPort] < (rotations * (360 * -1)))   )   &&   (   (nMotorEncoder[motorPort] > (rotations * 360))   ||   
	(nMotorEncoder[motorPort] > (rotations * (360 * -1)))   ))
	{
		wait1Msec(1);
	}

	nMotorEncoder[motorPort] = 0;
}

#endif
//----------------------------------------------------------------------------------------------------

//---------------------------------------| UntilEncoderCounts |---------------------------------------
#ifndef _UNTILENCODERCOUNTS_H_GUARD
#define _UNTILENCODERCOUNTS_H_GUARD

void untilEncoderCounts(int distance = 360, tMotor motorPort = motorB)//, int speed = 75, tMotor rm = motorB, tMotor lm = motorC, tMotor am = motorA)
{
  nMotorEncoder[motorPort] = 0;

  while((   (nMotorEncoder[motorPort] < distance)   ||   
			(nMotorEncoder[motorPort] < (distance * -1))   )   &&   (   (nMotorEncoder[motorPort] > distance)   ||   
			(nMotorEncoder[motorPort] > (distance * -1))   ))
			{
				wait1Msec(1);
			}

  nMotorEncoder[motorPort] = 0;
}

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------------| UntilTouch |-------------------------------------------
#ifndef _UNTILTOUCH_H_GUARD
#define _UNTILTOUCH_H_GUARD

void untilTouch(tSensors sensorPort = S1)
{
  while(SensorValue[sensorPort] != 1){wait1Msec(1);}
}

#endif
//----------------------------------------------------------------------------------------------------

//------------------------------------------| UntilRelease |------------------------------------------
#ifndef _UNTILRELEASE_H_GUARD
#define _UNTILRELEASE_H_GUARD

void untilRelease(tSensors sensorPort = S1)
{
  while(SensorValue[sensorPort] != 0){wait1Msec(1);}
}

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------------| UntilBump |--------------------------------------------
#ifndef _UNTILBUMP_H_GUARD
#define _UNTILBUMP_H_GUARD

void untilBump(tSensors sensorPort = S1, int delayTimeMS = 10)
{
  while(SensorValue[sensorPort] != 1){wait1Msec(1);}
  wait1Msec(delayTimeMS);
  while(SensorValue[sensorPort] != 0){wait1Msec(1);}
}

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------------| UntilDark |--------------------------------------------
#ifndef _UNTILDARK_H_GUARD
#define _UNTILDARK_H_GUARD

void untilDark(int threshold = 45, tSensors sensorPort = S3)
{
  while(SensorValue[sensorPort] > threshold);
}

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------------| UntilLight |-------------------------------------------
#ifndef _UNTILLIGHT_H_GUARD
#define _UNTILLIGHT_H_GUARD

void untilLight(int threshold = 45, tSensors sensorPort = S3)
{
  while(SensorValue[sensorPort] < threshold);
}

#endif
//----------------------------------------------------------------------------------------------------

/*******************************************************************************************************************************************\
																												|*  END "UNTIL" FUNCTIONS  *|
																												\***************************/
