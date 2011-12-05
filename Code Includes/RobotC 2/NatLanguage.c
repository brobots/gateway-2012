/*----------------------------------------------------------------------------------------------------*\
|*                                    - Natural Language Header -                                     *|
|*                                      ROBOTC on PLATFORM TYPE                                       *|
|*                                                                                                    *|
|*  This header file includes all of the Natural Language Keywords of all platforms...for now.        *|
\*-----------------------------------------------------------------------------------------------4246-*/
#pragma systemFile            // this eliminates warning for "unreferenced" functions
#include "NatLanguageInit.c"

typedef enum
{
  right = 0,
  left  = 1
}tDirections;

typedef enum
{
  cancelBtnNXT = 0,
  rightBtnNXT  = 1,
  leftBtnNXT   = 2,
  centerBtnNXT = 3
}tNxtButtons;

typedef enum
{
  leftBtnVEX            = 1,
  centerBtnVEX          = 2,
  //leftANDcenterBtnVEX   = 3,
  rightBtnVEX           = 4//,
  //leftANDrightBtnVEX    = 5,
  //centerANDrightBtnVEX  = 6,
  //allBtnsVEX            = 7
}tVEXLCDButtons;

typedef enum
{
  none		= 0,
  recbot	= 1,
  swervebot = 2
}tRobotType;



/*********************\
|*  SETUP FUNCTIONS  *|
\*******************************************************************************************************************************************/

//-------------------------------------------| RobotType |--------------------------------------------
#if defined(VEX2)
#ifndef _ROBOTTYPE_H_GUARD
#define _ROBOTTYPE_H_GUARD
void robotType(int type = none)
{
  if(type == 0)             // None
  {
	bMotorReflected[port2] = 0;
    bMotorReflected[port3] = 0;
  }
  else if(type == 1)        // Recbot
  {
    bMotorReflected[port2] = 1;
    bMotorReflected[port3] = 0;
  }
  else if(type == 2)        // Swervebot
  {
    bMotorReflected[port2] = 0;
    bMotorReflected[port3] = 1;
  }
}
#endif
#endif
//----------------------------------------------------------------------------------------------------

/*******************************************************************************************************************************************\
|*  SETUP FUNCTIONS  *|
\*********************/





/************************\
|*  MOVEMENT FUNCTIONS  *|
\*******************************************************************************************************************************************/

//-------------------------------------------| StartMotor |-------------------------------------------
#ifndef _STARTMOTOR_H_GUARD
#define _STARTMOTOR_H_GUARD

#if defined(NXT)

void startMotor(tMotor motorPort = motorA, int speed = 75)
{
  motor[motorPort] = speed;
}

#elif defined(VEX2)

void startMotor(tMotor motorPort = port6, int speed = 95)
{
  motor[motorPort] = speed;
}

/*#elif defined(TETRIX)
void startMotor(long t)
{
wait1Msec((long)t);
}
#elif defined(VEX)
void startMotor(long t)
{
wait1Msec((long)t);
}*/
#endif

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------------| StopMotor |--------------------------------------------
#ifndef _STOPMOTOR_H_GUARD
#define _STOPMOTOR_H_GUARD

#if defined(NXT)

void stopMotor(tMotor motorPort = motorA)
{
  motor[motorPort] = 0;
}

#elif defined(VEX2)

void stopMotor(tMotor motorPort = port6)
{
  motor[motorPort] = 0;
}

/*#elif defined(TETRIX)
void stopMotor(long t)
{
wait1Msec((long)t);
}
#elif defined(VEX)
void stopMotor(long t)
{
wait1Msec((long)t);
}*/
#endif

#endif
//----------------------------------------------------------------------------------------------------

//--------------------------------------------| SetServo |--------------------------------------------
#ifndef _SETSERVO_H_GUARD
#define _SETSERVO_H_GUARD

#if defined(VEX2)

void setServo(tMotor servoPort = port6, int position = 0)
{
  motor[servoPort] = position;
}

#endif
#endif
//----------------------------------------------------------------------------------------------------

/*******************************************************************************************************************************************\
|*  MOVEMENT FUNCTIONS  *|
\************************/






/**********************\
|*  "WAIT" FUNCTIONS  *|
\*******************************************************************************************************************************************/

//----------------------------------------------| Wait |----------------------------------------------
#ifndef _WAIT_H_GUARD
#define _WAIT_H_GURAD

#if defined(NXT) || defined(TETRIX) || defined(VEX2)

