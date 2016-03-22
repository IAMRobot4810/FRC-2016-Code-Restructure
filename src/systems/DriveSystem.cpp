/*
 * DriveSystem.cpp
 *
 *  Created on: Feb 7, 2016
 *      Author: 1750800404
 */

#include "DriveSystem.h"

DriveSystem::DriveSystem() : gyro(0){
	flTal = new CANTalon(2); //1, 7 practice
	rlTal = new CANTalon(3); //2, 8 practice
	frTal = new CANTalon(5); //3, 5 practice
	rrTal = new CANTalon(6); //4, 6 practice
	flTal->SetFeedbackDevice(CANTalon::QuadEncoder);
	rlTal->SetFeedbackDevice(CANTalon::QuadEncoder);
	frTal->SetFeedbackDevice(CANTalon::QuadEncoder);
	rrTal->SetFeedbackDevice(CANTalon::QuadEncoder);
	roboDrive = new RobotDrive(flTal, rlTal, frTal, rrTal);
	roboDrive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
	roboDrive->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
	roboDrive->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
	roboDrive->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
	//gyro = new AnalogGyro(0);
	gyro.InitGyro();
	//roboDrive->SetSafetyEnabled(false);
}

DriveSystem::~DriveSystem(){
	delete flTal;
	delete rlTal;
	delete frTal;
	delete rrTal;
	delete roboDrive;
	//delete gyro;
}

double DriveSystem::GyroAngleRead(){
	return gyro.GetAngle();
}

void DriveSystem::DriveArcade(float straight, float rotate){
	roboDrive->ArcadeDrive(straight, rotate, false);
}

void DriveSystem::DriveTank(float left, float right){
	roboDrive->TankDrive(left, right, false);
}

void DriveSystem::RotatetoAngle(double angle, double speed){
	if(gyro.GetAngle() < angle){
		while(gyro.GetAngle() < angle){
			roboDrive->ArcadeDrive(0.0, PMotorPower(gyro.GetAngle(), angle, raiseShooterP, speed, -speed), false);
		}
		roboDrive->ArcadeDrive(0.0, 0.0, false);
	}
	else if(gyro.GetAngle() > angle){
		while(gyro.GetAngle() < angle){
			roboDrive->ArcadeDrive(0.0, PMotorPower(gyro.GetAngle(), angle, raiseShooterP, speed, -speed), false);
		}
		roboDrive->ArcadeDrive(0.0, 0.0, false);
	}
	else{
		roboDrive->ArcadeDrive(0.0, 0.0, false);
	}
}



