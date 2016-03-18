/*
 * Shooter.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: 1750800404
 */

#include "Shooter.h"

Shooter::Shooter(){
	raiseShoot = new CANTalon(4); //7
	raiseShoot->SetFeedbackDevice(CANTalon::CtreMagEncoder_Absolute);
	UpLimit = new DigitalInput(4);
	DownLimit = new DigitalInput(5);
	ballSense = new DigitalInput(0); //3
	shootSol = new Solenoid(1, 0);
	lShooter = new CANTalon(1); //5
	rShooter = new CANTalon (2); //6
	lRPMSensor = new DigitalInput(1);
	rRPMSensor = new DigitalInput(2);
	picker = new CANTalon(3); //8
	rpmTimerL = new Timer();
	rpmTimerR = new Timer();
}

Shooter::~Shooter(){
	delete raiseShoot;
	delete UpLimit;
	delete DownLimit;
	delete ballSense;
	delete shootSol;
	delete lShooter;
	delete rShooter;
	delete lRPMSensor;
	delete rRPMSensor;
	delete picker;
	delete rpmTimerL;
	delete rpmTimerR;
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
		lShooter->Set(-(speed/1.5));
		rShooter->Set(speed/1.5);
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
	lShooter->Set(-(speed/1.5));
	rShooter->Set(speed/1.5);
}

void Shooter::ResetRaiseEncoder(){
	if(UpLimit->Get()){
		raiseShoot->SetEncPosition(0);
	}
}

//Reset the raising and lowering encoder manually
void Shooter::ResetRaiseEncoderManual(){
	raiseShoot->SetEncPosition(0);
}

//Raise manually, will stop at top limit
void Shooter::Raise(float speed){
	if(UpLimit->Get() == true){
		raiseShoot->Set(-speed);
	}
	else{
		raiseShoot->Set(0.0);
	}
}

//Raise manually when there's a sensor failure
void Shooter::RaiseNoSensors(float speed){
		raiseShoot->Set(-speed);
}

//Lower manually, will stop at top limit
void Shooter::Lower(float speed){
	if(DownLimit->Get() == true){ //raiseShoot->GetEncPosition() < shooterRestLimit
		raiseShoot->Set(speed);
	}
	else{
		raiseShoot->Set(0.0);
	}
}

//Lower manually when there's a sensor failure
void Shooter::LowerNoSensors(float speed){
		raiseShoot->Set(speed);
}

//Aim for the high goal from far
void Shooter::BombShotAim(float speed){
	if(raiseShoot->GetEncPosition() > 10100){
		while(raiseShoot->GetEncPosition() > 10100){
			//raiseShoot->Set(-speed);
			raiseShoot->Set(PMotorPower(raiseShoot->GetEncPosition(), 10100, raiseShooterP, speed, -speed));
		}
		raiseShoot->Set(0.0);
	}
	else if (raiseShoot->GetEncPosition() < 10000){
		while(raiseShoot->GetEncPosition() < 10000){
			//raiseShoot->Set(speed);
			raiseShoot->Set(PMotorPower(raiseShoot->GetEncPosition(), 10000, raiseShooterP, speed, -speed));
		}
		raiseShoot->Set(0.0);
	}
	else{
		raiseShoot->Set(0.0);
	}
}

//Aim for the high goal from close
void Shooter::TurretShotAim(float speed){
	if(raiseShoot->GetEncPosition() > 5100){
		while(raiseShoot->GetEncPosition() > 5100){
			//raiseShoot->Set(-speed);
			raiseShoot->Set(PMotorPower(raiseShoot->GetEncPosition(), 5100, raiseShooterP, speed, -speed));
		}
		raiseShoot->Set(0.0);
	}
	else if (raiseShoot->GetEncPosition() < 5000){
		while(raiseShoot->GetEncPosition() < 5000){
			//raiseShoot->Set(speed);
			raiseShoot->Set(PMotorPower(raiseShoot->GetEncPosition(), 5000, raiseShooterP, speed, -speed));
		}
		raiseShoot->Set(0.0);
	}
	else{
		raiseShoot->Set(0.0);
	}
}

//Aim for the low goal
void Shooter::LowGoalAim(float speed){
	if(DownLimit->Get()){
		while(DownLimit->Get()){
			raiseShoot->Set(-speed);
		}
		raiseShoot->Set(0.0);
	}
	else{
		raiseShoot->Set(0.0);
	}
}

float Shooter::ReadRPM(DigitalInput *banner, Timer *Minute, float rpmReading){
	bool bannerToggle = true;
	int reads = 0;
	Minute->Reset();
	Minute->Start();
	while(Minute->Get() <= 0.05){
		if(banner->Get() == false && bannerToggle){
			bannerToggle = false;
			reads++;
		}
		else if(banner->Get()){
			bannerToggle = true;
		} //Test this
	}
	Minute->Stop();
	rpmReading = reads * 400; //1200
	return rpmReading;
}

/*void Shooter::Shoot(int leftRPM, int rightRPM, float rollPow){
	lShooter->Set(0.1);
	rShooter->Set(-0.1);
	picker->Set(rollPow);
	if(leftRPM > 2400){
		leftRPM = 2400;
	}
	if(rightRPM > 2400){
		rightRPM = 2400;
	}
	for(int lPow = 0.1; ReadRPM(lBanner, rpmTimerL, lRPMReading) < (leftRPM - 200) || lPow <= 1.0; lPow += 0.1){
		lShooter->Set(lPow);
	}
	for(int rPow = 0.1; ReadRPM(rBanner, rpmTimerR, rRPMReading) < (rightRPM - 200) || rPow <= 1.0; rPow -= 0.1){
		rShooter->Set(-rPow);
	}
	shootSol->Set(true);
	Wait(1.0);
	shootSol->Set(false);
	lShooter->Set(0.0);
	rShooter->Set(0.0);
	picker->Set(0.0);
}*/

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