void wait(float waitTime = 1.0)
{
  long mins = (abs(waitTime) / 60.0);
  long secs = ((abs(waitTime) * 1000) / 1000) - (mins * 60);
  long millisecs = (abs(waitTime) * 1000) - ((abs((long)waitTime) * 1000));

  for(long i=0; i<mins; i++)      // minutes loop
  {
    wait10Msec(6000);
  }

  for(long j=0; j<secs; j++)      // seconds loop
  {
    wait1Msec(1000);
  }

  /*for(long k=0; k<millisecs; k++) // milliseconds loop
  {
    wait1Msec(1);
  }*/

  wait1Msec(millisecs);
}

#elif defined(VEX)
void wait(long waitTime = 1)
{
  long mins = (abs(waitTime) / 60);
  long time = ((abs(waitTime) % 60 ) * 1000);

  for(long i=0; i<mins; i++)      // minutes loop
  {
    wait10Msec(6000);
  }

  for(long j=0; j<time; j++)      // remainder loop
  {
    wait1Msec(1);
  }
}
#endif

#endif
//----------------------------------------------------------------------------------------------------

//---------------------------------------| WaitInMilliseconds |---------------------------------------
#ifndef _WAITINMILLISECONDS_H_GUARD
#define _WAITINMILLISECONDS_H_GUARD

#if defined(NXT) || defined(TETRIX) || defined(VEX2)
void waitInMilliseconds(long waitTime = 1000)
{
  wait1Msec((long)waitTime);
}

#elif defined(VEX)
void waitInMilliseconds(long waitTime = 1000)
{
  wait1Msec((long)waitTime);
}
#endif

#endif
//----------------------------------------------------------------------------------------------------
/*******************************************************************************************************************************************\
|*  "WAIT" FUNCTIONS  *|
\**********************/






/***********************\
|*  "UNTIL" FUNCTIONS  *|
\*******************************************************************************************************************************************/

//-------------------------------------------| UntilTouch |-------------------------------------------
#ifndef _UNTILTOUCH_H_GUARD
#define _UNTILTOUCH_H_GUARD

#if defined(NXT)

void untilTouch(tSensors sensorPort = S1)
{
  while(SensorValue[sensorPort] != 1);
}

#elif defined(VEX2)

void untilTouch(tSensors sensorPort = dgtl6)
{
  while(SensorValue[sensorPort] != 1);
}

/*#elif defined(TETRIX)
void untilTouch(long t)
{
wait1Msec((long)t);
}
#elif defined(VEX)
void untilTouch(long t)
{
wait1Msec((long)t);
}*/
#endif

#endif
//----------------------------------------------------------------------------------------------------

//------------------------------------------| UntilRelease |------------------------------------------
#ifndef _UNTILRELEASE_H_GUARD
#define _UNTILRELEASE_H_GUARD

#if defined(NXT)

void untilRelease(tSensors sensorPort = S1)
{
  while(SensorValue[sensorPort] != 0);
}

#elif defined(VEX2)

void untilRelease(tSensors sensorPort = dgtl6)
{
  while(SensorValue[sensorPort] != 0);
}

/*#elif defined(TETRIX)
void untilRelease(long t)
{
wait1Msec((long)t);
}
#elif defined(VEX)
void untilRelease(long t)
{
wait1Msec((long)t);
}*/
#endif

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------------| UntilBump |--------------------------------------------
#ifndef _UNTILBUMP_H_GUARD
#define _UNTILBUMP_H_GUARD

#if defined(NXT)

void untilBump(tSensors sensorPort = S1)
{
  while(SensorValue[sensorPort] != 1);
  while(SensorValue[sensorPort] != 0);
}

#elif defined(VEX2)

void untilBump(tSensors sensorPort = dgtl6)
{
  while(SensorValue[sensorPort] != 1);
  wait1Msec(10);
  while(SensorValue[sensorPort] != 0);
}

/*#elif defined(TETRIX)
void untilBump(long t)
{
wait1Msec((long)t);
}
#elif defined(VEX)
void untilBump(long t)
{
wait1Msec((long)t);
}*/
#endif

#endif
//----------------------------------------------------------------------------------------------------

//---------------------------------------| UntilSonarLessThan |---------------------------------------
#ifndef _UNTILSONARLESSTHAN_H_GUARD
#define _UNTILSONARLESSTHAN_H_GUARD

#if defined(NXT)

void untilSonarLessThan(int distance = 30, tSensors sensorPort = S4)
{
  while(SensorValue[sensorPort] > distance || SensorValue[sensorPort] == 255);
}

#elif defined(VEX2)

void untilSonarLessThan(int distance = 30, tSensors sensorPort = dgtl8)
{
  while(SensorValue[sensorPort] > distance || SensorValue[sensorPort] == -1);
}

