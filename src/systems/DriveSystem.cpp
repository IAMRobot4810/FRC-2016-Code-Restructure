/*
 * DriveSystem.cpp
 *
 *  Created on: Feb 7, 2016
 *      Author: 1750800404
 */

#include "DriveSystem.h"

DriveSystem::DriveSystem(){
	flTal = new CANTalon(7); //1
	rlTal = new CANTalon(8); //2
	frTal = new CANTalon(5); //3
	rrTal = new CANTalon(6); //4
	roboDrive = new RobotDrive(flTal, rlTal, frTal, rrTal);
	roboDrive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
	roboDrive->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
	roboDrive->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
	roboDrive->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
	roboDrive->SetExpiration(0.1);
}

DriveSystem::~DriveSystem(){
	delete flTal;
	delete rlTal;
	delete frTal;
	delete rrTal;
	delete roboDrive;
}

void DriveSystem::DriveArcade(float straight, float rotate){
	roboDrive->ArcadeDrive(straight, rotate, false);
}

void DriveSystem::DriveTank(float left, float right){
	roboDrive->TankDrive(left, right, false);
}



