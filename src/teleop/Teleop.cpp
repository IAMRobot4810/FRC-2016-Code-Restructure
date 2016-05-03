/*
 * Teleop.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: 1750800404
 */

#include "Teleop.h"

Teleop::Teleop(DriveSystem *teledrive, MultiTool *teletool, StickControl *firstcontroller,
		StickControl *secondcontroller):

		a1Toggle(true),
		b1Toggle(true),
		x1Toggle(true),
		y1Toggle(true),
		r1Toggle(true),
		l1Toggle(true),
		r1StickToggle(true),
		l1StickToggle(true),
		start1Toggle(true),
		back1Toggle(true),
		pov01Toggle(true),
		pov451Toggle(true),
		pov901Toggle(true),
		pov1351Toggle(true),
		pov1801Toggle(true),
		pov2251Toggle(true),
		pov2701Toggle(true),
		pov3151Toggle(true),

		a2Toggle(true),
		b2Toggle(true),
		x2Toggle(true),
		y2Toggle(true),
		r2Toggle(true),
		l2Toggle(true),
		r2StickToggle(true),
		l2StickToggle(true),
		start2Toggle(true),
		back2Toggle(true),
		pov02Toggle(true),
		pov452Toggle(true),
		pov902Toggle(true),
		pov1352Toggle(true),
		pov1802Toggle(true),
		pov2252Toggle(true),
		pov2702Toggle(true),
		pov3152Toggle(true),

		currentPos(0.0d)
{
	controller1 = firstcontroller;
	controller2 = secondcontroller;
	conv1 = new InOutConverter();
	conv2 = new InOutConverter();
	tDrive = teledrive;
	tTool = teletool;
}

Teleop::~Teleop(){
	delete controller1;
	delete controller2;
	delete conv1;
	delete conv2;
}

void Teleop::TeleopNoSensors(){
	tDrive->DriveTank(conv1->stickOut(controller1, 1), conv1->stickOut(controller1, 3));

	//To raise and lower the roller
	if(controller2->aButtonGet() && a2Toggle){
		a2Toggle = false;
		tTool->moveRoll();
	}
	else if(controller2->aButtonGet() == false){
		a2Toggle = true;
	}
	SmartDashboard::PutBoolean("Roller Lowered", tTool->rolly->Low);

	//Pick up the ball
	if(controller2->getlStickY() >= 0){
		tTool->pickBallNoSensor(controller2->getlStickY());
	}
	else{
		tTool->pickBallNoSensor(0.0);
	}

	//To raise and lower the defense arm
	if(controller2->bButtonGet() && b2Toggle){
		b2Toggle = false;
		tTool->moveDef();
	}
	else if(controller2->bButtonGet() == false){
		b2Toggle = true;
	}
	SmartDashboard::PutBoolean("Defense Arm Lowered", tTool->def->Low);

	//Raise manually 50% speed
	if(controller2->rBumperGet() && !controller2->lBumperGet() &&
			controller2->getrTrig() < 0.25 && controller2->getlTrig() < 0.25){
		tTool->shooty->RaiseNoSensors(0.5);
	}
	//Lower manually 50% speed
	else if(controller2->lBumperGet() && !controller2->rBumperGet() &&
			controller2->getrTrig() < 0.25 && controller2->getlTrig() < 0.25){
		tTool->shooty->LowerNoSensors(0.5);
	}
	//Raise manually variable up to 25%
	else if(!controller2->lBumperGet() && !controller2->rBumperGet() &&
			controller2->getrTrig() >= 0.25 && controller2->getlTrig() < 0.25){
		tTool->shooty->RaiseNoSensors(conv2->trigOut(controller2, 3));
	}
	//Lower manually variable up to 25%
	else if(!controller2->lBumperGet() && !controller2->rBumperGet() &&
			controller2->getrTrig() < 0.25 && controller2->getlTrig() >= 0.25){
		tTool->shooty->LowerNoSensors(conv2->trigOut(controller2, 2));
	}
	else{
		tTool->shooty->raiseShoot->StopMotor();
	}

	//Shoot 95%
	if(controller1->rBumperGet() && r1Toggle){
		r1Toggle = false;
		tTool->shooty->ShootNoSensors(0.95, 0.95);
	}
	else if(controller1->rBumperGet() == false){
		r1Toggle = true;
	}

	//Shoot 75%
	if(controller1->lBumperGet() && l1Toggle){
		r1Toggle = false;
		tTool->shooty->ShootNoSensors(0.75, 0.75);
	}
	else if(controller1->lBumperGet() == false){
		l1Toggle = true;
	}
}