/*#elif defined(TETRIX)
void untilSonarLessThan(long t)
{
wait1Msec((long)t);
}
#elif defined(VEX)
void untilSonarLessThan(long t)
{
wait1Msec((long)t);
}*/
#endif

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------| UntilSonarGreaterThan |--------------------------------------
#ifndef _UNTILSONARGREATERTHAN_H_GUARD
#define _UNTILSONARGREATERTHAN_H_GUARD

#if defined(NXT)

void untilSonarGreaterThan(int distance = 30, tSensors sensorPort = S4)
{
  while(SensorValue[sensorPort] < distance || SensorValue[sensorPort] == 255);
}

#elif defined(VEX2)

void untilSonarGreaterThan(int distance = 30, tSensors sensorPort = dgtl8)
{
  while(SensorValue[sensorPort] < distance || SensorValue[sensorPort] == -1);
}

/*#elif defined(TETRIX)
void untilSonarGreaterThan(long t)
{
wait1Msec((long)t);
}
#elif defined(VEX)
void untilSonarGreaterThan(long t)
{
wait1Msec((long)t);
}*/
#endif

#endif
//----------------------------------------------------------------------------------------------------

//-----------------------------------| UntilPotentiometerLessThan |-----------------------------------
#ifndef _UNTILPOTENTIOMETERLESSTHAN_H_GUARD
#define _UNTILPOTENTIOMETERLESSTHAN_H_GUARD

#if defined(VEX2)

void untilPotentiometerLessThan(int position = 2048, tSensors sensorPort = in6)
{
  while(SensorValue[sensorPort] > abs(position));
}

#endif
#endif
//----------------------------------------------------------------------------------------------------

//---------------------------------| UntilPotentiometerGreaterThan |----------------------------------
#ifndef _UNTILPOTENTIOMETERGREATERTHAN_H_GUARD
#define _UNTILPOTENTIOMETERGREATERTHAN_H_GUARD

#if defined(VEX2)

void untilPotentiometerGreaterThan(int position = 2048, tSensors sensorPort = in6)
{
  while(SensorValue[sensorPort] < abs(position));
}

#endif
#endif
//----------------------------------------------------------------------------------------------------

//----------------------------------------| UntilButtonPress |----------------------------------------
#ifndef _UNTILBUTTONPRESS_H_GUARD
#define _UNTILBUTTONPRESS_H_GUARD

#if defined(NXT)

void untilButtonPress(int button = centerBtnNXT)
{
  while(true)
  {
    if(nNxtButtonPressed == button)
    {
      break;
    }
  }
}

#elif defined(VEX2)

void untilButtonPress(int button = centerBtnVEX)
{
  while(true)
  {
    if(nLCDButtons == button)
    {
      break;
    }
  }
}

/*#elif defined(TETRIX)
void untilButtonPress(long t)
{
wait1Msec((long)t);
}
#elif defined(VEX)
void untilButtonPress(long t)
{
wait1Msec((long)t);
}*/
#endif

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------------| UntilDark |--------------------------------------------
#ifndef _UNTILDARK_H_GUARD
#define _UNTILDARK_H_GUARD

#if defined(NXT)

void untilDark(int threshold = 30, tSensors sensorPort = S3)
{
  while(SensorValue[sensorPort] > threshold);
}

#elif defined(VEX2)

void untilDark(int threshold = 505, tSensors sensorPort = in2)
{
  while(SensorValue[sensorPort] < threshold);
}

/*#elif defined(TETRIX)
void untilDark(long t)
{
wait1Msec((long)t);
}
#elif defined(VEX)
void untilDark(long t)
{
wait1Msec((long)t);
}*/
#endif

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------------| UntilLight |-------------------------------------------
#ifndef _UNTILLIGHT_H_GUARD
#define _UNTILLIGHT_H_GUARD

#if defined(NXT)

void untilLight(int threshold = 30, tSensors sensorPort = S3)
{
  while(SensorValue[sensorPort] < threshold);
}

#elif defined(VEX2)

void untilLight(int threshold = 505, tSensors sensorPort = in2)
{
  while(SensorValue[sensorPort] > threshold);
}

/*#elif defined(TETRIX)
void untilLight(long t)
{
wait1Msec((long)t);
}
#elif defined(VEX)
void untilLight(long t)
{
wait1Msec((long)t);
}*/
#endif

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------------| UntilSound |-------------------------------------------
#ifndef _UNTILSOUND_H_GUARD
#define _UNTILSOUND_H_GUARD

#if defined(NXT)

void untilSound(int threshold = 50, tSensors sensorPort = S2)
{
  while(SensorValue[sensorPort] < threshold);
}

