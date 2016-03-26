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

	//Pick up the ball
	if(controller2->getlStickY() >= 0){
		shoot->PickupNoSensors(controller2->getlStickY());
	}
	else{
		shoot->PickupNoSensors(0);
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
	SmartDashboard::PutBoolean("Defense Arm Lowered", def->Low);

	//Raise manually 50% speed
	if(controller2->rBumperGet() && !controller2->lBumperGet() &&
			controller2->getrTrig() < 0.25 && controller2->getlTrig() < 0.25){
		shoot->RaiseNoSensors(0.5);
	}
	//Lower manually 50% speed
	else if(controller2->lBumperGet() && !controller2->rBumperGet() &&
			controller2->getrTrig() < 0.25 && controller2->getlTrig() < 0.25){
		shoot->LowerNoSensors(0.5);
	}
	//Raise manually variable up to 25%
	else if(!controller2->lBumperGet() && !controller2->rBumperGet() &&
			controller2->getrTrig() >= 0.25 && controller2->getlTrig() < 0.25){
		shoot->RaiseNoSensors(conv2->trigOut(controller2, 3));
	}
	//Lower manually variable up to 25%
	else if(!controller2->lBumperGet() && !controller2->rBumperGet() &&
			controller2->getrTrig() < 0.25 && controller2->getlTrig() >= 0.25){
		shoot->LowerNoSensors(conv2->trigOut(controller2, 2));
	}
	else{
		shoot->raiseShoot->Set(0.0);
	}

	//Shoot 100%
	if(controller1->rBumperGet() && rToggle){
		rToggle = false;
		shoot->ShootNoSensors(0.95, 0.95, 0.95);
	}
	else if(controller1->rBumperGet() == false){
		rToggle = true;
	}

	//Shoot 75%
	if(controller1->lBumperGet() && lToggle){
		rToggle = false;
		shoot->ShootNoSensors(0.75, 0.75, 0.75);
	}
	else if(controller1->lBumperGet() == false){
		lToggle = true;
	}
}

void Teleop::TeleopWithSensors(){
	drive->DriveTank(conv1->stickOut(controller1, 1), conv1->stickOut(controller1, 5));

	//Pick up the ball
	if(controller2->getlStickY() >= 0){
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
	SmartDashboard::PutBoolean("Defense Arm Lowered", def->Low);

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

	currentEnco = shoot->raiseShoot->GetEncPosition();
	SmartDashboard::PutNumber("Encoder", currentEnco);

	//Shoot
	if(controller1->rBumperGet() && rToggle){
		rToggle = false;
		shoot->ShootNoSensors(0.95, 0.95, 0.95);
	}
	else if(controller1->rBumperGet() == false){
		rToggle = true;
	}
}
