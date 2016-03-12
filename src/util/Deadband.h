/*
 * Deadband.h
 *
 *  Created on: Mar 7, 2016
 *      Author: 1750800404
 *
 *      Function to set input based on dead bands from controller axis input.
 */

#ifndef SRC_UTIL_DEADBAND_H_
#define SRC_UTIL_DEADBAND_H_

#include "teleop/StickControl.h"

//Setting dead bands for controller input
float SetDeadbands(float lowLimit, float highLimit, StickControl *control, int axisid);

#endif /* SRC_UTIL_DEADBAND_H_ */
