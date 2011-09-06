#if !defined(__I2C_Intrinsics__)
#define __I2C_Intrinsics__

#if defined(NXT) || defined(TETRIX)

#include "I2CDrivers.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                Access Internal Firmware I2C Background Polling Device Driver
//
// ROBOTC firmware uses an internal background polling mechanism to continuously retrieve the values from the
// digital sensors that it has a built-in driver. This file provides the functionality to expose this interface
// to end user application programs.
//
// Its relatively easy to use the background I2C polling capabilities. Simply follow these steps:
//
// 1. First configure the sensor port as a "custom I2C" type.
//        1) ROBOTC firmware supports three different types which provide varying improvement in I2C messaging
//           speed. The slowest speed is compatible with the NXT-G firmware implementation. Higher speeds work
//           with almost all third party sensors.
//
//           sensorI2CCustom                Slow. Compatible with NXT-G firmware.
//
//           sensorI2CCustomFast             2 to 3 times faster. So far, all 3rd party sensors are compatible.
//
//           sensorI2CCustomFastSkipStates   Up to 5 times faster. Not compatible with some 3rd party sensors.
//
//    The sensor will be configured as able to generate I2C messaging traffic. There will be no background polling.
//
//    There are another three sensor types (sensorI2CCustom9V, ...) which additionally instruct the firmware to
//    provide 9V power to the sensor.
//
// 2. Setup the background polling configuration. This is performed with a call to the "configureI2CPolling"
//    intrinsic. This provides a data configuration to the firmware that is now used to perform the background
//    polling.
//        1) The driver starts by sending an initialization message to configrue the sensor. It repeats this
//           message until it is successfully transmitted -- e.g. the sensor cable may be unplugged.
//        2) A short delay before sending the first polling message.
//        3) Send a message to poll the data from the sensor.
//        4) Receive the polling reply and buffer it. If there was an I2C error, then go back to initialization
//           state (1).
//        5) Delay between polling cycles.
//        6) Go back to state (3).
//
//
// Background polling can be halted with a call to "configureI2CPolling" with a "NULL" entry.
//
//
// Two intrinsic functions are available to read the last polled data.
//
//         getI2CSensorReply()     returns the last polled data.
//         getI2CSensorInfo()      reutrns not only the polled data but internal statisics on the driver.
//
// See the file "I2CDrivers.h" for a definition of the various data structures used by the above functions.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

intrinsic void getI2CPolledData(const tSensors nSensorIndex, byte *pBuffer, const int nNumbOfBytes)

                asm(opcdSystemFunctions, byte(sysFuncI2CSensorReply),
                                         variable(nSensorIndex),
                                         variableRefPointer(pBuffer),
                                         variable(nNumbOfBytes));

intrinsic void getI2CDriverStatistics(const tSensors nSensorIndex, TI2CStatistics& nBuffer)
                asm(opcdSystemFunctions, byte(sysFuncI2CGetSensorInfo),
                                         variable(nSensorIndex),
                                         variableRefPointer(nBuffer));

intrinsic TI2cDriverState getI2CDriverState(const tSensors nSensorIndex)
                asm(opcdSystemFunctions, byte(sysFuncI2CGetDriverState),
                                         variable(nSensorIndex),
                                         functionReturn);

intrinsic void clearI2CStatistics(const tSensors nSensorIndex)

                asm(opcdSystemFunctions, byte(sysFuncI2CClearSensorInfo),
                                         variable(nSensorIndex));

intrinsic void setI2CSensorConfig(const tSensors nSensorIndex, TI2CSensorSetupData& nBuffer)

                asm(opcdSystemFunctions, byte(sysFuncI2CSensorConfig),
                                         variable(nSensorIndex),
                                         variableRefPointer(nBuffer));
#endif

#endif //#if !defined(__I2C_Intrinsics__)