/*#elif defined(TETRIX)
void untilSound(long t)
{
wait1Msec((long)t);
}
#elif defined(VEX2)
void untilSound(long t)
{
wait1Msec((long)t);
}
#elif defined(VEX)
void untilSound(long t)
{
wait1Msec((long)t);
}*/
#endif

#endif
//----------------------------------------------------------------------------------------------------

//-----------------------------------------| UntilRotations |-----------------------------------------
#ifndef _UNTILROTATIONS_H_GUARD
#define _UNTILROTATIONS_H_GUARD

#if defined(NXT)

void untilRotations(float rotations = 1.0, tMotor motorPort = motorB)
{
  nMotorEncoder[motorPort] = 0;

  while(nMotorEncoder[motorPort] < (long)(abs(rotations) * 360)  &&  nMotorEncoder[motorPort] > (long)(abs(rotations) * (360 * -1)));
}

#elif defined(VEX2)

void untilRotations(float rotations = 1.0, tSensors sensorPort = dgtl1)
{
  SensorValue[sensorPort] = 0;

  while(SensorValue[sensorPort] < (abs(rotations) * 360)  &&  SensorValue[sensorPort] > (abs(rotations) * (360 * -1)));
}

/*#elif defined(TETRIX)
void untilRotations(long t)
{
wait1Msec((long)t);
}
#elif defined(VEX)
void untilRotations(long t)
{
wait1Msec((long)t);
}*/
#endif

#endif
//----------------------------------------------------------------------------------------------------

//---------------------------------------| UntilEncoderCounts |---------------------------------------
#ifndef _UNTILENCODERCOUNTS_H_GUARD
#define _UNTILENCODERCOUNTS_H_GUARD

#if defined(NXT)

void untilEncoderCounts(int distance = 360, tMotor m = motorB)
{
  nMotorEncoder[m] = 0;

  while(nMotorEncoder[m] < (abs(distance))  &&  nMotorEncoder[m] > (abs(distance) * -1));
}

#elif defined(VEX2)

void untilEncoderCounts(int distance = 360, tSensors sensorPort = dgtl1)
{
  SensorValue[sensorPort] = 0;

  while(SensorValue[sensorPort] < (abs(distance))  &&  SensorValue[sensorPort] > (abs(distance) * -1));
}

/*#elif defined(TETRIX)
void untilEncoderCounts(long t)
{
wait1Msec((long)t);
}
#elif defined(VEX)
void untilEncoderCounts(long t)
{
wait1Msec((long)t);
}*/
#endif

#endif
//----------------------------------------------------------------------------------------------------

/*******************************************************************************************************************************************\
|*  "UNTIL" FUNCTIONS  *|
\***********************/






/****************************\
|*  ROBOT MOTION FUNCTIONS  *|
\*******************************************************************************************************************************************/

//--------------------------------------------| Forward |---------------------------------------------
#ifndef _FORWARD_H_GUARD
#define _FORWARD_H_GUARD

#if defined(NXT)

void forward(int speed = 75)
{
  motor[motorB] = abs(speed);
  motor[motorC] = abs(speed);
}

#elif defined(VEX2)

void forward(int speed = 95)
{
  motor[port2] = abs(speed);
  motor[port3] = abs(speed);
}
/*#elif defined(TETRIX)
void forward(long t)
{
wait1Msec((long)t);
}
#elif defined(VEX)
void forward(long t)
{
wait1Msec((long)t);
}*/
#endif

#endif
//----------------------------------------------------------------------------------------------------

//--------------------------------------------| Backward |--------------------------------------------
#ifndef _BACKWARD_H_GUARD
#define _BACKWARD_H_GUARD

#if defined(NXT)

void backward(int speed = -75)
{
  motor[motorB] = abs(speed) * -1;
  motor[motorC] = abs(speed) * -1;
}

#elif defined(VEX2)

void backward(int speed = -95)
{
  motor[port2] = abs(speed) * -1;
  motor[port3] = abs(speed) * -1;
}
/*#elif defined(TETRIX)
void backward(long t)
{
wait1Msec((long)t);
}
#elif defined(VEX)
void backward(long t)
{
wait1Msec((long)t);
}*/
#endif

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------------| SwingTurn |--------------------------------------------
#ifndef _SWINGTURN_H_GUARD
#define _SWINGTURN_H_GUARD

#if defined(NXT)

void swingTurn(int direction = right, int speed = 75)
{
  if(direction == 1)      // LEFT
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
  else if(direction == 0) // RIGHT
  {
    if(speed >= 0)
    {
      motor[motorB] = 0;
      motor[motorC] = abs(speed);
    }
    else if(speed < 0)
    {
      motor[motorB] = speed;
      motor[motorC] = 0;
    }
  }
}

