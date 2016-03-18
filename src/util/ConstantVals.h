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
const double stickOutSlope = 0.933333333333333; //Slope for linear scaling for stick input
const double stickOutIntercept = -0.233333333333333; //Intercept offset for linear scaling for stick input
const double trigLowDead = 0.0; //Low end deadband for triggers
const double trigHighDead = 0.25; //High end deadband for triggers
const double trigInMin = 0.0; //Min input from trigger
const double trigInMax = 1.0; //Max input from trigger
const double trigOutMin = 0.0; //Min output for trigger
const double trigOutMax = 0.25; //Max output for trigger

const double turnAngleP = 0.05; //P constant for turning to an angle PID

const double raiseShooterP = 0.0007; //P constant for raising the shooter PID
const double shooterRampTime = 0.5; //Ramp up time when shooting without RPM sensors
const double shooterWaitTime = 0.25; //Wait time after shooting ball before retracting cylinder without RPM sensors

#endif /* SRC_UTIL_CONSTANTVALS_H_ */
