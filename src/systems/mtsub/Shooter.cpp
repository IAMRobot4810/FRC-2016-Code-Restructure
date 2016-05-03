/*
 * Shooter.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: 1750800404
 */

#include "systems/mtsub/Shooter.h"

Shooter::Shooter(CANTalon *pivot, CANTalon *leftrotor, CANTalon *rightrotor,
		DigitalInput *topswitch, DigitalInput *bottomswitch, Solenoid *puncher,
		ShootRotorEncoder *leftrpmsensor, ShootRotorEncoder *rightrpmsensor){
	raiseShoot = pivot;
	raiseShoot->SetFeedbackDevice(CANTalon::CtreMagEncoder_Absolute);
	UpLimit = topswitch;
	DownLimit = bottomswitch;
	shootSol = puncher;
	lShooter = leftrotor;
	lShooter->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	lShooter->SetControlMode(CANTalon::kSpeed);
	lShooter->SetPID(0.7, 0.0, 0.0);
	lShooter->EnableControl();
	rShooter = rightrotor;
	rShooter->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	rShooter->SetControlMode(CANTalon::kSpeed);
	rShooter->SetPID(0.7, 0.0, 0.0);
	rShooter->EnableControl();
	lRPMSensor = leftrpmsensor;
	rRPMSensor = rightrpmsensor;
}

Shooter::~Shooter(){
	delete raiseShoot;
	delete UpLimit;
	delete DownLimit;
	delete shootSol;
	delete lShooter;
	delete rShooter;
	delete lRPMSensor;
	delete rRPMSensor;
}

//Reset the raising and lowering encoder manually
void Shooter::ResetRaisePositionManual(){
	raiseShoot->SetPosition(0);
}

//Raise manually, will stop at top limit
void Shooter::Raise(float speed){
	raiseShoot->StopMotor();
	if(raiseShoot->GetControlMode() == CANSpeedController::kPercentVbus){
		if(UpLimit->Get() == false || raiseShoot->GetEncPosition() >= minShooterPos){
			raiseShoot->Set(-speed);
		}
		else{
			raiseShoot->StopMotor();
			ResetRaisePositionManual();
		}
	}
	else{
		raiseShoot->SetControlMode(CANSpeedController::kPercentVbus);
		raiseShoot->EnableControl();
		if(UpLimit->Get() == false || raiseShoot->GetEncPosition() >= minShooterPos){
			raiseShoot->Set(-speed);
		}
		else{
			raiseShoot->StopMotor();
			ResetRaisePositionManual();
		}
	}
}

//Raise manually when there's a sensor failure
void Shooter::RaiseNoSensors(float speed){
	raiseShoot->StopMotor();
	if(raiseShoot->GetControlMode() == CANSpeedController::kPercentVbus){
		raiseShoot->Set(-speed);
	}
	else{
		raiseShoot->SetControlMode(CANSpeedController::kPercentVbus);
		raiseShoot->EnableControl();
		raiseShoot->Set(-speed);
	}
}

//Lower manually, will stop at top limit
void Shooter::Lower(float speed){
	raiseShoot->StopMotor();
	if(raiseShoot->GetControlMode() == CANSpeedController::kPercentVbus){
		if(DownLimit->Get() == false || raiseShoot->GetPosition() <= maxShooterPos){
			raiseShoot->Set(speed);
		}
		else{
			raiseShoot->StopMotor();
		}
	}
	else{
		raiseShoot->SetControlMode(CANSpeedController::kPercentVbus);
		raiseShoot->EnableControl();
		if(DownLimit->Get() == false || raiseShoot->GetPosition() <= maxShooterPos){
			raiseShoot->Set(speed);
		}
		else{
			raiseShoot->StopMotor();
		}
	}
}

//Lower manually when there's a sensor failure
void Shooter::LowerNoSensors(float speed){
	raiseShoot->StopMotor();
	if(raiseShoot->GetControlMode() == CANSpeedController::kPercentVbus){
		raiseShoot->Set(speed);
	}
	else{
		raiseShoot->SetControlMode(CANSpeedController::kPercentVbus);
		raiseShoot->EnableControl();
		raiseShoot->Set(speed);
	}
}

