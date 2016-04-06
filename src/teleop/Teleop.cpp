/*
 * Teleop.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: 1750800404
 */

#include "Teleop.h"

Teleop::Teleop(): aToggle(true), bToggle(true), xToggle(true), yToggle(true),
rToggle(true), lToggle(true), rStickToggle(true), lStickToggle(true), startToggle(true),
backToggle(true), currentPos(0.0d)
{
	controller1 = new StickControl(cont1ID);
	controller2 = new StickControl(cont2ID);
	conv1 = new InOutConverter();
	conv2 = new InOutConverter();
	drive = new DriveSystem();
	shoot = new Shooter();
	def = new DefenseArm();

	camera = new Camera();
	camera->calibrate(50, 0, 0);
	camera->calibrateAuto(50);
}

Teleop::~Teleop(){
	delete controller1;
	delete controller2;
	delete conv1;
	delete conv2;
	delete drive;
	delete shoot;
	delete def;
	//delete camera;
}

void Teleop::TeleopNoSensors(){
	drive->DriveTank(conv1->stickOut(controller1, 1), conv1->stickOut(controller1, 3));
	camera->capture();
	camera->get_infos();
	camera->check_emergency_stop();
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

	//Shoot 95%
	if(controller1->rBumperGet() && rToggle){
		rToggle = false;
		def->Lower();
		shoot->ShootNoSensors(0.95, 0.95, 0.95);
	}
	else if(controller1->rBumperGet() == false){
		rToggle = true;
	}

	//Shoot 75%
	if(controller1->lBumperGet() && lToggle){
		rToggle = false;
		def->Lower();
		shoot->ShootNoSensors(0.75, 0.75, 0.75);
	}
	else if(controller1->lBumperGet() == false){
		lToggle = true;
	}
}

void Teleop::TeleopWithSensors(){
	drive->DriveTank(conv1->stickOut(controller1, 1), conv1->stickOut(controller1, 3));
	camera->capture();
	camera->get_infos();
	camera->check_emergency_stop();
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
		shoot->TurretShotAim();
		currentPos = turretPos;
	}
	else if(controller2->xButtonGet() == false){
		xToggle = true;
	}

	//Aim Bomb
	if(controller2->yButtonGet() && yToggle){
		yToggle = false;
		shoot->BombShotAim();
		currentPos = bombPos;
	}
	else if(controller2->yButtonGet() == false){
		yToggle = true;
	}

	//Raise manually 50% speed
	if(controller2->rBumperGet() && !controller2->lBumperGet() &&
			controller2->getrTrig() < 0.25 && controller2->getlTrig() < 0.25){
		shoot->Raise(0.5);
		currentPos = shoot->raiseShoot->GetPosition();
	}
	//Lower manually 50% speed
	else if(controller2->lBumperGet() && !controller2->rBumperGet() &&
			controller2->getrTrig() < 0.25 && controller2->getlTrig() < 0.25){
		shoot->Lower(0.5);
		currentPos = shoot->raiseShoot->GetPosition();
	}
	//Raise manually variable up to 25%
	else if(!controller2->lBumperGet() && !controller2->rBumperGet() &&
			controller2->getrTrig() >= 0.25 && controller2->getlTrig() < 0.25){
		shoot->Raise(conv2->trigOut(controller2, 3));
		currentPos = shoot->raiseShoot->GetPosition();
	}
	//Lower manually variable up to 25%
	else if(!controller2->lBumperGet() && !controller2->rBumperGet() &&
			controller2->getrTrig() < 0.25 && controller2->getlTrig() >= 0.25){
		shoot->Lower(conv2->trigOut(controller2, 2));
		currentPos = shoot->raiseShoot->GetPosition();
	}
	//Hold Position
	else{
		shoot->raiseShoot->StopMotor();
		if(shoot->raiseShoot->GetControlMode() == CANSpeedController::kPosition){
			shoot->raiseShoot->Set(currentPos);
		}
		else{
			shoot->raiseShoot->SetControlMode(CANSpeedController::kPosition);
			shoot->raiseShoot->SetPID(0.7, 0.0, 0.0);
			shoot->raiseShoot->EnableControl();
			shoot->raiseShoot->Set(currentPos);
		}
	}

	SmartDashboard::PutNumber("CurrentPos", currentPos);
	SmartDashboard::PutNumber("ShooterPosLive", shoot->raiseShoot->GetPosition());
	SmartDashboard::PutBoolean("UpLimit", shoot->UpLimit->Get());
	SmartDashboard::PutBoolean("DownLimit", shoot->DownLimit->Get());

	//Shoot 95%
	if(controller1->rBumperGet() && rToggle){
		rToggle = false;
		def->Lower();
		shoot->ShootNoSensors(0.95, 0.95, 0.95);
	}
	else if(controller1->rBumperGet() == false){
		rToggle = true;
	}

	//Shoot 75%
	if(controller1->lBumperGet() && lToggle){
		lToggle = false;
		def->Lower();
		shoot->ShootNoSensors(0.75, 0.75, 0.75);
	}
	else if(controller1->lBumperGet() == false){
		lToggle = true;
	}
}