#elif defined(VEX2)

void swingTurn(int direction = right, int speed = 95)
{
  if(direction == 1)      // LEFT
  {
    if(speed >= 0)
    {
      motor[port2] = speed;
      motor[port3] = 0;
    }
    else if(speed < 0)
    {
      motor[port2] = 0;
      motor[port3] = speed;
    }
  }
  else if(direction == 0) // RIGHT
  {
    if(speed >= 0)
    {
      motor[port2] = 0;
      motor[port3] = abs(speed);
    }
    else if(speed < 0)
    {
      motor[port2] = speed;
      motor[port3] = 0;
    }
  }
}

/*#elif defined(TETRIX)
void swingTurn(long t)
{
wait1Msec((long)t);
}
#elif defined(VEX)
void swingTurn(long t)
{
wait1Msec((long)t);
}*/
#endif

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------------| PointTurn |--------------------------------------------
#ifndef _POINTTURN_H_GUARD
#define _POINTTURN_H_GUARD

#if defined(NXT)

void pointTurn(int direction = right, int speed = 75)
{
  if(direction == 1)      // LEFT
  {
    motor[motorB] = abs(speed);
    motor[motorC] = abs(speed) * -1;
  }
  else if(direction == 0) // RIGHT
  {
    motor[motorB] = abs(speed) * -1;
    motor[motorC] = abs(speed);
  }
}

#elif defined(VEX2)

void pointTurn(int direction = right, int speed = 95)
{
  if(direction == 1)      // LEFT
  {
    motor[port2] = abs(speed);
    motor[port3] = abs(speed) * -1;
  }
  else if(direction == 0) // RIGHT
  {
    motor[port2] = abs(speed) * -1;
    motor[port3] = abs(speed);
  }
}

/*#elif defined(TETRIX)
void pointTurn(long t)
{
wait1Msec((long)t);
}
#elif defined(VEX)
void pointTurn(long t)
{
wait1Msec((long)t);
}*/
#endif

#endif
//----------------------------------------------------------------------------------------------------

//----------------------------------------------| Stop |----------------------------------------------
#ifndef _STOP_H_GUARD
#define _STOP_H_GUARD

#if defined(NXT)

void stop()
{
  motor[motorB] = 0;
  motor[motorC] = 0;
}

#elif defined(VEX2)

void stop()
{
  motor[port2] = 0;
  motor[port3] = 0;
}

/*#elif defined(TETRIX)
void stop(long t)
{
wait1Msec((long)t);
}
#elif defined(VEX)
void stop(long t)
{
wait1Msec((long)t);
}*/
#endif

#endif
//----------------------------------------------------------------------------------------------------

//-----------------------------------------| LineTrackTIME |------------------------------------------
#ifndef _LINETRACKTIME_H_GUARD
#define _LINETRACKTIME_H_GUARD

#if defined(NXT)

void lineTrackForTime(float trackTime = 5.0, int threshold = 45, tSensors sensorPort = S3)
{
  float timeStart = ((float)nPgmTime / 1000);

  while(((float)nPgmTime / 1000) - timeStart < trackTime)
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
  }
}

#elif defined(VEX2)

void lineTrackForTime(float trackTime = 5.0, int threshold = 505, tSensors leftSensorPort = in1, tSensors centerSensorPort = in2, tSensors rightSensorPort = in3)
{
  float timeStart = ((float)nPgmTime / 1000);

  while(((float)nPgmTime / 1000) - timeStart < trackTime)
  {
    // RIGHT sensor sees dark:
    if(SensorValue(rightSensorPort) > threshold)
    {
      // counter-steer right:
      motor[port2] = 0;
      motor[port3] = 85;
    }
    // CENTER sensor sees dark:
    if(SensorValue(centerSensorPort) > threshold)
    {
      // go straight
      motor[port2] = 85;
      motor[port3] = 85;
    }
    // LEFT sensor sees dark:
    if(SensorValue(leftSensorPort) > threshold)
    {
      // counter-steer left:
      motor[port2] = 85;
      motor[port3] = 0;
    }
  }
}

/*#elif defined(TETRIX)
void untilDegrees(long t)
{
wait1Msec((long)t);
}
#elif defined(VEX)
void untilDegrees(long t)
{
wait1Msec((long)t);
}*/
#endif

#endif
//----------------------------------------------------------------------------------------------------

//---------------------------------------| LineTrackROTATIONS |---------------------------------------
#ifndef _LINETRACKROTS_H_GUARD
#define _LINETRACKROTS_H_GUARD

#if defined(NXT)

