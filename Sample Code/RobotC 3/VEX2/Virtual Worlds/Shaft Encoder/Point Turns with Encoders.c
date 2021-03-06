#pragma config(Sensor, in1,    lightSensor,         sensorLineFollower)
#pragma config(Sensor, dgtl1,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,         sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  compassSensor,       sensorVirtualCompass)
#pragma config(Sensor, dgtl6,  touchSensor,         sensorTouch)
#pragma config(Sensor, dgtl8,  sonarSensor,         sensorSONAR_inch)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*+++++++++++++++++++++++++++++++++++++++++++++| Notes |++++++++++++++++++++++++++++++++++++++++++++++
Point Turns with Encoders

This program instructs the robot to turn left, and then right, using feedback from the encoders.
There is a two second pause at the beginning of the program.

The used for feedback should be cleared just before it starts counting  using the
"SensorValue(encoder) = 0;".  This helps ensure consistancy.

Robot Model(s): Squarebot & Swervebot

[I/O Port]          [Name]              [Type]                [Description]
Motor Port 2        rightMotor          VEX Motor             Right side motor
Motor Port 3        leftMotor           VEX Motor             Left side motor
Digital - Port 1    rightEncoder        VEX Shaft Encoder     Right side
Digital - Port 3    leftEncoder         VEX Shaft Encoder     Left side

*To run this sample program on Swervebot, be sure to Reverse Motor Port 3 in the Motors and Sensors
 Setup, and to make sure that Motor Port 2 is NOT Reversed.
----------------------------------------------------------------------------------------------------*/


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
	wait1Msec(2000);							            //Robot waits for 2000 milliseconds before executing program

	SensorValue[rightEncoder] = 0;	          //Set the encoder so that it starts counting at 0

  while(SensorValue(rightEncoder) < 1800)   //While rightEncoder has counted less than 1800 counts
	{
		//Turn Left
		motor[rightMotor] = 127;					      //Motor on port2 is run at full (127) power forward
		motor[leftMotor]  = -127;				        //Motor on port3 is run at full (-127) power reverse
	}

	SensorValue[leftEncoder] = 0;	            //Set the encoder so that it starts counting at 0

  while(SensorValue(leftEncoder) < 1800)    //While leftEncoder has counted less than 1800 counts
	{
		//Turn Right
		motor[rightMotor] = -127;				        //Motor on port2 is run at full (-127) power reverse
		motor[leftMotor]  = 127;				      	//Motor on port3 is run at full (127) power forward
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
