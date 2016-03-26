#include "auto/AutonDrive.h"


AutonDrive::AutonDrive(){
	gyr = new GyroSensor(0);

}

AutonDrive::~AutonDrive(){
	delete gyr;
}

void AutonDrive::TimedDrive(float time, float straight, float rotate){
	//time in seconds
	for(int i = 0; i < (time/tick); i++){
		roboDrive->ArcadeDrive(straight, rotate, false);
		Wait(tick);
	}
	roboDrive->ArcadeDrive(0.0, 0.0, false);
	//Wait(15.0);
}

void AutonDrive::EncoDrive(int lEncoderVal, int rEncoderVal){

}

void AutonDrive::RotateToAngle(double angle, double speed){
	if(gyr->GyroAngleRead() < angle){
		while(gyr->GyroAngleRead() < angle){
			roboDrive->ArcadeDrive(0.0, PMotorPower(gyr->GyroAngleRead(), angle, turnAngleP, speed, -speed), false);
		}
		roboDrive->ArcadeDrive(0.0, 0.0, false);
	}
	else if(gyr->GyroAngleRead() > angle){
		while(gyr->GyroAngleRead() < angle){
			roboDrive->ArcadeDrive(0.0, PMotorPower(gyr->GyroAngleRead(), angle, turnAngleP, speed, -speed), false);
		}
		roboDrive->ArcadeDrive(0.0, 0.0, false);
	}
	else{
		roboDrive->ArcadeDrive(0.0, 0.0, false);
	}
}
