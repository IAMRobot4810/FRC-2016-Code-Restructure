/*
 * Shooter.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: 1750800404
 */

#include "Shooter.h"

Shooter::Shooter(){
	raiseShoot = new CANTalon(raiseShootID);
	raiseShoot->SetFeedbackDevice(CANTalon::CtreMagEncoder_Absolute);
	UpLimit = new DigitalInput(upLimitID);
	DownLimit = new DigitalInput(downLimitID);
	ballSense = new DigitalInput(ballSenseID);
	shootSol = new Solenoid(pcmID, shootSolID);
	lShooter = new CANTalon(lShooterID);
	rShooter = new CANTalon (rShooterID);
	picker = new CANTalon(pickerID);
}

Shooter::~Shooter(){
	delete raiseShoot;
	delete UpLimit;
	delete DownLimit;
	delete ballSense;
	delete shootSol;
	delete lShooter;
	delete rShooter;
	delete picker;
}

//Detect if the ball is in the cradle
bool Shooter::DetectBall(){
	bool ball;
	if(ballSense->Get()){
		ball = true;
	}
	else{
		ball = false;
	}
	return ball;
}

//Pickup the ball and stop when a ball is detected
void Shooter::Pickup(float speed){
	if(DetectBall() == false){
		picker->Set(speed);
		lShooter->Set(-(speed/rotorPickupDivisor));
		rShooter->Set(speed/rotorPickupDivisor);
	}
	else{
		picker->Set(0.0);
		lShooter->Set(0.0);
		rShooter->Set(0.0);
	}
	DetectBall();
}

//Pickup the ball if there's a sensor failure
void Shooter::PickupNoSensors(float speed){
	picker->Set(speed);
	lShooter->Set(-(speed/rotorPickupDivisor));
	rShooter->Set(speed/rotorPickupDivisor);
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
			raiseShoot->Set(0.0);
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
			raiseShoot->Set(0.0);
			ResetRaisePositionManual();
		}
	}
}

//Raise manually when there's a sensor failure
void Shooter::RaiseNoSensors(float speed){
		raiseShoot->Set(-speed);
}

//Lower manually, will stop at top limit
void Shooter::Lower(float speed){
	raiseShoot->StopMotor();
	if(raiseShoot->GetControlMode() == CANSpeedController::kPercentVbus){
		if(DownLimit->Get() == false || raiseShoot->GetPosition() <= maxShooterPos){
			raiseShoot->Set(speed);
		}
		else{
			raiseShoot->Set(0.0);
		}
	}
	else{
		raiseShoot->SetControlMode(CANSpeedController::kPercentVbus);
		raiseShoot->EnableControl();
		if(DownLimit->Get() == false || raiseShoot->GetPosition() <= maxShooterPos){
			raiseShoot->Set(speed);
		}
		else{
			raiseShoot->Set(0.0);
		}
	}
}

//Lower manually when there's a sensor failure
void Shooter::LowerNoSensors(float speed){
		raiseShoot->Set(speed);
}

//Aim for the high goal from far
void Shooter::BombShotAim(){
	raiseShoot->StopMotor();
	if(raiseShoot->GetControlMode() == CANSpeedController::kPosition){
		raiseShoot->Set(bombPos);
	}
	else{
		raiseShoot->SetControlMode(CANSpeedController::kPosition);
		raiseShoot->SetPID(shootPosP, shootPosI, shootPosD);
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
		raiseShoot->SetPID(shootPosP, shootPosI, shootPosD);
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
		raiseShoot->Set(0.0);
	}
	else{
		raiseShoot->Set(0.0);
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
		raiseShoot->SetPID(shootPosP, shootPosI, shootPosD);
		raiseShoot->EnableControl();
		raiseShoot->Set(pos);
	}
}

void Shooter::RPMShoot(int leftRPM, int rightRPM, float rollPow){

}

//Shoot when there's a sensor failure
void Shooter::ShootNoSensors(float leftPow, float rightPow, float rollPow){
	lShooter->Set(leftPow);
	rShooter->Set(-rightPow);
	picker->Set(-rollPow);
	Wait(shooterRampTime);
	shootSol->Set(true);
	Wait(shooterWaitTime);
	shootSol->Set(false);
	lShooter->Set(0.0);
	rShooter->Set(0.0);
	picker->Set(0.0);
}

