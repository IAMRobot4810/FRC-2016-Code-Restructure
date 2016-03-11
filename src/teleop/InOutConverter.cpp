/*
 * InOutConverter.cpp
 *
 *  Created on: Mar 11, 2016
 *      Author: 1750800404
 */

#include "InOutConverter.h"

InOutConverter::InOutConverter(StickControl *cont){

}

InOutConverter::~InOutConverter(){

}

double InOutConverter::stickOut(int axis){
	double out;
	out = linearScale(SetDeadbands(stickLowDead, stickHighDead, cont, axis), stickOutSlope, stickOutIntercept, true);
	return out;
}

double InOutConverter::trigOut(int axis){
	double out;
	out = autoLinearScale(SetDeadbands(trigLowDead, trigHighDead, cont, axis), trigInMin, trigInMax, trigOutMin, trigOutMax);
	return out;
}
