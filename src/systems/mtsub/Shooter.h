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
#include "util/DeviceIDs.h"
#include "systems/mtsub/parts/ShootRotorEncoder.h"

class Shooter{

public:
	Shooter(CANTalon *pivot, CANTalon *leftrotor, CANTalon *rightrotor,
			DigitalInput *topswitch, DigitalInput *bottomswitch, Solenoid *puncher,
			ShootRotorEncoder *leftrpmsensor, ShootRotorEncoder *rightrpmsensor);
	~Shooter();

	CANTalon *raiseShoot;
	CANTalon *lShooter;
	CANTalon *rShooter;
	DigitalInput *UpLimit;
	DigitalInput *DownLimit;
	Solenoid *shootSol;
	ShootRotorEncoder *lRPMSensor;
	ShootRotorEncoder *rRPMSensor;

	//void Pickup(float speed); //Pickup the ball and stop when a ball is detected
	//void PickupNoSensors(float speed); //Pickup the ball if there's a sensor failure
	void ResetRaisePositionManual(); //Reset the raising and lowering encoder manually
	void Raise(float speed); //Raise manually, will stop at top limit
	void RaiseNoSensors(float speed); //Raise manually when there's a sensor failure
	void Lower(float speed); //Lower manually, will stop at top limit
	void LowerNoSensors(float speed); //Lower manually when there's a sensor failure
	void BombShotAim(); //Aim for the high goal from far
	void TurretShotAim(); //Aim for the high goal from close
	void LowGoalAim(float speed); //Aim for the low goal
	void CustomAim(double pos); //Aim to a specific encoder value
	void RPMShoot(int leftRPM, int rightRPM); //Shoot with RPM readings
	void SpinRotors(float leftPow, float rightPow); //Spin the rotors. Positive is outward, negative is inward.
	void ShootNoSensors(float leftSpeed, float rightSpeed); //Shoot when there's a sensor failure

private:

protected:

};

#endif /* SRC_SYSTEMS_SHOOTER_H_ */
