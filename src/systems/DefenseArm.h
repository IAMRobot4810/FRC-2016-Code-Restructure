/*
 * DefenseArm.h
 *
 *  Created on: Mar 7, 2016
 *      Author: 1750800404
 */

#ifndef SRC_SYSTEMS_DEFENSEARM_H_
#define SRC_SYSTEMS_DEFENSEARM_H_

#include "Solenoid.h"
#include "util/DeviceIDs.h"

class DefenseArm{
public:
	DefenseArm();
	~DefenseArm();

	Solenoid *noid;
	bool Low;

	void Lower();
	void Raise();
private:
protected:
};

#endif /* SRC_SYSTEMS_DEFENSEARM_H_ */
