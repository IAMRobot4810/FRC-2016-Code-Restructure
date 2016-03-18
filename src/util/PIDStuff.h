/*
 * PIDStuff.h
 *
 *  Created on: Mar 15, 2016
 *      Author: 1750800404
 */

#ifndef SRC_UTIL_PIDSTUFF_H_
#define SRC_UTIL_PIDSTUFF_H_

double PPower(double in, double target, double P); //Proportional error correction for other
double PMotorPower(double in, double target, double P, double max, double min); //Proportional error correction for motors

#endif /* SRC_UTIL_PIDSTUFF_H_ */
