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

#include "Joystick.h"

float SetDeadbands(float lowLimit, float highLimit, Joystick stick, int axis);
float StickIn;

#endif /* SRC_UTIL_DEADBAND_H_ */
