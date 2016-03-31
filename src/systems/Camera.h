#ifndef CAMERA_H
#define CAMERA_H

#include "WPILib.h"

class Camera{
private:
	USBCamera* camera;
	Image* image;
public:
	Camera();
	~Camera();

	void capture();
	void get_infos();
	void calibrate(unsigned int brightness, unsigned int exposure, unsigned int whitebalance);
	void calibrateAuto(int brightness);
};


#endif
