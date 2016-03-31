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
static const std::string camID = "cam0";

//GyroSensor IDs
static const int gyroID = 0;

//DriveSystem IDs
static const int flTalID = 1; //7
static const int rlTalID = 2; //8
static const int frTalID = 3; //5
static const int rrTalID = 4; //6

//Shooter IDs
static const int raiseShootID = 7; //4
static const int upLimitID = 4;
static const int downLimitID = 5;
static const int ballSenseID = 0;
static const int shootSolID = 0;
static const int lShooterID = 5; //1
static const int rShooterID = 6; //2
static const int lRPMSensorID = 1;
static const int rRPMSensorID = 2;
static const int pickerID = 8; //3

//DefenseArm IDs
static const int noidID = 1;

#endif /* SRC_UTIL_DEVICEIDS_H_ */
