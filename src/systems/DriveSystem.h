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

#include "CANTalon.h"
#include "RobotDrive.h"

class DriveSystem{

public:
	DriveSystem();
	~DriveSystem();

	CANTalon *flTal;
	CANTalon *rlTal;
	CANTalon *frTal;
	CANTalon *rrTal;
	RobotDrive *roboDrive;

	void DriveArcade(float straight, float rotate);
	void DriveTank(float left, float right);

private:

protected:

};

#endif /* SRC_DRIVESYSTEM_H_ */
