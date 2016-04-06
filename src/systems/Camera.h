#ifndef CAMERA_H
#define CAMERA_H

#include "USBCamera.h"
#include "nivision.h"
#include "CameraServer.h"
#include "NIIMAQdx.h"
#include "SmartDashboard/SmartDashboard.h"
#include "util/DeviceIDs.h"

class Camera{
private:
	USBCamera* camera;
	Image* image;
public:
	Camera();
	Camera(std::string camId);
	~Camera();

	void capture();
	void get_infos();
	void check_emergency_stop();
	void calibrate(unsigned int brightness, unsigned int exposure, unsigned int whitebalance);
	void calibrateAuto(int brightness);
};


#endif
