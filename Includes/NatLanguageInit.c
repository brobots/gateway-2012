/*----------------------------------------------------------------------------------------------------*\
|*                                  - Natural Language Initializer -                                  *|
|*                                      ROBOTC on PLATFORM TYPE                                       *|
|*                                                                                                    *|
|*  This header file initializes a robot that has not been set up via motors and sensors setup.       *|
|*  However it does not overwrite an existing setup.  This is optimized for Beginners ROBOTC.         *|
\*-----------------------------------------------------------------------------------------------4246-*/
#pragma systemFile            // this eliminates warning for "unreferenced" functions


#pragma autoStartTasks        // Automatically start this task when the main user program starts.




/*
SensorValue[port] == SensorType;
*/

task initializeSetup()
{
  hogCPU();
#if defined(NXT)                    /////////////////////////////////////////////////////////////// NXT
  if(SensorType[S1] == sensorNone)
  {
    SensorType[S1] = sensorTouch;
  }

  if(SensorType[S2] == sensorNone)
  {
    SensorType[S2] = sensorSoundDB;
  }

  if(SensorType[S3] == sensorNone)
  {
    SensorType[S3] = sensorLightActive;
  }

  if(SensorType[S4] == sensorNone)
  {
    SensorType[S4] = sensorSONAR;
  }
#elif defined(VEX2)                 /////////////////////////////////////////////////////////////// CORTEX
  //bMotorReflected[port2] = 1;
  if(SensorType[in1] == sensorNone)
  {
    SensorType[in1] = sensorLineFollower;
  }

  if(SensorType[in2] == sensorNone)
  {
    SensorType[in2] = sensorLineFollower;
  }

  if(SensorType[in3] == sensorNone)
  {
    SensorType[in3] = sensorLineFollower;
  }

  if(SensorType[in6] == sensorNone)
  {
    SensorType[in6] = sensorPotentiometer;
  }

  if(SensorType[dgtl1] == sensorNone && SensorType[dgtl2] == sensorNone)
  {
    SensorType[dgtl1] = sensorQuadEncoder;
	//SensorType[dgtl2] = sensorQuadEncoderSecondPort;
  }

  if(SensorType[dgtl3] == sensorNone && SensorType[dgtl4] == sensorNone)
  {
    SensorType[dgtl3] = sensorQuadEncoder;
	//SensorType[dgtl4] = sensorQuadEncoderSecondPort;
  }

  if(SensorType[dgtl6] == sensorNone)
  {
    SensorType[dgtl6] = sensorTouch;
  }

  if(SensorType[dgtl7] == sensorNone)
  {
    SensorType[dgtl7] = sensorTouch;
  }

  if(SensorType[dgtl8] == sensorNone && SensorType[dgtl9] == sensorNone)
  {
    SensorType[dgtl8] = sensorSONAR_cm;
	//SensorType[dgtl9] = sensorSONARSecondPort;
  }

                                    /////////////////////////////////////////////////////////////// TETRIX
  /*#elif defined(TETRIX)
  void setMotor(long t)
  {
  wait1Msec((long)t);
  }
#elif defined(VEX)                  /////////////////////////////////////////////////////////////// VEXPIC
  void setMotor(long t)
  {
  wait1Msec((long)t);
  }*/
#endif
  releaseCPU();
StopTask(initializeSetup);
}

