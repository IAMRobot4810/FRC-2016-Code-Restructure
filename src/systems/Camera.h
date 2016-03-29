#ifndef SYSTEMS_CAMERA_H
#define SYSTEMS_CAMERA_H

#include "WPILib.h"
#include "NIVision.h"

#include <string>

class Camera{
private:
	Image* frame;
	IMAQdxSession session;
	IMAQdxError imaqError;
	const char* cam_name = "cam1";
public:
	Camera();
	~Camera();

	void initCamera();
	void startAcquisition();
	void runCamera();
};


#endif
