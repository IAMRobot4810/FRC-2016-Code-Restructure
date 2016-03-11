/*
 * UnitScaling.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: 1750800404
 */

#include "UnitScaling.h"

double linearScale(double in, double m, double b, bool negativesOpposite){
	double out;
	if(negativesOpposite == true){
		if(in > 0){
			out = (m*in) + b;
		}
		else if(in < 0){
			out = (m*in) - b;
		}
		else{
			out = 0;
		}
	}
	else{
		out = (m*in) + b;
	}
	return out;
}

double autoLinearScale(double in, double minIn, double maxIn, double minOut, double maxOut){
	double out;
	double m;
	double b;
	m = (maxOut-minOut)/(maxIn-minIn);
	b = minOut-(m*minIn);
	out = (m*in) + b;
	return out;
}

double exponentialScale(double in, int exp, double multiple, double intercept, bool negativesOpposite){
	double out;
	if(negativesOpposite == true){
		if(exp % 2 == 0){
			if(in > 0){
				out = (multiple*(pow(in, exp))) + intercept;
			}
			else if(in < 0){
				out = (multiple*(pow(in, exp))) - intercept;
			}
			else{
				out = 0;
			}
		}
		else{
			if(in > 0){
				out = (multiple*(pow(in, exp))) + intercept;
			}
			else if(in < 0){
				out = -((multiple*(pow(in, exp))) + intercept);
			}
			else{
				out = 0;
			}
		}
	}
	else{
		out = (multiple*(pow(in, exp))) + intercept;
	}
	return out;
}

double autoExponentialScale(double in, double minIn, double maxIn, double minOut, double maxOut, double power){
	double out;
	out = 0.0;
	return out;
}



