/*
 * Auto.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: 1750800404
 */

#include "Auto.h"

Auto::Auto(){
	a_drive = new AutonDrive();
	a_drive->roboDrive->SetExpiration(0.10);
}

Auto::~Auto(){
	delete a_drive;
}

void Auto::AutonMode1(){
	a_drive->TimedDrive(2.0, 0.1, 0.0);
	Wait(0.03);
	a_drive->TimedDrive(2.0, 0.0, 0.0);
	Wait(0.03);

	//a_drive->RotatetoAngle((a_drive->gyr->GyroAngleRead() + 30), 0.1);
}
