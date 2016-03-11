/*
 * Deadband.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: 1750800404
 */

#include "Deadband.h"

float SetDeadbands(float lowLimit, float highLimit, StickControl *control, int axisid){
	float StickIn;
	switch (axisid){
	case 0:
		if((control->getlStickX() > lowLimit) && (control->getlStickX() < highLimit)){
			StickIn = 0.0;
		}
		else{
			StickIn = control->getlStickX();
		}
		break;
	case 1:
		if((control->getlStickY() > lowLimit) && (control->getlStickY() < highLimit)){
			StickIn = 0.0;
		}
		else{
			StickIn = control->getlStickY();
		}
		break;
	case 2:
		if((control->getlTrig() > lowLimit) && (control->getlTrig() < highLimit)){
			StickIn = 0.0;
		}
		else{
			StickIn = control->getlTrig();
		}
		break;
	case 3:
		if((control->getrTrig() > lowLimit) && (control->getrTrig() < highLimit)){
			StickIn = 0.0;
		}
		else{
			StickIn = control->getrTrig();
		}
		break;
	case 4:
		if((control->getrStickX() > lowLimit) && (control->getrStickX() < highLimit)){
			StickIn = 0.0;
		}
		else{
			StickIn = control->getrStickX();
		}
		break;
	case 5:
		if((control->getrStickY() > lowLimit) && (control->getrStickY() < highLimit)){
			StickIn = 0.0;
		}
		else{
			StickIn = control->getrStickY();
		}
		break;
	default:
		StickIn = 0;
	}
	return StickIn;
}
