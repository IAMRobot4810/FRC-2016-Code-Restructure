/*
 * RotorEncoder.h
 *
 *  Created on: Apr 4, 2016
 *      Author: Achintya
 */

#ifndef SRC_SYSTEMS_PARTS_SHOOTROTORENCODER_H_
#define SRC_SYSTEMS_PARTS_SHOOTROTORENCODER_H_

#include "DigitalInput.h"
#include "Timer.h"
#include "util/ConstantVals.h"

class ShootRotorEncoder{

public:
	ShootRotorEncoder(int DIOPort);
	~ShootRotorEncoder();

	DigitalInput *RPMSensor;
	Timer *RPMTimer;

	int ReadRPM(); //Read RPM

private:

protected:

};

#endif /* SRC_SYSTEMS_PARTS_SHOOTROTORENCODER_H_ */
