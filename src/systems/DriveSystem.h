/*
 * DriveSystem.h
 *
 *  Created on: Feb 7, 2016
 *      Author: 1750800404
 *
 *      Driving system for the robot
 */

#ifndef DRIVESYSTEM_H
#define DRIVESYSTEM_H

#include "AnalogGyro.h"
#include "CANTalon.h"
#include "RobotDrive.h"
#include "Timer.h"
#include "util/PIDStuff.h"
#include "util/ConstantVals.h"

class DriveSystem{

public:
	DriveSystem(RobotDrive *drivesystem, AnalogGyro *gyroscope);
	~DriveSystem();

	RobotDrive *roboDrive;
	AnalogGyro *gyr;

	void DriveArcade(float straight, float rotate);
	void DriveTank(float left, float right);
	void ResetGyro();
	void RotatetoAngle(double angle, double speed);
	void TimeDrive(float straight, float rotate, int seconds);

private:

protected:

};

#endif /* SRC_DRIVESYSTEM_H_ */
