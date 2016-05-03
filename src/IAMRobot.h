/*
 * IAMRobot.h
 *
 *  Created on: Apr 5, 2016
 *      Author: Achintya
 */

#ifndef SRC_IAMROBOT_H_
#define SRC_IAMROBOT_H_

#include "WPILib.h"
#include "LiveWindow/LiveWindow.h"
#include "nivision.h"
#include "systems/mtsub/parts/ShootRotorEncoder.h"
#include "systems/mtsub/DefenseArm.h"
#include "systems/mtsub/Roller.h"
#include "systems/mtsub/Shooter.h"
#include "systems/Camera.h"
#include "systems/DriveSystem.h"
#include "systems/MultiTool.h"
#include "teleop/StickControl.h"
#include "teleop/Teleop.h"
#include "auto/Auto.h"
#include "util/DeviceIDs.h"

class IAMRobot: public IterativeRobot{

public:
	IAMRobot();

private:
	~IAMRobot();

	LiveWindow *lw = LiveWindow::GetInstance();

	//Misc Objects
	USBCamera *camorra;
	CameraServer *camServe;
	Camera *cammy;
	bool camOn;

	//ShootRotorEncoder Objects
	DigitalInput *lRPMSensor;
	DigitalInput *rRPMSensor;
	Timer *lTimer;
	Timer *rTimer;
	ShootRotorEncoder *lTachy;
	ShootRotorEncoder *rTachy;

	//DriveSystem Objects
	CANTalon *flTal;
	CANTalon *rlTal;
	CANTalon *frTal;
	CANTalon *rrTal;
	RobotDrive *roboDrive;
	AnalogGyro *drvGyro;
	DriveSystem *drv;

	//Shooter Objects
	CANTalon *aimer;
	CANTalon *lShoot;
	CANTalon *rShoot;
	DigitalInput *upStop;
	DigitalInput *lowStop;
	Solenoid *plunger;
	Shooter *sht;

	//Roller Objects
	CANTalon *grabber;
	Solenoid *rlrMove;
	Roller *rlr;

	//DefenseArm Objects
	Solenoid *defMove;
	DefenseArm *def;

	//MultiTool Objects
	DigitalInput *senseBall;
	MultiTool *mt;

	//Camera Objects

	//Teleop Objects
	StickControl *cont1;
	StickControl *cont2;
	SendableChooser *teleChooser;
	const std::string teleNameSensors;
	const std::string teleNameNoSensors;
	std::string teleSelected;
	Teleop *tele;

	//Auto Objects
	SendableChooser *autoChooser;
	const std::string autoNameNone;
	const std::string autoNameLowBar;
	const std::string autoNameTerrain;
	const std::string autoNameMoat;
	const std::string autoNameDefense;
	const std::string autoNameSpy;
	std::string autoSelected;
	Auto *auton;

	void RobotInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestPeriodic();
};

#endif /* SRC_IAMROBOT_H_ */
