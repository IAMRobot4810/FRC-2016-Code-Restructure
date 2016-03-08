/*
 * Deadband.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: 1750800404
 */

#include "Deadband.h"

float SetDeadbands(float lowLimit, float highLimit, Joystick controller, int axis){
	if((controller.GetRawAxis(axis) > lowLimit) && (controller.GetRawAxis(axis) < highLimit)){
		StickIn = 0.0;
	}
	else{
		StickIn = controller.GetRawAxis(axis);
	}
	return StickIn;
}
