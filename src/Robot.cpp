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
	const std::string autoNameLowBar = "Low Bar Auto";
	const std::string autoNameTerrain = "Terrain Auto";
	const std::string autoNameDefense = "Defense Auto";
	const std::string autoNameSpy = "Spy Box Auto";
	std::string autoSelected;

	USBCamera *camera;
	Teleop *tele;
	//Auto *auton;

	~Robot(){
		delete camera;
		delete tele;
		//delete auton;
	}

	void RobotInit()
	{
		chooser = new SendableChooser();
		chooser->AddDefault(autoNameLowBar, (void*)&autoNameLowBar);
		chooser->AddObject(autoNameTerrain, (void*)&autoNameTerrain);
		chooser->AddObject(autoNameDefense, (void*)&autoNameDefense);
		chooser->AddObject(autoNameSpy, (void*)&autoNameSpy);
		SmartDashboard::PutData("Auto Modes", chooser);

		camera = new USBCamera("cam1", true);

		camera->SetExposureManual(1);
		camera->SetBrightness(1);
		camera->SetSize(320, 240);
		camera->SetFPS(20.0);

		CameraServer::GetInstance()->SetQuality(10);
		CameraServer::GetInstance()->StartAutomaticCapture("cam1");

		//auton = new Auto();
		tele = new Teleop();
		tele->shoot->raiseShoot->SetPosition(0.0);
		tele->shoot->raiseShoot->SetPulseWidthPosition(0);
		tele->shoot->raiseShoot->SetEncPosition(0);
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

		if(autoSelected == autoNameTerrain){
			//Custom Auto goes here
			tele->shoot->Raise(0.5);
			tele->drive->TimeDrive(0.75, 0.0, 4.0);
			Wait(5.0);
		}
		else if(autoSelected == autoNameDefense){

		}
		else if(autoSelected == autoNameSpy){
			tele->def->Lower();
			tele->shoot->BombShotAim(0.75);
		}
		else{
			//Default Auto goes here
			tele->def->Lower();
			Wait(0.5);
			tele->drive->TimeDrive(0.5, 0.0, 1.0);
			Wait(0.25);
			tele->shoot->Lower(0.75);
			Wait(0.75);
			tele->shoot->raiseShoot->Set(0.0);
			tele->drive->TimeDrive(0.75, 0.0, 2.5);
			Wait(1.0);
			tele->drive->RotatetoAngle(45, 0.75);
			tele->shoot->BombShotAim(0.75);
		}
	}

	void AutonomousPeriodic()
	{
		if(autoSelected == autoNameLowBar){
			//Custom Auto goes here
		} else {
			//Default Auto goes here
		}
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
