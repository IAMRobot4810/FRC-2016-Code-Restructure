/*
 * ConstantVals.h
 *
 *  Created on: Mar 11, 2016
 *      Author: 1750800404
 */

#ifndef SRC_UTIL_CONSTANTVALS_H_
#define SRC_UTIL_CONSTANTVALS_H_

//StickControl constants
static const double stickLowDead = -0.25; //Low end deadband for joystick
static const double stickHighDead = 0.25; //High end deadband for joystick
static const double stickOutSlope = 1.333333333333333333;  //0.933333333333333; //Slope for linear scaling for stick input
static const double stickOutIntercept = -0.4; //-0.233333333333333; //Intercept offset for linear scaling for stick input
static const double trigLowDead = 0.0; //Low end deadband for triggers
static const double trigHighDead = 0.25; //High end deadband for triggers
static const double trigInMin = 0.0; //Min input from trigger
static const double trigInMax = 1.0; //Max input from trigger
static const double trigOutMin = 0.0; //Min output for trigger
static const double trigOutMax = 0.35; //Max output for trigger

//DriveSystem constants
static const double turnAngleP = 0.05; //P constant for turning to an angle PID
static const double timeDriveWait = 0.03; //Wait time between loops for timed drive

//ShootRotorEncoder constants
static const int tapeLines = 8; //Number of pieces of tape on the rotor
static const int secsPerMin = 60; //Seconds per minute
static const float updateTime = 0.01; //Update time in seconds for sensor readings
static float scaleMultiple = secsPerMin/(updateTime*tapeLines); //Multiplier to convert reads per update to RPM

//Shooter constants
static const double rotorPickupDivisor = 1.5; //Voltage percentage division factor for rotors in pickup
static const double maxShooterPos = 0.919; //Maximum shooter encoder value
static const double minShooterPos = 0.0; //Minimum shooter encoder value
static const double turretPos = 0.108; //Turret shot encoder value
static const double bombPos = 0.033; //Bomb shot encoder value
static const double shootPosP = 0.5; //P Value for shooter aiming
static const double shootPosI = 0.0; //I Value for shooter aiming
static const double shootPosD = 0.0; //D Value for shooter aiming
static const int shooterAimTolerance = 50; //Shooter aiming encoder tolerance
static const double raiseShooterP = 0.001; //P constant for raising the shooter PID
static const double shooterRampTime = 1.0; //Ramp up time when shooting without RPM sensors
static const double shooterWaitTime = 0.25; //Wait time after shooting ball before retracting cylinder

#endif /* SRC_UTIL_CONSTANTVALS_H_ */
