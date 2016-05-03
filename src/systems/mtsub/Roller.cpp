/*
 * Roller.cpp
 *
 *  Created on: Apr 5, 2016
 *      Author: Achintya
 */

#include "systems/mtsub/Roller.h"

Roller::Roller(CANTalon *rollermotor, Solenoid *pivot) : Low(false){
	picker = rollermotor;
	raiseSol = pivot;
}

Roller::~Roller(){
	delete picker;
	delete raiseSol;
}

//Spins the roller motor. Positive rolls in, negative rolls out.
void Roller::Roll(float speed){
	picker->Set(speed);
}

//Raise the roller
void Roller::Raise(){
	Low = false;
	raiseSol->Set(Low);
}

//Lower the roller
void Roller::Lower(){
	Low = true;
	raiseSol->Set(Low);
}
