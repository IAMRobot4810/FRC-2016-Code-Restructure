/*
 * RotorEncoder.cpp
 *
 *  Created on: Apr 4, 2016
 *      Author: Achintya
 */

#include "ShootRotorEncoder.h"

ShootRotorEncoder::ShootRotorEncoder(int DIOPort){
	RPMSensor = new DigitalInput(DIOPort);
	RPMTimer = new Timer();
}

ShootRotorEncoder::~ShootRotorEncoder(){
	delete RPMSensor;
}

//Read RPM
int ShootRotorEncoder::ReadRPM(){
	int rpmReading;
	bool sensorToggle = true;
	int reads = 0;
	RPMTimer->Reset();
	RPMTimer->Start();
	while(RPMTimer->Get() <= updateTime){
		if(RPMSensor->Get() == false && sensorToggle){
			sensorToggle = false;
			reads++;
		}
		else if(RPMSensor->Get()){
			sensorToggle = true;
		}
	}
	RPMTimer->Stop();
	rpmReading = (reads * scaleMultiple);
	return rpmReading;
}
