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
	flTal->SetFeedbackDevice(CANTalon::QuadEncoder);
	rlTal->SetFeedbackDevice(CANTalon::QuadEncoder);
	frTal->SetFeedbackDevice(CANTalon::QuadEncoder);
	rrTal->SetFeedbackDevice(CANTalon::QuadEncoder);
	roboDrive = new RobotDrive(flTal, rlTal, frTal, rrTal);
	roboDrive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
	roboDrive->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
	roboDrive->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
	roboDrive->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
	gyr = new GyroSensor;
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

void DriveSystem::RotatetoAngle(double angle, double speed){
	if(gyr->GyroAngleRead() < angle){
		while(gyr->GyroAngleRead() < angle){
			roboDrive->ArcadeDrive(0.0, PMotorPower(gyr->GyroAngleRead(), angle, turnAngleP, speed, -speed), false);
		}
		roboDrive->ArcadeDrive(0.0, 0.0, false);
	}
	else if(gyr->GyroAngleRead() > angle){
		while(gyr->GyroAngleRead() < angle){
			roboDrive->ArcadeDrive(0.0, PMotorPower(gyr->GyroAngleRead(), angle, turnAngleP, speed, -speed), false);
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

