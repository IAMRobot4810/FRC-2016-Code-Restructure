/*
 * Auto.h
 *
 *  Created on: Mar 7, 2016
 *      Author: 1750800404
 */

#ifndef SRC_AUTO_AUTO_H_
#define SRC_AUTO_AUTO_H_

#include "AutonDrive.h"
#include "systems/DriveSystem.h"
#include "systems/GyroSensor.h"

class Auto{
private:
	AutonDrive* a_drive;
	//DriveSystem* auto_system;
public:
	Auto(); //initialization
	~Auto();
	void AutonMode1();
};



#endif /* SRC_AUTO_AUTO_H_ */