void Teleop::TeleopWithSensors(){
	tDrive->DriveTank(conv1->stickOut(controller1, 1), conv1->stickOut(controller1, 3));

	//To raise and lower the roller
	if(controller2->aButtonGet() && a2Toggle){
		a2Toggle = false;
		tTool->moveRoll();
	}
	else if(controller2->aButtonGet() == false){
		a2Toggle = true;
	}
	SmartDashboard::PutBoolean("Roller Lowered", tTool->rolly->Low);

	//Pick up the ball
	tTool->pickBall(controller2->getlStickY());

	//To raise and lower the defense arm
	if(controller2->bButtonGet() && b2Toggle){
		b2Toggle = false;
		tTool->moveDef();
	}
	else if(controller2->bButtonGet() == false){
		b2Toggle = true;
	}
	SmartDashboard::PutBoolean("Defense Arm Lowered", tTool->def->Low);

	//Aim low goal
	/*if(controller2->aButtonGet() && a2Toggle){
		a2Toggle = false;
		tTool->shooty->LowGoalAim(0.7);
	}
	else if(controller2->aButtonGet() == false){
		a2Toggle = true;
	}*/

	//Aim Turret
	if(controller2->xButtonGet() && x2Toggle){
		x2Toggle = false;
		tTool->shooty->TurretShotAim();
		currentPos = turretPos;
	}
	else if(controller2->xButtonGet() == false){
		x2Toggle = true;
	}

	//Aim Bomb
	if(controller2->yButtonGet() && y2Toggle){
		y2Toggle = false;
		tTool->shooty->BombShotAim();
		currentPos = bombPos;
	}
	else if(controller2->yButtonGet() == false){
		y2Toggle = true;
	}

	//Raise all multitool systems
	if(controller2->getPOV() == 0 && pov902Toggle){
		pov902Toggle = false;
		tTool->raiseAll();
		currentPos = 0.0;
	}
	else if(controller2->getPOV() != 0){
		pov902Toggle = true;
	}

	//Lower all multitool systems
	if(controller2->getPOV() == 180 && pov1802Toggle){
		pov1802Toggle = false;
		tTool->lowerAll();
		currentPos = maxShooterPos;
	}
	else if(controller2->getPOV() != 180){
		pov1802Toggle = true;
	}

	SmartDashboard::PutNumber("Controller 2 POV:", controller2->getPOV());

	//Raise manually 50% speed
	if(controller2->rBumperGet() && !controller2->lBumperGet() &&
			controller2->getrTrig() < 0.25 && controller2->getlTrig() < 0.25){
		tTool->shooty->RaiseNoSensors(0.5);
		currentPos = tTool->shooty->raiseShoot->GetPosition();
	}
	//Lower manually 50% speed
	else if(controller2->lBumperGet() && !controller2->rBumperGet() &&
			controller2->getrTrig() < 0.25 && controller2->getlTrig() < 0.25){
		tTool->shooty->LowerNoSensors(0.5);
		currentPos = tTool->shooty->raiseShoot->GetPosition();
	}
	//Raise manually variable up to 25%
	else if(!controller2->lBumperGet() && !controller2->rBumperGet() &&
			controller2->getrTrig() >= 0.25 && controller2->getlTrig() < 0.25){
		tTool->shooty->RaiseNoSensors(conv2->trigOut(controller2, 3));
		currentPos = tTool->shooty->raiseShoot->GetPosition();
	}
	//Lower manually variable up to 25%
	else if(!controller2->lBumperGet() && !controller2->rBumperGet() &&
			controller2->getrTrig() < 0.25 && controller2->getlTrig() >= 0.25){
		tTool->shooty->LowerNoSensors(conv2->trigOut(controller2, 2));
		currentPos = tTool->shooty->raiseShoot->GetPosition();
	}
	//Hold Position
	else{
		tTool->shooty->CustomAim(currentPos);
	}

	SmartDashboard::PutNumber("CurrentPos", currentPos);
	SmartDashboard::PutNumber("ShooterPosLive", tTool->shooty->raiseShoot->GetPosition());
	SmartDashboard::PutBoolean("UpLimit", tTool->shooty->UpLimit->Get());
	SmartDashboard::PutBoolean("DownLimit", tTool->shooty->DownLimit->Get());

	//Shoot 95%
	if(controller1->rBumperGet() && r1Toggle){
		r1Toggle = false;
		tTool->shootBall(0.95, 0.95, false); //tTool->shootBall(7000, 7000, true);
	}
	else if(controller1->rBumperGet() == false){
		r1Toggle = true;
	}

	//Shoot 75%
	if(controller1->lBumperGet() && l1Toggle){
		l1Toggle = false;
		tTool->shootBall(0.75, 0.75, false); //tTool->shootBall(6500, 6500, true);
	}
	else if(controller1->lBumperGet() == false){
		l1Toggle = true;
	}
	SmartDashboard::PutNumber("Left Shooter Speed", tTool->shooty->lShooter->GetSpeed());
	SmartDashboard::PutNumber("Right Shooter Speed", tTool->shooty->rShooter->GetSpeed());
}
