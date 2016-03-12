/*
 * Teleop.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: 1750800404
 */

#include "Teleop.h"

Teleop::Teleop(){
	controller1 = new StickControl(0);
	controller2 = new StickControl(1);
	conv1 = new InOutConverter();
	conv2 = new InOutConverter();
	drive = new DriveSystem();
}

Teleop::~Teleop(){
	delete controller1;
	delete controller2;
	delete conv1;
	delete conv2;
	delete drive;
}

void Teleop::TeleopNoSensors(){
	drive->DriveTank(conv1->stickOut(controller1, 1), conv1->stickOut(controller1, 5));
}

void Teleop::TeleopWithSensors(){
	drive->DriveTank(conv1->stickOut(controller1, 1), conv1->stickOut(controller1, 5));
}
