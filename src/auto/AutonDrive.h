#ifndef AUTO_AUTONDRIVE_H
#define AUTO_AUTONDRIVE_H

class AutonDrive : public DriveSystem{
private:
public:
	void TimedDrive(float time, float lPower, float rPower);
	void EncoDrive(int lEncoderVal, int rEncoderVal)
};


#endif
