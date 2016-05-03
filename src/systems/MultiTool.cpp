/*
 * MultiTool.cpp
 *
 *  Created on: Apr 5, 2016
 *      Author: Achintya
 */

#include "MultiTool.h"

MultiTool::MultiTool(Shooter *shooter, Roller *roller,
		DigitalInput *ballsensor, DefenseArm *defensearm){
	shooty = shooter;
	rolly = roller;
	ballSense = ballsensor;
	def = defensearm;
}

MultiTool::~MultiTool(){
	delete shooty;
	delete rolly;
	delete ballSense;
	delete def;
}

//Move the roller into up or down position
void MultiTool::moveRoll(){
	if(rolly->Low == true){
		rolly->Raise();
	}
	else{
		rolly->Lower();
	}
}

//Shoot the ball
void MultiTool::shootBall(float leftSpeed, float rightSpeed, bool RPM){
	if(shooty->raiseShoot->GetPosition() < shooterHalfPos){
		rolly->Lower();
		def->Lower();
		if(RPM == true){
			shooty->RPMShoot(leftSpeed, rightSpeed);
		}
		else{
			shooty->ShootNoSensors(leftSpeed, rightSpeed);
		}
	}
	else{
		rolly->Raise();
		if(RPM == true){
			shooty->RPMShoot(leftSpeed, rightSpeed);
		}
		else{
			shooty->ShootNoSensors(leftSpeed, rightSpeed);
		}
	}
}

//Pickup the ball and stop when a ball is detected
void MultiTool::pickBall(float speed){
	float rotoSpeed = (-(speed/rotorPickupDivisor));
	if(ballSense->Get() == false){
		rolly->Roll(speed);
		shooty->SpinRotors(rotoSpeed, rotoSpeed);
	}
	else{
		rolly->Roll(0.0);
		shooty->SpinRotors(0.0, 0.0);
	}
	ballSense->Get();
}

//Pickup the ball if there's a sensor failure
void MultiTool::pickBallNoSensor(float speed){
	float rotoSpeed = (-(speed/rotorPickupDivisor));
	rolly->Roll(speed);
	shooty->SpinRotors(rotoSpeed, rotoSpeed);
}

//Move the defense arm up and down
void MultiTool::moveDef(){
	if(def->Low == true){
		def->Raise();
	}
	else{
		def->Lower();
	}
}

//Raise all multitool systems
void MultiTool::raiseAll(){
	shooty->CustomAim(0.0);
	def->Raise();
	rolly->Raise();
}

//Lower all multitool systems
void MultiTool::lowerAll(){
	shooty->LowGoalAim(0.75);
	def->Lower();
	rolly->Lower();
}
