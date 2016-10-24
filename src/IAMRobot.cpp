
#include "IAMRobot.h"

IAMRobot::IAMRobot() : camOn(true), teleNameSensors("Sensors Enabled"),
	teleNameNoSensors("Sensors Disabled"), autoNameNone("No Auto"),
	autoNameLowBar("Low Bar / Portcullis Auto"), autoNameTerrain("Rough Terrain / Rock Wall Auto"),
	autoNameMoat("Moat / Ramparts Auto"), autoNameDefense("Defense Arm Auto"),
	autoNameSpy("Spy Bot Auto")
{
	//Misc Objects
	camorra = new USBCamera(camID, false);
	camServe = CameraServer::GetInstance();
	cammy = new Camera(camorra, camServe);

	//ShootRotorEncoder Objects
	lRPMSensor = new DigitalInput(lRPMSensorID);
	rRPMSensor = new DigitalInput(rRPMSensorID);
	lTimer = new Timer();
	rTimer = new Timer();
	lTachy = new ShootRotorEncoder(lRPMSensor, lTimer);
	rTachy = new ShootRotorEncoder(rRPMSensor, rTimer);

	//DriveSystem Objects
	flTal = new CANTalon(flTalID);
	rlTal = new CANTalon(rlTalID);
	frTal = new CANTalon(frTalID);
	rrTal = new CANTalon(rrTalID);
	roboDrive = new RobotDrive(flTal, rlTal, frTal, rrTal);
	drvGyro = new AnalogGyro(gyroID);
	drv = new DriveSystem(roboDrive, drvGyro);

	//Shooter Objects
	aimer = new CANTalon(raiseShootID);
	lShoot = new CANTalon(lShooterID);
	rShoot  = new CANTalon(rShooterID);
	upStop  = new DigitalInput(upLimitID);
	lowStop = new DigitalInput(downLimitID);
	plunger = new Solenoid(pcmID, shootSolID);
	sht = new Shooter(aimer, lShoot, rShoot, upStop, lowStop, plunger, lTachy, rTachy);

	//Roller Objects
	grabber = new CANTalon(rollerTalID);
	rlrMove = new Solenoid(pcmID, rollerSolID);
	rlr = new Roller(grabber, rlrMove);

	//DefenseArm Objects
	defMove = new Solenoid(pcmID, noidID);
	def = new DefenseArm(defMove);

	//MultiTool Objects
	senseBall = new DigitalInput(ballSenseID);
	mt = new MultiTool(sht, rlr, senseBall, def);

	//Camera Objects

	//Teleop Objects
	cont1 = new StickControl(cont1ID);
	cont2 = new StickControl(cont2ID);
	teleChooser = new SendableChooser();
	tele = new Teleop(drv, mt, cont1, cont2);

	//Auto Objects
	autoChooser = new SendableChooser();
	auton = new Auto(drv, mt);
}

IAMRobot::~IAMRobot(){
	delete lRPMSensor;
	delete rRPMSensor;
	delete lTimer;
	delete rTimer;
	delete lTachy;
	delete rTachy;
	delete flTal;
	delete rlTal;
	delete frTal;
	delete rrTal;
	delete roboDrive;
	delete drvGyro;
	delete drv;
	delete aimer;
	delete lShoot;
	delete rShoot;
	delete upStop;
	delete lowStop;
	delete plunger;
	delete sht;
	delete grabber;
	delete rlrMove;
	delete rlr;
	delete defMove;
	delete def;
	delete senseBall;
	delete mt;
	delete cont1;
	delete cont2;
	delete tele;
	delete auton;
}

