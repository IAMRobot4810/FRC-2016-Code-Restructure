#include "auto/AutonDrive.h"

void AutonDrive::TimedDrive(float time, float lPower, float rPower){
	Wait(0.01);
	//time in seconds
	for(int i = 0; i < (time/tick); i++){
		roboDrive->TankDrive(lPower, rPower, false);
		Wait(tick);
	}
	roboDrive->TankDrive(0.0, 0.0, false);
	//Wait(15.0);
}

void AutonDrive::EncoDrive(int lEncoderVal, int rEncoderVal){

}