void lineTrackForRotations(float r = 3.0, int h = 45, tSensors l = S3)
{
  nMotorEncoder[motorB] = 0;
  nMotorEncoder[motorC] = 0;

  while((nMotorEncoder[motorB] < (r * 360))  &&  (nMotorEncoder[motorC] < (r * 360)))
  {
    //nxtDisplayBigTextLine(3, "%0.4f", ((float)nPgmTime / 1000));  // debug
    //Line Follow:
    if(SensorValue[l] < h)        // DARK:
    {
      motor[motorB] = 25;
      motor[motorC] = 55;
    }
    else if(SensorValue[l] >= h)  // LIGHT:
    {
      motor[motorB] = 55;
      motor[motorC] = 25;
    }
  }
}

#elif defined(VEX2)

void lineTrackForRotations(float rotations = 3.0, int threshold = 505, tSensors leftSensorPort = in1, tSensors centerSensorPort = in2, tSensors rightSensorPort = in3)
{
  SensorValue[dgtl1] = 0;
  SensorValue[dgtl3] = 0;

  while((SensorValue[dgtl1] < (rotations * 360))  &&  (SensorValue[dgtl3] < (rotations * 360)))
  {
    // RIGHT sensor sees dark:
    if(SensorValue(rightSensorPort) > threshold)
    {
      // counter-steer right:
      motor[port2] = 0;
      motor[port3] = 85;
    }
    // CENTER sensor sees dark:
    if(SensorValue(centerSensorPort) > threshold)
    {
      // go straight
      motor[port2] = 85;
      motor[port3] = 85;
    }
    // LEFT sensor sees dark:
    if(SensorValue(leftSensorPort) > threshold)
    {
      // counter-steer left:
      motor[port2] = 85;
      motor[port3] = 0;
    }
  }
}

/*#elif defined(TETRIX)
void lineTrackForRotations(long t)
{
wait1Msec((long)t);
}
#elif defined(VEX)
void lineTrackForRotations(long t)
{
wait1Msec((long)t);
}*/
#endif

#endif
//----------------------------------------------------------------------------------------------------

//------------------------------------------| TankControl |-------------------------------------------
#ifndef _TANKCONTROL_H_GUARD
#define _TANKCONTROL_H_GUARD

#if defined(VEX2)

void tankControl(TVexJoysticks rightJoystick = Ch2, TVexJoysticks leftJoystick = Ch3)
{
  motor[port2] = vexRT[rightJoystick];
  motor[port3] = vexRT[leftJoystick];
}

#endif
#endif
//----------------------------------------------------------------------------------------------------

//-----------------------------------------| ArcadeControl |------------------------------------------
#ifndef _ARCADECONTROL_H_GUARD
#define _ARCADECONTROL_H_GUARD

#if defined(VEX2)

void arcadeControl(TVexJoysticks verticalJoystick = Ch2, TVexJoysticks horizontalJoystick = Ch1)
{
    motor[port3] = (vexRT[verticalJoystick] + vexRT[horizontalJoystick])/2;  // (y + x)/2
    motor[port2] = (vexRT[verticalJoystick] - vexRT[horizontalJoystick])/2;  // (y - x)/2
}

#endif
#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------| MoveStraightROTATIONS |--------------------------------------
#ifndef _MOVESTRAIGHTROTS_H_GUARD
#define _MOVESTRAIGHTROTS_H_GUARD

#if defined(VEX2)

void moveStraightForRotations(float rotations = 1.0, tSensors rightEncoderPort = dgtl1, tSensors leftEncoderPort = dgtl3)
{
  SensorValue[rightEncoderPort] = 0;
  SensorValue[leftEncoderPort] = 0;

  while(SensorValue[rightEncoderPort] < (abs(rotations) * 360))
  {
		if(SensorValue[rightEncoderPort] == SensorValue[leftEncoderPort]) // If rightEncoder has counted the same amount as leftEncoder:
		{
			// Move Forward
			motor[port2] = 85;		// Right Motor is run at power level 85
			motor[port3]  = 85;		// Left Motor is run at power level 85
		}
		else if(SensorValue[rightEncoderPort] > SensorValue[leftEncoderPort])	// If rightEncoder has counted more encoder counts
		{
			// Turn slightly right
			motor[port2] = 65;		// Right Motor is run at power level 65
			motor[port3]  = 85;		// Left Motor is run at power level 85
		}
		else	// Only runs if leftEncoder has counted more encoder counts
		{
			// Turn slightly left
			motor[port2] = 85;		// Right Motor is run at power level 85
			motor[port3]  = 65;		// Left Motor is run at power level 65
		}
  }
}

