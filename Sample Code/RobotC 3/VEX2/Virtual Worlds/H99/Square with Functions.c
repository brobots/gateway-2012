#pragma config(Sensor, in1,    lightSensor,         sensorLineFollower)
#pragma config(Sensor, dgtl1,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,         sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  compassSensor,       sensorVirtualCompass)
#pragma config(Sensor, dgtl6,  touchSensor,         sensorTouch)
#pragma config(Sensor, dgtl8,  sonarSensor,         sensorSONAR_inch)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


/**********************************************************\
|*  ROBOTC Virtual World                                  *|
|*  Moving in a Square with the Compass (using Functions) *|
\**********************************************************/

// This program drives around in a square using the compassSensor to make turns.
// It has one large function that moves forward and turns, which it calls 4 times in main.

// Variables to be used later:
int compassReading;
int turn;

//-------------------------------------| Move Forward And Turn |--------------------------------------
void moveForwardAndTurn()
{
  motor[rightMotor] = 75;                 // set port2 to speed 75
  motor[leftMotor]  = 75;                 // set port3 to speed 75
  wait1Msec(3000);                        // wait 3 seconds
  motor[rightMotor] = 0;                  // stop port2
  motor[leftMotor]  = 0;                  // stop port3
  wait1Msec(1000);                        // wait 1 second

  compassReading = SensorValue(compassSensor);  // set 'compassReading' to the current
                                          // value of the compassSensor sensor

  turn = ((compassReading + 90) % 360);   // set 'turn' to be 'compassReading' + 90 degrees
                                          // (% 360) to keep the values circular (within 360 degrees)
  // if 'turn' is 0:
  if(turn == 0)
  {
    turn = 360; // set 'turn' to 360 (the compassSensor sensor reads 360 instead of 0)
  }

  // while the current reading of the compassSensor sensor
  // is not yet equal to our 'turn' value:
  while(SensorValue(compassSensor) != turn)
  {
    // turn right in place 90 degrees:
    motor[rightMotor] = -15;   	// port2 forward at speed -15
    motor[leftMotor]  = 15;		// port3 backward at speed 15
  }
}
//----------------------------------------------------------------------------------------------------


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
  // Do the movements 4 times (square):

  moveForwardAndTurn();   // call our function
  moveForwardAndTurn();   // call our function
  moveForwardAndTurn();   // call our function
  moveForwardAndTurn();   // call our function

  // rather than writing our code 4 times, we can write it once as a function
  // and call our function 4 times!
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
