#include "Camera.h"


Camera::Camera(){
	CameraServer::GetInstance()->StartAutomaticCapture(camID.c_str());
	image = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
	camera = nullptr;
}

Camera::Camera(std::string camId){
	camera = new USBCamera(camId, false);
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
	SmartDashboard::PutBoolean("camera disconnect", camera->StatusIsFatal());

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

void Camera::check_emergency_stop(){
	if(camera->StatusIsFatal()){
		camera->StopCapture();
	}
}



