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

public:
	Camera(USBCamera *camera, CameraServer *camServer);
	~Camera();

	USBCamera *cam;
	CameraServer *cServer;
	Image *image;

	void capture();
	void stopCapture();
	void get_infos();
	void calibrate(unsigned int brightness, unsigned int exposure, unsigned int whitebalance);
	void calibrateAuto(unsigned int brightness);
};


#endif