void IAMRobot::RobotInit(){
		autoChooser->AddDefault(autoNameNone, (void*)&autoNameNone);
		autoChooser->AddObject(autoNameLowBar, (void*)&autoNameLowBar);
		autoChooser->AddObject(autoNameTerrain, (void*)&autoNameTerrain);
		autoChooser->AddObject(autoNameMoat, (void*)&autoNameMoat);
		autoChooser->AddObject(autoNameDefense, (void*)&autoNameDefense);
		autoChooser->AddObject(autoNameSpy, (void*)&autoNameSpy);
		SmartDashboard::PutData("Auto Modes", autoChooser);

		teleChooser->AddDefault(teleNameSensors, (void*)&teleNameSensors);
		teleChooser->AddObject(teleNameNoSensors, (void*)&teleNameNoSensors);
		SmartDashboard::PutData("Sensors in Teleop", teleChooser);

		//CameraServer::GetInstance()->StartAutomaticCapture(camID);
		/*camorra->SetBrightness(50);
		camorra->SetExposureAuto();
		camorra->SetWhiteBalanceAuto();*/
		//camServe->StartAutomaticCapture(camID);

		cammy->calibrateAuto(50);

		flTal->SetFeedbackDevice(CANTalon::QuadEncoder);
		rlTal->SetFeedbackDevice(CANTalon::QuadEncoder);
		frTal->SetFeedbackDevice(CANTalon::QuadEncoder);
		rrTal->SetFeedbackDevice(CANTalon::QuadEncoder);

		sht->raiseShoot->SetPosition(0.0);
		sht->raiseShoot->SetPulseWidthPosition(0);
		sht->raiseShoot->SetEncPosition(0);
}


	/**
	 * This autonomous (along with the chooser code above) shows how to select between different autonomous modes
	 * using the dashboard. The sendable chooser code works with the Java SmartDashboard. If you prefer the LabVIEW
	 * Dashboard, remove all of the chooser code and uncomment the GetString line to get the auto name from the text box
	 * below the Gyro
	 *
	 * You can add additional auto modes by adding additional comparisons to the if-else structure below with additional strings.
	 * If using the SendableChooser make sure to add them to the chooser code above as well.
	 */
void IAMRobot::AutonomousInit()
{
	autoSelected = *((std::string*)autoChooser->GetSelected());
	//std::string autoSelected = SmartDashboard::GetString("Auto Selector", autoNameDefault);
	std::cout << "Auto selected: " << autoSelected << std::endl;

	if(autoSelected == autoNameTerrain){
		auton->RockRoughAuton();
	}
	else if(autoSelected == autoNameMoat){
		auton->MoatRampartsAuton();
	}
	else if(autoSelected == autoNameDefense){
		auton->DoorAuton();
	}
	else if(autoSelected == autoNameSpy){
		auton->SpyAuton();
	}
	else if(autoSelected == autoNameLowBar){
		auton->LowPortAuton();
	}
	else{
		auton->NoAuton();
	}
}

void IAMRobot::AutonomousPeriodic()
{
	if(autoSelected == autoNameLowBar){
		//Custom Auto goes here
	}
	else{
		//Default Auto goes here
	}
}

void IAMRobot::TeleopInit()
{
	teleSelected = *((std::string*)teleChooser->GetSelected());
	std::cout << "Sensor Setting: " << teleSelected << std::endl;

	if(teleSelected == teleNameNoSensors){
	}
	else{
	}
}

void IAMRobot::TeleopPeriodic()
{
	/*if(teleSelected == teleNameNoSensors){
		if(camorra->StatusIsFatal()){
			cammy->stopCapture();
			tele->TeleopNoSensors();
		}
		else{
			cammy->capture();
			tele->TeleopNoSensors();
		}
		//tele->TeleopNoSensors();
	}
	else{
		if(camorra->StatusIsFatal()){
			cammy->stopCapture();
			tele->TeleopWithSensors();
		}
		else{
			cammy->capture();
			tele->TeleopWithSensors();
		}
		//tele->TeleopWithSensors();
	}*/

	//if(camOn == false){
		tele->TeleopWithSensors();
	/*}
	else{
		cammy->capture();
		tele->TeleopWithSensors();
		if(camorra->StatusIsFatal() == true){
			cammy->stopCapture();
			camOn = false;
		}
	}*/
}

void IAMRobot::TestPeriodic()
{
	lw->Run();
}

START_ROBOT_CLASS(IAMRobot)
