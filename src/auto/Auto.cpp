/*
 * Auto.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: 1750800404
 */

#include "Auto.h"

Auto::Auto(){
	a_drive = new AutonDrive();
}

Auto::~Auto(){
	delete a_drive;
}

void Auto::AutonMode1(){
	a_drive->TimedDrive(1.5, 0.1, 0.0);
	Wait(0.005);
	a_drive->DriveTank(0.0, 0.0);
	Wait(15.0);
}
