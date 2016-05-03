#include "Camera.h"


Camera::Camera(USBCamera *camera, CameraServer *camServer){
	cam = camera;
	cServer = camServer;
	image = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
	imaqFlip(image, image, FlipAxis::IMAQ_HORIZONTAL_AXIS);
	cam->OpenCamera();
	cam->StartCapture();
}

Camera::~Camera(){
	cam->StopCapture();
	delete cam;
	delete cServer;
}

void Camera::capture(){
	/*if(cam->StatusIsFatal()){
		stopCapture();
	}*/
	//else{
	cam->GetImage(image);
	CameraServer::GetInstance()->SetImage(image);
	//}
	//cServer->StartAutomaticCapture(cam);
}

void Camera::stopCapture(){
	cam->StopCapture();
	cam->CloseCamera();
	delete image;
	delete cam;
}

void Camera::calibrate(unsigned int brightness, unsigned int exposure, unsigned int whitebalance){
	cam->SetBrightness(brightness);
	cam->SetExposureManual(exposure);
	cam->SetWhiteBalanceManual(whitebalance);
}

void Camera::calibrateAuto(unsigned int brightness){
	cam->SetBrightness(brightness);
	cam->SetExposureAuto();
	cam->SetWhiteBalanceAuto();
}



