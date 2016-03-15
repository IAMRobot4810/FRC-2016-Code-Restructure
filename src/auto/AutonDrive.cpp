#include "auto/AutonDrive.h"

void AutonDrive::TimedDrive(float time, float lPower, float rPower){
	Wait(0.01);
	roboDrive->TankDrive(lPower, rPower);
	Wait(time);
	roboDrive->TankDrive(0.0, 0.0);
}

void AutonDrive::EncoDrive(int lEncoderVal, int rEncoderVal){

}
