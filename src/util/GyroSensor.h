/*
 * GyroSensor.h
 *
 *  Created on: Mar 21, 2016
 *      Author: 1750800404
 */

#ifndef SRC_UTIL_GYROSENSOR_H_
#define SRC_UTIL_GYROSENSOR_H_

#include "AnalogGyro.h"

class GyroSensor{

public:
	GyroSensor();
	~GyroSensor();

	AnalogGyro *gyro;

	double GyroAngleRead();
	void RecalGyro();

private:
protected:
};

#endif /* SRC_UTIL_GYROSENSOR_H_ */