#endif
#endif
//----------------------------------------------------------------------------------------------------

//----------------------------------------| MoveStraightTIME |----------------------------------------
#ifndef _MOVESTRAIGHTTIME_H_GUARD
#define _MOVESTRAIGHTTIME_H_GUARD

#if defined(VEX2)
void moveStraightForTime(float seconds = 5.0, tSensors rightEncoderPort = dgtl1, tSensors leftEncoderPort = dgtl3)
{
  SensorValue[rightEncoderPort] = 0;
  SensorValue[leftEncoderPort] = 0;

  float timeStart = ((float)nPgmTime / 1000);

  while(((float)nPgmTime / 1000) - timeStart < seconds)
  {
		if(SensorValue[rightEncoderPort] == SensorValue[leftEncoderPort]) // If rightEncoder has counted the same amount as leftEncoder:
		{
			// Move Forward
			motor[port2] = 85;		// Right Motor is run at power level 85
			motor[port3]  = 85;		// Left Motor is run at power level 85
		}
		else if(SensorValue[rightEncoderPort] > SensorValue[leftEncoderPort])	// If rightEncoder has counted more encoder counts
		{
			// Turn slightly right
			motor[port2] = 65;		// Right Motor is run at power level 65
			motor[port3]  = 85;		// Left Motor is run at power level 85
		}
		else	// Only runs if leftEncoder has counted more encoder counts
		{
			// Turn slightly left
			motor[port2] = 85;		// Right Motor is run at power level 85
			motor[port3]  = 65;		// Left Motor is run at power level 65
		}
  }
}

#endif
#endif
//----------------------------------------------------------------------------------------------------

/*******************************************************************************************************************************************\
|*  ROBOT MOTION FUNCTIONS  *|
\****************************/






/***********************\
|*  SPECIAL FUNCTIONS  *|
\*******************************************************************************************************************************************/

//-------------------------------------------| TurnLEDON |--------------------------------------------
#ifndef _TURNLEDON_H_GUARD
#define _TURNLEDON_H_GUARD

#if defined(VEX2)

void turnLEDOn(tSensors digitalPort = dgtl2)
{
  SensorValue[digitalPort] = 0;
}

#endif
#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------------| TurnLEDOFF |-------------------------------------------
#ifndef _TURNLEDOFF_H_GUARD
#define _TURNLEDOFF_H_GUARD

#if defined(VEX2)

void turnLEDOff(tSensors digitalPort = dgtl2)
{
  SensorValue[digitalPort] = 1;
}

#endif
#endif
//----------------------------------------------------------------------------------------------------

//----------------------------------------| TurnFlashlightON |----------------------------------------
#ifndef _TURNFLASHLIGHTON_H_GUARD
#define _TURNFLASHLIGHTON_H_GUARD

#if defined(VEX2)

void turnFlashlightOn(tMotor flashlightPort = port4, short brightness = 63)
{
  if(bMotorReflected[flashlightPort] == 0)
  {
    motor[flashlightPort] = abs(brightness) * -1;
  }
  else
  {
    motor[flashlightPort] = abs(brightness);
  }
}

#endif
#endif
//----------------------------------------------------------------------------------------------------

//---------------------------------------| TurnFlashlightOFF |----------------------------------------
#ifndef _TURNFLASHLIGHTOFF_H_GUARD
#define _TURNFLASHLIGHTOFF_H_GUARD

#if defined(VEX2)

void turnFlashlightOff(tMotor flashlightPort = port4)
{
  motor[flashlightPort] = 0;
}

#endif
#endif
//----------------------------------------------------------------------------------------------------

/*******************************************************************************************************************************************\
|*  SPECIAL FUNCTIONS  *|
\***********************/






