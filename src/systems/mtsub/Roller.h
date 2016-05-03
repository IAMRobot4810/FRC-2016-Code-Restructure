/*
 * Roller.h
 *
 *  Created on: Apr 5, 2016
 *      Author: Achintya
 */

#ifndef SRC_SYSTEMS_ROLLER_H_
#define SRC_SYSTEMS_ROLLER_H_

#include "CANTalon.h"
#include "Solenoid.h"
#include "util/DeviceIDs.h"

class Roller{

public:
	Roller(CANTalon *rollermotor, Solenoid *pivot);
	~Roller();

	CANTalon *picker;
	Solenoid *raiseSol;
	bool Low;

	void Roll(float speed); //Spins the roller motor. Positive rolls in, negative rolls out.
	void Raise(); //Raise the roller
	void Lower(); //Lower the roller

private:

protected:

};

#endif /* SRC_SYSTEMS_ROLLER_H_ */
