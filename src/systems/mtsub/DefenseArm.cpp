/*
 * DefenseArm.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: 1750800404
 */

#include "systems/mtsub/DefenseArm.h"

DefenseArm::DefenseArm(Solenoid *pivot) : Low(false){
	noid = pivot;
}

DefenseArm::~DefenseArm(){
	delete noid;
}

void DefenseArm::Lower(){
	Low = true;
	noid->Set(Low);
}

void DefenseArm::Raise(){
	Low = false;
	noid->Set(Low);
}