/*******************************\
|*  SENSOR MOVEMENT FUNCTIONS  *|
|*******************************************************************************************************************************************|
|* INDEFINITELY REMOVED FROM LIBRARY!!	*|
\****************************************/
/*
//---------------------------------------| ForwardUntilTouch |----------------------------------------
#ifndef _FORWARDUNTILTOUCH_H_GUARD
#define _FORWARDUNTILTOUCH_H_GUARD

#if defined(NXT)

void forwardUntilTouch(int speed = 75, tSensors touch = S1)//, tMotor rm = motorB, tMotor lm = motorC)
{
while(SensorValue[touch] == 0)
{
motor[motorB] = 75;
motor[motorC] = 75;
//motor[rm] = speed;
//motor[lm] = speed;
}
motor[motorB] = 0;
motor[motorC] = 0;
}

#elif defined(TETRIX)
void forwardUntilTouch(long t)
{
wait1Msec((long)t);
}
#elif defined(VEX2)
void forwardUntilTouch(long t)
{
wait1Msec((long)t);
}
#elif defined(VEX)
void forwardUntilTouch(long t)
{
wait1Msec((long)t);
}
#endif

#endif
//----------------------------------------------------------------------------------------------------

//---------------------------------------| ForwardUntilSonar |----------------------------------------
#ifndef _FORWARDUNTILSONAR_H_GUARD
#define _FORWARDUNTILSONAR_H_GUARD

#if defined(NXT)

void forwardUntilSonar(int distance = 30, tSensors sonar = S4)//, int speed = 75, tMotor rm = motorB, tMotor lm = motorC)
{
while(SensorValue[sonar] > distance)
{
motor[motorB] = 75;
motor[motorC] = 75;
//motor[rm] = speed;
//motor[lm] = speed;
}
motor[motorB] = 0;
motor[motorC] = 0;
}

#elif defined(TETRIX)
void forwardUntilSonar(long t)
{
wait1Msec((long)t);
}
#elif defined(VEX2)
void forwardUntilSonar(long t)
{
wait1Msec((long)t);
}
#elif defined(VEX)
void forwardUntilSonar(long t)
{
wait1Msec((long)t);
}
#endif

#endif
//----------------------------------------------------------------------------------------------------

//--------------------------------------| ForwardUntilRotation |--------------------------------------
#ifndef _FORWARDUNTILROTATION_H_GUARD
#define _FORWARDUNTILROTATION_H_GUARD

#if defined(NXT)

void forwardUntilRotation(int distance = 360)//, int speed = 75, tMotor rm = motorB, tMotor lm = motorC, tMotor am = motorA)
{
nMotorEncoder[motorB] = 0;
nMotorEncoder[motorC] = 0;
while(nMotorEncoder[motorB] < distance || nMotorEncoder[motorC] < distance)
{
motor[motorB] = 75;
motor[motorC] = 75;
//motor[rm] = speed;
//motor[lm] = speed;
}
motor[motorB] = 0;
motor[motorC] = 0;
}

#elif defined(TETRIX)
void forwardUntilRotation(long t)
{
wait1Msec((long)t);
}
#elif defined(VEX2)
void forwardUntilRotation(long t)
{
wait1Msec((long)t);
}
#elif defined(VEX)
void forwardUntilRotation(long t)
{
wait1Msec((long)t);
}
#endif

#endif
//----------------------------------------------------------------------------------------------------

//---------------------------------------| ForwardUntilLight |----------------------------------------
#ifndef _FORWARDUNTILLIGHT_H_GUARD
#define _FORWARDUNTILLIGHT_H_GUARD

#if defined(NXT)

void forwardUntilLight(int threshold = 30, tSensors light = S3)//, int speed = 75, tMotor rm = motorB, tMotor lm = motorC, tMotor am = motorA)
{
while(SensorValue[light] < threshold)
{
motor[motorB] = 75;
motor[motorC] = 75;
//motor[rm] = speed;
//motor[lm] = speed;
}
motor[motorB] = 0;
motor[motorC] = 0;
}

#elif defined(TETRIX)
void forwardUntilLight(long t)
{
wait1Msec((long)t);
}
#elif defined(VEX2)
void forwardUntilLight(long t)
{
wait1Msec((long)t);
}
#elif defined(VEX)
void forwardUntilLight(long t)
{
wait1Msec((long)t);
}
#endif

#endif
//----------------------------------------------------------------------------------------------------

//----------------------------------------| ForwardUntilDark |----------------------------------------
#ifndef _FORWARDUNTILDARK_H_GUARD
#define _FORWARDUNTILDARK_H_GUARD

#if defined(NXT)

void forwardUntilDark(int threshold = 30, tSensors dark = S3)//, int speed = 75, tMotor rm = motorB, tMotor lm = motorC, tMotor am = motorA)
{
while(SensorValue[dark] > threshold)
{
motor[motorB] = 75;
motor[motorC] = 75;
//motor[rm] = speed;
//motor[lm] = speed;
}
motor[motorB] = 0;
motor[motorC] = 0;
}

#elif defined(TETRIX)
void forwardUntilDark(long t)
{
wait1Msec((long)t);
}
#elif defined(VEX2)
void forwardUntilDark(long t)
{
wait1Msec((long)t);
}
#elif defined(VEX)
void forwardUntilDark(long t)
{
wait1Msec((long)t);
}
#endif

#endif
//----------------------------------------------------------------------------------------------------
*/
/*******************************\
|*  SENSOR MOVEMENT FUNCTIONS  *|
\*******************************************************************************************************************************************/
