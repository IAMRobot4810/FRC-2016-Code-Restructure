/*
 * PIDStuff.cpp
 *
 *  Created on: Mar 15, 2016
 *      Author: 1750800404
 */

double PPower(double in, double target, double P){
	double error = target - in;
	double power = P * error;
	return power;
}

double PMotorPower(double in, double target, double P, double max, double min){
	double error = target - in;
	double power = P * error;
	if(power > max){
		return max;
	}
	else if(power < min){
		return min;
	}
	else{
		return power;
	}
}


