/*
 * UnitScaling.h
 *
 *  Created on: Mar 7, 2016
 *      Author: 1750800404
 *
 *      Scaling is handled here, whether it be for controller axis input, or for sensor readings
 */

#ifndef SRC_UTIL_UNITSCALING_H_
#define SRC_UTIL_UNITSCALING_H_

#ifndef SRC_UTIL_SCALING_H_
#define SRC_UTIL_SCALING_H_

//Linear scaling function. "negativesOpposite" is true if you want negative inputs to be the same as positive, just negative, and is useful when setting "b".
double linearScale(double in, double m, double b, bool negativesOpposite);
double autoLinearScale(double minIn, double maxIn, double maxIn, double maxOut, bool negativesOpposite);

//Exponential scaling function. "negativesOpposite" functions the same as above.
double exponentialScale(double in, double exp, double multiple, double intercept, bool negativesOpposite);
double autoExponentialScale(double minIn, double maxIn, double maxIn, double maxOut, double power, bool negativesOpposite);

#endif /* SRC_UTIL_UNITSCALING_H_ */
