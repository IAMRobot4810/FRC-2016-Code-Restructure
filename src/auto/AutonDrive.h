#ifndef AUTO_AUTONDRIVE_H
#define AUTO_AUTONDRIVE_H

#include "WPILib.h"
#include "systems/DriveSystem.h"
#include "systems/GyroSensor.h"

class AutonDrive : public DriveSystem{
private:
	const float tick = 0.03;
	GyroSensor *gyr;
public:
	AutonDrive();
	~AutonDrive();

	void TimedDrive(float time, float straight, float rotate);
	void EncoDrive(int lEncoderVal, int rEncoderVal);

	void RotateToAngle(double angle, double speed);
};


#endif