//Aim for the high goal from far
void Shooter::BombShotAim(){
	raiseShoot->StopMotor();
	if(raiseShoot->GetControlMode() == CANSpeedController::kPosition){
		raiseShoot->Set(bombPos);
	}
	else{
		raiseShoot->SetControlMode(CANSpeedController::kPosition);
		raiseShoot->SetPID(shootPosP, shootPosI, shootPosD, shootPosF);
		raiseShoot->EnableControl();
		raiseShoot->Set(bombPos);
	}
}

//Aim for the high goal from close
void Shooter::TurretShotAim(){
	raiseShoot->StopMotor();
	if(raiseShoot->GetControlMode() == CANSpeedController::kPosition){
		raiseShoot->Set(turretPos);
	}
	else{
		raiseShoot->SetControlMode(CANSpeedController::kPosition);
		raiseShoot->SetPID(shootPosP, shootPosI, shootPosD, shootPosF);
		raiseShoot->EnableControl();
		raiseShoot->Set(turretPos);
	}
}

//Aim for the low goal
void Shooter::LowGoalAim(float speed){
	if(DownLimit->Get() == true){
		while(DownLimit->Get() == true){
			raiseShoot->Set(speed);
		}
		raiseShoot->StopMotor();
	}
	else{
		raiseShoot->StopMotor();
	}
}

//Aim for a custom position
void Shooter::CustomAim(double pos){
	raiseShoot->StopMotor();
	if(raiseShoot->GetControlMode() == CANSpeedController::kPosition){
		raiseShoot->Set(pos);
	}
	else{
		raiseShoot->SetControlMode(CANSpeedController::kPosition);
		raiseShoot->SetPID(shootPosP, shootPosI, shootPosD, shootPosF);
		raiseShoot->EnableControl();
		raiseShoot->Set(pos);
	}
}

//Shoot with RPM readings
void Shooter::RPMShoot(int leftRPM, int rightRPM){
	//NEEDS TO BE FINISHED
	lShooter->SetControlMode(CANTalon::kSpeed);
	rShooter->SetControlMode(CANTalon::kSpeed);
	lShooter->EnableControl();
	rShooter->EnableControl();
	while(lShooter->GetSpeed() > (-leftRPM + 300) || rShooter->GetSpeed() < (rightRPM - 300)){
		lShooter->Set(-leftRPM);
		rShooter->Set(rightRPM);
		SmartDashboard::PutNumber("Left Shooter Speed", lShooter->GetSpeed());
		SmartDashboard::PutNumber("Right Shooter Speed", rShooter->GetSpeed());
	}
	shootSol->Set(true);
	Wait(shooterWaitTime);
	shootSol->Set(false);
	lShooter->StopMotor();
	rShooter->StopMotor();
}

//Spin the rotors. Positive is outward, negative is inward.
void Shooter::SpinRotors(float leftPow, float rightPow){
	lShooter->SetControlMode(CANTalon::kPercentVbus);
	rShooter->SetControlMode(CANTalon::kPercentVbus);
	lShooter->EnableControl();
	rShooter->EnableControl();
	lShooter->Set(-leftPow);
	rShooter->Set(rightPow);
}

//Shoot when there's a sensor failure
void Shooter::ShootNoSensors(float leftSpeed, float rightSpeed){
	lShooter->SetControlMode(CANTalon::kPercentVbus);
	rShooter->SetControlMode(CANTalon::kPercentVbus);
	lShooter->EnableControl();
	rShooter->EnableControl();
	SpinRotors(leftSpeed, rightSpeed);
	Wait(shooterRampTime);
	shootSol->Set(true);
	Wait(shooterWaitTime);
	shootSol->Set(false);
	lShooter->StopMotor();
	rShooter->StopMotor();
}

