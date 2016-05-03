/*
 * RotorEncoder.cpp
 *
 *  Created on: Apr 4, 2016
 *      Author: Achintya
 */

#include "systems/mtsub/parts/ShootRotorEncoder.h"

ShootRotorEncoder::ShootRotorEncoder(DigitalInput *tapesensor, Timer *timer){
	RPMSensor = tapesensor;
	RPMTimer = timer;
}

ShootRotorEncoder::~ShootRotorEncoder(){
	delete RPMSensor;
	delete RPMTimer;
}

//Read RPM average from 100 reads
int ShootRotorEncoder::ReadRPM(){
	int readTable[100];
	for(int i = 0; i <= 99; i++){
		readTable[i] = singleRead();
	}
	int readSum = std::accumulate(std::begin(readTable), std::end(readTable), 0, std::plus<int>());
	int avg = (readSum / 100);
	return avg;
}

//Get single instance of RPM
int ShootRotorEncoder::singleRead(){
	int reading;
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
	reading = (reads * scaleMultiple);
	return reading;
}
