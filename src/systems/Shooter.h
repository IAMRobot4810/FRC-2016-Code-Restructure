/*
 * Shooter.h
 *
 *  Created on: Mar 7, 2016
 *      Author: 1750800404
 */

#ifndef SRC_SYSTEMS_SHOOTER_H_
#define SRC_SYSTEMS_SHOOTER_H_

#include "CANTalon.h"
#include "Solenoid.h"
#include "DigitalInput.h"
#include "Timer.h"
#include "util/ConstantVals.h"
#include "util/PIDStuff.h"

class Shooter{

public:
	Shooter();
	~Shooter();

	CANTalon *raiseShoot;
	CANTalon *lShooter;
	CANTalon *rShooter;
	CANTalon *picker;
	DigitalInput *UpLimit;
	DigitalInput *DownLimit;
	Solenoid *shootSol;
	DigitalInput *ballSense;
	DigitalInput *lRPMSensor;
	DigitalInput *rRPMSensor;
	Timer *rpmTimerL;
	Timer *rpmTimerR;

	bool DetectBall(); //Detect if the ball is in the cradle
	void Pickup(float speed); //Pickup the ball and stop when a ball is detected
	void PickupNoSensors(float speed); //Pickup the ball if there's a sensor failure
	void ResetRaiseEncoder(); //Reset the raising and lowering encoder based on limit switch
	void ResetRaiseEncoderManual(); //Reset the raising and lowering encoder manually
	void Raise(float speed); //Raise manually, will stop at top limit
	void RaiseNoSensors(float speed); //Raise manually when there's a sensor failure
	void Lower(float speed); //Lower manually, will stop at top limit
	void LowerNoSensors(float speed); //Lower manually when there's a sensor failure
	void BombShotAim(float speed); //Aim for the high goal from far
	void TurretShotAim(float speed); //Aim for the high goal from close
	void LowGoalAim(float speed); //Aim for the low goal
	float ReadRPM(DigitalInput *banner, Timer *time); //Read rotor RPM
	void Shoot(int leftRPM, int rightRPM, float rollPow); //Shoot with RPM readings
	void ShootNoSensors(float leftPow, float rightPow, float rollPow); //Shoot when there's a sensor failure

private:

protected:

};

#endif /* SRC_SYSTEMS_SHOOTER_H_ */
