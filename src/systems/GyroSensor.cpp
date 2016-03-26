/*
 * GyroSensor.cpp
 *
 *  Created on: Mar 21, 2016
 *      Author: 1750800404
 */

#include "GyroSensor.h"

GyroSensor::GyroSensor(){
	delete gyro;
	gyro = NULL;
}

GyroSensor::GyroSensor(int AnalogIO){
	gyro = new AnalogGyro(AnalogIO);
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
