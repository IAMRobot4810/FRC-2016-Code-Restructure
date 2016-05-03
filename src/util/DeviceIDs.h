/*
 * DeviceIDs.h
 *
 *  Created on: Mar 31, 2016
 *      Author: 1750800404
 */

#ifndef SRC_UTIL_DEVICEIDS_H_
#define SRC_UTIL_DEVICEIDS_H_

//Common IDs
static const int pcmID = 1;

//StickControl IDs
static const int cont1ID = 0;
static const int cont2ID = 1;
static const int aButtonID = 1;
static const int bButtonID = 2;
static const int xButtonID = 3;
static const int yButtonID = 4;
static const int lBumperID = 5;
static const int rBumperID = 6;
static const int backButtonID = 7;
static const int startButtonID = 8;
static const int lStickButtonID = 9;
static const int rStickButtonID = 10;
static const int lStickXAxis = 0;
static const int lStickYAxis = 1;
static const int lTrigAxis = 2;
static const int rTrigAxis = 3;
static const int rStickXAxis = 4;
static const int rStickYAxis = 5;

//Camera IDs
static constexpr char const *camID = "cam1";

//DriveSystem IDs
static const int flTalID = 7; //1
static const int rlTalID = 8; //2
static const int frTalID = 5; //3
static const int rrTalID = 6; //4
static const int gyroID = 0;

//Roller IDs
static const int rollerTalID = 3; //8
static const int rollerSolID = 2;

//Shooter IDs
static const int raiseShootID = 4; //7
static const int upLimitID = 4;
static const int downLimitID = 5;
static const int shootSolID = 0;
static const int lShooterID = 1; //5
static const int rShooterID = 2; //6

//ShootRotorEncoder IDs
static const int lRPMSensorID = 1;
static const int rRPMSensorID = 2;

//DefenseArm IDs
static const int noidID = 1;

//MultiTool IDs
static const int ballSenseID = 0;

#endif /* SRC_UTIL_DEVICEIDS_H_ */
