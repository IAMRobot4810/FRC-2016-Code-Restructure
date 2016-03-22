/*
 * Teleop.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: 1750800404
 */

#include "Teleop.h"

Teleop::Teleop(): aToggle(true), bToggle(true), xToggle(true),
yToggle(true), rToggle(true), lToggle(true), rStickToggle(true), lStickToggle(true),
startToggle(true), backToggle(true)
{
	controller1 = new StickControl(0);
	controller2 = new StickControl(1);
	conv1 = new InOutConverter();
	conv2 = new InOutConverter();
	drive = new DriveSystem();
	shoot = new Shooter();
	def = new DefenseArm();
	/*
	bool aToggle = true;
	bool bToggle = true;
	bool xToggle = true;
	bool yToggle = true;
	bool rToggle = true;
	bool lToggle = true;
	bool rStickToggle = true;
	bool lStickToggle = true;
	bool startToggle = true;
	bool backToggle = true;
	*/
}

Teleop::~Teleop(){
	delete controller1;
	delete controller2;
	delete conv1;
	delete conv2;
	delete drive;
	delete shoot;
	delete def;
}

void Teleop::TeleopNoSensors(){
	drive->DriveTank(conv1->stickOut(controller1, 1), conv1->stickOut(controller1, 5));
}

void Teleop::TeleopWithSensors(){
	drive->DriveTank(conv1->stickOut(controller1, 1), conv1->stickOut(controller1, 5));

	//Pick up the ball
	if(controller2->getlStickY() <= 0){
		shoot->Pickup(controller2->getlStickY());
	}
	else{
		shoot->Pickup(0);
	}

	//To raise and lower the defense arm
	if(controller2->bButtonGet() && bToggle){
		bToggle = false;
		if(def->Low == true){
			def->Raise();
		}
		else{
			def->Lower();
		}
	}
	else if(controller2->bButtonGet() == false){
		bToggle = true;
	}

	//Aim low goal
	if(controller2->aButtonGet() && aToggle){
		aToggle = false;
		shoot->LowGoalAim(0.7);
	}
	else if(controller2->aButtonGet() == false){
		aToggle = true;
	}

	//Aim Turret
	if(controller2->xButtonGet() && xToggle){
		xToggle = false;
		shoot->TurretShotAim(0.7);
	}
	else if(controller2->xButtonGet() == false){
		xToggle = true;
	}

	//Aim Bomb
	if(controller2->yButtonGet() && yToggle){
		yToggle = false;
		shoot->BombShotAim(0.7);
	}
	else if(controller2->yButtonGet() == false){
		yToggle = true;
	}

	//Raise manually 50% speed
	if(controller2->rBumperGet() && !controller2->lBumperGet() &&
			controller2->getrTrig() < 0.25 && controller2->getlTrig() < 0.25){
		shoot->Raise(0.5);
	}
	//Lower manually 50% speed
	else if(controller2->lBumperGet() && !controller2->rBumperGet() &&
			controller2->getrTrig() < 0.25 && controller2->getlTrig() < 0.25){
		shoot->Lower(0.5);
	}
	//Raise manually variable up to 25%
	else if(!controller2->lBumperGet() && !controller2->rBumperGet() &&
			controller2->getrTrig() >= 0.25 && controller2->getlTrig() < 0.25){
		shoot->Raise(conv2->trigOut(controller2, 3));
	}
	//Lower manually variable up to 25%
	else if(!controller2->lBumperGet() && !controller2->rBumperGet() &&
			controller2->getrTrig() < 0.25 && controller2->getlTrig() >= 0.25){
		shoot->Lower(conv2->trigOut(controller2, 2));
	}
	else{
		shoot->raiseShoot->Set(0.0);
	}
}
