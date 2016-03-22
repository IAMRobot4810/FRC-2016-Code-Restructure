#ifndef AUTO_AUTONDRIVE_H
#define AUTO_AUTONDRIVE_H

#include "WPILib.h"
#include "systems/DriveSystem.h"

class AutonDrive : public DriveSystem{
private:
	const float tick = 0.03;

public:
	void TimedDrive(float time, float lPower, float rPower);
	void EncoDrive(int lEncoderVal, int rEncoderVal);
};


#endif
