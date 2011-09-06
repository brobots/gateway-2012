/******************************\
|*  ROBOTC for Beginners      *|
|*  Moving the Arm Attachment *|
\******************************/

task main()
{
  robotType(recbot);      // We are using the recbot.

  setMotor(port6, 63);    // Set motor port 6 to speed 63.
  wait(0.5);              // Wait 0.5 seconds.
  stopMotor(port6);       // Stop motor port 6.

  wait(1.0);              // Wait 1.0 seconds.

  setMotor(port6, -63);   // Set motor port 6 to speed -63.
  wait(0.5);              // Wait 0.5 seconds.
  stopMotor(port6);       // Stop motor port 6.
}
