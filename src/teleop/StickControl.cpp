/*
 * StickControl.cpp
 *
 *  Created on: Mar 9, 2016
 *      Author: 1750800404
 */

#include "StickControl.h"

StickControl::StickControl(int id){
	stick = new Joystick(id);
	aButton = new JoystickButton(stick, 1);
	bButton = new JoystickButton(stick, 2);
	xButton = new JoystickButton(stick, 3);
	yButton = new JoystickButton(stick, 4);
	rBumper = new JoystickButton(stick, 6);
	lBumper = new JoystickButton(stick, 5);
	rStickButton = new JoystickButton(stick, 10);
	lStickButton = new JoystickButton(stick, 9);
	startButton = new JoystickButton(stick, 8);
	backButton = new JoystickButton(stick, 7);
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
	stick->GetPOV();
}

double StickControl::getrStickX(){
	return stick->GetRawAxis(4);
}

double StickControl::getrStickY(){
	return stick->GetRawAxis(5);
}

double StickControl::getlStickX(){
	return stick->GetRawAxis(0);
}

double StickControl::getlStickY(){
	return stick->GetRawAxis(1);
}

double StickControl::getrTrig(){
	return stick->GetRawAxis(3);
}

double StickControl::getlTrig(){
	return stick->GetRawAxis(2);
}
