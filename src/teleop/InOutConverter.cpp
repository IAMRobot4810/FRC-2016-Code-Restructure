/*
 * InOutConverter.cpp
 *
 *  Created on: Mar 11, 2016
 *      Author: 1750800404
 */

#include "InOutConverter.h"

InOutConverter::InOutConverter(){
}

InOutConverter::~InOutConverter(){
}

double InOutConverter::stickOut(StickControl *cont, int axis){
	double out;
	out = linearScale(SetDeadbands(stickLowDead, stickHighDead, cont, axis), stickOutSlope, stickOutIntercept, true);
	return out;
}

double InOutConverter::trigOut(StickControl *cont, int axis){
	double out;
	out = autoLinearScale(SetDeadbands(trigLowDead, trigHighDead, cont, axis), trigInMin, trigInMax, trigOutMin, trigOutMax);
	return out;
}
