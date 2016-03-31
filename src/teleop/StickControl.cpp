/*
 * StickControl.cpp
 *
 *  Created on: Mar 9, 2016
 *      Author: 1750800404
 */

#include "StickControl.h"

StickControl::StickControl(int id){
	stick = new Joystick(id);
	aButton = new JoystickButton(stick, aButtonID);
	bButton = new JoystickButton(stick, bButtonID);
	xButton = new JoystickButton(stick, xButtonID);
	yButton = new JoystickButton(stick, yButtonID);
	rBumper = new JoystickButton(stick, rBumperID);
	lBumper = new JoystickButton(stick, lBumperID);
	rStickButton = new JoystickButton(stick, rStickButtonID);
	lStickButton = new JoystickButton(stick, lStickButtonID);
	startButton = new JoystickButton(stick, startButtonID);
	backButton = new JoystickButton(stick, backButtonID);
}

StickControl::~StickControl(){
	delete stick;
	delete aButton;
	delete bButton;
	delete xButton;
	delete yButton;
	delete rBumper;
	delete lBumper;
	delete rStickButton;
	delete lStickButton;
	delete startButton;
	delete backButton;
}

bool StickControl::aButtonGet(){
	return aButton->Get();
}

bool StickControl::bButtonGet(){
	return bButton->Get();
}

bool StickControl::xButtonGet(){
	return xButton->Get();
}

bool StickControl::yButtonGet(){
	return yButton->Get();
}

bool StickControl::rBumperGet(){
	return rBumper->Get();
}

bool StickControl::lBumperGet(){
	return lBumper->Get();
}

bool StickControl::rStickPress(){
	return rStickButton->Get();
}

bool StickControl::lStickPress(){
	return lStickButton->Get();
}

bool StickControl::startButtonGet(){
	return startButton->Get();
}

bool StickControl::backButtonGet(){
	return backButton->Get();
}

int StickControl::getPOV(){
	return stick->GetPOV();
}

double StickControl::getrStickX(){
	return stick->GetRawAxis(rStickXAxis);
}

double StickControl::getrStickY(){
	return stick->GetRawAxis(rStickYAxis);
}

double StickControl::getlStickX(){
	return stick->GetRawAxis(lStickXAxis);
}

double StickControl::getlStickY(){
	return stick->GetRawAxis(lStickYAxis);
}

double StickControl::getrTrig(){
	return stick->GetRawAxis(rTrigAxis);
}

double StickControl::getlTrig(){
	return stick->GetRawAxis(lTrigAxis);
}
