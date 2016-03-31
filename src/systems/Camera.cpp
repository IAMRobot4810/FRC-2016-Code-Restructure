#include "Camera.h"


Camera::Camera(){
	camera = new USBCamera("cam1", false);
	image = imaqCreateImage(IMAQ_IMAGE_RGB, 0);

	camera->OpenCamera();
	camera->StartCapture();
}

Camera::~Camera(){
	camera->StopCapture();
	delete camera;
}

void Camera::capture(){
	camera->GetImage(image);
	CameraServer::GetInstance()->SetImage(image);
}


void Camera::get_infos(){
	SmartDashboard::PutNumber("brightness", camera->GetBrightness());

}

void Camera::calibrate(unsigned int brightness, unsigned int exposure, unsigned int whitebalance){
	camera->SetBrightness(brightness);
	camera->SetExposureManual(exposure);
	camera->SetWhiteBalanceManual(whitebalance);
}

void Camera::calibrateAuto(int brightness){
	camera->SetBrightness(brightness);
	camera->SetExposureAuto();
	camera->SetWhiteBalanceAuto();
}



