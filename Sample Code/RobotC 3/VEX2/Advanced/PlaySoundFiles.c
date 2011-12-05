#pragma platform(VEX2, Arduino, Generic)

// Simple program to cycle through the file system and play all sound files

task main()
{
  long nCycles = 0;
  long nPlaying = 0;
  string sFileName;
  TFileExtensionTypes nFileType;

  for (int i = 0; i < 5; ++i)
    ;

  for (int i = 0; i < 5; ++i);

  if (nCycles == 0) ;
  if (nCycles == 0)
    ;

  while (true)
  {
    ++nCycles;
    while (bSoundActive)
    {
      ++nPlaying;
      wait1Msec(1);
    }
    //wait1Msec(500);

    PlaySoundFile("1million.wav");
    //PlaySound(soundBeepBeep);
  }

  while (true)
  {
    ++nCycles;
    for (int nFileIndex = 0; nFileIndex < 64; ++nFileIndex)
    {
      if (!bValidFile(nFileIndex))
        continue;

      nFileType = getFileType(nFileIndex);
      switch (nFileType)
      {
      case ftSound:
      case ftWAV:
        break;

      default:
        continue;
      }

      while (bSoundActive)
      {
        ++nPlaying;
        wait1Msec(1);
      }
      wait1Msec(500);

      getFileName(nFileIndex, sFileName);
      PlaySoundFile(sFileName);
      PlaySound(soundBeepBeep);

    }
  }
}
