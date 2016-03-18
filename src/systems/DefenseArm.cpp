/*
 * DefenseArm.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: 1750800404
 */

#include "DefenseArm.h"

DefenseArm::DefenseArm(){
	noid = new Solenoid(1, 1);
	Low = false;
}

DefenseArm::~DefenseArm(){
	delete noid;
}

void DefenseArm::Lower(){
	noid->Set(true);
	Low = true;
}

void DefenseArm::Raise(){
	noid->Set(false);
	Low = false;
}
