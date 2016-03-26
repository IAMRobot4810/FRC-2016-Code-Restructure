#include "IterativeRobot.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"
#include "SmartDashboard/SendableChooser.h"
#include "USBCamera.h"
#include "CameraServer.h"
#include "teleop/Teleop.h"
#include "auto/Auto.h"


class Robot: public IterativeRobot
{
private:
	LiveWindow *lw = LiveWindow::GetInstance();
	SendableChooser *chooser;
	const std::string autoNameDefault = "Default";
	const std::string autoNameCustom = "My Auto";
	std::string autoSelected;

	//USBCamera *camera;
	Teleop *tele;
	Auto* auton;

	//bool runnable = true;

	~Robot(){
		//delete camera;
		delete tele;
		delete auton;
	}

	void RobotInit()
	{
		chooser = new SendableChooser();
		chooser->AddDefault(autoNameDefault, (void*)&autoNameDefault);
		chooser->AddObject(autoNameCustom, (void*)&autoNameCustom);
		SmartDashboard::PutData("Auto Modes", chooser);


		/*
		camera = new USBCamera("cam1", true);

		camera->SetExposureManual(1);
		camera->SetBrightness(1);
		camera->SetSize(320, 240);
		camera->SetFPS(20.0);


		CameraServer::GetInstance()->SetQuality(10);

		CameraServer::GetInstance()->StartAutomaticCapture("cam0");

		*/

		tele = new Teleop();
		auton = new Auto();



		//CameraServer::GetInstance()->StartAutomaticCapture("cam1");

		tele->def->Raise();

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
	void AutonomousInit()
	{
		autoSelected = *((std::string*)chooser->GetSelected());
		//std::string autoSelected = SmartDashboard::GetString("Auto Selector", autoNameDefault);
		std::cout << "Auto selected: " << autoSelected << std::endl;

		if(autoSelected == autoNameCustom){
			//Custom Auto goes here
		} else {
			//Default Auto goes here
		}
		//tele->drive->roboDrive->SetSafetyEnabled(false)
	}

	void AutonomousPeriodic()
	{
		//tele->drive->roboDrive->SetSafetyEnabled(false);
		/*
		if(autoSelected == autoNameCustom){
			//Custom Auto goes here
		} else {
			//Default Auto goes here
		}
		*/
		auton->AutonMode1();

		Wait(0.03);
		//Wait(15.0);
	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		tele->TeleopWithSensors();
		//tele->TeleopNoSensors();
	}

	void TestPeriodic()
	{
		lw->Run();
	}

};

START_ROBOT_CLASS(Robot)
