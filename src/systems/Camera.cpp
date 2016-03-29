#include "systems/Camera.h"

Camera::Camera(): imaqError(IMAQdxErrorSuccess){
	frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);

}


void Camera::initCamera(){
	imaqError = IMAQdxOpenCamera(cam_name, IMAQdxCameraControlModeController, &session);
	if(imaqError != IMAQdxErrorSuccess){
		DriverStation::ReportError("IMAQdxOpenCamera error: " + std::to_string((long)imaqError) + "\n");
	}
	imaqError = IMAQdxConfigureGrab(session);
	if(imaqError != IMAQdxErrorSuccess) {
		DriverStation::ReportError("IMAQdxConfigureGrab error: " + std::to_string((long)imaqError) + "\n");
	}

}

void Camera::startAcquisition(){
	IMAQdxStartAcquisition(session);
}

void Camera::runCamera(){
	IMAQdxGrab(session, frame, true, NULL);
	if(imaqError != IMAQdxErrorSuccess) {
		DriverStation::ReportError("IMAQdxGrab error: " + std::to_string((long)imaqError) + "\n");
	} else {
		CameraServer::GetInstance()->SetImage(frame);
	}

}

Camera::~Camera(){
	IMAQdxStopAcquisition(session);
}
