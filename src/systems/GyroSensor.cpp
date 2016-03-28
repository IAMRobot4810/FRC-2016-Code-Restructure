/*
 * GyroSensor.cpp
 *
 *  Created on: Mar 21, 2016
 *      Author: 1750800404
 */

#include "GyroSensor.h"

GyroSensor::GyroSensor(){
	gyro = new AnalogGyro(0);
	gyro->InitGyro();
}

GyroSensor::~GyroSensor(){
	delete gyro;
}

double GyroSensor::GyroAngleRead(){
	return gyro->GetAngle();
}

void GyroSensor::RecalGyro(){
	gyro->Calibrate();
}
