/*
 * Controller.cpp
 *
 *  Created on: Mar 9, 2016
 *      Author: 1750800404
 */

#include "Controller.h"

Controller::Controller(int id){
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

Controller::~Controller(){
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

bool Controller::aButtonGet(){
	return aButton->Get();
}

bool Controller::bButtonGet(){
	return bButton->Get();
}

bool Controller::xButtonGet(){
	return xButton->Get();
}

bool Controller::yButtonGet(){
	return yButton->Get();
}

bool Controller::rBumperGet(){
	return rBumper->Get();
}

bool Controller::lBumperGet(){
	return lBumper->Get();
}

bool Controller::rStickPress(){
	return rStickButton->Get();
}

bool Controller::lStickPress(){
	return lStickButton->Get();
}

bool Controller::startButtonGet(){
	return startButton->Get();
}

bool Controller::backButtonGet(){
	return backButton->Get();
}

int Controller::getPOV(){
	stick->GetPOV();
}

double Controller::getrStickX(){
	return stick->GetRawAxis(4);
}

double Controller::getrStickY(){
	return stick->GetRawAxis(5);
}

double Controller::getlStickX(){
	return stick->GetRawAxis(0);
}

double Controller::getlStickY(){
	return stick->GetRawAxis(1);
}

double Controller::getrTrig(){
	return stick->GetRawAxis(3);
}

double Controller::getlTrig(){
	return stick->GetRawAxis(2);
}
