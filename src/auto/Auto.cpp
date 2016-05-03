/*
 * Auto.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: 1750800404
 */

#include "Auto.h"

Auto::Auto(DriveSystem *autoDrive, MultiTool *autoTool){
	aDrive = autoDrive;
	aTool = autoTool;
}

Auto::~Auto(){
	delete aDrive;
	delete aTool;
}

void Auto::LowPortAuton(){
	aTool->def->Lower();
	Wait(0.5);
	aDrive->TimeDrive(0.5, 0.0, 1.0);
	Wait(0.25);
	aTool->shooty->Lower(0.75);
	Wait(0.75);
	aTool->shooty->raiseShoot->Set(0.0);
	aDrive->TimeDrive(0.75, 0.0, 2.5);
	Wait(1.0);
	//tele->drive->RotatetoAngle(45, 0.75);
	aTool->shooty->BombShotAim();
}

void Auto::RockRoughAuton(){
	aTool->def->Raise();
	aTool->shooty->BombShotAim();
	aDrive->TimeDrive(0.75, 0.0, 3.5);
	Wait(5.0);
}

void Auto::MoatRampartsAuton(){
	aTool->def->Raise();
	aTool->shooty->BombShotAim();
	aDrive->TimeDrive(0.95, 0.0, 3.0);
	Wait(5.0);
}

void Auto::DoorAuton(){

}

void Auto::SpyAuton(){
	aTool->def->Lower();
	aTool->shooty->BombShotAim();
	aTool->shootBall(10000, 10000, true);
}

void Auto::NoAuton(){
	Wait(15.0);
}
