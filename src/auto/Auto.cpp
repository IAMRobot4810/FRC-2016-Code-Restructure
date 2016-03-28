/*
 * Auto.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: 1750800404
 */

#include "Auto.h"

Auto::Auto(){
	def = new DefenseArm();
	drv = new DriveSystem();
	sht = new Shooter();
}

Auto::~Auto(){
	delete def;
	delete drv;
	delete sht;
}

void Auto::RegularAuton(){
	def->Lower();
	Wait(0.5);
	drv->TimeDrive(0.5, 0.0, 1.0);
	Wait(0.25);
	sht->Lower(0.75);
	Wait(0.75);
	sht->raiseShoot->Set(0.0);
	drv->TimeDrive(0.75, 0.0, 2.5);
	Wait(5.0);
}

void Auto::TerrainAuton(){
	def->Raise();
	Wait(0.0);
	sht->Raise(0.15);
	drv->TimeDrive(0.75, 0.0, 5.0);
}
