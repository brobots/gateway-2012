#ifndef _CameraIntrinsics__
#define _CameraIntrinsics__

#pragma systemFile


#if defined(hasCamera)


///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//																	Camera Control and Operation
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

	intrinsic void StartCamera()                       asm(opcdSystemFunctions, byte(sysFuncCameraFunctions),  byte(camStart));
	intrinsic void StopCamera()       								 asm(opcdSystemFunctions, byte(sysFuncCameraFunctions),  byte(camStop));
	intrinsic void ResetCameraConfigurationToDefault() asm(opcdSystemFunctions, byte(sysFuncCameraFunctions),  byte(camUseDefaultConfig));
	intrinsic void SetCameraConfig(byte &config)       asm(opcdSystemFunctions, byte(sysFuncSetCameraConfig),  variableRefByte(config));
	intrinsic void GetCameraConfig(byte &config)       asm(opcdSystemFunctions, byte(sysFuncGetCameraConfig),  variableRefByte(config));
	intrinsic void GetTrackingParms(TTrackingDataWords &myData)
	                                                    asm(opcdSystemFunctions, byte(sysFuncGetTrackingParms),  variableRefRAM(myData));

  intrinsic TTrackingDataWords variableIndex(trackingData,  opcdSourceExternMemoryRef, kExternCMUCAMTracking);

	intrinsic int           variableIndex(nCameraVertical,         opcdSourceCamera, camVertical)
	intrinsic int           variableIndex(nCameraHorizontal,       opcdSourceCamera, camHorizontal)
	intrinsic int           variableIndex(nCameraConfidence,       opcdSourceCamera, camConfidence)
	intrinsic int           variableIndex(nCameraTrackingPackets,  opcdSourceCamera, camNumbTrackingRecords)
	intrinsic TCameraStatus variableIndex(nCameraStatus,           opcdSourceCamera, camTrackingStatus)


#endif
#endif
