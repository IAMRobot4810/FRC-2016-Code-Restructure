/*
 * ConstantVals.h
 *
 *  Created on: Mar 11, 2016
 *      Author: 1750800404
 */

#ifndef SRC_UTIL_CONSTANTVALS_H_
#define SRC_UTIL_CONSTANTVALS_H_

const double stickLowDead = -0.25; //Low end deadband for joystick
const double stickHighDead = 0.25; //High end deadband for joystick
const double stickOutSlope = 1.333333333333333333;  //0.933333333333333; //Slope for linear scaling for stick input
const double stickOutIntercept = -0.4; //-0.233333333333333; //Intercept offset for linear scaling for stick input
const double trigLowDead = 0.0; //Low end deadband for triggers
const double trigHighDead = 0.25; //High end deadband for triggers
const double trigInMin = 0.0; //Min input from trigger
const double trigInMax = 1.0; //Max input from trigger
const double trigOutMin = 0.0; //Min output for trigger
const double trigOutMax = 0.35; //Max output for trigger

const double turnAngleP = 0.05; //P constant for turning to an angle PID
const double timeDriveWait = 0.03; //Wait time between loops for timed drive

const double maxShooterPos = 0.919; //Maximum shooter encoder value
const double minShooterPos = 0.0; //Minimum shooter encoder value
const double turretPos = 0.173; //Turret shot encoder value
const double bombPos = 0.041; //Bomb shot encoder value
const int shooterAimTolerance = 50; //Shooter aiming encoder tolerance
const double raiseShooterP = 0.001; //P constant for raising the shooter PID
const double shooterRampTime = 0.5; //Ramp up time when shooting without RPM sensors
const double shooterWaitTime = 0.25; //Wait time after shooting ball before retracting cylinder without RPM sensors

#endif /* SRC_UTIL_CONSTANTVALS_H_ */
