/*
 * DriveSystem.cpp
 *
 *  Created on: Feb 7, 2016
 *      Author: 1750800404
 */

#include "systems/DriveSystem.h"

DriveSystem::DriveSystem(RobotDrive *drivesystem, AnalogGyro *gyroscope){
	roboDrive = drivesystem;
	roboDrive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
	roboDrive->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
	roboDrive->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
	roboDrive->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
	roboDrive->SetExpiration(0.1);
	gyr = gyroscope;
}

DriveSystem::~DriveSystem(){
	delete roboDrive;
}

void DriveSystem::DriveArcade(float straight, float rotate){
	roboDrive->ArcadeDrive(straight, rotate, false);
}

void DriveSystem::DriveTank(float left, float right){
	roboDrive->TankDrive(left, right, false);
}

void DriveSystem::ResetGyro(){
	gyr->Reset();
}

void DriveSystem::RotatetoAngle(double angle, double speed){
	if(gyr->GetAngle() < angle){
		while(gyr->GetAngle() < angle){
			roboDrive->ArcadeDrive(0.0, PMotorPower(gyr->GetAngle(), angle, turnAngleP, speed, -speed), false);
		}
		roboDrive->ArcadeDrive(0.0, 0.0, false);
	}
	else if(gyr->GetAngle() > angle){
		while(gyr->GetAngle() < angle){
			roboDrive->ArcadeDrive(0.0, PMotorPower(gyr->GetAngle(), angle, turnAngleP, speed, -speed), false);
		}
		roboDrive->ArcadeDrive(0.0, 0.0, false);
	}
	else{
		roboDrive->ArcadeDrive(0.0, 0.0, false);
	}
}

void DriveSystem::TimeDrive(float straight, float rotate, int seconds){
	for(int i = 0; i <= (seconds/timeDriveWait); i++){
		roboDrive->ArcadeDrive(straight, rotate, false);
		Wait(timeDriveWait);
	}
	roboDrive->ArcadeDrive(0.0, 0.0, false);
}

